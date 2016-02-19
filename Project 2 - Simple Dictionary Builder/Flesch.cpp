//
//  Flesch.cpp
//  Project2
//
//  Created by Altun Shukurlu on 6/3/14.
//
//

#include "Flesch.h"

//Compute the Flesch Readability Index.
void Flesch::fleschRating(){
    double num = 206.835 - 84.6 * ny / nw - 1.015 * nw / ns;
    //round the index to the nearest integer
    if( (num + 0.5) >= (int(num) + 1) )
        index = int(num)+1;
    else
        index = int(num);
}

//Return the String type Educational level based on the input numeric index.
char* Flesch::levelOf(int index) const{
    if(index > 90){
        return "5th grader";
    }
    if(index > 80){
        return "6th grader";
    }
    if(index > 70){
        return "7th grader";
    }
    if(index > 65){
        return "8th grader";
    }
    if(index > 60){
        return "9th grader";
    }
    if(index > 50){
        return "High school student";
    }
    if(index > 30){
        return "College student";
    }
    if(index >= 0){
        return "College graduate";
    }
    if(index < 0){
        return "Law school graduate";
    }
    return "ERROR!"; //program shouldn't come to this point. for test-purposes.
}

//Analyze the input argument, sentence.
//Update parameters for the Flesch Readability index computation and dictionary.
void Flesch::analyzeSentence(char* sentence, Dictionary *dictionary){
    word = nextWordIn(sentence); //read the next word from the sentence
    ns++; //increment number of sentences
    while(word != NULL){ //while there is a word to process
        ny = ny + countSyllablesIn(word); //update number of syllables
        nw++; //update number of words
        dictionary->update(word); //update the dictionary
        word = nextWordIn(sentence); //read the next word, process it
    }
}

//Tokenize each word from the input argument, sentence.
//Return the tokenized word to the calling method.
char* Flesch::nextWordIn(char* sentence){
    if(word == NULL){ //if there is no word saved, initialize the tokenizer
        word = strtok(sentence, " ");
    }else{ //read the next word
        word = strtok(NULL, " ");
    }
    return word;
}

//Count syllables and return the number of syllables in a word.
int Flesch::countSyllablesIn(char* word){
    int syllables = 0; //current number of syllables
    bool begin = false; //if current subset of syllables is consisted from vowels.
    size_t len = strlen(word); //size of the word
    
    //for loop iterates through all and increments the number of syllables for every subset of vowels found, except the subset including the last vowel
    for(string::size_type i = 0; i < len; ++i) { //iterate through all
        if(begin == true){ //if previos subsete is all vowels
            if(isVowel(word[i])){ //if this is also vowel, go to the next syllabus
            }else{ //otherwise,
                begin = false; //end the subset
                syllables++; //increase the number of syllables
            }
        }else{ //if last syllable is NOT a vowel
            if(isVowel(word[i])){ //if this one is a vowel
                begin = true; //set the flag
            }
        }
    }
    if(begin){ //if the last character is a vowel.
        if(word[len-1] != 'e'){ //if it is not 'e', increment number of syllables
            syllables++;
        }else{ //if it is 'e' and if the previous character is a vowel, increment no of syll.
            if(isVowel(word[len-2])){
                syllables++;
            }
        }
    }
    //if there was no vowels, increment syllables from 0 to 1.
    if(syllables == 0){
        syllables = 1;
    }

    return syllables;
}

//returns true if char c is a vowel.
bool Flesch::isVowel(char c){
    c = tolower(c);//to check for capitalized forms as well.
    switch(c)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'y':
            return true;
        default:
            return false;
    }
}

//ACCESSORS AND MUTATORS FOR DATA MEMBERS. MOST OF THEM WERE NOT USED.
int Flesch::getNs(){
    return ns;
}

int Flesch::getNw(){
    return nw;
}

int Flesch::getNy(){
    return ny;
}

int Flesch::getIndex(){
    return index;
}

void Flesch::setIndex(int index){
    this->index = index;
}

void Flesch::setNs(int ns){
    this->ns = ns;
}

void Flesch::setNw(int nw){
    this->nw = nw;
}

void Flesch::setNy(int ny){
    this->ny = ny;
}

const char* Flesch::getWord(){
    return word;
}

void Flesch::setWord(char* word){
    strcpy(this->word, word);
}
Flesch::Flesch(){
    
}

Flesch::~Flesch(){
    delete word;
    word = 0;
}