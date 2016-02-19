//
//  OrdList.h
//  Prj5
//
//  Created by Altun Shukurlu on 6/22/14.
//
//

#ifndef __Prj5__OrdList__
#define __Prj5__OrdList__

#include <iostream>

#include "linkedlist.cpp"

template <class Type, class Key>
class OrdList : public LinkedList<Type>//Inheritance
{
public:
    OrdList(); //constructor 
    ~OrdList(); //destructor
    void insert(Type& item); //insert an element 
    void merge(const OrdList<Type,Key> other_list); //merge two lists
    int search(Key search_key); //search for an element with a given key
};


#endif 
