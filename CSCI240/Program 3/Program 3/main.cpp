//
//  main.cpp
//  Program 3
//
//  Created by Alexander Kashyap on 12/3/20.
//

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    /*
     init variables
     int tot_score - the running total of how many scores the team has made
     int tot_attempt - the running total of how many attempts the team has made
     int scored - how many scores for that particular game
     int attempted - how many attempts for that particular game
     int n - number of games
     
     double shooting - the combined shooting percentage
     
     string more_data - the "y" or "n" varible that controls the loop
     */
    int tot_score, tot_attempt, scored, attempted;
    int n = 0;
    double shooting, first_shooting;
    string more_data;
    
    // do-while loop to ask about game once no matter what
    do {
        // update the numner of games
        n++;
        
        // ask the user the number of goals, check to make sure it is >= 0, and update the running total.
        cout << "Enter the number of goals that were scored: ";
        cin >> scored;
        while (scored < 0) {
            cout << "Error: the number of goals must be greater than 0. Try again: ";
            cin >> scored;
        }
        tot_score += scored;
        
        // ask the user the number of attempts, check to make sure it is >= 0, and update the running total.
        cout << "\nEnter the number of goals that were attempted: ";
        cin >> attempted;
        while (attempted < 0) {
            cout << "Error: the number of shot attempts must be greater than 0. Try again: ";
            cin >> attempted;
        }
        tot_attempt += attempted;
        
        // if it is the first game, save the first shooting percentage for the last comparison
        if (n == 1) {
            first_shooting = (100.0 * scored) / attempted;
        }
        // calculate the running shooting percentage and print it out
        shooting = (100.0 * tot_score) / tot_attempt;
        cout << "\nThe Team shooting percentage after " << fixed << setprecision(1) << n << " games(s) is " << shooting << "\n";
        
        //ask the user if they want to add more data, if the user replies with y, then we ask the whole series of questions again
        cout << "\n\nIs there more data? (y or n): ";
        cin >> more_data;
        cout << "\n";
    } while (more_data == "y");
    
    // finally, print the change in shooting percentage from the first game
    double change_in_shooting = shooting - first_shooting;
    cout << "The change in Team shooting percentage after " << n << " game(s) is " << fixed << setprecision(1) << change_in_shooting << "%\n";
    
    return 0;
}
