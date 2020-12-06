/***************************************************************
 CSCI 240         Program 8     Fall 2020
 @author Alexander Kashyap
 @file main.cpp
 @version 1.0
 Section: N/A
 Date Due: N/A
 Purpose:  A program that implement the methods for a class that can be used to represent a rational number (ie. fraction)
***************************************************************/

#include <iostream>

using namespace std;

//Rational Class
class Rational {
    //data members
    int numerator, denominator;
    
public:
    Rational();
    Rational(int num, int den);
    void displayFloat();
    void displayFraction();
    void display();
    void setNumerator( int newNumerator );
    void setDenominator( int newDenominator );
    void setRational( int newNumerator, int newDenominator );
    Rational add( int addNumerator, int addDenominator );
    Rational subtract( int subNumerator, int subDenominator );
    Rational multiply( int multNumerator, int multDenominator );
    Rational divide( int divNumerator, int divDenominator );
private:
    void reduce();
    int GCD( int val1, int val2 );
    int LCM( int val1, int val2 );
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

/**
 Default contructor for Rational Class, sets numerator and denominator both to 1
 */
Rational::Rational() {
    numerator = 1;
    denominator = 1;
}

/**
 Contrictor for Rational Class
 @param num numerator
 @param den demoninator
 */
Rational::Rational(int num, int den) {
    setRational(num, den);
}
