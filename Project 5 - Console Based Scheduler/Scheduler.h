//
//  Scheduler.h
//  Prj5
//
//  Created by Altun Shukurlu on 6/22/14.
//
//

#ifndef __Prj5__Scheduler__
#define __Prj5__Scheduler__


#include <iostream>
#include "OrdList.cpp"
#include "Memo.h"
#include <fstream>
#include <string>

using namespace std;

class Scheduler
{
public:
    Scheduler();
    ~Scheduler();
    void copyConstTest();
    void insertMemo(Memo newMemo);
    void deleteMemo(char *time);
    void readMemos(char filename[]);
    void writeMemos(char filename[]);
    void displayMemos();
    void mergeMemos(char filename[]);
    void clearMemos();
    
private:
    OrdList<Memo, int> memos;
};


#endif 
