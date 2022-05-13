//
// Created by aleks on 01.05.22.
//
#pragma once
#ifndef SDIZO_PROJEKT2_LIST_H
#define SDIZO_PROJEKT2_LIST_H
#include "iostream"

struct Node{
    int data;
    Node* next_node = nullptr;
    Node* previous_node = nullptr;
};

class List {

private:

    Node* head = nullptr;
    Node* tail = nullptr;
public:

    void List_Add_front(int data);
    void List_Add_end(int data);
    void List_Insert_before(int data,Node* node);
    void List_Insert_after(int data,Node* node);

    void List_Search(int data);

    void List_Pop_front();
    void List_Pop_back();
    void List_delete_after(Node* node);
    void List_delete_before(Node* node);
    void List_delete_node(Node* node);

    Node* get_node(int data);
    Node* get_node_atpos(int pos);
    void List_display();

    ~List();


};


#endif //SDIZO_PROJEKT2_LIST_H
