//
// Created by aleks on 11.05.22.
//

#ifndef SDIZO_PROJEKT2_BENCHMARKS_H
#define SDIZO_PROJEKT2_BENCHMARKS_H
#include "chrono"
#include "random"
#include "Array.h"
#include "List.h"
#include "Heap.h"
#include "RB_tree.h"
#include "vector"
#pragma once

class Benchmarks : public Array {

const int amount = 3000;
 int repeats = 100;
class TimeMeasure {

    std::chrono::high_resolution_clock::time_point start, end;
    std::chrono::duration<double> elapsed = std::chrono::duration<double>::zero();
    std::size_t times=0;

public:
    void Benchmarks_start() {

        start = std::chrono::high_resolution_clock::now();
    }

    void Benchmarks_stop() {

        end = std::chrono::high_resolution_clock::now();

        elapsed += end - start;
        times++;
    }

    unsigned long long GetTimeElapsed() {

        return std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count()/times;
    }
};

public:
       std::vector<int> randData(int first, int second,int amount); //function for generating random data into a vector for later usage
    //Array benchmark functions
       void Array_tests(); //function to run all array tests
        //insert functions benchmarks
       unsigned long long Array_p_front();
       unsigned long long Array_p_back();
       unsigned long long Array_insert();
        //delete functions benchmarks
       unsigned long long Array_d_front();
       unsigned long long Array_d_back();
       unsigned long long Array_d_pos();

       unsigned long long Array_search();

        //List benchmark functions
        void List_tests();
        //insert functions benchmarks
        unsigned long long List_push_front();
        unsigned long long List_push_end();
        unsigned long long  List_I_before();
        unsigned long long  List_I_after();

        unsigned long long  List_Search_benchmark();
        //delete functions benchmarks
        unsigned long long  List_pop_front();
        unsigned long long  List_pop_back();
        unsigned long long  List_d_after();
        unsigned long long  List_d_before();
        unsigned long long  List_d_node();

        //Heap benchmark functions
        void Heap_tests();
        //Heap insert functions
        unsigned long long Heap_ins();
        //Heap delete benchmarks
        unsigned long long Heap_d_max();
        unsigned long long Heap_d_val();
        //heap find and extract benchmarks
        unsigned long long Find_max_benchmark();
        unsigned long long Extract_max_benchmark();

        //Red black tree benchmark functions
        void RB_tests();

        unsigned long long Rb_Ins();
        unsigned long long Rb_d_root();
        unsigned long long Rb_d_node();
        unsigned long long Rb_search_benchmark();
        //unsigned long long Rb_get_r();


};


#endif //SDIZO_PROJEKT2_BENCHMARKS_H
