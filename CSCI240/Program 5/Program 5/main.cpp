/***************************************************************
 CSCI 240         Program 5     Fall 2020
 @author Alexander Kashyap
 @file main.cpp
 @version 1.0
 Section: N/A
 Date Due: N/A
 Purpose:  a program that will calculate how much a person would earn over a finite (random) period of time if their salary is a random amount for the first day and continues to double each day for three different jobs.
***************************************************************/

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>

using namespace std;

#define MAX_DAYS 30
#define MAX_SAL 10

int main(int argc, const char * argv[]) {
    // seed the random number generator
    srand(15);
    
    /*
     Job 1 For Loop
     */
    
    cout << "\n********     Job 1     ********" << endl;
    
    //Start by randomly generating the salaray and the days worked and creating accumulators for the salary info
    double salary = (1 + (rand() % MAX_SAL)) / 100.0;
    double daily_sal = salary;
    double tot_sal = salary;
    int days_worked = 1 + (rand() % MAX_DAYS);
    
    //Display the salary and days worked info, as well as set up the columns for Daily Salary and Amount Earned
    cout << "\nStarting Salary: $ " << fixed << setprecision(2) << salary << endl;
    cout << "Number of days to work: " << days_worked << "\n\n";
    cout << "\n              Daily Salary     Amount Earned" << endl;
    
    //loop for each day worked and display the daily salary and the total amount earned
    for (int i = 1; i <= days_worked; i++) {
        cout << "Day " << right << setw(2) << i << ": " << right << setw(15) << daily_sal << right << setw(17) << tot_sal << endl;
        daily_sal += daily_sal;
        tot_sal += daily_sal;
    }
    
    //Print the info for that particular day
    cout << "\nFor Job 1, you earned $" << fixed << setprecision(2) << (daily_sal - salary) << " in " << days_worked << " day(s)." << endl;
    
    // Set the first references to the highest and lowest paying job to be the first one.
    int highest_job = 1;
    int lowest_job = 1;
    double highest_sal = tot_sal - daily_sal;
    double lowest_sal = tot_sal - daily_sal;
    
    
    /*
     Job 2 While Loop
     */
    
    cout << "\n\n********     Job 2     ********" << endl;
    
    //Start by randomly generating the salaray and the days worked and creating accumulators for the salary info. Also, creater a counter for the loop
    salary = (1 + (rand() % MAX_SAL)) / 100.0;
    days_worked = 1 + (rand() % MAX_DAYS);
    daily_sal = salary;
    tot_sal = salary;
    int count = 0;
    
    //Display the salary and days worked info, as well as set up the columns for Daily Salary and Amount Earned
    cout << "\nStarting Salary: $ " << fixed << setprecision(2) << salary << endl;
    cout << "Number of days to work: " << days_worked << endl;
    cout << "\n              Daily Salary     Amount Earned" << endl;
    
    //loop for each day worked and display the daily salary and the total amount earned
    while (count < days_worked) {
        count++;
        cout << "Day " << right << setw(2) << count << ": " << right << setw(15) << daily_sal << right << setw(17) << tot_sal << endl;
        daily_sal += daily_sal;
        tot_sal += daily_sal;
    }
    
    //Print the info for that particular day
    cout << "\nFor Job 2, you earned $" << fixed << setprecision(2) << (daily_sal - salary) << " in " << days_worked << " day(s)." << endl;
    
    //use conditionals to check and see if this job would be the new highest or lowest payign job of the 3
    if ((tot_sal - daily_sal) > highest_sal) {
        highest_sal = tot_sal - daily_sal;
        highest_job = 2;
    } else if ((tot_sal - daily_sal) < lowest_sal) {
        lowest_sal = tot_sal - daily_sal;
        lowest_job = 2;
    }
    
    
    /*
     Job 3 Do-While Loop
     */
    
    cout << "\n\n********     Job 3     ********" << endl;
    
    //Start by randomly generating the salaray and the days worked and creating accumulators for the salary info. Also, creater a counter for the loop
    salary = (1 + (rand() % MAX_SAL)) / 100.0;
    days_worked = 1 + (rand() % MAX_DAYS);
    daily_sal = salary;
    tot_sal = salary;
    count = 0;
    
    //Display the salary and days worked info, as well as set up the columns for Daily Salary and Amount Earned
    cout << "\nStarting Salary: $ " << fixed << setprecision(2) << salary << endl;
    cout << "Number of days to work: " << days_worked << endl;
    cout << "\n              Daily Salary     Amount Earned" << endl;
    
    //loop for each day worked and display the daily salary and the total amount earned
    do {
        count++;
        cout << "Day " << right << setw(2) << count << ": " << right << setw(15) << daily_sal << right << setw(17) << tot_sal << endl;
        daily_sal += daily_sal;
        tot_sal += daily_sal;
    } while (count < days_worked);
    
    //Print the info for that particular day
    cout << "\nFor Job 3, you earned $" << fixed << setprecision(2) << (daily_sal - salary) << " in " << days_worked << " day(s)." << endl;
    
    //use conditionals to check and see if this job would be the new highest or lowest payign job of the 3
    if ((tot_sal - daily_sal) > highest_sal) {
        highest_sal = tot_sal - daily_sal;
        highest_job = 3;
    } else if ((tot_sal - daily_sal) < lowest_sal) {
        lowest_sal = tot_sal - daily_sal;
        lowest_job = 3;
    }
    
    //Printing the highest and lowest paying jobs
    cout << "\n\n\nThe highest paying job was job " << highest_job << " paying $" << fixed << setprecision(2) << highest_sal << endl;
    cout << "\nThe lowest paying job was job " << lowest_job << " paying $" << fixed << setprecision(2) << lowest_sal << endl;

    return 0;
}
