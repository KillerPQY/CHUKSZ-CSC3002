/*
 * File: GymJudge.cpp
 * ------------------
 * This program averages a set of gymnastic scores after eliminating
 * the lowest and highest scores.
 */

#include <iostream>
#include <iomanip>
#include <string>
#include "error.h"
#include "simpio.h"
#include "strlib.h"
#include "console.h"
using namespace std;

/* Constants */

const int MAX_JUDGES = 100;
const double MIN_SCORE =  0.0;
const double MAX_SCORE = 10.0;

/* Function prototypes */

double sumArray(double array[], int n);
double findLargest(double scores[], int n);
double findSmallest(double scores[], int n);
int readScores(double scores[], int max);

/* Test program */

int P1_test() {
   double scores[MAX_JUDGES];
   int nJudges = readScores(scores, MAX_JUDGES);
   if (nJudges < 3) {
      cout << "You must enter scores for at least three judges." << endl;
   } else {
      double total = sumArray(scores, nJudges);
      double smallest = findSmallest(scores, nJudges);
      double largest = findLargest(scores, nJudges);
      double average = (total - smallest - largest) / (nJudges - 2);
      cout << "The average after eliminating "
           << fixed << setprecision(2) << smallest << " and "
           << setprecision(2) << largest << " is "
           << setprecision(2) << average << "." << endl;
   }
   return 0;
}

/*
 * Function: sumArray
 * Usage: double sum = sumArray(array, n);
 * ---------------------------------------
 * This function returns the sum of the first n elements in array.
 */

double sumArray(double array[], int n) {

    //TODO
    // Use try-catch to prevent n from going out of range.
    try {
        double result = 0;
        for (int i = n - 1; i >= 0; i--) {
            // Check if each score is out of range
            if (array[i] > MAX_SCORE || array[i] < MIN_SCORE) {
                error("The score shouble be between 0.0 and 10.0");
            }
            // Accumulation.
            result += array[i];
        }
        return result;
    }  catch (int n) {
        error("n should bigger than 0, and cann't exceed the number of elements in the array");
    }
}

/*
 * Function: findLargest
 * Usage: double largest = findLargest(array, n);
 * ----------------------------------------------
 * This function returns the largest value in the first n elements in array.
 */

double findLargest(double array[], int n) {

    //TODO
    // Use try-catch to prevent n from going out of range.
    try {
        double maxele = array[n - 1];
        // Check if array[n - 1] is out of range
        if (maxele > MAX_SCORE || maxele < MIN_SCORE) {
            error("The score shouble be between 0.0 and 10.0");
        }
        for (int i = n - 2; i >= 0; i--) {
            // Check if each score is out of range
            if (array[i] > MAX_SCORE || array[i] < MIN_SCORE) {
                error("The score shouble be between 0.0 and 10.0");
            }
            // Refresh maximum
            if (array[i] > maxele) {
                maxele = array[i];
            }
        }
        return maxele;
    }  catch (int n) {
        error("n should bigger than 0, and cann't exceed the number of elements in the array");
    }
}

/*
 * Function: findSmallest
 * Usage: double smallest = findSmallest(array, n);
 * ------------------------------------------------
 * This function returns the smallest value in the first n elements in array.
 */

double findSmallest(double array[], int n) {

    //TODO
    // Use try-catch to prevent n from going out of range.
    try {
        double minele = array[n - 1];
        // Check if array[n - 1] is out of range
        if (minele > MAX_SCORE || minele < MIN_SCORE) {
            error("The score shouble be between 0.0 and 10.0");
        }
        for (int i = n - 2; i >= 0; i--) {
            // Check if each score is out of range
            if (array[i] > MAX_SCORE || array[i] < MIN_SCORE) {
                error("The score shouble be between 0.0 and 10.0");
            }
            // Refresh minimum
            if (array[i] < minele) {
                minele = array[i];
            }
        }
        return minele;
    }  catch (int n) {
        error("n should bigger than 0, and cann't exceed the number of elements in the array");
    }
}

/*
 * Function: readScores
 * Usage: int nJudges = readScores(scores, max);
 * ---------------------------------------------
 * This function reads in scores for each of the judges.  The array
 * scores must be declared by the caller and must have an allocated
 * size of max.  The return value is the number of scores.  From the
 * user's perspective, the numbering of the judges begins with 1
 * because that style of numbering is more familiar; internally,
 * the array index values begin with 0.
 */

int readScores(double scores[], int max) {
   cout << "Enter a score for each judge in the range " << MIN_SCORE;
   cout << " to " << MAX_SCORE << "." << endl;
   cout << "Enter a blank line to signal the end of the list." << endl;
   int n = 0;
   while (n < max) {
      string line = getLine("Judge #" + integerToString(n + 1) + ": ");
      if (line == "") return n;
      double score = stringToReal(line);
      if (MIN_SCORE <= score && score <= MAX_SCORE) {
         scores[n++] = score;
      } else {
         cout << "That score is out of range." << endl;
      }
   }
   return max;
}
