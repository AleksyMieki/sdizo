//
// Created by aleks on 11.05.22.
//

#include "Benchmarks.h"

std::vector<int> Benchmarks::randData(int first, int second,int amount) {

    std::vector<int> vec;
    for(int i =0; i < amount; i++) {
        static   std::random_device dev;
        static std::default_random_engine rng(dev());
        std::uniform_int_distribution<int> dist6(first, second);
        vec.push_back(dist6(rng));
    }
    return vec;

}





unsigned long long Benchmarks::Array_p_front() {

    TimeMeasure timeMeasure;
    std::vector<int> vec = randData(10,300,amount);
    Array array;
    for(auto val : vec)
    {
        array.push_front(val);
    }
    for(int i = 0 ; i < repeats ; i++) {
        timeMeasure.Benchmarks_start();
        array.push_front(4);
        timeMeasure.Benchmarks_stop();
    }
    return  timeMeasure.GetTimeElapsed();

}

unsigned long long Benchmarks::Array_p_back() {
    TimeMeasure timeMeasure;
    std::vector<int> vec = randData(10,300,amount);
    Array array;
    for(auto val : vec)
    {
        array.push_back(val);
    }
    for(int i = 0 ; i < repeats ; i++) {
        timeMeasure.Benchmarks_start();
        array.push_back(1);
        timeMeasure.Benchmarks_stop();
    }
    return  timeMeasure.GetTimeElapsed();
}



unsigned long long Benchmarks::Array_insert() {

    TimeMeasure timeMeasure;
    std::vector<int> vec = randData(10,300,amount);
    Array array;

    for(auto val : vec)
    {
        array.push_back(val);
    }
    for(int i = 0 ; i < repeats ; i++) {
        timeMeasure.Benchmarks_start();
        array.insert(1, 15);
        timeMeasure.Benchmarks_stop();
    }
    return  timeMeasure.GetTimeElapsed();

}

unsigned long long Benchmarks::Array_d_front() {

    TimeMeasure timeMeasure;
    std::vector<int> vec = randData(10,300,amount);
    Array array;

    for(auto val : vec)
    {
        array.push_back(val);
    }
    for(int i = 0 ; i < repeats ; i++) {
        timeMeasure.Benchmarks_start();
        array.delete_front();
        timeMeasure.Benchmarks_stop();
    }
    return  timeMeasure.GetTimeElapsed();
}

unsigned long long Benchmarks::Array_d_back() {

    TimeMeasure timeMeasure;
    std::vector<int> vec = randData(10,300,amount);
    Array array;

    for(auto val : vec)
    {
        array.push_back(val);
    }
    for(int i = 0 ; i < repeats ; i++) {
        timeMeasure.Benchmarks_start();
        array.delete_back();
        timeMeasure.Benchmarks_stop();
    }
    return  timeMeasure.GetTimeElapsed();
}

unsigned long long Benchmarks::Array_d_pos() {

    TimeMeasure timeMeasure;
    std::vector<int> vec = randData(10,300,amount);
    Array array;

    for(auto val : vec)
    {
        array.push_back(val);
    }
    for(int i = 0 ; i < repeats ; i++) {
        timeMeasure.Benchmarks_start();
        array.delete_pos(20);
        timeMeasure.Benchmarks_stop();
    }
    return  timeMeasure.GetTimeElapsed();
}

unsigned long long Benchmarks::Array_search() {

    TimeMeasure timeMeasure;
    std::vector<int> vec = randData(10,300,amount);
    Array array;

    for(auto val : vec)
    {
        array.push_back(val);
    }
    for(int i = 0 ; i < repeats ; i++) {
        timeMeasure.Benchmarks_start();
        array.search_val(450);
        timeMeasure.Benchmarks_stop();
    }
    return  timeMeasure.GetTimeElapsed();
}
void Benchmarks::Array_tests() {

    std::cout <<"Array push front for: " << amount << " elements is " << Array_p_front() <<" ns\n";
    std::cout <<"Array push back for: " << amount << " elements is " << Array_p_back() <<" ns\n";
    std::cout <<"Array insert for: " << amount << " elements is " << Array_insert() <<" ns\n";
    std::cout <<"Array delete front for: " << amount << " elements is " << Array_d_front() <<" ns\n";
    std::cout <<"Array delete back for: " << amount << " elements is " << Array_d_back() <<" ns\n";
    std::cout <<"Array delete at position for: " << amount << " elements is " << Array_d_pos() <<" ns\n";
    std::cout <<"Array search for: " << amount << " elements is " << Array_search() <<" ns\n";
}

unsigned long long Benchmarks::List_push_front() {

    TimeMeasure timeMeasure;
    std::vector<int> vec = randData(10,300,amount);
    List list;

    for(auto val : vec)
    {
        list.List_Add_front(val);
    }
    for(int i = 0 ; i < repeats ; i++) {
        timeMeasure.Benchmarks_start();
        list.List_Add_front(450);
        timeMeasure.Benchmarks_stop();
    }
    return  timeMeasure.GetTimeElapsed();
}



unsigned long long Benchmarks::List_push_end() {

    TimeMeasure timeMeasure;
    std::vector<int> vec = randData(10,300,amount);
    List list;

    for(auto val : vec)
    {
        list.List_Add_front(val);
    }
    for(int i = 0 ; i < repeats ; i++) {
        timeMeasure.Benchmarks_start();
        list.List_Add_end(450);
        timeMeasure.Benchmarks_stop();
    }
    return  timeMeasure.GetTimeElapsed();

}

unsigned long long Benchmarks::List_I_before() {

    TimeMeasure timeMeasure;
    std::vector<int> vec = randData(10,300,amount);
    List list;

    for(auto val : vec)
    {
        list.List_Add_front(val);
    }
    Node* node = list.get_node_atpos(450);
    for(int i = 0 ; i < repeats ; i++) {
        timeMeasure.Benchmarks_start();
        list.List_Insert_before(450, node);
        timeMeasure.Benchmarks_stop();
    }
    return  timeMeasure.GetTimeElapsed();
}

unsigned long long Benchmarks::List_I_after() {

    TimeMeasure timeMeasure;
    std::vector<int> vec = randData(10,300,amount);
    List list;

    for(auto val : vec)
    {
        list.List_Add_front(val);
    }
    Node* node = list.get_node_atpos(450);
    for(int i = 0 ; i < repeats ; i++) {
        timeMeasure.Benchmarks_start();
        list.List_Insert_after(450, node);
        timeMeasure.Benchmarks_stop();
    }
    return  timeMeasure.GetTimeElapsed();

}

unsigned long long Benchmarks::List_Search_benchmark() {

    TimeMeasure timeMeasure;
    std::vector<int> vec = randData(10,300,amount);
    List list;

    for(auto val : vec)
    {
        list.List_Add_front(val);
    }

    for(int i = 0 ; i < repeats ; i++) {
        timeMeasure.Benchmarks_start();
        list.List_Search(230);
        timeMeasure.Benchmarks_stop();
    }
    return  timeMeasure.GetTimeElapsed();
}

unsigned long long Benchmarks::List_pop_front() {

    TimeMeasure timeMeasure;
    std::vector<int> vec = randData(10,300,amount);
    List list;

    for(auto val : vec)
    {
        list.List_Add_front(val);
    }

    for(int i = 0 ; i < repeats ; i++) {
        timeMeasure.Benchmarks_start();
        list.List_Pop_front();
        timeMeasure.Benchmarks_stop();
    }
    return  timeMeasure.GetTimeElapsed();
}

unsigned long long Benchmarks::List_pop_back() {

    TimeMeasure timeMeasure;
    std::vector<int> vec = randData(10,300,amount);
    List list;

    for(auto val : vec)
    {
        list.List_Add_front(val);
    }

    for(int i = 0 ; i < repeats ; i++) {
        timeMeasure.Benchmarks_start();
        list.List_Pop_back();
        timeMeasure.Benchmarks_stop();
    }
    return  timeMeasure.GetTimeElapsed();
}

unsigned long long Benchmarks::List_d_after() {

    TimeMeasure timeMeasure;
    std::vector<int> vec = randData(10,300,amount);
    List list;

    for(auto val : vec)
    {
        list.List_Add_front(val);
    }
    Node* node = list.get_node_atpos(450);
    for(int i = 0 ; i < repeats ; i++) {
        timeMeasure.Benchmarks_start();
        list.List_delete_after(node);
        timeMeasure.Benchmarks_stop();
    }
    return  timeMeasure.GetTimeElapsed();
}

unsigned long long Benchmarks::List_d_before() {
    TimeMeasure timeMeasure;
    std::vector<int> vec = randData(10,300,amount);
    List list;

    for(auto val : vec)
    {
        list.List_Add_front(val);
    }
    Node* node = list.get_node_atpos(450);
    for(int i = 0 ; i < repeats ; i++) {
        timeMeasure.Benchmarks_start();
        list.List_delete_before(node);
        timeMeasure.Benchmarks_stop();
    }
    return  timeMeasure.GetTimeElapsed();
}

unsigned long long Benchmarks::List_d_node() {

    TimeMeasure timeMeasure;
    std::vector<int> vec = randData(10,300,amount);
    List list;

    for(auto val : vec)
    {
        list.List_Add_front(val);
    }
    //Node* node = list.get_node_atpos(30);
  for(int i = 0 ; i < repeats ; i++) {
      timeMeasure.Benchmarks_start();
      list.List_delete_node(list.get_node_atpos(30));
      timeMeasure.Benchmarks_stop();
  }
    return  timeMeasure.GetTimeElapsed();

}
void Benchmarks::List_tests() {
    std::cout <<"List push front for: " << amount << " elements is " << List_push_front() <<" ns\n";
    std::cout <<"List push back for: " << amount << " elements is " << List_push_end() <<" ns\n";
    std::cout <<"List insert before for: " << amount << " elements is " << List_I_before() <<" ns\n";
    std::cout <<"List insert after for: " << amount << " elements is " << List_I_after() <<" ns\n";
    std::cout <<"List pop front for: " << amount << " elements is " << List_pop_front() <<" ns\n";
    std::cout <<"List pop back for: " << amount << " elements is " << List_pop_back() <<" ns\n";
    std::cout <<"List delete after a node for: " << amount << " elements is " << List_d_after() <<" ns\n";
    std::cout <<"List delete before a node for: " << amount << " elements is " << List_d_before() <<" ns\n";
    std::cout <<"List delete node for: " << amount << " elements is " << List_d_node() <<" ns\n";
    std::cout <<"List search for: " << amount << " elements is " << List_Search_benchmark() <<" ns\n";
}

unsigned long long Benchmarks::Heap_ins() {

    TimeMeasure timeMeasure;
    std::vector<int> vec = randData(10,300,amount);
    Heap heap;

    for(auto val : vec)
    {
        heap.Heap_insert(val);
    }

    for(int i = 0 ; i < repeats ; i++) {
        timeMeasure.Benchmarks_start();
        heap.Heap_insert(i);
        timeMeasure.Benchmarks_stop();
    }
    return  timeMeasure.GetTimeElapsed();
}

unsigned long long Benchmarks::Heap_d_max() {

    TimeMeasure timeMeasure;
    std::vector<int> vec = randData(10,300,amount);
    Heap heap;

    for(auto val : vec)
    {
        heap.Heap_insert(val);
    }

    for(int i = 0 ; i < repeats ; i++) {
        timeMeasure.Benchmarks_start();
        heap.Heap_delete_max();
        timeMeasure.Benchmarks_stop();
    }
    return  timeMeasure.GetTimeElapsed();
}

unsigned long long Benchmarks::Heap_d_val() {

    TimeMeasure timeMeasure;
    std::vector<int> vec = randData(10,300,amount);
    Heap heap;

    for(auto val : vec)
    {
        heap.Heap_insert(val);
    }

    for(int i = 0 ; i < repeats ; i++) {
        timeMeasure.Benchmarks_start();
        heap.Heap_delete_val(34);
        timeMeasure.Benchmarks_stop();
    }
    return  timeMeasure.GetTimeElapsed();
}

unsigned long long Benchmarks::Find_max_benchmark() {

    TimeMeasure timeMeasure;
    std::vector<int> vec = randData(10,300,amount);
    Heap heap;

    for(auto val : vec)
    {
        heap.Heap_insert(val);
    }

    for(int i = 0 ; i < repeats ; i++) {
        timeMeasure.Benchmarks_start();
        heap.Find_max();
        timeMeasure.Benchmarks_stop();
    }
    return  timeMeasure.GetTimeElapsed();
}

unsigned long long Benchmarks::Extract_max_benchmark() {
    TimeMeasure timeMeasure;
    std::vector<int> vec = randData(10,300,amount);
    Heap heap;

    for(auto val : vec)
    {
        heap.Heap_insert(val);
    }

    for(int i = 0 ; i < repeats ; i++) {
        timeMeasure.Benchmarks_start();
        heap.Extract_max();
        timeMeasure.Benchmarks_stop();
    }
    return  timeMeasure.GetTimeElapsed();
}

void Benchmarks::Heap_tests() {

    std::cout <<"Heap insert for: " << amount << " elements is " << Heap_ins() <<" ns\n";
    std::cout <<"Heap delete max for: " << amount << " elements is " << Heap_d_max() <<" ns\n";
    std::cout <<"Heap delete val for: " << amount << " elements is " << Heap_d_val() <<" ns\n";
    std::cout <<"Heap find max for: " << amount << " elements is " << Find_max_benchmark() <<" ns\n";
    std::cout <<"Heap extract max for: " << amount << " elements is " << Extract_max_benchmark() <<" ns\n";

}

unsigned long long Benchmarks::Rb_Ins() {

    TimeMeasure timeMeasure;
    std::vector<int> vec = randData(10,300,amount);
    RB_tree rbTree;

    for(auto val : vec)
    {
        rbTree.Rb_Insert(val);
    }

    for(int i = 0 ; i < repeats ; i++) {
        timeMeasure.Benchmarks_start();
        rbTree.Rb_Insert(i);
        timeMeasure.Benchmarks_stop();
    }
    return  timeMeasure.GetTimeElapsed();

}



unsigned long long Benchmarks::Rb_d_root() {
    TimeMeasure timeMeasure;
    std::vector<int> vec = randData(10,300,amount);
    RB_tree rbTree;

    for(auto val : vec)
    {
        rbTree.Rb_Insert(val);
    }

    for(int i = 0 ; i < repeats ; i++) {
        timeMeasure.Benchmarks_start();
        rbTree.Rb_delete_val(rbTree.Rb_get_root());
        timeMeasure.Benchmarks_stop();

    }
    return  timeMeasure.GetTimeElapsed();
}

unsigned long long Benchmarks::Rb_d_node() {

    TimeMeasure timeMeasure;
    std::vector<int> vec = randData(10,300,amount);
    RB_tree rbTree;

    for(auto val : vec)
    {
        rbTree.Rb_Insert(val);
    }

    for(int i = 0 ; i < repeats ; i++) {
        timeMeasure.Benchmarks_start();
        rbTree.Rb_delete_val(rbTree.Rb_get_root()->left_child);
        timeMeasure.Benchmarks_stop();
    }
    return  timeMeasure.GetTimeElapsed();

}

unsigned long long Benchmarks::Rb_search_benchmark() {

    TimeMeasure timeMeasure;
    std::vector<int> vec = randData(10,300,amount);
    RB_tree rbTree;

    for(auto val : vec)
    {
        rbTree.Rb_Insert(val);
    }

    for(int i = 0 ; i < repeats ; i++) {
        timeMeasure.Benchmarks_start();
        rbTree.Rb_search(rbTree.Rb_get_root(),i+20);
        timeMeasure.Benchmarks_stop();
    }
    return  timeMeasure.GetTimeElapsed();
}

void Benchmarks::RB_tests() {

    std::cout <<"Rb tree insert for: " << amount << " elements is " << Rb_Ins() <<" ns\n";
    std::cout <<"Rb tree delete root for: " << amount << " elements is " << Rb_d_root() <<" ns\n";
    std::cout <<"Rb tree delete node for: " << amount << " elements is " << Rb_d_node() <<" ns\n";
    std::cout <<"Rb tree search val for: " << amount << " elements is " << Rb_search_benchmark() <<" ns\n";

}








