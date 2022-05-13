//
// Created by aleks on 02.05.22.
//

#include "RB_tree.h"

RB_tree::~RB_tree() {

    if(root) Rb_delete_children(root);
    delete Nil;
}

void RB_tree::Rb_delete_children(Rb_Node *parent) {

    if (parent->left_child)
        Rb_delete_children(parent->left_child);
    if (parent->right_child)
        Rb_delete_children(parent->right_child);
   // if (parent == Nil) free(parent);
if(parent!= Nil)
    delete parent;

}
void RB_tree::Rb_Insert(int data) {

    auto* node = new Rb_Node;
    node->parent = nullptr;
    node->data = data;
    node->left_child = Nil;
    node->right_child = Nil;
    node->color = true;

    Rb_Node* y = nullptr;
    Rb_Node* x = root;


    while(x != Nil)
    {
        y = x;
        if(node->data < x->data)
        {
            x = x->left_child;
        }
        else{
            x = x->right_child;
        }
    }

    node->parent = y;

    if (y == nullptr) {
        root = node;
    } else if (node->data < y->data) {
        y->left_child = node;
    } else {
        y->right_child = node;
    }

    if (node->parent == nullptr) {
        node->color = false;
        return;
    }

    if (node->parent->parent == nullptr) {
        return;
    }

    Rb_insert_fix(node);

}

Rb_Node *RB_tree::Rb_get_root() {
    return this->root;
}

void RB_tree::Rb_insert_fix(Rb_Node *node) {

    Rb_Node* u;

    while (node->parent->color == 1) {
        if (node->parent == node->parent->parent->right_child) {
            u = node->parent->parent->left_child;
            if (u->color == 1) {
                u->color = 0;
                node->parent->color = 0;
                node->parent->parent->color = 1;
                node = node->parent->parent;
            } else {
                if (node == node->parent->left_child) {
                    node = node->parent;
                    Rb_Right_rotate(node);
                }
                node->parent->color = 0;
                node->parent->parent->color = 1;
                Rb_Left_rotate(node->parent->parent);
            }
        } else {
            u = node->parent->parent->right_child;

            if (u || u->color == 1) {

                u->color = 0;
                node->parent->color = 0;
                node->parent->parent->color = 1;
                node = node->parent->parent;
            } else {
                if (node == node->parent->right_child) {
                    node = node->parent;
                    Rb_Left_rotate(node);
                }
                node->parent->color = 0;
                node->parent->parent->color = 1;
                Rb_Right_rotate(node->parent->parent);
            }
        }
        if (node == root) {
            break;
        }
    }
    root->color = 0;

}



void RB_tree::Rb_Left_rotate(Rb_Node* node) {

        Rb_Node* y = node->right_child;

        node->right_child = y->left_child;

        if (y->left_child != Nil) {
            y->left_child->parent = node;
        }
        y->parent = node->parent;
        if (node->parent == nullptr) {
            this->root = y;
        } else if (node == node->parent->left_child) {
            node->parent->left_child = y;
        } else {
            node->parent->right_child = y;
        }
        y->left_child = node;
        node->parent = y;

}

void RB_tree::Rb_Right_rotate(Rb_Node *node) {

    Rb_Node* y = node->left_child;

    node->left_child = y->right_child;

    if (y->right_child != Nil) {
        y->right_child->parent = node;
    }

    y->parent = node->parent;

    if (node->parent == nullptr) {
        this->root = y;
    } else if (node == node->parent->right_child) {
        node->parent->right_child = y;
    } else {
        node->parent->left_child = y;
    }

    y->right_child = node;
    node->parent = y;

}

void RB_tree::Rb_print(Rb_Node* node) {

    if (node != nullptr) {

        Rb_print(node->left_child);

        if(node == root) std::cout <<" root-";
        if(node != Nil) {std::cout << node->data ;
            if(node->color) {
                std::cout << "<-R ";
            }else std::cout << "<-B ";
        }


        Rb_print(node->right_child);


    }





}
void RB_tree::rbTransplant(Rb_Node* u, Rb_Node* v) {

    if (u->parent == nullptr) {
    root  = v;
    } else if (u == u->parent->left_child) {
        u->parent->left_child = v;
    } else {
        u->parent->right_child = v;
    }
    v->parent = u->parent;
}

void RB_tree::Rb_delete_fix(Rb_Node *x) {

    Rb_Node* s;
    while (x != root && x->color == 0) {
        if(s==Nil) return;
        if (x == x->parent->left_child) {
            s = x->parent->right_child;
            if (s->color == 1) {
                s->color = 0;
                x->parent->color = 1;
                Rb_Left_rotate(x->parent);
                s = x->parent->right_child;
            }
        if(s!=Nil)
            if (s->left_child->color == 0 && s->right_child->color == 0) {
                s->color = 1;
                x = x->parent;
            } else {
                if (s->right_child->color == 0) {
                    s->left_child->color = 0;
                    s->color = 1;
                    Rb_Right_rotate(s);
                    s = x->parent->right_child;
                }

                s->color = x->parent->color;
                x->parent->color = 0;
                s->right_child->color = 0;
                Rb_Left_rotate(x->parent);
                x = root;
            }
        } else {
            s = x->parent->left_child;
            if (s->color == 1) {
                s->color = 0;
                x->parent->color = 1;
                Rb_Right_rotate(x->parent);
                s = x->parent->left_child;
            }
            if(s!=Nil)
            if (s->left_child->color == 0 && s->right_child->color == 0) {
                s->color = 1;
                x = x->parent;
            } else {
                if (s->left_child->color == 0) {
                    s->right_child->color = 0;
                    s->color = 1;
                    Rb_Left_rotate(s);
                    s = x->parent->left_child;
                }

                s->color = x->parent->color;
                x->parent->color = 0;
                s->left_child->color = 0;
                Rb_Right_rotate(x->parent);
                x = root;
            }
        }
    }
    x->color = 0;
}

void RB_tree::Rb_delete_val(Rb_Node *node) {

     if(!node) return;

    Rb_Node* y = node;
    Rb_Node* x;
    int y_original_color = y->color;
    if (node->left_child == Nil) {
        x = node->right_child;
        rbTransplant(node, node->right_child);
    } else if (node->right_child == Nil) {
        x = node->left_child;
        rbTransplant(node, node->left_child);
    } else {
        y = minimum(node->right_child);
        y_original_color = y->color;
        x = y->right_child;
        if (y->parent == node) {
            x->parent = y;
        } else {
            rbTransplant(y, y->right_child);
            y->right_child = node->right_child;
            y->right_child->parent = y;
        }

        rbTransplant(node, y);
        y->left_child = node->left_child;
        y->left_child->parent = y;
        y->color = node->color;
    }
    delete node;
    if (y_original_color == 0) {
        Rb_delete_fix(x);
    }
}

Rb_Node* RB_tree::minimum(Rb_Node* node) {
    if (node) {
        while (node->left_child != Nil) {
            node = node->left_child;
        }
        return node;
    }
    return Nil;
}

Rb_Node* RB_tree::Rb_search(Rb_Node* node, int data) {
    if(!root) return nullptr;
    if (node == Nil || data == node->data) {
        return node;
    }

    if (data < node->data) {
        return Rb_search(node->left_child, data);
    }
    return Rb_search(node->right_child, data);
}

void RB_tree::print(Rb_Node *root, std::string indent, bool last) {

    if (root != Nil) {
        std::cout << indent;
        if (last) {
            std::cout << "R----";
            indent += "   ";
        } else {
            std::cout << "L----";
            indent += "|  ";
        }

        std::string sColor = root->color ? "RED" : "BLACK";
        std::cout << root->data << "(" << sColor << ")" << std::endl;
        print(root->left_child, indent, false);
        print(root->right_child, indent, true);
    }
}




