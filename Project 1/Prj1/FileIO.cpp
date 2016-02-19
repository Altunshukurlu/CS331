//
//  FileIO.cpp
//  Prj1
///Users/test/Desktop/Prj1/Prj1/FileIO.cpp
//  Created by Altun Shukurlu on 5/23/14.
//
//

#include "stdafx.h"

//openInputFile opens the file with a given name,
//returns true if the file is open, error message and false otherwise.
bool FileIO::openInputFile(char *filename){
    inFile.open(filename);
    if (inFile.is_open()){
        return true;
    }else{
        cout << "Error opening file!" << endl;
        return false;
    }
}

//readDataSize reads the first line of the file and returns it
//--reads the number of zipcodes in the given file
int FileIO::readDataSize(){
    int total;
    inFile >> total; //read the next integer
    return total;
}

//readZipCode reads the next line of the file and returns it
//--reads the next zipcode
int FileIO::readZipCode(){
    int nextZipCode;
    inFile >> nextZipCode; //read the next integer
    return nextZipCode;
}
//constructor
FileIO::FileIO(){
    
}
//destructor
FileIO::~FileIO(){
    
}