#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//#include "list.h"
#include "orders.h"
#include "mtm_ex3.h"

struct SOrder {
    TechnionFaculty Faculty; //faculty of escape room
    char* email; //client email address
    int ID; //room ID
    int day;
    int hour;
    int num_ppl;
    int total_price;
};

TechnionFaculty getOrderFaculty(Order order) {
    if (order == NULL) {
        return UNKNOWN;
    }
    return order->Faculty;
}

char* getOrderEmail(Order order) {
    if (order == NULL) {
        return NULL;
    }
    return order->email;
}

int getOrderID(Order order) {
    if (order == NULL) {
        return -1;
    }
    return order->ID;
}

int getOrderDay(Order order) {
    if (order == NULL) {
        return -1;
    }
    return order->day;
}

int getOrderHour(Order order) {
    if (order == NULL) {
        return -1;
    }
    return order->hour;
}

int getOrderPeople(Order order) {
    if (order == NULL) {
        return -1;
    }
    return order->num_ppl;
}

int getOrderPrice(Order order) {
    if (order == NULL) {
        return -1;
    }
    return order->total_price;
}

ListResult setOrderFaculty(Order order, TechnionFaculty faculty) {
    if (order == NULL) {
        return LIST_NULL_ARGUMENT;
    }
    order->Faculty = faculty;
    return LIST_SUCCESS;
}

ListResult setOrderEmail(Order order, char* email) {
    if (order == NULL || email == NULL) {
        return LIST_NULL_ARGUMENT;
    }
    order->email = malloc(strlen(email)+1);
    if (order->email == NULL) {
        return LIST_OUT_OF_MEMORY;
    }
    strcpy(order->email, email);
    return LIST_SUCCESS;
}

ListResult setOrderID(Order order, int ID) {
    if (order == NULL) {
        return LIST_NULL_ARGUMENT;
    }
    order->ID = ID;
    return LIST_SUCCESS;
}

ListResult setOrderDay(Order order, int day) {
    if (order == NULL) {
        return LIST_NULL_ARGUMENT;
    }
    order->day = day;
    return LIST_SUCCESS;
}

ListResult setOrderHour(Order order, int hour) {
    if (order == NULL) {
        return LIST_NULL_ARGUMENT;
    }
    order->hour = hour;
    return LIST_SUCCESS;
}

ListResult setOrderPeople(Order order, int num_ppl) {
    if (order == NULL) {
        return LIST_NULL_ARGUMENT;
    }
    order->num_ppl = num_ppl;
    return LIST_SUCCESS;
}

ListResult setOrderPrice(Order order, int total_price) {
    if (order == NULL) {
        return LIST_NULL_ARGUMENT;
    }
    order->total_price = total_price;
    return LIST_SUCCESS;
}

ListElement CopyOrder(ListElement order) {
    assert(order);
    Order order_copy = malloc(sizeof(struct SOrder));
    if (order_copy == NULL) {
        return NULL;
    }
    if (setOrderFaculty(order_copy, getOrderFaculty(order)) != LIST_SUCCESS ||
        setOrderEmail(order_copy, getOrderEmail(order)) != LIST_SUCCESS ||
        setOrderID(order_copy, getOrderID(order)) != LIST_SUCCESS ||
        setOrderDay(order_copy, getOrderDay(order)) != LIST_SUCCESS ||
        setOrderHour(order_copy, getOrderHour(order)) != LIST_SUCCESS ||
        setOrderPeople(order_copy, getOrderPeople(order)) != LIST_SUCCESS ||
        setOrderPrice(order_copy, getOrderPrice(order)) != LIST_SUCCESS) {
        return NULL;
    }
    return order_copy;
}

//check the difference between delete, clear, destroy... do they remove the node and shrink the list?
//if I free the data, it needs to point to null in the node. who does it?
void DeleteOrder(ListElement order) {
    assert(order);
    free(getOrderEmail(order));
    free(order);
}//I need to remove from general order list, from room order list, and from visitor order list


int CompareOrders(ListElement order1, ListElement order2) {
    assert(order1 && order2);
    if (getOrderDay(order1) > getOrderDay(order2)) {
        return 1;
    }
    else if (getOrderDay(order1) < getOrderDay(order2)) {
        return -1;
    }
    else { //order1->day == order2->day
        if (getOrderHour(order1) > getOrderHour(order2)) {
            return 1;
        }
        else if (getOrderHour(order1) < getOrderHour(order2)) {
            return -1;
        }
        else { //order1->hour == order2->hour
            if (getOrderFaculty(order1) > getOrderFaculty(order2)) {
                return 1;
            }
            else if (getOrderFaculty(order1) < getOrderFaculty(order2)) {
                return -1;
            }
            else { //order1->Faculty == order2->Faculty
                if (getOrderID(order1) > getOrderID(order2)) {
                    return 1;
                }
                else if (getOrderID(order1) < getOrderID(order2)) {
                    return -1;
                }
                else { //order1->ID == order2->ID
                    return 0;
                }
            }
        }
    }
}


//bool FilterOrderList(Order, OrderFilterKey);


List orderListCreate(CopyListElement copyOrder, FreeListElement deleteOrder) {
    assert(copyOrder && deleteOrder);
    List list = listCreate(copyOrder, deleteOrder);
    if (list == NULL) {
        return NULL;
    }
    return list;
}

List orderListCopy(List list) {
    assert(list);
    List list_copy = listCopy(list);
    if (list_copy == NULL) {
        return NULL;
    }
    return list_copy;
}


int orderListGetSize(List list) {
    assert(list);
    int order_num = listGetSize(list);
    if (order_num < 0) {
        return -1;
    }
    return order_num;
}


Order getFirstOrder(List list) {
    assert(list);
    Order first = listGetFirst(list);
    if (first == NULL) {
        return NULL;
    }
    return first;
}


Order getNextOrder(List list) {
    assert(list);
    Order next = listGetNext(list);
    if (next == NULL) {
        return NULL;
    }
    return next;
}


Order getCurrentOrder(List list) {
    assert(list);
    Order current = listGetCurrent(list);
    if (current == NULL) {
        return NULL;
    }
    return current;
}


ListResult insertOrderFirst(List list, Order order) {
    assert(list && order);
    ListResult insert_result = listInsertFirst(list, order);
    if (insert_result != LIST_SUCCESS) {
        return insert_result;
    }
    return LIST_SUCCESS;
}


ListResult insertOrderLast(List list, Order order) {
    assert(list && order);
    ListResult insert_result = listInsertLast(list, order);
    if (insert_result != LIST_SUCCESS) {
        return insert_result;
    }
    return LIST_SUCCESS;
}


ListResult insertOrderBeforeCurrent(List list, Order order) {
    assert(list && order);
    ListResult insert_result = listInsertBeforeCurrent(list, order);
    if (insert_result != LIST_SUCCESS) {
        return insert_result;
    }
    return LIST_SUCCESS;
}


ListResult insertOrderAfterCurrent(List list, Order order) {
    assert(list && order);
    ListResult insert_result = listInsertAfterCurrent(list, order);
    if (insert_result != LIST_SUCCESS) {
        return insert_result;
    }
    return LIST_SUCCESS;
}


ListResult removeCurrentOrder(List list) {
    assert(list);
    ListResult remove_result = listRemoveCurrent(list);
    if (remove_result != LIST_SUCCESS) {
        return remove_result;
    }
    return LIST_SUCCESS;
}


ListResult sortOrders(List list, CompareListElements compare) {//finish
    assert(list && compare);
    ListResult sort_result = listSort(list, compare);
    if (sort_result != LIST_SUCCESS) {
        return sort_result;
    }
    return LIST_SUCCESS;//maybe just "return sort_result"?
}


/*List filterOrders(List list, FilterListElement filter, ListFilterKey key) {//finish
    assert(list && filter && key);
}*/


ListResult clearOrders(List list) {
    assert(list);
    ListResult clear_result = listClear(list);
    if (clear_result != LIST_SUCCESS) {
        return clear_result;
    }
    return LIST_SUCCESS;
}


void destroyOrderList(List list) {
    assert(list);
    listDestroy(list);
}

