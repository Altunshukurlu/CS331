//
//  Polynomial.h
//  Prj4
//
//  Created by Altun Shukurlu on 6/15/14.
//
//

#ifndef Prj4_Polynomial_h
#define Prj4_Polynomial_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
using namespace std;

class Polynomial {
    
    friend istream& operator>>(istream& in, Polynomial& v);
    friend ostream& operator<<(ostream& out, const Polynomial& v);
    friend void show(Polynomial* p);
    
public:
    Polynomial();
    Polynomial( const Polynomial& );
    Polynomial( const char *);
    Polynomial operator+( const Polynomial& ) const;
    Polynomial operator-( const Polynomial& ) const;
    Polynomial operator*( const Polynomial& );
    Polynomial& operator+=( const Polynomial& );
    Polynomial& operator-=( const Polynomial& );
    Polynomial& operator*=( const Polynomial& );
    int operator[]( int ) const;
    int& operator[]( int );
    int operator()( int );
    
private:
    int coefficients_[10];
};

#endif
