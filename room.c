#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "room.h"
//#include "list_mtm1.h"

struct SRoom {
    char* email; //room email address
    int ID; //room ID
    int opening; //opening hour - hh:00
    int closing; //closing hour - hh:00
    int num_ppl; //room capacity
    int price; //price per person
    int difficulty; //required skill level
    Order order_list; //points to the 'head' of this room's order list
};

char* getRoomEmail(Room room) {
    if (room == NULL) {
        return NULL;
    }
    return room->email;
}

int getRoomID(Room room) {
    if (room == NULL) {
        return -1;
    }
    return room->ID;
}

int getRoomOpening(Room room) {
    if (room == NULL) {
        return -1;
    }
    return room->opening;
}

int getRoomClosing(Room room) {
    if (room == NULL) {
        return -1;
    }
    return room->closing;
}

int getRoomCapacity(Room room) {
    if (room == NULL) {
        return -1;
    }
    return room->num_ppl;
}

int getRoomPrice(Room room) {
    if (room == NULL) {
        return -1;
    }
    return room->price;
}

int getRoomDifficulty(Room room) {
    if (room == NULL) {
        return -1;
    }
    return room->difficulty;
}

Order getRoomOrders (Room room) {
    if (room == NULL) {
        return NULL;
    }
    return room->order_list;
}

ListResult setRoomEmail(Room room, char* email) {
    if (room == NULL || email == NULL) {
        return LIST_NULL_ARGUMENT;
    }
    room->email = malloc(strlen(email)+1);
    if (room->email == NULL) {
        return LIST_OUT_OF_MEMORY;
    }
    strcpy(room->email, email);
    return LIST_SUCCESS;
}

ListResult setRoomID(Room room, int ID) {
    if (room == NULL) {
        return LIST_NULL_ARGUMENT;
    }
    room->ID = ID;
    return LIST_SUCCESS;
}

ListResult setRoomOpening(Room room, int opening_hour) {
    if (room == NULL) {
        return LIST_NULL_ARGUMENT;
    }
    room->opening = opening_hour;
    return LIST_SUCCESS;
}

ListResult setRoomClosing(Room room, int closing_hour) {
    if (room == NULL) {
        return LIST_NULL_ARGUMENT;
    }
    room->closing = closing_hour;
    return LIST_SUCCESS;
}

ListResult setRoomCapacity(Room room, int num_ppl) {
    if (room == NULL) {
        return LIST_NULL_ARGUMENT;
    }
    room->num_ppl = num_ppl;
    return LIST_SUCCESS;
}

ListResult setRoomPrice(Room room, int price) {
    if (room == NULL) {
        return LIST_NULL_ARGUMENT;
    }
    room->price = price;
    return LIST_SUCCESS;
}

ListResult setRoomDifficulty(Room room, int difficulty) {
    if (room == NULL) {
        return LIST_NULL_ARGUMENT;
    }
    room->difficulty = difficulty;
    return LIST_SUCCESS;
}

ListResult setRoomOrder (Room room, Order order) {
    if (room == NULL) {
        return LIST_NULL_ARGUMENT;
    }
    //?
    return LIST_SUCCESS;
}

ListElement CopyRoom(ListElement room) {
    assert(room);
    Room room_copy = malloc(sizeof(struct SRoom));
    if (room_copy == NULL) {
        return NULL;
    }
    if (setRoomEmail(room_copy, getRoomEmail(room)) != LIST_SUCCESS ||
        setRoomID(room_copy, getRoomID(room)) != LIST_SUCCESS ||
        setRoomOpening(room_copy, getRoomOpening(room)) != LIST_SUCCESS ||
        setRoomClosing(room_copy, getRoomClosing(room)) != LIST_SUCCESS ||
        setRoomCapacity(room_copy, getRoomCapacity(room)) != LIST_SUCCESS ||
        setRoomPrice(room_copy, getRoomPrice(room)) != LIST_SUCCESS ||
        setRoomDifficulty(room_copy, getRoomDifficulty(room)) != LIST_SUCCESS) {//orders?
        return NULL;
    }
    return room_copy;
}

void DeleteRoom(ListElement room) {
    assert(room);
    free(getRoomEmail(room));
    free(room);
}

int CompareRooms(ListElement room1, ListElement room2);//by what? make sure ID isn't recurring?


List roomListCreate(CopyListElement CopyRoom, FreeListElement DeleteRoom) {
    assert(CopyRoom && DeleteRoom);
    List list = listCreate(CopyRoom, DeleteRoom);
    if (list == NULL) {
        return NULL;
    }
    return list;
}


List roomListCopy(List list) {
    assert(list);
    List list_copy = listCopy(list);
    if (list_copy == NULL) {
        return NULL;
    }
    return list_copy;
}


int roomListGetSize(List list) {
    assert(list);
    int room_num = listGetSize(list);
    if (room_num < 0) {
        return -1;
    }
    return room_num;
}


Room getFirstRoom(List list) {
    assert(list);
    Room first = listGetFirst(list);
    if (first == NULL) {
        return NULL;
    }
    return first;
}


Room getNextRoom(List list) {
    assert(list);
    Room next = listGetNext(list);
    if (next == NULL) {
        return NULL;
    }
    return next;
}


Room getCurrentRoom(List list) {
    assert(list);
    Room current = listGetCurrent(list);
    if (current == NULL) {
        return NULL;
    }
    return current;
}


ListResult insertRoomFirst(List list, Room room) {
    assert(list && room);
    ListResult insert_result = listInsertFirst(list, room);
    if (insert_result != LIST_SUCCESS) {
        return insert_result;
    }
    return LIST_SUCCESS;
}


ListResult insertRoomLast(List list, Room room) {
    assert(list && room);
    ListResult insert_result = listInsertLast(list, room);
    if (insert_result != LIST_SUCCESS) {
        return insert_result;
    }
    return LIST_SUCCESS;
}


ListResult insertRoomBeforeCurrent(List list, Room room) {
    assert(list && room);
    ListResult insert_result = listInsertBeforeCurrent(list, room);
    if (insert_result != LIST_SUCCESS) {
        return insert_result;
    }
    return LIST_SUCCESS;
}


ListResult insertRoomAfterCurrent(List list, Room room) {
    assert(list && room);
    ListResult insert_result = listInsertAfterCurrent(list, room);
    if (insert_result != LIST_SUCCESS) {
        return insert_result;
    }
    return LIST_SUCCESS;
}


ListResult removeCurrentRoom(List list) {
    assert(list);
    ListResult remove_result = listRemoveCurrent(list);
    if (remove_result != LIST_SUCCESS) {
        return remove_result;
    }
    return LIST_SUCCESS;
}


ListResult sortRooms(List list, CompareListElements compare) {
    assert(list && compare);
    ListResult sort_result = listSort(list, compare);
    if (sort_result != LIST_SUCCESS) {
        return sort_result;
    }
    return LIST_SUCCESS;//maybe just "return sort_result"?
}


//List filterRooms(List list, FilterListElement filter, ListFilterKey key);


ListResult clearRooms(List list) {
    assert(list);
    ListResult clear_result = listClear(list);
    if (clear_result != LIST_SUCCESS) {
        return clear_result;
    }
    return LIST_SUCCESS;
}


void destroyRoomList(List list) {
    assert(list);
    listDestroy(list);
}