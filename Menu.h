//
// Created by aleks on 21.04.22.
//
#pragma once

#ifndef SDIZO_PROJEKT2_MENU_H
#define SDIZO_PROJEKT2_MENU_H

#include "Heap.h"
#include "Array.h"
#include "List.h"
#include "RB_tree.h"
#include "vector"
#include "fstream"
#include "cstdlib"

class Menu {

Array array;
Heap heap;
List list;
RB_tree rbTree;

public:
    int Options();
    int Get_data();
    void Array_functions();
    void Heap_functions();
    void List_functions();
    void Rb_functions();
    int End_program(){ return 0; };

    void read_from_file_Array();//TODO dodac do switcha i cos z rozmiarem tablicy na poczatku
    void read_from_file_List();
    void read_from_file_Heap();
    void read_from_file_Rbtree();
};


#endif //SDIZO_PROJEKT2_MENU_H
