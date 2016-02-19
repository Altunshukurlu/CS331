//
//  main.cpp
//  Prj3
//
//  Created by Altun Shukurlu on 6/7/14.
//
//
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


#include "linkedlist.CPP"
template <typename Type>
void outList(LinkedList<Type> list)
{
    char tmp;
    
    if (list.empty())
        cout << "Empty list" << endl;
    else
    {
        list.gotoBeginning();
        do
        {
            tmp = list.retrieve();
            cout << tmp << " -> ";
            
        }
        while (list.gotoNext());
        cout << endl;
    }
}

int main(int argc, const char * argv[])
{
 
  
        LinkedList<char> testList;		// Test list
        char testElement;			// List element
        char cmd;					// Input command
        cout << endl << "Commands:" << endl;
        cout << "  +x  : Insert x after the current element" << endl;
        cout << "  -   : Remove the current element" << endl;
        cout << "  @   : Display the current element" << endl;
        cout << "  <   : Go to the beginning of the list" << endl;
        cout << "  N   : Go to the next element" << endl;
        cout << "  P   : Go to the prior element" << endl;
        cout << "  C   : Clear the list" << endl;
        cout << "  E   : Empty list?" << endl;
        cout << "  Q   : Quit the program" << endl;
        cout << endl;
        
        do
        {
            outList(testList);				// Output list
            cout << endl << "Command: ";				// Read command
            cin >> cmd;
            if ( ( cmd == '+' ) || ( cmd == '=' ) || ( cmd == '#' ) )
                cin >> testElement;
            
            switch ( cmd )
            {
                case '+' :
                    cout << "Insert " << testElement << endl;
                    testList.insert(testElement, 0);
                    break;
                    
                case '-' :
                    cout << "Remove the current element" << endl;
                    testList.remove();
                    break;
                    
                case '@' :
                    cout << "Current element is "
                    << testList.retrieve() << endl;
                    break;
                    
                case '<' :
                    if ( testList.gotoBeginning() )
                        cout << "Go to the beginning of the list" << endl;
                    else
                        cout << "Failed -- list is empty" << endl;
                    break;
                    
                case 'N' : case 'n' :
                    if ( testList.gotoNext() )
                        cout << "Go to the next element" << endl;
                    else
                        cout << "Failed -- either at the end of the list "
                        << "or the list is empty" << endl;
                    break;
                    
                case 'P' : case 'p' :
                    if ( testList.gotoPrior() )
                        cout << "Go to the prior element" << endl;
                    else
                        cout << "Failed -- either at the beginning of the "
                        << "list or the list is empty" << endl;
                    break;
                    
                case 'C' : case 'c' :
                    cout << "Clear the list" << endl;
                    testList.clear();
                    break;
                    
                case 'E' : case 'e' :                     
                    if ( testList.empty() )
                        cout << "List is empty" << endl;
                    else
                        cout << "List is NOT empty" << endl;
                    break;
                    
                case 'Q' : case 'q' :  
                    break;
                    
                default :              
                    cout << "Inactive or invalid command" << endl;
            }
        }
        while ( ( cmd != 'Q' ) && ( cmd != 'q' ) );
		_CrtDumpMemoryLeaks();

}

