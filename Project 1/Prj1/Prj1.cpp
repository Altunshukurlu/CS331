// Prj1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>/** main method initializes the zipcode object, reads the zipcodes 
 * by invoking readZipCode() method and
 * prints the barcodes by invoking printBarCode() method.
 */
int _tmain(int argc, _TCHAR* argv[])
{
  Zipcode zipcode;
	zipcode.readZipCode();
       zipcode.printBarcode();
       	system("pause");
       	  return 0;
}