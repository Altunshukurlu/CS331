//
//  main.cpp
//  Project2
//
//  Created by Altun Shukurlu on 6/2/14.
//
//

#include <iostream>
#include "InputOutput.h"
#include "Flesch.h"

//Creates the objects InputOutput, Flesch, and Dictionary
//Opens the input/output files
//Invokes the necessary methods to create the report.
int main(int argc, const char * argv[])
{
    //necesserary objects
    InputOutput inputOutput;
    Dictionary* dictionary = new Dictionary;
    Flesch flesch;
    
    //open the necessary files
    inputOutput.openInFile("SmallSample1.txt");
    inputOutput.openOutFile("SmallSample1.out");
    inputOutput.openEditedInFile("TEMP.txt");
    
    //while there are more sentences extract them and use flesch.analyzeSentence method to process it.
    while(inputOutput.extractSentence()){
        flesch.analyzeSentence(inputOutput.getSentence(), dictionary);
    }

    flesch.fleschRating(); //compute the index
    dictionary->sort(); //sort the words
    
    inputOutput.generateOutput(flesch, dictionary); //save output to outFile and display on console
    delete dictionary; 
    return 0;
}

