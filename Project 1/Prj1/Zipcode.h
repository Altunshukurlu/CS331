//
//  Zipcode.h
//  Prj1
//
//  Created by Altun Shukurlu on 5/23/14.
//
//

#ifndef __Prj1__Zipcode__
#define __Prj1__Zipcode__

#include <iostream>
#include "FileIO.h"

using namespace std;
//class Zipcode uses FileIO object to open and
//read the data from the file then prints the barcode.
class Zipcode{
private:
    FileIO fileIO; //composition of fileIO object.
    int numZipCode; //total number of zip codes
    int *zipcode; // array of zipcodes
    int *correctionDigit; // array of correction digits
public:
    void readZipCode(); // read all zipcodes and stores in zipcode array
    void CorrectionDigitOf(int); // computes all correction digits and saves in correctionDigit array
    int extract(int, int); // extracts individual digits of a zipcode at a given location
    void printBarcode(); // prints zipcodes, correction digits, and bar codes
    void displayBarcode(int); // displays barcode of a specific zipcide
    void displayCode(int); // displays code of a digit
    Zipcode(); // constructor
    ~Zipcode(); // destructor
};

#endif /* defined(__Prj1__Zipcode__) */
