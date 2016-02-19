//
//  linkedlist.h
//  Prj3
//
//  Created by Altun Shukurlu on 6/7/14.
//
//

#ifndef Prj3_linkedlist_h
#define Prj3_linkedlist_h

#include <iostream>
using namespace std;

template <typename Type>
class LinkedList
{
public:
    LinkedList();//Constructor
    ~LinkedList();//Destructor
    
    void insert(const Type &item, int);//
    void remove();//
    Type retrieve() const;//
    int  gotoPrior();//
    int  gotoNext();//
    int  gotoBeginning();//
    void clear();
    int  empty() const;//
    
    LinkedList(const LinkedList &src);
    
protected:
    class ListElement
    {
    public:
        ListElement(const Type &item, ListElement* nextP):
        element(item), next(nextP) {}
        Type element;
        ListElement* next;
    };
    ListElement *head; //A pointer points the beginning of a singly linked list that stores ListElement type nodes.  ListElement class is an
                        //inner class of the LinkedList class and the class implementation is already provided in the LinkedList header file.
    ListElement *cursor;//A pointer points a list node where the next list operations will be applied.
};

#endif
