//
//  main.cpp
//  Program 2
//
//  Created by Alexander Kashyap on 12/3/20.
//

#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, const char * argv[]) {
    /*
     int scored - how many goals were scored
     int shot - how many shots in total
     */
    int scored, shot;
    
    // ask how many goals were scored and check if it is greater than 0.
    cout << "Enter the number of goals that were scored: ";
    cin >> scored;
    if (scored <= 0) {
        cout << "\nError the number of goals must be greater than 0. Try again: ";
        cin >> scored;
    }
    
    // ask how many goals were attempted and check if it is greater than 0.
    cout << "\nEnter the number of goals that were attempted: ";
    cin >> shot;
    if (shot <= 0) {
        cout << "\nError the number of shot attempts must be greater than 0. Try again: ";
        cin >> shot;
    }
    
    // calculate the shooting percentage.
    double shooting = (100.0 * scored) / shot;
    
    // print what the shooting percentage is with one decimal place.
    cout << "\nThe Shooting Percentage is " << fixed << setprecision(1) << shooting << "\n";
    return 0;
}
