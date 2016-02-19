//
//  Dictionary.cpp
//  Project2
//
//  Created by Altun Shukurlu on 6/3/14.
//
//

#include "Dictionary.h"

//Display method prints the values on the console and
//saves the to the output file using the pointer to the output file from the argument.
void Dictionary::display(ofstream* outfile){
    *outfile << "\nDictionary" << endl; //write the first line
    cout << "\nDictionary" << endl; //print the first line
    for(int i = 0; i < MAX_WORDS; i++){ //iterate through all words, stop when hitting first NULL
        if(words[i] == NULL) break ;
        *outfile << words[i] << " " << occurences[i] << endl;
        cout <<  words[i] << " " << occurences[i] << endl;
    }
   

}

//update the list by adding the 'word'
void Dictionary::update(char* word){
    bool inserted = false; //true if the word is already in the list.
    int i = 0; //pointer to the first element
    while(!inserted){ //while word is not in the list
        if(words[i] == NULL){ //if space is empty, insert the word
            words[i] = new char[24]; //allocate space
            strcpy(words[i], word); //insert the word
            occurences[i] = 1; //increment the occurences
            inserted = true; //set the flag
        }else{ //otherwise
            if(strcmp(words[i],word) == 0){ //if current word is equal to our word
                occurences[i]++; //increment the occurences
                inserted = true; //set the flag
            }
        }
        i++; //go to the next entry
    }
}

//Sort the words in ascending order
void Dictionary::sort(){
    int size; //size of the array
    char *tempWord = new char[24]; //temp array to store the word (for sorting)
    
    //determine the size of the array.
    for( size = 0; size < MAX_WORDS; size++){
        if(words[size] == NULL){
            break;
        }
    }
    
    //using brute force sort algorithm.
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(strcmp(words[i], words[j]) > 0){
                //swap the elementts
                strcpy(tempWord, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], tempWord);
                int tempOcc = occurences[j];
                occurences[j] = occurences[i];
                occurences[i] = tempOcc;
            }
        }
    }
    delete tempWord; //clean the memory
}

//Accessor and Mutator
const int* Dictionary::getOccurences(){
    return occurences;
}

//Accessor
const char* Dictionary::getWords() {
    return *words;
}

//constructor
Dictionary::Dictionary(){

}

//destructor 
Dictionary::~Dictionary(){
    for(int i = 0; i < MAX_WORDS; i++){
        delete [] words[i];
        words[i] = 0;
    }
}