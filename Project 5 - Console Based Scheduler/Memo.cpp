//
//  Memo.cpp
//  Prj5
//
//  Created by Altun Shukurlu on 6/22/14.
//
//

#include "Memo.h"

//constructor
Memo::Memo(){
    
}

//accessor
const char* Memo::getTime(){
    return time;
}

//accessor
const char* Memo::getTitle(){
    return title;
}

//modifier
void Memo::setTime(const char *t){
    time[0] = '\0'; //nullify the data field 
    strncpy(time, t, sizeof(time));

}

//modifier
void Memo::setTitle(const char *t){
    title[0] = '\0'; //nullify the data field
    strncpy(title, t, sizeof(title));

}

//getKey method returns the unique key for each Memo
int Memo::getKey(){
    return ((time[0] - '0')*1000 + (time[1] - '0')*100 + (time[3] - '0')*10 + (time[4] - '0'));
}