/***************************************************************
 CSCI 240         Program 1    Fall 2020
 @author Alexander Kashyap
 @file main.cpp
 @version 1.0
 Section: N/A
 Date Due: N/A
 Purpose: a program that will calculate team shooting percentages
***************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, const char * argv[]) {
    //inititialize variables for goals attempted and scored
    double scored, shots;
    
    //display a promp and read the input data
    cout << "Enter the number of goals that were scored: ";
    cin >> scored;
    cout << "\nEnter the number of shots that were attempted: ";
    cin >> shots;
    
    //calculate and display the shooting percentage
    double shooting = (scored/shots) * 100;
    cout << "The Shooting Percentage is: " << shooting << "%\n";
    
    return 0;
}
