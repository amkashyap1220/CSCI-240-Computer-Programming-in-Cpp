/***************************************************************
 CSCI 240         Program 10     Fall 2020
 @author Alexander Kashyap
 @file main.cpp
 @version 1.0
 Section: N/A
 Date Due: N/A
 Purpose:  the simplified version of the game Twenty-One
***************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>

using namespace std;

//Card class
class Card {
    //data members
    int face;
    char suit[9];
    
    //public methods
public:
    Card();
    void setCard(int newFace, const char newSuit[]);
    int getFace();
    const char* getSuit();
    void displayCard();
};

//DeckofCards Class
class DeckOfCards
{
    //public methods
public:
    DeckOfCards();
    Card draw();
    void shuffle();
    bool isEmpty();

    //private methods and data members
private:
    static const int MAX_CARDS = 52;       //Maximum number of cards in a deck
    static const int NUM_SUITS = 4;        //Number of card suits
    static const int CARDS_PER_SUIT = 13;  //Number of cards of each suit

    Card deck[MAX_CARDS];     //The deck of cards
    int topCard;              //The subscript of the card on the top of the deck
};


int main()
{
    //Set the seed value for the random number generator
    srand(0);

    //create the instance of the deck
    DeckOfCards deck = DeckOfCards();
    
    //initialize turn variables
    int current_player = 1, sum, points_this_turn, p1_score = 0, p2_score = 0;
    
    //while there  are still cards left in the deck... continue the game
    while (!deck.isEmpty()) {
        //display the current player
        cout << "Player " << current_player << ": " << endl;
        sum = 0;
        
        //turn logic
        //player gets to draw up to 3 cards as long as their sum is less than 21 and the deck is not empty
        int count = 0;
        while (sum < 21 and !deck.isEmpty() and count < 3) {
            count++;
            
            //draw and display the card
            Card draw = deck.draw();
            draw.displayCard();
            
            //update the the current players sum
            if (draw.getFace() == 1) {
                sum += 11;
            } else if (draw.getFace() >= 11) {
                sum += 10;
            } else {
                sum += draw.getFace();
            }
            cout << "\tTotal: " << sum << endl;
        }
        
        //displaying the end result of the turn
        if (sum > 21) {
            cout << "\nSorry player " << current_player << " -- Busted!" << endl;
            points_this_turn = 0;
        } else if (sum < 21) {
            cout << "\nCongratulations player " << current_player << "! 10 points awarded!" << endl;
            points_this_turn = 10;
        } else {
            cout << "\nCongratulations player " << current_player << "! 15 points awarded!" << endl;
            points_this_turn = 15;
        }
        cout << "-------------------\n" << endl;
        
        //at the end of a turn add points and switch players
        if (current_player == 1) {
            p1_score += points_this_turn;
            current_player = 2;
        } else {
            p2_score += points_this_turn;
            current_player = 1;
        }
        
    }
    
    //at the end of the game display the point totals and the winner
    cout << "\nPlayer 1 score: " << p1_score << endl;
    cout << "Player 2 score: " << p2_score << endl;
    p1_score > p2_score ? cout << "\nPlayer 1 won!" << endl : cout << "\nPlayer 2 won!" << endl;
    
    return 0;
}

/**
 Default contructor for Card
 */
Card::Card() {
    //generate a card
    face = 1 + (rand() % 13);
    int s = 1 + (rand() % 4);
    
    //use strcpy to copt over the name of the suit
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
void Card::setCard(int newFace, const char newSuit[]) {
    //set the new face value of the card (check bounds)
    face = (newFace > 0 and newFace < 14) ? newFace : 1;
    
    //(ugly) set the new value of the suit (check if valid)
    (strcmp(newSuit, "Clubs") == 0 or
     strcmp(newSuit, "Diamonds") == 0 or
     strcmp(newSuit, "Hearts") == 0 or
     strcmp(newSuit, "Spades") == 0)
    ? strcpy(suit, newSuit) : strcpy(suit, "Hearts");
}

/**
 returns the face value of the Card
 @return value of the Card
 */
int Card::getFace() {
    return face;
}

/**
 returns the suit value of the Card
 @return a pointer to a constant character array (the suit)
 */
const char* Card::getSuit() {
    return suit;
}

/**
 displays a text version of the Card
 */
void Card::displayCard() {
    string cards[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    cout << cards[face - 1] << " of " << suit;
}

/***************************************************************
Constructor

Use: This creates a DeckOfCards object and then shuffles the
     cards

Arguments: none

Note: -1 is used to signal that no cards have been removed from
      the deck
***************************************************************/
DeckOfCards::DeckOfCards()
{
    //An array of the 4 possible values for the card suits
    const char suitVals[NUM_SUITS][9] = { "Clubs", "Diamonds", "Hearts", "Spades" };

    int cardSub = 0;    //subscript to process the deck of cards

    //Go through all 52 spots in the array of Cards and put a card
    //at the location

    for( int suitSub = 0; suitSub < NUM_SUITS; suitSub++ )
      {
      //For each of the suits, put in all of the cards for the suit
      for( int faceVal = 1; faceVal <= CARDS_PER_SUIT; faceVal++ )
        {
        //Put the card into the deck
        deck[ cardSub ].setCard( faceVal, suitVals[suitSub] );

        //Move to the next card in the deck
        cardSub++;
        }
      }

    //shuffle the playing cards
    shuffle();

    //Set the top card location to -1 to indicate the deck is brand new
    topCard = -1;
}



/***************************************************************
Method:  Card draw()

Use: This method draws a card from the top of the deck

Arguments: none

Returns: a Card object (the card on the top of the deck)
***************************************************************/

Card DeckOfCards::draw()
{
    //Increment to get the subscript of the current top card
    topCard++;

    //return the card that is currently on the top of the deck
    return deck[topCard];
}



/***************************************************************
Method:  void shuffle()

Use: This method shuffles the deck of cards

Arguments: none

Returns: nothing

Note: this method uses the random_shuffle function that is part
      of the algorithm library to shuffle the 52 cards
***************************************************************/

void DeckOfCards::shuffle()
{
    //Shuffle all 52 cards that are in the deck
    random_shuffle(deck, deck+MAX_CARDS);
}


/***************************************************************
Method:  bool isEmpty()

Use: This method determines if the deck of cards is empty( have
     all of the cards been drawn)

Arguments: none

Returns: boolean value: true if all of the cards have been drawn
                        false if there are still cards in the deck
***************************************************************/

bool DeckOfCards::isEmpty()
{
    //if topCard subscript plus 1 is greater than 52, the deck is
    //empty. Otherwise, there are cards that can be drawn.

    return topCard + 1 >= MAX_CARDS;
}
