//
//  Memo.h
//  Prj5
//
//  Created by Altun Shukurlu on 6/22/14.
//
//

#ifndef __Prj5__Memo__
#define __Prj5__Memo__

#include <iostream>
using namespace std;

class Memo
{
public:
    Memo();
    const char * getTime(); //accessor
    const char * getTitle(); //accessor 
    void setTime(const char *t); //mutator
    void setTitle(const char *t);  //mutator
    int getKey(); //Returns the key value of a memo. Key will be created by the following formula: hour * 100 + minute 
private:
    char time[6]; //Holds an appointment time terminated by a null character in a military time form
    char title[41]; // Holds appointment information terminated by a null char.
};

#endif 
