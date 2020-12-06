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
    
    //public methods
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
    
    //private methods
private:
    void reduce();
    int GCD( int val1, int val2 );
    int LCM( int val1, int val2 );
};

int main(int argc, const char * argv[]) {
    //Creating all of the Rational Objects
    Rational rational1 = Rational();
    Rational rational2 = Rational(11, 30);
    Rational rational3 = Rational(2, 30);
    Rational rational4 = Rational(5, 6);
    Rational rational5 = Rational(3, 7);
    
    //Testing the constructors
    cout << "***** Testing the constructors *****" << endl;
    
    //default constructor
    cout << "\nThe default constructor produces ";
    rational1.displayFraction();
    cout << endl;
    
    //alternate constructor
    cout << "\nThe alternate constructor: " << endl;
    printf("\nWith %d, %d produces ", 11, 30);
    rational2.display();
    printf("With %d, %d produces ", 2, 30);
    rational3.display();
    printf("With %d, %d produces ", 5, 6);
    rational4.display();
    printf("With %d, %d produces ", 3, 7);
    rational5.display();
    
    //Testing the set methods
    cout << "\n\n***** Testing the set methods *****" << endl;
    
    //setNumerator
    cout << "\nsetNumerator(8) changes ";
    rational3.displayFraction();
    cout << " to ";
    rational3.setNumerator(8);
    rational3.displayFraction();
    cout << endl;
    
    //setDenominator
    cout << "\nsetDenominator(73) changes ";
    rational4.displayFraction();
    cout << " to ";
    rational4.setDenominator(73);
    rational4.displayFraction();
    cout << endl;
    
    //setRational
    cout << "\nsetRational(4, 6) changes ";
    rational1.displayFraction();
    cout << " to ";
    rational1.setRational(4, 6);
    rational1.displayFraction();
    cout << endl;
    
    
    //testing the add method
    cout << "\n\n***** Testing the add method *****\n";
    
    cout << "\n5/73 + 3/7 = ";
    Rational rational6 = rational4.add(3, 7);
    rational6.display();
    cout << "\n254/511 + 3/7 = ";
    rational6 = rational6.add(3, 7);
    rational6.display();
    
    cout << "\n8/15 + 1/2 = ";
    Rational rational7 = rational3.add(1, 2);
    rational7.display();
    
    cout << "\n2/3 + 15/16 = ";
    Rational rational8 = rational1.add(15, 16);
    rational8.display();
    
    
    //testing the subtract methods
    cout << "\n\n***** Testing the subtract method *****\n";
    
    cout << "\n473/511 - 5/7 = ";
    Rational rational9 = rational6.subtract(5, 7);
    rational9.display();
    
    cout << "\n31/30 - 3/6 = ";
    Rational rational10 = rational7.subtract(3, 6);
    rational10.display();
    
    cout << "\n77/48 - 101/117 = ";
    Rational rational11 = rational8.subtract(101, 117);
    rational11.display();
    
    
    //testing the multiply method
    cout << "\n\n***** Testing the multiply method *****\n";
    
    cout << "\n108/511 * 1/1 = ";
    Rational rational12 = rational9.multiply(1, 1);
    rational12.display();
    
    cout << "\n8/15 * 7/30 = ";
    Rational rational13 = rational10.multiply(7, 30);
    rational3.display();
    
    cout << "\n1387/1872 * 2/4 = ";
    Rational rational14 = rational11.multiply(2, 4);
    rational14.display();
    
    
    //testing the divide method
    cout << "\n\n***** Testing the divide method *****\n";
    
    cout << "\n108/511 / 5/8 = ";
    Rational rational15 = rational9.divide(5, 8);
    rational15.display();
    
    cout << "\n28/225 / 5/15 = ";
    Rational rational16 = rational13.divide(5, 15);
    rational16.display();
    
    cout << "\n3/7 / 2/4 = ";
    Rational rational17 = rational5.divide(2, 4);
    rational17.display();
    
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

/**
 displays the rational number in its decimal form with 5 digits after the decimal point
 */
void Rational::displayFloat() {
    //first calculate the value as a decimal then print
    double decimal = (double) numerator / denominator;
    printf("%.5f", decimal);
}

/**
 displays the rational number in its fractional form (i.e. numerator/denominator)
 */
void Rational::displayFraction() {
    printf("%d/%d", numerator, denominator);
}

/**
 displays the rational number in both its decimal and fractional forms
 */
void Rational::display(){
    //call both the displayFraction and displayFloat in order to show both
    displayFraction();
    cout << "    or    ";
    displayFloat();
    cout << endl;
}

/**
 change the denominator value
 @param newDenominator the new denominator value
 */
void Rational::setDenominator(int newDenominator) {
    denominator = newDenominator;
    //reduce the fraction after changing any value
    reduce();
}

/**
 change the numerator value
 @param newNumerator the new numerator value
 */
void Rational::setNumerator(int newNumerator) {
    numerator = newNumerator;
    //reduce the fraction after changing any value
    reduce();
}

/**
 change fractional value
 @param newNumerator the new numerator value
 @param newDenominator the new denominator value
 */
void Rational::setRational(int newNumerator, int newDenominator) {
    numerator = newNumerator;
    denominator = newDenominator;
    //reduce the fraction after changing any value
    reduce();
}

/**
 adds two rational numbers
 @param addNumerator numerator of the rational number being added
 @param addDenominator denominator of the rational number being added
 @return sum of the addition
 */
Rational Rational::add(int addNumerator, int addDenominator) {
    //get the LCM and the amount that each numerator will need to be multiplied by
    int lcm = LCM(denominator, addDenominator);
    int currMultValue = lcm / denominator;
    int argMultValue = lcm / addDenominator;
    
    //compute the new rationals numerator
    int sumNum = (numerator * currMultValue) + (addNumerator * argMultValue);
    
    //create the Rational and return it
    Rational sum = Rational(sumNum, lcm);
    return sum;
}

/**
 subtract two rational numbers
 @param subNumerator the numerator of the rational number being subtracted
 @param subDenominator the denominator of the rational number being subtracted
 @return difference of the subtraction
 */
Rational Rational::subtract(int subNumerator, int subDenominator) {
    //get the LCM and the amount that each numerator will need to be multiplied by
    int lcm = LCM(denominator, subDenominator);
    int currMultValue = lcm / denominator;
    int argMultValue = lcm / subDenominator;
    
    //compute the new rationals numerator
    int difNum = (numerator * currMultValue) - (subNumerator * argMultValue);
    
    //create the Rational and return it
    Rational dif = Rational(difNum, lcm);
    return dif;
}

/**
 multiplies two rational numbers
 @param multNumerator numerator of the rational number the current instance is being multiplied by
 @param multDenominator the denominator of the rational number the current instance is being multiplied by
 @return product of the multiplication
 */
Rational Rational::multiply(int multNumerator, int multDenominator) {
    //create a new rational object to return (math done in parameters)
    Rational product = Rational(numerator * multNumerator, denominator * multDenominator);
    return product;
}

/**
 divides two rational numbers
 @param divNumerator numerator of the rational number the current instance is being divided by
 @param divDenominator denominator of the rational number the current instance is being divided by
 @return result of the division
 */
Rational Rational::divide(int divNumerator, int divDenominator) {
    //create a new rational object to return (math done in parameters)
    Rational result = Rational(numerator * divDenominator, denominator * divNumerator);
    return result;
}

/**
 reduces a Rational object to its simplest form
 */
void Rational::reduce() {
    //find the greatest common divisor
    int gcd = GCD(numerator, denominator);
    //divide by it...
    numerator /= gcd;
    denominator /= gcd;
}

/**
 calculates and returns the greatest common divisor of two integer values
 @param val1 First value
 @param val2 Second value
 */
int Rational::GCD( int val1, int val2 )
{
    int remainder, num1, num2;

    //set variables num1 and num2 to the two passed in values
    num1 = val1;
    num2 = val2;

    //continue dividing num1 by num2 until a remainder of 0 is found
    while (true)
      {
      //find the remainder when num1 is divided by num2
      remainder = num1 % num2;

      //if the remainder is 0, get out of the loop
      if( remainder == 0 )
        break;

      //set num1 to the current num2 value
      num1 = num2;
      
      //set num2 to the remainder
      num2 = remainder;
      }//end while

    //After the loop is done executing, the variable num2 will contain the
    //greatest common divisor.
    return num2;
}

/**
 calculates and returns the least common multiple of two integer values
 @param val1 First value
 @param val2 Second value
 */
int Rational::LCM( int val1, int val2 )
{
    int num1, num2, lcm;

    //set variables num1 and num2 to the two passed in values
    num1 = val1;
    num2 = val2;

    //set lcm to the first passed in value
    lcm = num1;

    //while lcm is less than or equal to the product of num1 and num2
    while( lcm <= num1 * num2 )
      {
      //if the remainder of lcm divided by num1 is 0 and
      //   the remainder of lcm divided by num2 is 0, get out of the loop
      if( lcm % num1 == 0 and lcm % num2 == 0 )
        break;

      //increment lcm by 1
      lcm++;
      }//end while

    //return the least common multiple
    return lcm;
}
