//
//  Dictionary.h
//  Project2
//
//  Created by Altun Shukurlu on 6/3/14.
//
//

#ifndef __Project2__Dictionary__
#define __Project2__Dictionary__

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;

//This class provides operations associated with updating Dictionary
class Dictionary{
public:
    Dictionary(); //constructor
    void update(char*); //update the list words by adding one word.
    void sort(); //sort the list
    void display(ofstream* outfile); //display the words
    ~Dictionary(); //destructor
    //accessors. weren't used.
    const int* getOccurences();
    const char* getWords();
    static const int MAX_WORDS = 1000; //maximum number of words
private:
    int occurences[MAX_WORDS]; // number of occurences of words
    char* words[MAX_WORDS]; //words 

};

#endif /* defined(__Project2__Dictionary__) */
