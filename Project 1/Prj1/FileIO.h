//
//  FileIO.h
//  Prj1
//
//  Created by Altun Shukurlu on 5/23/14.
//
//

#ifndef __Prj1__FileIO__
#define __Prj1__FileIO__

#include <iostream>
#include <fstream>

using namespace std;
//Class FileIO opens the file and reads the data
class FileIO{
private:
    ifstream inFile;
public:
    bool openInputFile(char*);
    int readDataSize();
    int readZipCode();
    FileIO();
    ~FileIO();
};

#endif /* defined(__Prj1__FileIO__) */
