/***************************************************************
 CSCI 240         Program 8     Fall 2020
 @author Alexander Kashyap
 @file main.cpp
 @version 1.0
 Section: N/A
 Date Due: N/A
 Purpose:  A program that will caluclate and display information about a quardratic
***************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

using namespace std;

/* Place the Quadratic class definition here */
class Quadratic
{
    //data members
    int a, b, c;
    
    //public methods
public:
    Quadratic(int ac, int bc, int cc);
    void printEquation();
    double calcX();
    double calcY();
    void printVertex();
    void printConcavity();
    void print();
    
    //Extra Credit
    void printRoots();
    
    //Private methods
private:
    double calcDiscrum();
    int calcRoots(double &root1, double &root2);
    
};

int main()
{
    //Create a Quadratic object with a-coordinate of 1,
    //b-coordinate of 4, and c-coordinate of -5
    Quadratic equation1(1, 4, -5);


    //Display ONLY the equation for Quadratic 1

    cout << "-------------------" << endl
         << "-   Quadratic 1   -" << endl
         << "-------------------" << endl;

    equation1.printEquation();



    //Test the calcX and calcY methods

    //Display the coordinates of the vertex with 4 digits
    //after the decimal point
    cout << fixed << setprecision(4);

    cout << endl
         << "The x-coordinate of the vertex is " << equation1.calcX() << endl;

    cout << "The y-coordinate of the vertex is " << equation1.calcY()
         << endl << endl;



    //Test the printVertex method
    equation1.printVertex();


    //Test the printConcavity method
    equation1.printConcavity();



    //Create a Quadratic object with a-coordinate of -1,
    //b-coordinate of 2, and c-coordinate of -1
    Quadratic equation2(-1, 2, -1);

    //Display the information for Quadratic 2
    cout << endl << endl
         << "-------------------" << endl
         << "-   Quadratic 2   -" << endl
         << "-------------------" << endl;

    equation2.print();


    //Create a Quadratic object with a-coordinate of 1,
    //b-coordinate of 0, and c-coordinate of 25
    Quadratic equation3(1, 0, 25);

    //Display the information for Quadratic 3
    cout << endl
         << "-------------------" << endl
         << "-   Quadratic 3   -" << endl
         << "-------------------" << endl;

    equation3.print();


    //Create a Quadratic object with a-coordinate of -12,
    //b-coordinate of 2, and c-coordinate of 3
    Quadratic equation4(-12, 2, 3);

    //Display the information for Quadratic 4
    cout << endl << endl
         << "-------------------" << endl
         << "-   Quadratic 4   -" << endl
         << "-------------------" << endl;

    equation4.print();


    //Create a Quadratic object with a-coordinate of 12,
    //b-coordinate of 2, and c-coordinate of 3
    Quadratic equation5(12, 2, 3);

    //Display the information for Quadratic 5
    cout << endl << endl
         << "-------------------" << endl
         << "-   Quadratic 5   -" << endl
         << "-------------------" << endl;

    equation5.print();


    //Create a Quadratic object with a-coordinate of 0,
    //b-coordinate of -3, and c-coordinate of 0
    Quadratic equation6(0, -3, 0);

    //Display the information for Quadratic 6
    cout << endl
         << "-------------------" << endl
         << "-   Quadratic 6   -" << endl
         << "-------------------" << endl;

    equation6.print();
    
    //Extra Credit
    cout << endl << "Extra Credit Output" << endl;
    
    //For each equation (1-6) print it out and print the roots
    equation1.printEquation();
    equation1.printRoots();
    cout << endl;
    
    equation2.printEquation();
    equation2.printRoots();
    cout << endl;
    
    equation3.printEquation();
    equation3.printRoots();
    cout << endl;
    
    equation4.printEquation();
    equation4.printRoots();
    cout << endl;
    
    equation5.printEquation();
    equation5.printRoots();
    cout << endl;
    
    equation6.printEquation();
    equation6.printRoots();
    cout << endl;
    
    return 0;
}

/* Code the constructor and methods for the Quadratic
class below this comment.

DON'T FORGET TO ADD DOCUMENTATION BOXES FOR EACH
CONSTRUCTOR/METHOD that is coded. */

/**
 The constructor for the class is used to create a Quadratic object
 @param ac initial value for the a-coefficient
 @param bc initial value for the b-coefficient
 @param cc initial value for the c-coefficient
 */
Quadratic::Quadratic(int ac, int bc, int cc){
    //initialize the Quadradtic Class data members
    a = (ac == 0) ? 1 : ac;
    b = bc;
    c = cc;
}

/**
 displays the quadratic equation in its standard form
 */
void Quadratic::printEquation(){
    //build a string for the equation (Extra Credit)
    
    //Start with an empty string
    string equation = "";
    
    //All of the checking for the first term
    if (a == -1) {
        equation += "-x^2";
    } else if (a == 1) {
        equation += "x^2";
    } else {
        equation += (to_string(a) + "x^2");
    }
    
    //All of the checking for the second term
    if (b == 1) {
        equation += " + x";
    } else if (b != 0) {
        equation += (" + " + to_string(b)  + "x");
    }
    
    //the checking for the third term
    equation += (c != 0) ? (" + " + to_string(c)) : "";
    
    //finally add the "= 0" and print the equation
    equation += " = 0";
    cout << equation << endl;
}

/**
 calculates and returns the x-coordinate of the vertex of the quadratic equation
 @return the calculated x-coordinate
 */
double Quadratic::calcX(){
    double x = -b / (2.0 * a);
    return x;
}

/**
 calculates and returns the y-coordinate of the vertex of the quadratic equation
 @return the calculated y-coordinate
 */
double Quadratic::calcY(){
    double y = a * pow(calcX(), 2) + b * calcX() + c;
    return y;
}

/**
 displays the x and y-coordinates of the vertex of the quadratic equation
 */
void Quadratic::printVertex(){
    printf("Vertex Coordinates: (%.4f, %.4f)\n", calcX(), calcY());
}

/**
 displays the direction that a parabola produced by the quadratic equation would open if it was graphed
 */
void Quadratic::printConcavity(){
    //if first term is positive then upward else downward
    string direction = (a > 0) ? "UPWARD" : "DOWNWARD";
    
    cout << "The paraboloa opens " << direction << endl;
}

/**
 displays everything related to the parabola
 */
void Quadratic::print() {
    printEquation();
    printVertex();
    printConcavity();
}

/**
 calculates and returns the value of the discriminant
 @return the value of the discriminant
 */
double Quadratic::calcDiscrum() {
    double discrim = pow(b , 2) - 4 * a * c;
    return discrim;
}

/**
 calculates and passes back the roots for the equation
 @param root1 a reference to a double to pass back the first root
 @param root2 a reference to a double to pass back the first root
 @return the number of roots
 */
int Quadratic::calcRoots(double &root1, double &root2){
    //first get the value of the discriminate
    double discrim = calcDiscrum();
    
    //depending on the value of the discriminate calculate the roots return how many there is
    if (discrim > 0) {
        root1 = (-b + sqrt(discrim)) / (2 * a);
        root2 = (-b - sqrt(discrim)) / (2 * a);
        return 2;
    } else if (discrim == 0) {
        root1 = (-b + sqrt(discrim)) / (2 * a);
        return 1;
    }
    return 0;
}

/**
 displays the roots of the equation (if they exist)
 */
void Quadratic::printRoots(){
    //get the value for the roots and how many roots
    double root_1_val, root_2_val;
    int num_roots = calcRoots(root_1_val, root_2_val);
    
    //use a switch to go through the cases of 1, 2, or 0 roots and display them
    switch (num_roots) {
        case 1:
            cout << "There is ONE root at " << fixed << setprecision(3) << root_1_val << endl;
            break;
        case 2:
            cout << "There are TWO roots at " << fixed << setprecision(3) << root_1_val << " and " << fixed << setprecision(3) << root_2_val << endl;
            break;
        default:
            cout << "There are NO roots" << endl;
            break;
    }
}

