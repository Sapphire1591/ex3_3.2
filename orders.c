#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "list.h"
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
}*Order;

OrderList orderListCreate(CopyOrder copy, DeleteOrder delete) {
    assert(copy!=NULL && delete!=NULL);
    OrderList list = listCreate(copy, delete);

}


OrderList orderListCopy(OrderList list);


int orderListGetSize(OrderList list);


Order getFirstOrder(OrderList list);


Order getNextOrder(OrderList list);


Order getCurrentOrder(OrderList list);


ListResult insertOrderFirst(OrderList list, Order order);


ListResult insertOrderLast(OrderList list, Order order);


ListResult insertOrderBeforeCurrent(OrderList list, Order order);


ListResult insertOrderAfterCurrent(OrderList list, Order order);


ListResult removeCurrentOrder(OrderList list);


ListResult sortOrders(OrderList list, CompareOrders compare);


OrderList filterOrders(OrderList list, FilterOrderList filter, OrderFilterKey key);


ListResult clearOrders(OrderList list);


void destroyOrderList(OrderList list);

