//
//  OrdList.cpp
//  Prj5
//
//  Created by Altun Shukurlu on 6/22/14.
//
//

#include "OrdList.h"

/*
*Constructor
*/
template <class Type, class Key>
OrdList<Type , Key>:: OrdList(){
    LinkedList<Type>();
}

/*
*Destructor
*/
template <class Type, class Key>
OrdList<Type , Key>:: ~OrdList(){
}

/*
*Inserts the item into an appropriate position within a list.
*If an element that has the same key as the key of input item, 
*is already existed in the list, then replaces the existing element with new element.
*/
template <class Type, class Key>
void OrdList<Type, Key>::insert(Type &item){
    int search_result = search(item.getKey()); //get the search result 

    if(this->empty() == 1){ // if the list is empty, insert as first element 
        LinkedList<Type>::insert(item, 0);
    }else{ //otherwise 
        if(search_result == -1){ //if head is greater than search_key 
            this->cursor = this->head;
            LinkedList<Type>::insert(item, -1);
        }else if(search_result == 0){ //if we have to insert somewhere in the middle 
            LinkedList<Type>::insert(item, 0);
        }else if(search_result == 1){ //if element is in the list already 
            this->cursor->element = item;
        }
    }
}

/*
*The method will find a location to which applies the insertion or deletion operation. 
*a) If a list is not empty and the key of the head pointing element is 
*   greater than the input argument “search_key”, move the cursor to the beginning of the list and return –1.
*b) If an element that has the same key as the input argument “search_key”, 
*   moves the cursor to the element and return 1.
*c) If a list doesn’t have a node that has the same key as input argument 
*   “search_key”, moves the cursor to the element containing the largest key that is smaller than “search_key”.
*   Then return 0. 
*/
template <class Type, class Key>
int OrdList<Type, Key>::search(Key search_key){

    if(this->empty() != 1){ //if the list is not empty 
        if(this->head->element.getKey() > search_key){ //if the first element is greater than search key 
            this->cursor = this->head;
            return -1;
        }
        this->cursor = this->head;
		//otherwise 
        while(this->cursor != NULL){ //find the element 
            if(this->cursor->element.getKey() == search_key){
                return 1;
            }
            this->cursor = this->cursor->next;
        }
		//if the element is not in the list, return largest key which is smaller than the search key 
        this->gotoPrior();
        while(this->cursor != NULL){
            if(this->cursor->element.getKey() < search_key){
               	 return 0;
            }
            this->gotoPrior();
        }
    }
	//if the list is empty 
    return -2;

    
}

/*
*Merges the elements in the input argument list, “other_list”, into a this list. 
*After the operation, all elements should be maintained in ascending order.
*/
template <class Type, class Key>
void OrdList<Type, Key>::merge(const OrdList<Type, Key> other_list){
	ListElement *temp; //create a temporary pointer 
    temp = other_list.head; //points to the head of the list 
    while(temp != NULL){ //while there is an element 
		this->insert(temp->element); //insert into the list 
		temp = temp->next; //move to the next element 
	}
	delete temp; //delete the memory 
}
