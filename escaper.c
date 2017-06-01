#include "escaper.h"
#include "set.h"
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>


struct escaper_struct {
    char* email;
    TechnionFaculty faculty;
    int skill_level;
    Order *first_order;
};

Escaper escaperCreate(char* email, TechnionFaculty faculty, int skill_level){
    //need to check that all parameters are valid
    Escaper escaper = malloc(sizeof(*escaper));
    if(!escaper){
        return NULL;
    }
    escaper->email = email;
    escaper->faculty = faculty;
    escaper->skill_level = skill_level;
    return escaper;
}

Set escaperSetCreate(copySetElements copyElement, freeSetElements freeElement, compareSetElements compareElements) {
    Set escaper_set = setCreate(copyElement, freeElement, compareElements);
    return escaper_set;
}

void escaperSetDestroy(Set set){
    setDestroy(set);
}

int escaperSetGetSize(Set set){
    int size = setGetSize(set);
    return size;
}

bool escaperSetIsIn(Set set, Escaper escaper){
    bool is_in = setIsIn(set, escaper);
    return is_in;
}

Escaper escaperSetGetFirst(Set set){
    Escaper escaper = setGetFirst(set);
    return escaper;
}

Escaper escaperSetGetNext(Set set){
    Escaper escaper = setGetNext(set);
    return escaper;
}

Escaper escaperSetGetCurrent(Set set){
    Escaper escaper = setGetCurrent(set);
    return escaper;
}

SetResult escaperSetAdd(Set set, Escaper escaper){
    SetResult result = setAdd(set, escaper);
    return result;
}

SetResult escaperSetRemove(Set set, Escaper escaper){
    SetResult result = setRemove(set, escaper);
    return result;
}

SetResult escaperSetClear(Set set) {
    SetResult result = escaperSetClear(set);
    return result;
}