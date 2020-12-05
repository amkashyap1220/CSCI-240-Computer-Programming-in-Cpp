/***************************************************************
CSCI 240         Program 1     Fall 2020

Programmer: Alexander Kashyap

Section:

Date Due:

Purpose: This program calculates and displays the shooting
         percentage for an NHL team
***************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, const char * argv[]) {
    double scored, shots;
    cout << "Enter the number of goals that were scored: ";
    cin >> scored;
    cout << "\nEnter the number of shots that were attempted: ";
    cin >> shots;
    
    double shooting = (scored/shots) * 100;
    cout << "The Shooting Percentage is: " << shooting << "%\n";
    
    return 0;
}
