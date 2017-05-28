#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "list_mtm1.h"

typedef struct list_node {
    ListElement data;
    struct list_node* next;
}*Node;

struct list_t {
    Node head;
    Node iterator;
    CopyListElement copy;
    FreeListElement free;
};

List listCreate(CopyListElement copyElement, FreeListElement freeElement){
    if(!copyElement || !freeElement){
        return NULL;
    }
    List list = malloc(sizeof(struct list_t));
    if (!list) {
        return NULL;
    }
    list->head = malloc(sizeof(struct list_node));
    if (!list->head) {
        return NULL;
    }
    list->head->data = NULL;
    list->head->next = NULL;
    list->iterator = malloc(sizeof(struct list_node));
    if (!list->iterator) {
        return NULL;
    }
    list->iterator = list->head->next;
    list->copy = copyElement;
    list->free = freeElement;
    return list;
}

List listCopy(List list) {
    if(!list){
        return NULL;
    }
    List new_list = listCreate(list->copy, list->free);
    if (!new_list) {
        return NULL;
    }
    Node element = list->head->next;
    Node new_element = new_list->head->next;
    while (element) {
        new_element = list->copy(element);
        element = element->next;
        new_element = new_element->next;
    }
    new_list->iterator = list->iterator;
    return new_list;
}

int listGetSize(List list) {
    if(!list){
        return -1;
    }
    int counter = 0;
    Node current = list->head->next;
    while (current) {
        counter++;
        current = current->next;
    }
    return counter;
}

ListElement listGetFirst(List list) {
    if(!list){
        return NULL;
    }
    if (list->head->next) {
        list->iterator = list->head->next;
        return list->head->next->data;
    }
    return NULL; //list is empty
}

ListElement listGetNext(List list) {
    if(!list){
        return NULL;
    }
    Node current = listGetCurrent(list);
    if (!current || !current->next) {
        return NULL;
    }
    list->iterator = current->next;
    return current->next->data;
}

ListElement listGetCurrent(List list) {
    if(!list){
        return NULL;
    }
    return list->iterator->data;
}

ListResult listInsertFirst(List list, ListElement element) {
    if(!list || !element){
        LIST_NULL_ARGUMENT;
    }
    Node new_node = malloc(sizeof(struct list_node));
    if (!new_node) {
        return LIST_OUT_OF_MEMORY;
    }
    new_node->data = element;
    new_node->next = list->head->next;
    list->head->next = new_node;
    return LIST_SUCCESS;
}

ListResult listInsertLast(List list, ListElement element) {
    if(!list || !element){
        LIST_NULL_ARGUMENT;
    }
    Node new_node = malloc(sizeof(struct list_node));
    if (!new_node) {
        return LIST_OUT_OF_MEMORY;
    }
    Node last_node = list->head->next;
    if (last_node == NULL) {
        new_node->data = element;
        new_node->next = NULL;
        list->head->next = new_node;
        return LIST_SUCCESS;
    }
    else
        while (last_node->next) { //finds the "next" that points to NULL
            last_node = last_node->next;
        }
    new_node->data = element;
    new_node->next = NULL;
    last_node->next = new_node;
    return LIST_SUCCESS;
}

ListResult listInsertBeforeCurrent(List list, ListElement element) {
    if(list || element){
        LIST_NULL_ARGUMENT;
    }
    Node new_node = malloc(sizeof(struct list_node));
    if (!new_node) {
        return LIST_OUT_OF_MEMORY;
    }
    Node before_current = list->head->next;
    //find the "next" that points to current:
    while (before_current->next != list->iterator) {
        before_current = before_current->next;
    }
    new_node->data = element;
    new_node->next = before_current->next;
    before_current->next = new_node;
    return LIST_SUCCESS;
}

ListResult listInsertAfterCurrent(List list, ListElement element) {
    if(!list && !element){
        LIST_NULL_ARGUMENT;
    }
    if(!listGetCurrent(list)){
        LIST_INVALID_CURRENT;
    }
    Node new_node = malloc(sizeof(struct list_node));
    if (!new_node) {
        return LIST_OUT_OF_MEMORY;
    }
    new_node->data = element;
    new_node->next = list->iterator->next;
    list->iterator->next = new_node;
    return LIST_SUCCESS;
}


ListResult listRemoveCurrent(List list){
    if(!list){
        LIST_NULL_ARGUMENT;
    }
    if(!listGetCurrent(list)){
        LIST_INVALID_CURRENT;
    }
    Node next = list->iterator->next;
    listInsertBeforeCurrent(list, next);
    list->free(list->iterator->data);
    free(list->iterator);
    list->iterator = NULL;
    return LIST_SUCCESS;
}

static void swap(Node a, Node b){
    ListElement temp = a->data;
    a->data = b->data;
    b->data = temp;
}

ListResult listSort(List list, CompareListElements compareElement){
    if(!list || !compareElement){
        return LIST_NULL_ARGUMENT;
    }
    Node ptr = NULL; //pointer to the compared element
    list->iterator = listGetFirst(list);
    if(list->iterator){
        ptr = list->iterator->next;
    }
    while(list->iterator){
        while(ptr){
            if(compareElement(ptr, list->iterator) > 0){
                swap(ptr, list->iterator);
            }
            else{
                ptr = ptr->next;
            }
        }
    }
    return LIST_SUCCESS;
}

List listFilter(List list, FilterListElement filterElement, ListFilterKey key) {
    if(!list){
        return NULL;
    }
    List new_list = listCreate(list->copy, list->free);
    if(!new_list){
        return NULL;
    }
    Node ptr = list->head->next;
    if (!ptr) {
        return NULL;
    }
    while(ptr){
        if(filterElement(ptr->data, key)) {
            listInsertLast(new_list, ptr->data);
        }
        ptr = ptr->next;
    }
    new_list->iterator = new_list->head->next;
    return new_list;
}

ListResult listClear(List list){
    if(list){
        return LIST_NULL_ARGUMENT;
    }
    Node ptr;
    while(!list->head->next){
        ptr = list->head->next;
        list->free(ptr->data);
        ptr = ptr->next;
        free(list->head->next);
        list->head->next = ptr;
    }
    return LIST_SUCCESS;
}

void listDestroy(List list) {
    assert(list);
    listClear(list);
    free(list);
}