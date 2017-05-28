#ifndef ORDERS_H_
#define ORDERS_H_

#include "list.h"
#include "mtm_ex3.h"

/**

*/

typedef struct SOrder *Order;


Order CopyOrder(Order);


void DeleteOrder(Order);


int CompareOrders(Order, Order);


typedef void* OrderFilterKey;


bool FilterOrderList(Order, OrderFilterKey);


Order orderListCreate(CopyOrder copy, DeleteOrder delete);


Order orderListCopy(Order list);


int orderListGetSize(Order list);


Order getFirstOrder(Order list);


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


#define LIST_FOREACH(type,iterator,list) \
	for(type iterator = listGetFirst(list) ; \
		iterator ;\
		iterator = listGetNext(list))

#endif /* ORDERS_H_ */
