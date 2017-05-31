#include "orders.h"
#include "test_utilities.h"
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


static bool testListCreate() {
    ASSERT_TEST(orderListCreate(NULL,NULL) == NULL);
    ASSERT_TEST(orderListCreate(NULL,NULL) == NULL);
    ASSERT_TEST(orderListCreate(CopyOrder,NULL) == NULL);
    ASSERT_TEST(orderListCreate(NULL,DeleteOrder) == NULL);

    return true;
}/*
static bool testListFilter() {
    char* a[5] = {"aaa","bbb","NI","hello mister fish","I"};
    List list = listCreate(CopyOrder,DeleteOrder);
    for (int i=0;i <5; ++i){
        listInsertFirst(list,a[i]);
    }
    int key = 5;
    List filtered = listFilter(list,isLongerThan, &key);
    ASSERT_TEST(listGetSize(filtered) == 1);
    ASSERT_TEST(strcmp(listGetFirst(filtered),a[3])==0);
    listDestroy(list);
    listDestroy(filtered);
    return true;
}*/
static bool testListCopy() {
    ASSERT_TEST(orderListCopy(NULL) == NULL);
    return true;
}

static bool testListGetSize() {
    Order a = malloc(sizeof(Order));
    if (a == NULL) printf("\nmalloc a error\n");
    setOrderFaculty(a, CHEMISTRY);
    setOrderEmail(a, "a@123");
    setOrderID(a, 123);
    setOrderDay(a, 2);
    setOrderHour(a, 15);
    setOrderPeople(a, 3);
    setOrderPrice(a, 50);
    Order b = malloc(sizeof(Order));
    if (b == NULL) printf("\nmalloc b error\n");
    setOrderFaculty(b, ELECTRICAL_ENGINEERING);
    setOrderEmail(b, "b@234");
    setOrderID(b, 234);
    setOrderDay(b, 3);
    setOrderHour(b, 16);
    setOrderPeople(b, 6);
    setOrderPrice(b, 70);
    Order c = malloc(sizeof(Order));
    if (c == NULL) printf("\nmalloc c error\n");
    setOrderFaculty(c, EDUCATION_IN_TECH_AND_SCIENCE);
    setOrderEmail(c, "c@564");
    setOrderID(c, 564);
    setOrderDay(c, 6);
    setOrderHour(c, 10);
    setOrderPeople(c, 2);
    setOrderPrice(c, 20);
    List list = orderListCreate(CopyOrder,DeleteOrder);
    insertOrderFirst(list,a);
    insertOrderFirst(list,b);
    insertOrderFirst(list,c);
    ASSERT_TEST(orderListGetSize(list) == 3);
    destroyOrderList(list);
    return true;
}

static bool testListGetFirst() {
    Order a = malloc(sizeof(Order));
    if (a == NULL) printf("\nmalloc a error\n");
    setOrderFaculty(a, CHEMISTRY);
    setOrderEmail(a, "a@123");
    setOrderID(a, 123);
    setOrderDay(a, 2);
    setOrderHour(a, 15);
    setOrderPeople(a, 3);
    setOrderPrice(a, 50);
    Order b = malloc(sizeof(Order));
    if (b == NULL) printf("\nmalloc b error\n");
    setOrderFaculty(b, ELECTRICAL_ENGINEERING);
    setOrderEmail(b, "b@234");
    setOrderID(b, 234);
    setOrderDay(b, 3);
    setOrderHour(b, 16);
    setOrderPeople(b, 6);
    setOrderPrice(b, 70);
    Order c = malloc(sizeof(Order));
    if (c == NULL) printf("\nmalloc c error\n");
    setOrderFaculty(c, EDUCATION_IN_TECH_AND_SCIENCE);
    setOrderEmail(c, "c@564");
    setOrderID(c, 564);
    setOrderDay(c, 6);
    setOrderHour(c, 10);
    setOrderPeople(c, 2);
    setOrderPrice(c, 20);
    List list = orderListCreate(CopyOrder,DeleteOrder);
    insertOrderFirst(list,a);
    insertOrderFirst(list,b);
    insertOrderFirst(list,c);
    Order first = getFirstOrder(list);
    ASSERT_TEST(getOrderID(first) == getOrderID(c));
    destroyOrderList(list);
    return true;
}

static bool testListGetNext() {
    Order a = malloc(sizeof(Order));
    if (a == NULL) printf("\nmalloc a error\n");
    setOrderFaculty(a, CHEMISTRY);
    setOrderEmail(a, "a@123");
    setOrderID(a, 123);
    setOrderDay(a, 2);
    setOrderHour(a, 15);
    setOrderPeople(a, 3);
    setOrderPrice(a, 50);
    Order b = malloc(sizeof(Order));
    if (b == NULL) printf("\nmalloc b error\n");
    setOrderFaculty(b, ELECTRICAL_ENGINEERING);
    setOrderEmail(b, "b@234");
    setOrderID(b, 234);
    setOrderDay(b, 3);
    setOrderHour(b, 16);
    setOrderPeople(b, 6);
    setOrderPrice(b, 70);
    Order c = malloc(sizeof(Order));
    if (c == NULL) printf("\nmalloc c error\n");
    setOrderFaculty(c, EDUCATION_IN_TECH_AND_SCIENCE);
    setOrderEmail(c, "c@564");
    setOrderID(c, 564);
    setOrderDay(c, 6);
    setOrderHour(c, 10);
    setOrderPeople(c, 2);
    setOrderPrice(c, 20);
    List list = orderListCreate(CopyOrder,DeleteOrder);
    insertOrderFirst(list,a);
    insertOrderFirst(list,b);
    insertOrderFirst(list,c);
    Order first = getFirstOrder(list);
    ASSERT_TEST(getOrderID(first) == getOrderID(c));
    Order next = getNextOrder(list);
    ASSERT_TEST(getOrderID(next) == getOrderID(b));
    destroyOrderList(list);
    return true;
}

static bool testListInsertFirst() {
    Order a = malloc(sizeof(Order));
    if (a == NULL) printf("\nmalloc a error\n");
    setOrderFaculty(a, CHEMISTRY);
    setOrderEmail(a, "a@123");
    setOrderID(a, 123);
    setOrderDay(a, 2);
    setOrderHour(a, 15);
    setOrderPeople(a, 3);
    setOrderPrice(a, 50);
    Order b = malloc(sizeof(Order));
    if (b == NULL) printf("\nmalloc b error\n");
    setOrderFaculty(b, ELECTRICAL_ENGINEERING);
    setOrderEmail(b, "b@234");
    setOrderID(b, 234);
    setOrderDay(b, 3);
    setOrderHour(b, 16);
    setOrderPeople(b, 6);
    setOrderPrice(b, 70);
    Order c = malloc(sizeof(Order));
    if (c == NULL) printf("\nmalloc c error\n");
    setOrderFaculty(c, EDUCATION_IN_TECH_AND_SCIENCE);
    setOrderEmail(c, "c@564");
    setOrderID(c, 564);
    setOrderDay(c, 6);
    setOrderHour(c, 10);
    setOrderPeople(c, 2);
    setOrderPrice(c, 20);
    List list = orderListCreate(CopyOrder,DeleteOrder);
    insertOrderFirst(list,a);
    insertOrderFirst(list,b);
    insertOrderFirst(list,c);
    Order first = malloc(sizeof(Order));
    if (first == NULL) printf("\nmalloc first error\n");
    setOrderFaculty(first, AEROSPACE_ENGINEERING);
    setOrderEmail(first, "first@789");
    setOrderID(first, 789);
    setOrderDay(first, 4);
    setOrderHour(first, 18);
    setOrderPeople(first, 3);
    setOrderPrice(first, 40);
    ASSERT_TEST(getOrderID(getFirstOrder(list)) == getOrderID(first));
    return true;
}

static bool testListInsertLast() {
    return true;
}

static bool testListInsertBeforeCurrent() {
    return true;
}

static bool testListInsertAfterCurrent() {
    return true;
}

static bool testListRemoveCurrent() {
    return true;
}

static bool testListSort() {
    return true;
}

static bool testListClear() {
    return true;
}

static bool testListDestroy() {
    return true;
}

int main (int argv, char** arc){
    RUN_TEST(testListCreate);
    //RUN_TEST(testListFilter);
    RUN_TEST(testListCopy);
    RUN_TEST(testListGetSize);
    RUN_TEST(testListGetFirst);
    RUN_TEST(testListGetNext);
    RUN_TEST(testListInsertFirst);
    RUN_TEST(testListInsertLast);
    RUN_TEST(testListInsertBeforeCurrent);
    RUN_TEST(testListInsertAfterCurrent);
    RUN_TEST(testListRemoveCurrent);
    RUN_TEST(testListSort);
    RUN_TEST(testListClear);
    RUN_TEST(testListDestroy);
    return 0;
}

