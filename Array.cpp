//
// Created by aleks on 21.04.22.
//

#include "Array.h"

Array::Array() {
    this->array_size = 0;
}

Array::Array(int size): array_size(size) {

    if(size == 0) return;

    array = nullptr;

}


Array::~Array() {

    delete[] array;

}


void Array::push_back(const int val) {

    int *new_array = new int[array_size+1];

    for(int i = 0 ; i <array_size ; i++)
    {
        new_array[i] = array[i];
    }

    delete[] array;
    array = new_array;
    array_size +=1;

    array[array_size - 1] = val;

}



void Array::push_front(const int val) {

    int *new_array = new int[array_size + 1];

    for(int i = 0 ; i < array_size ; i++)
    {
        new_array[i+1] = array[i];
    }
    new_array[0] = val;

    delete [] array;
    array = new_array;
    array_size += 1;

}

void Array::insert(const int val,const int pos) {

    if(pos > array_size || pos < 0)
    {
        std::cerr<<"pos is out of array range\n";
        return;
    }
    int* new_array = new int[array_size + 1];

    int k = 0;
    for(int i = 0 ; i < array_size + 1 ; i++)
    {
        if(i == pos)
        {
            *(new_array+i) = val;
        }
        else
        {
            *(new_array+i) = *(array + k++);
        }
    }

    delete [] array;
    array = new_array;
    array_size +=1;

}

void Array::delete_front() {

    if(array_size == 0)
    {
        std::cerr<<"array has no elements\n";
        return;
    }

    int* new_array = new int[array_size - 1];

    for(int i = 0 ; i < array_size-1 ; i++)
    {
        new_array[i] = array[i+1];
    }

    delete[] array;
    array = new_array;
    array_size -= 1;
}

void Array::delete_back()
{
    if(array_size == 0)
    {
        std::cerr<<"array has no elements\n";
        return;
    }
    int *new_array = new int[array_size-1];

    for(int i = 0 ; i < array_size-1 ; i++)
    {
        new_array[i] = array[i];
    }

    delete[] array;
    array = new_array;
    array_size -=1;
}

void Array::delete_pos(const int pos) {

    if(pos > array_size || pos < 0)
    {
        std::cerr<< "given pos is out of range of the array";
        return;
    }

    int* new_array = new int[array_size - 1];

    int k=0;

    for(int i = 0 ; i < array_size ; i++)
    {
        if( i == pos )
        {

        }
        else
        {
            new_array[k++] = array[i];
        }
    }
    delete[] array;

    array = new_array;

}
void Array::display() const {

    for(int i = 0 ; i < array_size ; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int Array::search_val(const int val) {

    for(int i = 0 ; i < array_size ; i++)
    {
        if(val == array[i]) return i;
    }
    return 0;
}

int& Array::at(int pos){
    return array[pos];
}


int Array::size() const {
    return this->array_size;
}


