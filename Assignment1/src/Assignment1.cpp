/*
 * File: Assignment1.cpp
 * ----------------------
 * call for each function (of each problem) that you have finished 
 * please do not modify the main function
 */

#include <iostream>
#include <fstream>
#include "console.h"
#include "Assignment1.h"
using namespace std;

int main() {
    cout<<"Problem 1:"<<endl;
    TestCombinatorics();
    cout<<"Problem 2:"<<endl;
    TestFindDNAMatch();
    cout<<"Problem 3:"<<endl;
    TestRemoveComments();
    cout<<"Problem 4:"<<endl;
    TestBanishLetters();
    return 0;
}


/* 
 * Below is the testing part, 
 * you can use it for your testing
 * but do not delete it
 */

int TestCombinatorics() {
    /* TODO */
    /* You can test your implemented function here*/
    cout << "permutations(6, 3): " << permutations(6, 3) << endl;
    cout << "combinations(6, 3): " << combinations(6, 3) << endl;
    return 0;
}


int TestFindDNAMatch() {
    /* TODO */
    /* You can test your implemented function here */
    cout << "findDNAMatch(string \"AG\", string \"AGTCTC\", int start = 0): " << findDNAMatch("AG", "AGTCTC") << endl;
    cout << "matchingStrand(string \"AGTCTC\"): " << matchingStrand("AGTCTC") << endl;
    cout << "findAllMatches(string \"AG\", string \"AGTCTC\"): " << endl;
    findAllMatches("AG", "AGTCTC");
    return 0;
}


int TestRemoveComments() {
    /* TODO */
    /* You can test your implemented function here */
    cout << "removeComments(istream& \"hello.cpp\", ostream& cout): " << endl;
    ifstream hello("hello.cpp");
    removeComments(hello, cout);
    return 0;
}

int TestBanishLetters() {
    /* TODO */
    /* You can test your implemented function here */
    cout << "int BanishLetters(): " << endl;
    BanishLetters();
    cout << "You can find the file in \"build-Ass1-Desktop_Qt_5_12_11_MinGW_64_bit-Debug\".";
    return 0;
}
