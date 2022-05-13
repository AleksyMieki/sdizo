#include <iostream>
#include "Menu.h"

int main() {

Menu menu;

menu.read_from_file_List();
menu.read_from_file_Heap();
menu.read_from_file_Array();
menu.read_from_file_Rbtree();

while(1) {
    switch (menu.Options()) {
        case 1:
            menu.Array_functions();
            break;
        case 2:
            menu.Heap_functions();
            break;
        case 3:
            menu.List_functions();
            break;
        case 4:
            menu.Rb_functions();
            break;
        case 5:
            return 0;
        default:
            std::cout<<"not a valid option" << std::endl;
            return 0;

    }
}


}
