#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <string>

using namespace std;

struct Element {
	int id;
	string info;
	Element* next;
};

Element* element_create(int id, string info);
void element_print(Element* e);
void element_destroy(Element* e);

////////////////////////////////////////////////

struct List {
	Element* first;
	int size;
};

List* list_create();
void list_destroy(List* list);
void list_insertLast(List* list, Element* e);
int list_remove_last(List* list);
void list_print(List* list);
int list_indexOf(List* list, int id);
Element* list_getById(List* list, int id);

int list_insertAt(List* list, Element* e, int pos);
void list_insertSorted(List* list, Element* e);
int list_removeByIndex(List* list, int index);
int list_removeById(List* list, int id);

void list_insertFirst(List* list, Element* e);

#endif // LINKED_LIST_H
