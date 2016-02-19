//
//  Interface.h
//  Prj5
//
//  Created by Altun Shukurlu on 6/22/14.
//
//

#ifndef __Prj5__Interface__
#define __Prj5__Interface__

#include <iostream>
#include "Scheduler.h"
using namespace std;

class Interface
{
public:
    Interface ();
    void getCommand ();
    void executeCommand ();
    int done ();
    
private:
    Scheduler scheduler;
    char command; //Holds a keyboard command that was entered by the user. 
    int finished; //Holds a value that indicates the end of execution. 1=ended
};

#endif 
