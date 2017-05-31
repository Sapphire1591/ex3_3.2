#include "room.h"
#include "test_utilities.h"
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


static bool testListCreate() {
    ASSERT_TEST(roomListCreate(NULL,NULL) == NULL);
    ASSERT_TEST(roomListCreate(NULL,NULL) == NULL);
    ASSERT_TEST(roomListCreate(CopyRoom,NULL) == NULL);
    ASSERT_TEST(roomListCreate(NULL,DeleteRoom) == NULL);

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
    ASSERT_TEST(roomListCopy(NULL) == NULL);
    return true;
}

static bool testListGetSize() {
    Room a = malloc(sizeof(Room));
    if (a == NULL) printf("\nmalloc a error\n");
    setRoomEmail(a, "room_a@123");
    setRoomID(a, 123);
    setRoomOpening(a, 10);
    setRoomClosing(a, 20);
    setRoomCapacity(a, 5);
    setRoomPrice(a, 20);
    setRoomDifficulty(a, 4);
    Room b = malloc(sizeof(Room));
    if (b == NULL) printf("\nmalloc b error\n");
    setRoomEmail(b, "room_b@487");
    setRoomID(b, 487);
    setRoomOpening(b, 10);
    setRoomClosing(b, 20);
    setRoomCapacity(b, 5);
    setRoomPrice(b, 20);
    setRoomDifficulty(b, 4);
    Room c = malloc(sizeof(Room));
    if (c == NULL) printf("\nmalloc c error\n");
    setRoomEmail(c, "room_c@799");
    setRoomID(c, 799);
    setRoomOpening(c, 11);
    setRoomClosing(c, 22);
    setRoomCapacity(c, 7);
    setRoomPrice(c, 30);
    setRoomDifficulty(c, 8);
    List list = roomListCreate(CopyRoom,DeleteRoom);
    insertRoomFirst(list,a);
    insertRoomFirst(list,b);
    insertRoomFirst(list,c);
    ASSERT_TEST(roomListGetSize(list) == 3);
    destroyRoomList(list);
    return true;
}

static bool testListGetFirst() {
    Room a = malloc(sizeof(Room));
    if (a == NULL) printf("\nmalloc a error\n");
    setRoomEmail(a, "room_a@123");
    setRoomID(a, 123);
    setRoomOpening(a, 10);
    setRoomClosing(a, 20);
    setRoomCapacity(a, 5);
    setRoomPrice(a, 20);
    setRoomDifficulty(a, 4);
    Room b = malloc(sizeof(Room));
    if (b == NULL) printf("\nmalloc b error\n");
    setRoomEmail(b, "room_b@487");
    setRoomID(b, 487);
    setRoomOpening(b, 10);
    setRoomClosing(b, 20);
    setRoomCapacity(b, 5);
    setRoomPrice(b, 20);
    setRoomDifficulty(b, 4);
    Room c = malloc(sizeof(Room));
    if (c == NULL) printf("\nmalloc c error\n");
    setRoomEmail(c, "room_c@799");
    setRoomID(c, 799);
    setRoomOpening(c, 11);
    setRoomClosing(c, 22);
    setRoomCapacity(c, 7);
    setRoomPrice(c, 30);
    setRoomDifficulty(c, 8);
    List list = roomListCreate(CopyRoom,DeleteRoom);
    insertRoomFirst(list,a);
    insertRoomFirst(list,b);
    insertRoomFirst(list,c);
    Room first = getFirstRoom(list);
    ASSERT_TEST(getRoomID(first) == getRoomID(c));
    destroyRoomList(list);
    return true;
}

static bool testListGetNext() {
    Room a = malloc(sizeof(Room));
    if (a == NULL) printf("\nmalloc a error\n");
    setRoomEmail(a, "room_a@123");
    setRoomID(a, 123);
    setRoomOpening(a, 10);
    setRoomClosing(a, 20);
    setRoomCapacity(a, 5);
    setRoomPrice(a, 20);
    setRoomDifficulty(a, 4);
    Room b = malloc(sizeof(Room));
    if (b == NULL) printf("\nmalloc b error\n");
    setRoomEmail(b, "room_b@487");
    setRoomID(b, 487);
    setRoomOpening(b, 10);
    setRoomClosing(b, 20);
    setRoomCapacity(b, 5);
    setRoomPrice(b, 20);
    setRoomDifficulty(b, 4);
    Room c = malloc(sizeof(Room));
    if (c == NULL) printf("\nmalloc c error\n");
    setRoomEmail(c, "room_c@799");
    setRoomID(c, 799);
    setRoomOpening(c, 11);
    setRoomClosing(c, 22);
    setRoomCapacity(c, 7);
    setRoomPrice(c, 30);
    setRoomDifficulty(c, 8);
    List list = roomListCreate(CopyRoom,DeleteRoom);
    insertRoomFirst(list,a);
    insertRoomFirst(list,b);
    insertRoomFirst(list,c);
    Room first = getFirstRoom(list);
    ASSERT_TEST(getRoomID(first) == getRoomID(c));
    Room next = getNextRoom(list);
    ASSERT_TEST(getRoomID(next) == getRoomID(b));
    destroyRoomList(list);
    return true;
}

static bool testListInsertFirst() {
    Room a = malloc(sizeof(Room));
    if (a == NULL) printf("\nmalloc a error\n");
    setRoomEmail(a, "room_a@123");
    setRoomID(a, 123);
    setRoomOpening(a, 10);
    setRoomClosing(a, 20);
    setRoomCapacity(a, 5);
    setRoomPrice(a, 20);
    setRoomDifficulty(a, 4);
    Room b = malloc(sizeof(Room));
    if (b == NULL) printf("\nmalloc b error\n");
    setRoomEmail(b, "room_b@487");
    setRoomID(b, 487);
    setRoomOpening(b, 10);
    setRoomClosing(b, 20);
    setRoomCapacity(b, 5);
    setRoomPrice(b, 20);
    setRoomDifficulty(b, 4);
    Room c = malloc(sizeof(Room));
    if (c == NULL) printf("\nmalloc c error\n");
    setRoomEmail(c, "room_c@799");
    setRoomID(c, 799);
    setRoomOpening(c, 11);
    setRoomClosing(c, 22);
    setRoomCapacity(c, 7);
    setRoomPrice(c, 30);
    setRoomDifficulty(c, 8);
    List list = roomListCreate(CopyRoom,DeleteRoom);
    insertRoomFirst(list,a);
    insertRoomFirst(list,b);
    insertRoomFirst(list,c);
    Room first = malloc(sizeof(Room));
    if (first == NULL) printf("\nmalloc first error\n");
    setRoomEmail(first, "room_first@116");
    setRoomID(first, 116);
    setRoomOpening(first, 9);
    setRoomClosing(first, 18);
    setRoomCapacity(first, 6);
    setRoomPrice(first, 35);
    setRoomDifficulty(first, 5);
    insertRoomFirst(list, first);
    ASSERT_TEST(getRoomID(getFirstRoom(list)) == getRoomID(first));
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

