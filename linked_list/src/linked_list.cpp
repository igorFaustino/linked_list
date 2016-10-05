#include "linked_list.h"

//Element Functions

Element* element_create(int id, string info)
{
    Element* e = new Element;
    e->id = id;
    e->info = info;
    e->next = NULL;
}

void element_print(Element* e)
{
    cout << "{ " << e->id << ", " << e->info << " }" << endl;
}

void element_destroy(Element* e)
{
    if (e != NULL){
        delete e;
    }
}

//List Functions

List* list_create()
{
    List* list = new List;
    list->size = 0;
    list->first = NULL;
}

void list_destroy(List* list)
{
    Element* p = list->first;
    Element* prev = NULL;
    while (p){
        prev = p;
        p = p->next;
        element_destroy(prev);
    }
    delete list;
}

void list_insertLast(List* list, Element* e)
{
    Element* p = list->first;
    Element* prev = NULL;
    while (p){
        prev = p;
        p = p->next;
    }
    if(prev){           //list isn't empty
        prev->next = e;
    } else {
        list->first = e;
    }
    list->size++;
    e->next = NULL;
}

int list_remove_last(List* list)
{
    if (list->first == NULL){
        return -1;
    }
    Element* p = list->first;
    Element* prev = NULL;
    while(p->next){
        prev = p;
        p = p->next;
    }
    element_destroy(p);
    list->size--;
    if(prev){
        prev->next = NULL;
    } else {
        list->first = NULL;
    }
    return 0;
}

void list_print(List* list)
{
    Element* p = list->first;
    cout << "Linked List \nSize: " << list->size << "\n[" << endl;
    while(p){
        element_print(p);
        p = p->next;
    }
    cout << "]" << endl << endl;
}

Element* list_getById(List* list, int id)
{
    Element* p = list->first;
    while (p){
        if (p->id == id){
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void list_insertSorted(List* list, Element* e)
{
    Element* p = list->first;
    Element* prev = NULL;

    while (p && p->id < e->id) {
        prev = p;
        p = p->next;
    }
    if (prev){
        prev->next = e;
    } else {
        list->first = e;
    }
    e->next = p;
    list->size++;
}

int list_removeById(List* list, int id)
{
    if (list->first == NULL){
        return -1;
    }
    Element* p = list->first;
    Element* prev = NULL;
    while (p && p->id != id){
        prev = p;
        p = p->next;
    }
    if (!p){
        return -2;              //Element invalid;
    }
    if (!prev){
        list->first = p->next;
    } else {
        prev->next = p->next;
    }
    element_destroy(p);
    list->size--;
    return 0;
}

void list_insertFirst(List* list, Element* e)
{
    if(list->first){
        e->next = list->first;
    }
    list->first = e;
    list->size++;
}
