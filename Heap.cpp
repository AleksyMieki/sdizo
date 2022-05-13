//
// Created by aleks on 21.04.22.
//

#include "Heap.h"


void Heap::Heap_insert(const int val) {

        data.push_back(val);
        Heapify_up(data.size()-1);

}

void Heap::Heap_display()  {



        int j = 2;
        int p = 0;
    for(int i = 0 ; i < data.size() ; i++) {
        std::cout << data.at(i) << " ";


        if (i == j - 2) {
            std::cout << std::endl;
            j = j * 2;

        }
    }

    std::cout << std::endl;

}

void Heap::Heap_delete_max() {

    if(!data.size())
    {
        std::cout << "heap is empty" << std::endl;
        return;
    }


    data.at(0) = data.at(data.size()-1);
    data.delete_back();


    Heapify_down(0);

}

//heapify from top to bottom
void Heap::Heapify_down(int pos) {

    int child = Left(pos);
    int child1 = Right(pos);

    if (child >= 0 && child1 >= 0 && data.at(child) < data.at(child1))
    {
        child = child1;
    }
    if (child > 0)
    {

        int temp = data.at(pos);
        data.at(pos) = data.at(child);
        data.at(child) = temp;
        Heapify_down(child);

    }
}
void Heap::Heapify_up(int pos) {

    if (pos >= 0 && Parent(pos) >= 0 && data.at(Parent(pos)) < data.at(pos))
    {
        int temp = data.at(pos);
        data.at(pos) = data.at(Parent(pos));
        data.at(Parent(pos)) = temp;
        Heapify_up(Parent(pos));
    }
}

int Heap::Right(int parent) {

    int r = 2 * parent + 2;
    if(r < data.size())
        return r;
    else
        return -1;

}

int Heap::Left(int parent) {

    int l = 2 * parent + 1;
    if( l < data.size() )
        return l;
    else
        return -1;
}

int Heap::Parent(int child) {

    int p = (child - 1)/2;
    if(child == 0)
        return -1;
    else
        return p;
}

int Heap::Find_max() {
    if(data.size()) {
        return data.at(0);
    }
    return 0;
}

int Heap::Extract_max() {
    if(data.size()) {
        int max = data.at(0);

        data.at(0) = data.at(data.size()-1);
        data.delete_back();


        Heapify_down(0);
        return  max;
    }
    std::cout<<"heap is empty" << std::endl;
    return 0;

}

void Heap::Heap_delete_val(int val) {

        if(data.search_val(val))
        {
            int i = data.search_val(val);
            data.at(i) = data.at(data.size()-1);
            data.delete_back();
            Heapify_up(data.size()-1);
            return;
        }
       // std::cerr << "no such value in the heap\n";

}




