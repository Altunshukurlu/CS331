//
//  InputOutput.h
//  Project2
//
//  Created by Altun Shukurlu on 6/2/14.
//
//

#ifndef __Project2__InputOutput__
#define __Project2__InputOutput__

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include "Flesch.h"


using namespace std;

//This class handles operations associated with reading/writing from/to files
class InputOutput{
private:
    ifstream infile; //input file stream
    ofstream outfile; //output file stream
    ifstream edited_infile;  //edited input file in order to extract sentences
    char* sentence; //pointer points a sentence read from the input stream
public:
    InputOutput();
    ~InputOutput();
    bool openInFile(char*); //open the input file with given name
    bool openOutFile(char*); //open the output file with given name
    bool extractSentence(); //extract one full sentence from the edited_infile.
    void generateOutput(Flesch, Dictionary*); //save output to outfile and display it
    bool openEditedInFile(char*); //edit the input file and save it to editedInFile
    char* getSentence() const; //accessor for sentence
    //OTHER ACCESSORS AND MUTATORS ARE NOT REQUIRED:
    void setSentence(char*);
};

#endif /* defined(__Project2__InputOutput__) */
