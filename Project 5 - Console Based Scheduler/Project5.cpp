//
//  main.cpp
//  Prj5
//
//  Created by Altun Shukurlu on 6/22/14.
//
//


#include "Interface.h"



int main(int argc, const char * argv[])
{
    Interface interface; 
    cout << endl << "List of Commands:\n" << endl;
    cout << "  +   : Insert (or replace) a prompted memo. Enter information" << endl;
    cout << "  -   : Remove the memo. Enter the time" << endl;
    cout << " R,r  : Enter the filename to read memos from" << endl;
    cout << " W,w  : Enter the filename to write memos to" << endl;
    cout << " D,d  : Display all memos in Scheduler in ascending order" << endl;
    cout << " M,m  : Enter the filename to merge memos from" << endl;
    cout << " C,c  : Clear the Scheduler" << endl;
    cout << " Q,q  : Exit the application" << endl;
    cout << "  ?   : Display the command list" << endl;
    cout << endl;
    while(interface.done() != 1){
        interface.getCommand();
        interface.executeCommand();
    }

	_CrtDumpMemoryLeaks();

}

