//
// Created by aleks on 21.04.22.
//

#include "Menu.h"
int Menu::Options() {

    int i;

    std::cout << "1.Array functions\n2.Heap functions\n3.List_functions\n4.Rb tree functions\n5.end program\n";
    std::cout <<"state your choice: ";
    std::cin >> i;
    return i;

}
void Menu::Array_functions() {


    while(1) {

        int choice;
        std::cout << "\nARRAY\n"
                     "1.push front\n2.push back\n3.insert a value at a given position\n4.delete front\n5.delete back\n6.delete at a position\n7.display the array\n8.exit\n";
        std::cin >> choice;
        switch (choice) {
            case 1:
                array.push_front(Get_data());
                break;
            case 2:
                array.push_back(Get_data());
                break;
            case 3:
                array.insert(Get_data(),Get_data());
                break;
            case 4:
                array.delete_front();
                break;
            case 5:
                array.delete_back();
                break;
            case 6:
                array.delete_pos(Get_data());
                break;
            case 7:
                array.display();
                break;
            case 8:
                return;
            default:
                return;
        }

    }
}

void Menu::Heap_functions() {


    while(1)
    {
        int choice;
        std::cout << "\nMAX HEAP\n1.insert an element\n2.delete max element\n3.delete an element by value\n4.display heap\n5.return max element\n6.extract max element\n7.exit\n";
        std::cin >> choice;
        switch(choice)
        {
            case 1:
                heap.Heap_insert(Get_data());
                break;
            case 2:
                heap.Heap_delete_max();
                break;
            case 3:
                heap.Heap_delete_val(Get_data());
                break;
            case 4:
                heap.Heap_display();
                break;
            case 5:
                std:: cout << heap.Find_max() << std::endl;
                break;
            case 6:
                std::cout << heap.Extract_max() << std::endl;
                break;
            case 7:
                return;
            default:
                return;
        }
    }
}

void Menu::List_functions() {



    while(1)
    {
        int choice;
        std::cout<<"\nLIST\n1.push front\n2.push back\n3.insert before\n4.insert after\n5.search value\n6.pop front\n7.pop back\n8.delete after\n9.delete before\n10.delete node\n11.print list\n12.exit\n";
        std::cin >> choice;
        switch (choice) {
            case 1:
                list.List_Add_front(Get_data());
                break;

            case 2:
                list.List_Add_end(Get_data());
                break;
            case 3:
                list.List_Insert_before(Get_data(),list.get_node(Get_data()));
                break;
            case 4:
                list.List_Insert_after(Get_data(),list.get_node(Get_data()));
                break;
            case 5:
                list.List_Search(Get_data());
                break;
            case 6:
                list.List_Pop_front();
                break;
            case 7:
                list.List_Pop_back();
                break;
            case 8:
                list.List_delete_after(list.get_node(Get_data()));
                break;
            case 9:
                list.List_delete_before(list.get_node(Get_data()));
                break;
            case 10:
                list.List_delete_node(list.get_node(Get_data()));
                break;
            case 11:
                list.List_display();
                break;
            case 12:
                return;
        }
    }

}

int Menu::Get_data() {
    std::cout << "podaj wartość w postaci int: ";

    int i;
    std::cin >> i;
    return i;
}

void Menu::Rb_functions() {

   // RB_tree rbtree;
    while(1)
    {
        int choice;
        std::cout << "\nRB TREE\n1.insert an element\n2.delete root\n3.delete an element by value\n4.display tree\n5.search a value\n6.exit\n";
        std::cin >> choice;
        switch(choice)
        {
            case 1:
                rbTree.Rb_Insert(Get_data());
                break;
            case 2:
                rbTree.Rb_delete_val(rbTree.Rb_get_root());
                break;
            case 3:
                rbTree.Rb_delete_val(rbTree.Rb_search(rbTree.Rb_get_root(),Get_data()));
                break;
            case 4:
                rbTree.printTree();
                break;
            case 5:
                if(rbTree.Rb_search(rbTree.Rb_get_root(),Get_data())) std::cout << "\nvalue found\n" << std::endl;
                else std::cout << "\nvalue not found\n";
                break;
            case 6:
                return;
            default:
                return;
        }
    }
}

void Menu::read_from_file_Array() {


    int n;
    std::ifstream indata;
    indata.open("example.dat"); // opens the file
    if(!indata) { // file couldn't be opened
        std::cerr << "Error: file could not be opened" << std::endl;
        exit(1);
    }
    indata >> n;
    while ( !indata.eof() ) { // keep reading until end-of-file

        indata >> n;// sets EOF flag if no value found
        array.push_back(n);
    }
    indata.close();

}

void Menu::read_from_file_List() {

    int n;
    std::ifstream indata;
    indata.open("example.dat"); // opens the file
    if(!indata) { // file couldn't be opened
        std::cerr << "Error: file could not be opened" << std::endl;
        exit(1);
    }
    indata >> n;
    while ( !indata.eof() ) { // keep reading until end-of-file

        indata >> n;// sets EOF flag if no value found
      list.List_Add_end(n);
    }
    indata.close();


}

void Menu::read_from_file_Rbtree() {

    int n;
    std::ifstream indata;
    indata.open("example.dat"); // opens the file
    if(!indata) { // file couldn't be opened
        std::cerr << "Error: file could not be opened" << std::endl;
        exit(1);
    }
    indata >> n;
    while ( !indata.eof() ) { // keep reading until end-of-file

        indata >> n;// sets EOF flag if no value found
        rbTree.Rb_Insert(n);
    }
    indata.close();


}

void Menu::read_from_file_Heap() {

    int n;
    std::ifstream indata;
    indata.open("example.dat"); // opens the file
    if(!indata) { // file couldn't be opened
        std::cerr << "Error: file could not be opened" << std::endl;
        exit(1);
    }
    indata >> n;
    while ( !indata.eof() ) { // keep reading until end-of-file

        indata >> n;// sets EOF flag if no value found
        heap.Heap_insert(n);

    }
    indata.close();

}


