//
//  Polynomial.cpp
//  Prj4
//
//  Created by Altun Shukurlu on 6/15/14.
//
//

#include "Polynomial.h"

/*
 Default Constructor
 */
Polynomial::Polynomial(){
	for(int i = 0; i < 10; i++){
		coefficients_[i] = 0;
	}
}

/*
 Copy Constructor
 */
Polynomial::Polynomial(const Polynomial& arg){
	for(int k = 0; k < 10; k++){
		this->coefficients_[k] = arg.coefficients_[k];
	}
}

/*
 User-defined Constructor
 */
Polynomial::Polynomial(const char *arg){
    
	int term;
	int exponent;
    int sign ;
	char* tempTerm;
	char* temp = _strdup(arg);
	bool noTerms = false;
    char *pch;
    //set all coefficients to zero
    for(int i = 0; i < 10; i++){
		coefficients_[i] = 0;
	}
    
    //Block of code takes tempTerm and extracts the term and exponent.
	tempTerm = strtok(temp, " ");
	cout << "term is " << tempTerm << "\n";
	term = atoi(tempTerm);
    pch = strchr(tempTerm, 'x');
    if(pch != NULL){
        exponent = atoi((pch+1));
    }else{
        exponent = 0;
    }
	coefficients_[exponent] = term;
    
    
	while(!noTerms){
		tempTerm = strtok(NULL, " "); //take the sign of the coefficient
		if(tempTerm == NULL){ //if there are no more terms
			noTerms = true;
		} else { //otherwise
            if(strcmp(tempTerm, "+") == 0){ //assign the sign variable
                sign = 1;
            }else{
                sign = -1;
            }
            
            //Block of code takes tempTerm and extracts the term and exponent.
           	tempTerm = strtok(NULL, " ");
            cout << "term is " << tempTerm << "\n"; //print the current term
            term = atoi(tempTerm); //extract the coefficient
            term = term*sign; //update the sign of the term
            pch = strchr(tempTerm, 'x'); //check if the term has a variable
            if(pch != NULL){ //if yes, extract the power of the polynmoial
                exponent = atoi((pch+1));
            }else{ //otherwise, degree is zero
                exponent = 0;
            }
            coefficients_[exponent] = term; //update the coefficient
            
		}
	}
	delete temp; 
}

/*
 Overloaded addition operator
 */
Polynomial Polynomial::operator+(const Polynomial& arg) const{
	Polynomial temp;
    
	for(int i = 0; i < 10; i++){
		temp.coefficients_[i] = coefficients_[i] + arg.coefficients_[i];
	}
    
	return temp;
}

/*
 Overloaded subtraction operator
 */
Polynomial Polynomial::operator-(const Polynomial& arg) const{
	Polynomial temp;
    
	for(int i = 0; i < 10; i++){
		temp.coefficients_[i] = coefficients_[i] - arg.coefficients_[i];
	}
    
	return temp;
}

/*
 Overloaded mulitplication operator
 */
Polynomial Polynomial::operator*(const Polynomial& arg){
	Polynomial temp;
    
	for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(i+j < 10){
                // cout << (i+j) << " " << i << " " << j << " " << coefficients_[i] << " " << arg.coefficients_[j];
                temp.coefficients_[i+j] += coefficients_[i] * arg.coefficients_[j];
            }
        }
	}
    
	return temp;
}

/*
 Overloaded += operator
 */
Polynomial& Polynomial::operator+=(const Polynomial& arg){
    *this = *this + arg;
	return *this;
}

/*
 Overloaded -= operator
 */
Polynomial& Polynomial::operator-=(const Polynomial& arg){
    *this = *this - arg;
	return *this;
}

/*
 Overloaded *= operator
 */
Polynomial& Polynomial::operator*=(const Polynomial& arg){
    *this = *this * arg;
	return *this;
}

/*
 Overloaded [] operator
 */
int Polynomial::operator[](int degree) const{
    
	if(degree < 0 || degree >= 10){
        cout << "Degree should be between 0 and 9 !!!" << endl;
        exit(0);
	}
    
	return coefficients_[degree];
}

/*
 Overloaded [] operator
 */
int& Polynomial::operator[](int degree){
    
	if(degree < 0 || degree >= 10){
        cout << "Degree should be between 0 and 9 !!!" << endl;
        exit(0);
	}
    
	return coefficients_[degree];
}

/*
 Overloaded () operator
 */
int Polynomial::operator()(int num){
    int answer = 0;
    for(int i = 0; i < 10; i++){
        answer += coefficients_[i] * pow(num, i);
    }
    return answer;
}

istream& operator>>(istream& in, Polynomial& arg){
	Polynomial* temp; //temporary polynomial
	char line[100]; //array to store the line
    
    in.getline(line, 100); //read the line
    temp = new Polynomial(line); //create the polynomial
	
    arg = *temp; //assign the parameter
	delete(temp); //delete the temporary polynomial
    
	return in;
}

ostream& operator<<(ostream& out, const Polynomial& v){
    int i = 9;
    while(i > 0){ //print the first term with nonzero coefficient
        if(v.coefficients_[i] != 0){ //if there is such a term,
            out << v.coefficients_[i] << "x" << i; //print it and exit the while loop
            i--;
            break;
        }
        i--;
    }
    //print the other terms.
    int sign = 1;
	for(; i >= 0; i--){
        if(v.coefficients_[i] != 0){ //if coefficient is not zero, print the term
            if(v.coefficients_[i] < 0){ //if it is less than zero, print '-'
                sign = -1;
                out << " - ";
            }else{ //else print '+'
                sign = 1;
                out << " + ";
            }
            if(i!= 0){ //if it is not the last term
                out << (v.coefficients_[i]*sign) << "x" << i ;
            }else{
                out << v.coefficients_[i]*sign ;
            }
        }
	}
	return out;
}
