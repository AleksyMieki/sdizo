//
// Created by aleks on 01.05.22.
//

#include "List.h"


List::~List() {

    Node *node = head;

    while (node) {
        Node *next = node->next_node;

        delete node;
        node = next;
    }

}

void List::List_Add_front(int data) {

    Node* new_node = head;

    head = new Node();
    head->data = data;
    head->next_node = new_node;

    if(new_node)
    {
        new_node->previous_node = head;
    }
    else{
        tail = head;
    }

}

void List::List_Add_end(int data) {

    Node* new_node = new Node;

    new_node->data = data;
    new_node->previous_node = tail;

    if(tail)
    {
        tail->next_node = new_node;
    }
    else{//if tail doesnt exist then head also doesnt exist, so new_node becomes head
        head = new_node;
    }

    tail = new_node;
}

void List::List_display() {

    Node* node = head;

    while(node)
    {
        std::cout<<node->data<<" ";
        node = node->next_node;
    }

}

void List::List_Insert_before(int data,Node *node) {

    if(!node)
        {
            std::cerr<<"node doesnt exist" << std::endl;
            return;
        }

    Node* new_node = new Node();
    new_node->data = data;
    new_node->next_node = node;
    new_node->previous_node = node->previous_node;

    if(node->previous_node)
    {
        node->previous_node->next_node = new_node;

    }
    else{
        head = new_node;
    }
    node->previous_node = new_node;
}

void List::List_Insert_after(int data, Node *node) {

    if(!node)
    {
        std::cerr<<"node doesnt exist" << std::endl;
        return;
    }

    Node* new_node = new Node();

    new_node->data = data;
    new_node->previous_node = node;

    if(node->next_node)
    {
        node->next_node->previous_node = new_node;
        new_node->next_node = node->next_node;
        node->next_node = new_node;
    }
    else{
        tail = new_node;
    }
    node->next_node = new_node;
}

Node *List::get_node(int data) {

    Node* node = head;
    while(node)
    {
        if(node->data == data)
        {
            return node;
        }
        node = node->next_node;
    }
    return nullptr;
}

void List::List_Pop_front() {

    if(!head)
    {
        std::cerr <<"\nlist is empty\n" ;
        return;
    }

    if(!head->next_node)
    {
        delete head;

        head = nullptr;
        tail = nullptr;

        return;
    }

    Node* node = head;

    head = head->next_node;
    head->previous_node = nullptr;

    delete node;


}

void List::List_Pop_back() {

    if(!tail)
    {
        std::cerr << "\nlist is empty\n";
        return;
    }

    if(!tail->previous_node) //tail is the only element in the list
    {
        delete tail;

        tail = nullptr;
        head = nullptr;

        return;
    }

    Node* node = tail;

    tail = tail->previous_node;
    tail->next_node = nullptr;

    delete node;

}

void List::List_delete_after(Node* node) {

    if(!node)
    {
        std::cerr << "\nnode doesnt exist\n";
        return;
    }

    if(!node->next_node)
    {
        std::cerr << "\nnode is tail, nothing to delete\n";
        return;
    }

    if(!node->next_node->next_node)
    {
        delete node->next_node;
        node->next_node = nullptr;
        tail = node;

        return;
    }

    Node* temporary = node->next_node;
    node->next_node->next_node->previous_node = node;
    node->next_node = temporary->next_node;

    delete temporary;


}

void List::List_delete_before(Node *node) {

    if(!node)
    {
        std::cerr << "\nnode doesnt exist\n";
        return;
    }

    if(!node->previous_node)
    {
        std::cerr << "\nnode is head, nothing to delete\n";
        return;
    }

    if(!node->previous_node->previous_node)
    {
        delete node->previous_node;
        node->previous_node = nullptr;
        head = node;
        return;
    }

    Node* temporary = node->previous_node;

    node->previous_node->previous_node->next_node = node;
    node->previous_node = temporary->previous_node;

    delete temporary;


}

void List::List_delete_node(Node *node) {

    if(!node)
    {
        std::cerr << "\nnode doesnt exist\n";
        return;
    }


    if (node->previous_node)
        node->previous_node->next_node = node->next_node;
    else
    if (node->next_node)
        head = node->next_node;
    else
        head = nullptr;

    if (node->next_node)
        node->next_node->previous_node = node->previous_node;
    else

    if (node->previous_node)
        tail = node->previous_node;
    else
        tail = nullptr;

    delete node;
    node = nullptr;


}

void List::List_Search(int data) {

    Node* node = head;

    while(node)
    {
        if(node->data == data)
        {
      //     std::cout<<"node found";
            return;
        }
    node = node->next_node;
    }

   //std::cout <<"node not found\n";


}

Node *List::get_node_atpos(int pos) {

    Node* node = head;
    int i = 0;
    while(i!= pos && node)
    {
        i++;
        node = node->next_node;
        if(i == pos) return  node;

    }
    return nullptr;
}



