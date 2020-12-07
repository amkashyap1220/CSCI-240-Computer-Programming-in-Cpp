/***************************************************************
 CSCI 240         Program 10     Fall 2020
 @author Alexander Kashyap
 @file main.cpp
 @version 1.0
 Section: N/A
 Date Due: N/A
 Purpose:  A program that implement the methods for a class called card
***************************************************************/
#include <iostream>
#include <cstdlib>

using namespace std;

class Card {
    //data members
    int value;
    char suit[9];
    
    //public methods
public:
    Card();
    void setCard(int newFace, const char newSuit[]);
    int getFace();
    const char * getSuit();
    void displayCard();
};

int main(int argc, const char * argv[]) {
    srand(2);
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

/**
 Default contructor for Card
 */
Card::Card() {
    value = 1 + (rand() % 13);
    int s = 1 + (rand() % 4);
    switch (s) {
        case 1:
            strcpy(suit, "Clubs");
            break;
        case 2:
            strcpy(suit, "Diamonds");
            break;
        case 3:
            strcpy(suit, "Hearts");
            break;
        case 4:
            strcpy(suit, "Spades");
            break;
    }
}

/**
 sets both the face and the suit for the Card object
 @param newFace new face value for the card
 @param newSuit new suit value for the card
 */
