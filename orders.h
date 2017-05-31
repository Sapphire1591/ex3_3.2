#ifndef ORDERS_H_
#define ORDERS_H_

#include "list.h"
#include "mtm_ex3.h"

struct SOrder;
typedef struct SOrder *Order;

TechnionFaculty getOrderFaculty(Order order);

char* getOrderEmail(Order order);

int getOrderID(Order order);

int getOrderDay(Order order);

int getOrderHour(Order order);

int getOrderPeople(Order order);

int getOrderPrice(Order order);

ListResult setOrderFaculty(Order order, TechnionFaculty faculty);

ListResult setOrderEmail(Order order, char* email);

ListResult setOrderID(Order order, int ID);

ListResult setOrderDay(Order order, int day);

ListResult setOrderHour(Order order, int hour);

ListResult setOrderPeople(Order order, int num_ppl);

ListResult setOrderPrice(Order order, int total_price);

ListElement CopyOrder(ListElement order);


void DeleteOrder(ListElement order);


int CompareOrders(ListElement order1, ListElement order2);


typedef void* OrderFilterKey;


//bool FilterOrderList(Order, OrderFilterKey);


List orderListCreate(CopyListElement copy, FreeListElement delete);


List orderListCopy(List list);//?


int orderListGetSize(List list);


Order getFirstOrder(List list);


Order getNextOrder(List list);


Order getCurrentOrder(List list);


ListResult insertOrderFirst(List list, Order order);


ListResult insertOrderLast(List list, Order order);


ListResult insertOrderBeforeCurrent(List list, Order order);


ListResult insertOrderAfterCurrent(List list, Order order);


ListResult removeCurrentOrder(List list);


ListResult sortOrders(List list, CompareListElements compare);


List filterOrders(List list, FilterListElement filter, ListFilterKey key);


ListResult clearOrders(List list);


void destroyOrderList(List list);


#define LIST_FOREACH(type,iterator,list) \
	for(type iterator = listGetFirst(list) ; \
		iterator ;\
		iterator = listGetNext(list))

#endif /*ORDERS_H_*/
