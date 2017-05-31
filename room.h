#ifndef ROOMS_H_
#define ROOMS_H_

#include <stdbool.h>
#include "orders.h"

struct SRoom;
typedef struct SRoom *Room;

char* getRoomEmail(Room room);

int getRoomID(Room room);

int getRoomOpening(Room room);

int getRoomClosing(Room room);

int getRoomCapacity(Room room);

int getRoomPrice(Room room);

int getRoomDifficulty(Room room);

int getRoomOrderNum (Room room);

ListResult setRoomEmail(Room room, char* email);

ListResult setRoomID(Room room, int ID);

ListResult setRoomOpening(Room room, int opening_hour);

ListResult setRoomClosing(Room room, int closing_hour);

ListResult setRoomCapacity(Room room, int num_ppl);

ListResult setRoomPrice(Room room, int price);

ListResult setRoomDifficulty(Room room, int difficulty);

ListResult setRoomOrders(Room room, int order_num);

ListResult incRoomOrders(Room room);

ListResult decRoomOrders(Room room);

ListElement CopyRoom(ListElement room);

void DeleteRoom(ListElement room);

int CompareRooms(ListElement room1, ListElement room2);

typedef void* RoomFilterKey;


List roomListCreate(CopyListElement copy, FreeListElement delete);


List roomListCopy(List list);//?


int roomListGetSize(List list);


Room getFirstRoom(List list);


Room getNextRoom(List list);


Room getCurrentRoom(List list);


ListResult insertRoomFirst(List list, Room room);


ListResult insertRoomLast(List list, Room room);


ListResult insertRoomBeforeCurrent(List list, Room room);


ListResult insertRoomAfterCurrent(List list, Room room);


ListResult removeCurrentRoom(List list);


ListResult sortRooms(List list, CompareListElements compare);


List filterRooms(List list, FilterListElement filter, ListFilterKey key);


ListResult clearRooms(List list);


void destroyRoomList(List list);

#define LIST_FOREACH(type,iterator,list) \
	for(type iterator = listGetFirst(list) ; \
		iterator ;\
		iterator = listGetNext(list))

#endif /* ROOMS_H_ */
