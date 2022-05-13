//
// Created by aleks on 21.04.22.
//

#ifndef SDIZO_PROJEKT2_HEAP_H
#define SDIZO_PROJEKT2_HEAP_H
#pragma once
#include "iostream"
#include "Array.h"

class Heap {

        Array data;

public:


        void Heap_insert(int val); //inserts an element into heap
        void Heap_delete_max(); //deletes max element of the heap and heapifys
        void Heap_delete_val(int val); //deletes a given value
        void Heap_display(); //displays heap in a form of an array
        int Find_max(); //returns max value of the heap
        int Extract_max();

        void Heapify_down(int pos);//used to bring back the heap structure
        void Heapify_up(int pos);//same as above

        int Right(int parent); //return right child of given parent
        int Left(int parent); // return left child of given parent
        int Parent(int child); // return parent of a child
};


#endif //SDIZO_PROJEKT2_HEAP_H
