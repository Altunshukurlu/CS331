//
//  Interface.cpp
//  Prj5
//
//  Created by Altun Shukurlu on 6/22/14.
//
//

#include "Interface.h"

Interface::Interface(){
    
}
/*
*Prompts the user for the next command.
*/
void Interface::getCommand(){
    //get the command
	cout << "Enter command: " ; 
    char temp[100];
    cin.getline(temp, 100);
    command = temp[0] ;
}
/*
*Processes the user command. 
*/
void Interface::executeCommand(){
    //process the command
    switch(command){
        case '+' :{
            Memo temp;
            char time[6];
            char title[41];
            cout << "Enter time: ";
            cin.getline (time, 6);
            cout << "Enter Title: ";
            cin.getline (title, 41);
            temp.setTime(time);
            temp.setTitle(title);
            scheduler.insertMemo(temp);
            break;
        }
        case '-' :{
            char time[6];
            cout << "Enter time: ";
            cin.getline (time, 6);
            scheduler.deleteMemo(time);
            break;
            }
        case 'R' : case 'r' :{
            char filename[50];
            cout << "Enter FileName: " ;
            cin.getline (filename, 50);
            scheduler.readMemos(filename);
            break;
        }
        case 'W' : case 'w' :{
            char filename[50];
            cout << "Enter FileName: " ;
            cin.getline (filename, 50);
            scheduler.writeMemos(filename);
            break;
        }
        case 'D' : case 'd' :{
            scheduler.displayMemos();
            break;
        }
        case 'M' : case 'm' :{
            char filename[50];
            cout << "Enter FileName: " ;
            cin.getline (filename, 50);
            scheduler.mergeMemos(filename);
            break;
        }
        case 'C' : case 'c' :{
            scheduler.clearMemos();
            break;
        }
        case 'Q' : case 'q' :{
            finished = 1; 
            break;
        }
        case '?' :{
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
			cout << "Hit RETURN to continue" << endl; 
			cin.ignore();
			cout << "\n\n" << endl;
            break;
        }
        default :{
            cout << "Invalid Command\n" << endl;
            }
        }
}
/*
*Returns the value of finished data field.
*/
int Interface::done(){
    return finished;
}