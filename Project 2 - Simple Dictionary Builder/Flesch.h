//
//  Flesch.h
//  Project2
//
//  Created by Altun Shukurlu on 6/3/14.
//
//

#ifndef __Project2__Flesch__
#define __Project2__Flesch__

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include "Dictionary.h"
using namespace std;

//This class executes operations associated with computing Flesch Readability Index
class Flesch{
private:
    int ns; //number of sentences
    int nw; //number of words
    int ny; //number of syllables
    int index; //Flesch Readability Index
    char* word; //current word read from the current sentence
public:
    Flesch(); //constructor
    ~Flesch(); //destructor
    void fleschRating(); //Compute the Flesch Readability Index
    char* levelOf(int ) const; //Return the string type Educational Level based on the index
    void analyzeSentence(char* , Dictionary*); //analyze the input (sentence). Update parameters and the Dictionary
    char* nextWordIn(char* ); //tokenize each word from the input argument sentence. return that word
    int countSyllablesIn(char* ); //count syllables and return the number in a word
    bool isVowel(char); //method returns true if character equals to a,e,o,i,u, or y.
    //accessors
    int getNs();
    int getNw();
    int getNy();
    int getIndex();
    const char* getWord();
    //mutators
    void setNs(int ns);
    void setNw(int nw);
    void setNy(int ny);
    void setIndex(int index);
    void setWord(char* word);
    
};


#endif /* defined(__Project2__Flesch__) */
