/***************************************************************
 CSCI 240         Program 7     Fall 2020
 @author Alexander Kashyap
 @file main.cpp
 @version 1.0
 Section: N/A
 Date Due: N/A
 Purpose:  A program that will calculate the quiz average for a student in the CSCI 240 course.
***************************************************************/

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;

//symbolic constant to represent the maximum size of the array
#define MAX_SIZE 12

/**
 Fill the array with the quiz scores.
 @param quizArray array of integers that will hold the quiz scores
 @return number of quiz scores that were read
 */
int buildQuizArray( int quizArray[] ) {
    //input file stream and opening the file
    ifstream infile;
    infile.open("quizscores.txt");
    
    //if the file doesnt open correctly exit
    if (infile.fail()) {
       cout << "The quizscores.txt input file did not open";
       exit(-1);
    }
    
    //loop through the file and populate the array with the quiz scores
    int index = 0;
    int score;
    infile >> score;
    while (infile && index < MAX_SIZE) {
        quizArray[index] = score;
        index++;
        infile >> score;
    }
    
    //close the file and return how many quizes in the array
    infile.close();
    return index;
}

/**
 display the information for the quizzes that have been completed
 @param title title for the report that is being displayed
 @param quizArray array of integers that holds the quiz scores
 @param numberOfQuizzes integer that holds the number of quiz scores in the array
 */
void printQuizArray( string title, int quizArray[], int numberOfQuizzes ) {
    //print out the title
    cout << title << endl;
    cout << "----------------" << endl;
    //print out each quiz and its score / 10
    for (int i = 0; i < numberOfQuizzes; i++) {
        cout << "Quiz " << right << setw(3) << (i+1) << right << setw(10) << quizArray[i] << "/10" << endl;
    }
}

/**
 Sort the quiz scores in accending order
 @param array array of integers that holds the quiz scores
 @param numberOfQuizzes integer that holds the number of quiz scores in the array
 */
void sortArray( int array[], int numberOfQuizzes ) {
    // using selection sort
    // loop through each number of quizes
    for (int i = 0; i < numberOfQuizzes; i++) {
        
        //find the smallest value to the right of the current value
        int min = i;
        for (int j = i + 1; j < numberOfQuizzes; j++) {
            if (array[j] < array[min]) {
                min = j;
            }
        }
        
        //swap the current value with the smallest value to the right
        int temp = array[min];
        array[min] = array[i];
        array[i] = temp;
    }
}

/**
 copy a specific number of values from one array into another array.
 @param destination array of integers that values will be copied into
 @param source array of integers that values will be copied from
 @param numberOfValues number of values to be copied
 */
void copyArray( int destination[], int source[], int numberOfValues ) {
    //loop through the number of values and copy over the information from one array at an index to the other
    for (int i = 0; i < numberOfValues; i++) {
        destination[i] = source[i];
    }
}

/**
 calculate a student's quiz average
 @param quizArray array of integers that holds the quiz scores
 @param numberOfQuizzes integer that holds the number of quiz scores in the array
 @return the calculated quiz average
 */
double calcQuizAverage( int quizArray[], int numberOfQuizzes ) {
    //initialize a total score variable and a toReurn average
    double total = 0.0;
    double toReturn = 0.0;
    //create a copy of the quiz array and sort it
    int sorted[MAX_SIZE];
    copyArray(sorted, quizArray, numberOfQuizzes);
    sortArray(sorted, numberOfQuizzes);
    
    //get the sum of all of the quizes taken
    for (int i = 0; i < numberOfQuizzes; i++) {
        total += quizArray[i];
    }
    
    //computing the average of the quizes
    if (numberOfQuizzes > 2) {
        //drop the two lowest scores (gotten from sorted array)
        toReturn = (total - (sorted[0] + sorted[1])) / (10 * (numberOfQuizzes - 2)) * 100;
    } else {
        toReturn = total / (10 * numberOfQuizzes) * 100;
    }
    return toReturn;
}

int main(int argc, const char * argv[]) {
    //create the quiz array with max size 12
    int quizArray[MAX_SIZE];
    int size = buildQuizArray(quizArray);
    
    //calculate the quiz average
    double avg = calcQuizAverage(quizArray, size);
    
    //print out the quiz average and all of the quiz scores
    cout << "\nYour quiz average is " << fixed << setprecision(2) << avg << "%\n" << endl;
    printQuizArray("Quiz Scores", quizArray, size);
    
    return 0;
}
