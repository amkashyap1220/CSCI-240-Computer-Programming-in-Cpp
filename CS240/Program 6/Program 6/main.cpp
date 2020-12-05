/***************************************************************
 CSCI 240         Program 6     Fall 2020
 @author Alexander Kashyap
 @file main.cpp
 @version 1.0
 Section: N/A
 Date Due: N/A
 Purpose: The purpose of this program is to simulate a game of craps using functions
***************************************************************/

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <tgmath.h>

using namespace std;

// defining symbolic constants for the auto-lose craps
#define CRAPS_ONE     2
#define CRAPS_TWO     3
#define CRAPS_THREE  12

/**
 * Rolls two 'dice' and displays what the rolls are and the sum
 * @return sum of two dice rolls
 */
int rollTheDice() {
    // roll the two die and get the total
    int roll1 = 1 + (rand() % 6);
    int roll2 = 1 + (rand() % 6);
    int total = roll1 + roll2;
    
    // print the rolls and the total and return the total
    printf("\nRoll: %d + %d = %d", roll1, roll2, total);
    return total;
}

/**
 * Determines if the game of craps was immediately won on the come-out roll
 * @param roll the come-out dice roll
 * @return a boolean value depending on if the game was won
 */
bool winner(int roll) {
    // check for the initial win conditions
    if (roll == 7 || roll == 11) {
        printf("\n\nWinner! Winner! Congratulations!\n");
        return true;
    }
    return false;
}

/**
 * Determines if the game of craps was immediately lost on the come-out roll.
 * @param roll the come-out dice roll
 * @return a boolean value depending on if the game was lost
 */
bool craps(int roll) {
    // check for the initial lose condition
    if (roll == CRAPS_ONE || roll == CRAPS_TWO || roll == CRAPS_THREE) {
        printf("\nCraps! You Lose!\n");
        return true;
    }
    return false;
}

/**
 * Continues the game of craps until it is won or lost
 * @param point the point
 * @param wager the amount that the user has wagered
 */
void rollMore(int point, double wager) {
    //print the point for this game
    printf("\n\nThe point is %d\n", point);
    
    // loop and continue rolling until the game is either lost on 7 or won on the point.
    bool cont = true;
    do {
        int roll = rollTheDice();
        if (roll == point) {
            cont = false;
            printf("\n\nWinner! Winner! Congratulations!\n");
            printf("You won $%.2f\n", (wager * 2));
        } else if (roll == 7) {
            cont = false;
            printf("\n\nSeven'd Out! You Lose!\n");
            printf("You lost $%.2f\n", wager);
        }
    } while (cont);
}

/**
 * gets the player's wager amount and makes sure that it's a valid amount
 * @return a valid wager amount
 */
double getWager() {
    // get input for the wager
    double wager;
    printf("What's your wager (no cents allowed) (minimum 5.00)? ");
    scanf("%lf", &wager);
    
    // remove any extra cents on the wager
    double toReturn = floor(wager);
    double change = wager - toReturn;
    
    // loop until a valid wager is entered
    while (toReturn < 5.00) {
        printf("You can't bet $%.2f. The minimum bet is 5.00. Please try again: ", wager);
        scanf("%lf", &wager);
        toReturn = floor(wager);
        change = wager - toReturn;
    }
    
    // if there was any change, give it back and round down the wager.
    if (change > 0) {
        printf("You can have $%.2f back. The wager cannot have cents. Your wager is now $%.2f\n", change, toReturn);
    }
    
    //return the valid wager
    return toReturn;
}

/**
 * main function logic, controls the game play of the craps game
 */
int main(int argc, const char * argv[]) {
    // seed the random number generator
    srand(34);
    
    // get the first wager and roll
    double wager = getWager();
    int roll = rollTheDice();
    
    //check to see if they won/lost immediately or need to continue playing until a win/loss
    if (winner(roll)) {
        printf("You won $%.2f\n", (wager * 2));
    } else if (craps(roll)) {
        printf("You lost $%.2f\n", wager);
    } else {
        rollMore(roll, wager);
    }
    
    return 0;
}
