//
//  LinkedList.cpp
//  Prj5
//
//  Created by Altun Shukurlu on 6/22/14.
//
//

#include "linkedlist.h"
/*
	Constructor
*/
template <typename Type >
LinkedList< Type >::LinkedList(){
    head = NULL;
    cursor = NULL;
}

/*
	Copy Constructor
*/
template <typename Type >
LinkedList< Type >::LinkedList(const LinkedList &src){
	if(src.empty() == 1){
		head = NULL;
		cursor = NULL;
		return;
	}
    if(src.head == NULL){
        head = NULL;
        cursor = NULL;
    }else{
        head = new ListElement(src.head->element, NULL);
        cursor = head;
        ListElement *temp;
        ListElement *counter = src.head;
        while(counter->next != NULL){
            counter = counter->next;
            temp = new ListElement(counter->element, NULL);
            cursor->next = temp;
            cursor = cursor->next;
        }
        cursor = head;
    }
}

/*
	Destructor
*/
template <typename Type >
LinkedList< Type >::~LinkedList(){
    clear();
    if(head != NULL){
        delete head;
    }
}

/*
 When a list is not full, inserts the item into a list.
 a) If the list is empty, inserts the item as the first element in the list. The head and cursor pointer should be initialized properly after the insert operation.
 b) If the list is not empty and the second integer argument has the value of 0, inserts the item immediately after the cursor element.
 c) If the list is not empty and the second integer argument has the value of -1, inserts the item immediately before the cursor element.
 In all case, properly move the cursor to designate inserted item as the current element.
 */
template <typename Type>
void LinkedList<Type>::insert(const Type &item, int i){
    if(empty() == 1){ //if the list is empty, insert the element to the first position.
        head = new ListElement(item, NULL);
        cursor = head;
    }else{ //otherwise
        ListElement* newElement = new ListElement(item, NULL); //create the element
        if(i == -1 && cursor == head){
            newElement->next = cursor;
            head = newElement;
            cursor = head; 
        }else{
        if(i != 0){
            gotoPrior(); //set cursor one before.insert after that one
        }
        if(cursor->next == NULL){ //if it is the last element
            cursor->next = newElement; //insert the new element
        }else{ //otherwise, fix the pointers before inserting.
            ListElement *nextElement = cursor->next;
            newElement->next = nextElement;
            cursor->next = newElement;
        }
        
        cursor = newElement; //set the cursor to the inserted element.
        }
    }
}

/*
 a) When a list is not empty, removes the current element from the list. After deleting the cursor pointing element, set the cursor to the following element.
 b) If the cursor is pointing to an element that is the only element in the list, you should properly set the head and cursor pointer after deleting the node.
 c) If the cursor is pointing to the last element of the list, the link field of the previous node of the last node should be set to null after deleting the node.  Set the cursor to the head pointing element.
 */
template <typename Type>
void LinkedList<Type>::remove(){
    if(empty() == 1){ //if the list is empty, do nothing.
        head = NULL;
        cursor = NULL;
    }else{ //otherwise
        ListElement* elementToRemove = NULL; //pointer to the element that we are going to remove
        if(cursor == head){//removing first element
            elementToRemove = head; //set the pointer
            head = head->next; //detach the element from the list
            cursor = head; //update the cursor
        }else if(cursor->next == NULL){//removing last element
            elementToRemove = cursor; //set the pointer
            gotoPrior(); //move the cursor
            cursor->next = NULL; //detach the element from the list
            cursor = head; //update the cursor
            
        }else{//removing other elements
			elementToRemove = cursor;
            ListElement *nextNode = cursor->next; //set the pointer to the next element
            cursor->next = NULL; // detach the element
            gotoPrior(); // move to the element one before
            cursor->next = nextNode; // update the links
            cursor = cursor->next; //update the cursor
        }
        delete elementToRemove; //finally, remove the element
    }
}


/*
 When a list is not empty, return a copy of the cursor pointing element.
 */
template <typename Type>
Type LinkedList<Type>::retrieve() const{
    return cursor->element;
}

/*
 If a list is not empty and the cursor is not pointing the first element of the list,
 then designates the element immediately before the current element as the current element and returns 1.
 Otherwise, returns 0.
 */
template <typename Type>
int LinkedList<Type>::gotoPrior(){
    if(empty() == 1 || cursor == head){ //return 0 if the list is empty or cursor is set to the first element
        return 0;
    }else{ //otherwise update the cursor
        ListElement *temp = cursor;
        cursor = head;
        while(cursor->next != temp){
            cursor = cursor->next;
        }
        return 1;
    }
}

/*
 If the current element is not at the end of the list,
 then designates the element immediately after the current element as the current element and returns 1.
 Otherwise, returns 0.
 */
template <typename Type>
int LinkedList<Type>::gotoNext(){
    if(empty() == 1 || cursor->next == NULL){
        return 0;
    }else{
        cursor = cursor->next;
        return 1;
    }
}

/*
 If a list is not empty,
 then designates the element at the beginning of the list as the current element and returns 1.
 Otherwise, returns 0.
 */
template <typename Type>
int LinkedList<Type>::gotoBeginning(){
    if(empty() == 1){
        return 0;
    }else{
        cursor = head;
        return 1;
    }
}

/*
 Removes all the elements in a list and deallocates associated dynamic memory.
 */
template <typename Type>
void LinkedList<Type>::clear(){
    if(empty() != 1){ //if the list is not empty
        ListElement *elementToBeRemoved;
        cursor = NULL;
        while(head != NULL){ //while there is an element to remove
            elementToBeRemoved = head; //set the pointer
            head = head->next; // move to the next element
            delete elementToBeRemoved; //remove the element
        }
    }else{
        head = NULL;
        cursor = NULL;
    }
}

/*
 Returns 1 if a list is empty.  Otherwise, returns 0.
 */
template <typename Type>
int LinkedList<Type>::empty() const{
    if(head == NULL){
        return 1;
    }
    return 0;
}
