//
// Created by aleks on 21.04.22.
//

#ifndef SDIZO_PROJEKT2_ARRAY_H
#define SDIZO_PROJEKT2_ARRAY_H
#include "iostream"
#include "initializer_list"

class Array {

    int array_size;
    int* array = nullptr;

public:

    Array();
    explicit Array(int size);

    ~Array();


    int& at(int pos);
    int size() const ;
    void push_front(int val); //inserts an element in the front
    void push_back(int val); //inserts an element in the back
    void insert(int val, int pos); // inserts  an element at a given position

    void delete_front(); //deletes an element at front
    void delete_back(); //deletes an element in the back
    void delete_pos(int pos);
    int search_val(int val); //returns true if array contains given value

    void display() const; //displays array

};


#endif //SDIZO_PROJEKT2_ARRAY_H
