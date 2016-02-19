//
//  InputOutput.cpp
//  Project2
//
//  Created by Altun Shukurlu on 6/2/14.
//
//

#include "InputOutput.h"

//Open an input file with given file name.
//If success to open a file return true. Otherwise, return false.
bool InputOutput::openInFile(char *filename){
    infile.open(filename);
    if (infile.is_open()){
        return true;
    }else{
        cout << "Error opening file!" << endl;
        return false;
    }
}

//Open an output file with given file name.
//If success to open a file return true. Otherwise, return false.
bool InputOutput::openOutFile(char *filename){
    outfile.open(filename);
    if (outfile.is_open()){
        return true;
    }else{
        cout << "Error opening file!" << endl;
        return false;
    }
}

//This method opens a new file and writes the edited input file into it
//Opens the same file for extractSentence Method
//Note: This method and file are created in order to make it easier to extract the sentences.
bool InputOutput::openEditedInFile(char *filename){
    ofstream output_file(filename);
    string inbuf;
    
    while (!infile.eof())
    {
        getline(infile, inbuf);
        
        //replace all delimiters with 'period'
        replace(inbuf.begin(), inbuf.end(), ';', '.');
        replace(inbuf.begin(), inbuf.end(), ':', '.');
        replace(inbuf.begin(), inbuf.end(), '?', '.');
        replace(inbuf.begin(), inbuf.end(), '!', '.');
        
        //replace '\n' character with spaces.
        replace(inbuf.begin(), inbuf.end(), '\r', ' ');
        output_file << inbuf ;
        
    }
    output_file.close(); // close the file
    
    //open the file to extract the input (sentences)
    edited_infile.open(filename);
    if (edited_infile.is_open()){
        return true;
    }else{
        cout << "Error opening file!" << endl;
        return false;
    }
    
}

//Read line(s) from the input file to extract a sentence.
//If it reaches to the EOF, return false. Otherwise, return true.
bool InputOutput::extractSentence(){
    string inbuf;
    if(!getline(edited_infile, inbuf, '.').eof()  ){
        //copy inbuf in sentence
        sentence = new char[inbuf.size() + 1];
        copy(inbuf.begin(), inbuf.end(), sentence);
        sentence[inbuf.size()] = '\0'; // terminating the string
        
        return true;
    }
    //if we reached EOF without reaching the delimiter, return false
    return false;
}
//generate a report and display it. Format is given in the description file
void InputOutput::generateOutput(Flesch flesch, Dictionary* d){
    
    cout << "Number of sentences: " << flesch.getNs() << endl;
    cout << "Number of words: " << flesch.getNw() << endl;
    cout << "Number of syllables: " << flesch.getNy() << endl;
    cout << "Flesch Readability Index: " << flesch.getIndex() << " "<< flesch.levelOf(flesch.getIndex()) << endl;
    
    outfile << "Number of sentences: " << flesch.getNs() << endl;
    outfile << "Number of words: " << flesch.getNw() << endl;
    outfile << "Number of syllables: " << flesch.getNy() << endl;
    outfile << "Flesch Readability Index: " << flesch.getIndex() << " "<< flesch.levelOf(flesch.getIndex()) << endl;
    
    d->display(&outfile); //invoke display method of a dictionary to print the rest of the output.
    
}


//accessor for variable 'sentence'
char* InputOutput::getSentence() const{
    return sentence;
}

//mutator for variable 'sentence'
void InputOutput::setSentence(char *s){
    sentence = s;
}

//Constructor
InputOutput::InputOutput(){
    
}

//Destructor
InputOutput::~InputOutput(){
    delete [] sentence;
    sentence = 0;
    infile.close();
    outfile.close();
    edited_infile.close();
}