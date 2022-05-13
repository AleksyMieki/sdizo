//
// Created by aleks on 02.05.22.
//
#pragma once
#ifndef SDIZO_PROJEKT2_RB_TREE_H
#define SDIZO_PROJEKT2_RB_TREE_H
#include "iostream"


struct Rb_Node{

    int data=0;
    Rb_Node* parent = nullptr;
    Rb_Node* left_child = nullptr;
    Rb_Node* right_child = nullptr;

    int color = 1;
};


class RB_tree {

private:

    Rb_Node* root = nullptr;
    Rb_Node* Nil;

public:
    RB_tree() {

        Nil = new Rb_Node;
        Nil->color = 0;
        Nil->left_child = nullptr;
        Nil->right_child = nullptr;
        root = Nil;

    }

    ~RB_tree();
    void Rb_delete_children(Rb_Node* parent);

    //helper functions
    void Rb_Left_rotate(Rb_Node* node);
    void Rb_Right_rotate(Rb_Node* node);
    void rbTransplant(Rb_Node* u, Rb_Node* v);
    Rb_Node* minimum(Rb_Node* node); //function to return a minimum value of a given subtree
    Rb_Node* Rb_get_root();

    void Rb_Insert(int data);
    void Rb_delete_val(Rb_Node* node);
    void Rb_insert_fix(Rb_Node* node);
    void Rb_delete_fix(Rb_Node* node);

    Rb_Node* Rb_search(Rb_Node* node, int data);

    void Rb_print(Rb_Node* node);
    void print(Rb_Node* root, std::string indent, bool last);

    void printTree() {
        if (root) {
            print(this->root, "", true);
        }
    }



};


#endif //SDIZO_PROJEKT2_RB_TREE_H
