//
//  Zipcode.cpp
//  Prj1
//
//  Created by Altun Shukurlu on 5/23/14.
//
//

#include "stdafx.h"
//Read zip codes from the input file and stores it in the zipcode array.
void Zipcode::readZipCode(){
    fileIO.openInputFile("zipcode.txt");
    numZipCode = fileIO.readDataSize(); //read the total number of zipcodes
    zipcode = new int[numZipCode]; //initialize the array
    correctionDigit = new int[numZipCode];

    int count = 0;
    for(count = 0; count < numZipCode; count++){ //loop to read all zipcodes
        zipcode[count] = fileIO.readZipCode();
        CorrectionDigitOf(count); //compute the correction digit for current zipcode
    }
}

//Compute a correction digit for a zip code located at index location in the zipcode array.
//Then stores it to the corresponding location in the correctionDigit array.
void Zipcode::CorrectionDigitOf(int index){
    int location = 1; //counter to compute sum of the digits
    for(location = 1; location <= 5; location++){
        correctionDigit[index] += extract(index, location); //compute the sum
    }
    
    correctionDigit[index] = (10 - correctionDigit[index] % 10)%10; //compute correction digit
  
}

//Extracts individual digits of the zipcode at the given location.  The first input argument represents
//a zip code located at index location in the zipcode array.  The second argument value ‘1’, returns the
//first digit of the zipcode.
//The input argument value ‘2’, returns the second digit of the zipcode, etc.
int Zipcode::extract(int index, int location){
    int count = 1;
    int num = zipcode[index];
    
    for(count = 1; count < location; count++){
        num /= 10; //divide by 10 until we get to that location
    }
    
    return num%10; //return the last digit
}

//Display a bar code corresponding to a single digit provided by an input argument digit.
void Zipcode::displayCode(int digit){
    //for each case return a specific code.
    if(digit == 0){
        cout << "||:::" ;
    }
    if(digit == 1){
        cout << ":::||" ;
    }
    if(digit == 2){
        cout << "::|:|" ;
    }
    if(digit == 3){
        cout << "::||:" ;
    }
    if(digit == 4){
        cout << ":|::|" ;
    }
    if(digit == 5){
        cout << ":|:|:" ;
    }
    if(digit == 6){
        cout << ":||::" ;
    }
    if(digit == 7){
        cout << "|:::|" ;
    }
    if(digit == 8){
        cout << "|::|:" ;
    }
    if(digit == 9){
        cout << "|:|::" ;
    }
}

//Display an entire line of bar code associated with zipcode and
//correctionDigit at a location specified by input argument index.
void Zipcode::displayBarcode(int index){
    cout << "|"; //first element of the output
    for(int i = 5; i >= 1; i--){
        displayCode(extract(index, i)) ; //display code for each digit
    }
    displayCode(correctionDigit[index]); //display code for the correction digit
    cout << "|" << endl; //last element of the output
}

//Display zip codes, correction digits, and bar codes.
//Reference the figure given in the project description.
void Zipcode::printBarcode(){
    cout <<  "ZipCode   ";
    cout << "Correction   ";
  cout << "Barcode" << endl;
    cout << setw(18) << "Digit"<< endl;
    //print messages for each zipcode
    for(int index = 0; index < numZipCode; index++){
        cout << " " << zipcode[index] << " " ;
        cout << setw(9) << correctionDigit[index];
        cout << setw(8);
        displayBarcode(index);
    }
}
//constructor
Zipcode::Zipcode(){
    
}
//destructor 
Zipcode::~Zipcode(){
    
}