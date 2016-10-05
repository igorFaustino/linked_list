#include <iostream>
#include "linked_list.h"

using namespace std;

int main()
{
    List* list = list_create();
    list_insertFirst(list, element_create(11, "Max"));
    list_insertFirst(list, element_create(19, "Jones"));
    list_insertFirst(list, element_create(2, "Indiana"));
    list_insertFirst(list, element_create(4, "Batman"));
    list_print(list);

    list_remove_last(list);
    list_remove_last(list);
    list_remove_last(list);
    list_remove_last(list);
    list_remove_last(list);
    list_print(list);

    list_insertSorted(list, element_create(4, "Oasis"));
    list_insertSorted(list, element_create(1, "Lynyrd Skynyrd"));
    list_insertSorted(list, element_create(5, "Gun'n Roses"));
    list_insertSorted(list, element_create(3, "Metallica"));
    list_print(list);

    list_removeById(list, 4);
    list_removeById(list, 1);
    list_removeById(list, 5);
    list_removeById(list, 2);
    list_removeById(list, 3);

    list_insertLast(list, element_create(1000, "Foo Fighter"));
    list_insertLast(list, element_create(3, "three days grace"));
    list_print(list);

    element_print(list_getById(list, 1000));
    list_destroy(list);

    return 0;
}
