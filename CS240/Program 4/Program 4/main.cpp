//
//  main.cpp
//  Program 4
//
//  Created by Alexander Kashyap on 12/3/20.
//

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

// Defining symbolic constants
#define MAX_SIZE_1     25
#define MAX_SIZE_2     50
#define MAX_SIZE_3     250
#define MAX_DISP_1     5
#define MAX_DISP_2     6
#define MAX_DISP_3     7

int main(int argc, const char * argv[]) {
    // initialize the randome number generator
    srand(17);
    
    // Extra Credit: print the menu of choices and take input for which choice the user picks
    char choice;
    cout << "*****  Number Types  *****\n";
    cout << "E)ven\nO)dd\nZ)ero\n";
    cout << "\nWhat type of number would you like to count? ";
    cin >> choice;
    choice = tolower(choice);
    
    // check the input until a valid char has been entered
    while (choice != 'e' && choice != 'o' && choice != 'z') {
        cout << "Error: Please enter a option from the list about (E, O, Z): ";
        cin >> choice;
        choice = tolower(choice);
    }
    
    /*
     Using a For Loop
     get a random number for the size of the set and using a for loop, loop through the size of the set displaying numbers
     */
    int count = 0;
    int first_set_size = 1 + (rand() % MAX_SIZE_1);
    cout << "\n\nThere are " << first_set_size << " numbers in the first set of numbers.\n\n";
    for (int i = 1; i <= first_set_size; i++) {
        // Generate the random number
        int num = rand();
        // Extra Credit: depending on what the user selected (o, e, z) print the number with ** and update the counter.
        if (choice == 'e' && (num % 2) == 0) {
            cout << right << setw(14) << num << "**";
            count++;
        } else if (choice == 'o' && (num % 2) == 1) {
            cout << right << setw(14) << num << "**";
            count++;
        } else if (choice == 'z' && num == 0){
            cout << right << setw(14) << num << "**";
            count++;
        } else {
            cout << right << setw(14) << num << "  ";
        }
        // every 5 numbers go to a new line
        if ((i % MAX_DISP_1) == 0) {
            cout << "\n";
        }
    }
    // depending on the user choice from the begining print out how many numbers there were that met the criteria
    if (choice == 'e') {
        cout << "\nThere are " << count << " even numbers in the first set of numbers\n";
    } else if (choice == 'o') {
        cout << "\nThere are " << count << " odd numbers in the first set of numbers\n";
    } else {
        cout << "\nThere are " << count << " zeros in the first set of numbers\n";
    }
    
    /*
     using a While Loop
     get a random number for the size of the set and using a while loop, loop through the size of the set displaying numbers
     also, for the while loop, initialize another counter to track how many iterations we have done
     */
    count = 0;
    int second_set_size = 1 + (rand() % MAX_SIZE_2);
    cout << "\n\n\nThere are " << second_set_size << " numbers in the second set of numbers.\n\n";
    int i = 0;
    while (i < second_set_size) {
        // Update the counter and generate the random number
        i++;
        int num = rand();
        // Extra Credit: depending on what the user selected (o, e, z) print the number with ** and update the counter.
        if (choice == 'e' && (num % 2) == 0) {
            cout << right << setw(14) << num << "**";
            count++;
        } else if (choice == 'o' && (num % 2) == 1) {
            cout << right << setw(14) << num << "**";
            count++;
        } else if (choice == 'z' && num == 0){
            cout << right << setw(14) << num << "**";
            count++;
        } else {
            cout << right << setw(14) << num << "  ";
        }
        // every 6 numbers go to a new line
        if ((i % MAX_DISP_2) == 0) {
            cout << "\n";
        }
    }
    // depending on the user choice from the begining print out how many numbers there were that met the criteria
    if (choice == 'e') {
        cout << "\n\nThere are " << count << " even numbers in the first set of numbers\n";
    } else if (choice == 'o') {
        cout << "\n\nThere are " << count << " odd numbers in the first set of numbers\n";
    } else {
        cout << "\n\nThere are " << count << " zeros in the first set of numbers\n";
    }
    
    /*
     using a Do-While Loop
     get a random number for the size of the set and using a do-while loop, loop through the size of the set displaying numbers
     also, for the do-while loop, initialize another counter to track how many iterations we have done. The first iteration will
     be done no matter what given the nature of the do-while.
     */
    int third_set_size = 1 + (rand() % MAX_SIZE_3);
    cout << "\n\n\nThere are " << third_set_size << " numbers in the third set of numbers.\n\n";
    count = 0;
    i = 0;
    do {
        // Update the counter and generate the random number
        i++;
        int num = rand();
        // Extra Credit: depending on what the user selected (o, e, z) print the number with ** and update the counter.
        if (choice == 'e' && (num % 2) == 0) {
            cout << right << setw(14) << num << "**";
            count++;
        } else if (choice == 'o' && (num % 2) == 1) {
            cout << right << setw(14) << num << "**";
            count++;
        } else if (choice == 'z' && num == 0){
            cout << right << setw(14) << num << "**";
            count++;
        } else {
            cout << right << setw(14) << num << "  ";
        }
        // every 7 numbers go to a new line
        if ((i % MAX_DISP_3) == 0) {
            cout << "\n";
        }
    } while (i < third_set_size);
    // depending on the user choice from the begining print out how many numbers there were that met the criteria
    if (choice == 'e') {
        cout << "\n\nThere are " << count << " even numbers in the first set of numbers\n";
    } else if (choice == 'o') {
        cout << "\n\nThere are " << count << " odd numbers in the first set of numbers\n";
    } else {
        cout << "\n\nThere are " << count << " zeros in the first set of numbers\n";
    }
    
    return 0;
}
