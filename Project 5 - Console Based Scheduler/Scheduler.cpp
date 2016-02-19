//
//  Scheduler.cpp
//  Prj5
//
//  Created by Altun Shukurlu on 6/22/14.
//
//

#include "Scheduler.h"

//Constructor
Scheduler::Scheduler(){
    
}

//Destructor 
Scheduler::~Scheduler(){

}

/*
*An OrdList contains appointments for a day.
*Second generic type parameter represents a key field of a memo. 
*/
void Scheduler::insertMemo(Memo newMemo){
    memos.insert(newMemo);
}

/*
Converts the input argument “time” to the corresponding integer type key.  
*Reference getKey() method in the Memo class. 
*If an appointment is scheduled at the given time, delete the appointment (memo) from the “memos” OrdList. 
*If there is no schedule at that time, print out a message telling no appointment at the time.
*/
void Scheduler::deleteMemo(char *time){
    int search_key = (time[0] - '0')*1000 + (time[1] - '0')*100 + (time[3] - '0')*10 + (time[4] - '0'); //get the key 
    int search_result = memos.search(search_key); //get the search result 
    if(search_result == 1){
        //remove appointment
        memos.remove();
    }else{
		cout << "No memo found at " << time << "\n\n" <<endl; 
	}
    
}

/*
*Read memos from the given name file, “filename”, and insert memo objects into the OrdList in ascending order. 
*If the given name file does not exist, print out an error message. 
*/
void Scheduler::readMemos(char filename[]){
    ifstream infile; //input file 
    infile.open (filename);
    if(infile.is_open()){ //if its open 
		char time[6]; 
		char title[41];
		string time_s; //string to hold the time 
		string title_s; //string to hold the title 

		while(getline(infile, time_s)){ //while there are more memos 
			getline(infile, title_s); //read the title 
			Memo temp; //create the temporary memo 
			memcpy(time, time_s.c_str(), 6); //copy into char array 
			time[5] = '\0'; //set the null pointer 

			memcpy(title, title_s.c_str(), title_s.size()); //copy into char array 
			title[title_s.size()] = '\0'; //set the null pointer 

			temp.setTime(time); //set the memo time 
			temp.setTitle(title); //set the memo title 
        
			memos.insert(temp); //insert the memo 
			memset(time, 0, sizeof time); //nullify the arrays
			memset(title, 0, sizeof title) ;
		}
		infile.close(); //close the file 
    }else{
        cout << "Couldn't open the file!!! " << endl;
		system("pause");
        exit(0);
    }
}

/*
*Print out all memos in current OrdList to the standard output. 
*Each memo should be displayed as the following format:
*Time => Appointment info. 
*If there is no memo in the OrdList, print out a message, “No schedule for today”.*
*/
void Scheduler::displayMemos(){
    if(memos.empty() == 1){ //if it is empty 
        cout << "No schedule for today\n\n" << endl;
    }else{
        memos.gotoBeginning(); //iterate through each memo 
        while(memos.gotoNext() == 1){
            memos.gotoPrior();
            cout << memos.retrieve().getTime() << " => " << memos.retrieve().getTitle() << endl;;
            memos.gotoNext();
        }
		//print the last memo 
        cout << memos.retrieve().getTime() << " => " << memos.retrieve().getTitle() << endl;;
		cout << "\n\n" << endl; 
    }
}
/*
*Write all memos in current OrdList to the given file.
*/
void Scheduler::writeMemos(char *filename){
    ofstream outfile; //output file 
    outfile.open(filename);
    
    if(!outfile.is_open()){
        cout << "Error! Can't create a file to write the memos! Exiting the application" << endl;
		system("pause");
        exit(0);
    }
    
    memos.gotoBeginning(); //iterate through each memo
    while(memos.gotoNext() == 1){
        memos.gotoPrior();
        outfile << memos.retrieve().getTime() << endl;
        outfile << memos.retrieve().getTitle() << endl;
        memos.gotoNext();
    }
	//print the last memo 
    outfile << memos.retrieve().getTime() << endl;
    outfile << memos.retrieve().getTitle() << endl;
    outfile.close();
}

/*
*Reads the memos in the given name file, “filename”.  Merges them into a this OrdList.  
*After the operation, all elements should be maintained in ascending order.
*/
void Scheduler::mergeMemos(char* filename){
        ifstream infile;
        infile.open (filename);
        if(infile.is_open()){
            
            char time[6];
            char title[41];
            string time_s;
            string title_s;
            
            while(getline(infile, time_s)){
                getline(infile, title_s);
                Memo temp;
                memcpy(time, time_s.c_str(), 6);
                time[5] = '\0';
                
                memcpy(title, title_s.c_str(), title_s.size());
                title[title_s.size()] = '\0';
                
                temp.setTime(time);
                temp.setTitle(title);
                
                memos.insert(temp);
                memset(time, 0, sizeof time);
                memset(title, 0, sizeof title) ;
            }
            infile.close();
        }else{
            cout << "Couldn't open the file!!! " << endl;
			system("pause");
            exit(0);
        }

}

/*
*clear the scheduler 
*/
void Scheduler::clearMemos(){
    memos.clear(); 
}