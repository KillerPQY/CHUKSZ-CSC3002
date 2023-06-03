/*
 * File: Assignment.cpp
 * ----------------------
 * This file tests the Problem 1, 2 and 3.
 */

#include <iostream>
#include <cctype>
#include "strlib.h"
#include "simpio.h"
#include "calendar.h"
#include "reversequeue.h"
#include "morsecode.h"

//TODO

#include "console.h"
using namespace std;


int main() {
    /*******************Problem 1******************/
    /********************Part 1********************/
    /* a sample INPUT: 2012
     * The OUTPUT: Enter a year: 2012
     *             JANUARY has 31 days.
     *             FEBRUARY has 29 days.
     *             ...... //(You need print all of them)
     *             DECEMBER has 31 days.
     */

    //TODO
    int year;
    cout << "Enter a year: ";
    cin >> year;
    for (Month month = JANUARY; month <= 12; month++)
    {
        cout << monthToString(month) << " has " << daysInMonth(month, year) << " days." << endl;
    }
    /*******************Problem 1******************/
    /********************Part 2********************/
    /* Sample: Date moonLanding1(20, JULY, 1969);
     * OUTPUT: moonLanding1 = 20-Jul-1969
     * Sample: Date moonLanding2(JULY, 20, 1969);
     * OUTPUT: moonLanding2 = 20-Jul-1969
     */

     //TODO
     Date moonLanding1(20, JULY, 1969);
     Date moonLanding2(JULY, 20, 1969);
     cout << "moonLanding1 = " << moonLanding1 << endl;
     cout << "moonLanding2 = " << moonLanding2 << endl;
    /*******************Problem 1******************/
    /*******************For Part 3*****************/
    /* Sample: Date moonLanding(20, JULY, 1969);
     *         Date kennedyAssassination(NOVEMBER, 22, 1963);
     *         Date newYearsEve(DECEMBER, 31, 2011);
     *         Date inaugurationDay(21, JANUARY, 2013);
     *         Date electionDay(6, NOVEMBER, 2012);
     *
     * OUTPUT: moonLanding = 20-Jul-1969
     *         kennedyAssassination = 22-Nov-1963
     *         moonLanding < kennedyAssassination = false
     *         moonLanding > kennedyAssassination = true
     *         moonLanding == kennedyAssassination = false
     *         moonLanding == moonLanding = true
     *         inaugurationDay - electionDay = 76
     *         New Year's Eve = 31-Dec-2011
     *         New Year's Day = 1-Jan-2012
     *         6-Nov-2012 //Print days from election day to inauguration day.
     *         7-Nov-2012
     *         ...... //(You need print all of them)
     *         21-Jan-2013
     */

    //TODO
     Date moonLanding(20, JULY, 1969);
     Date kennedyAssassination(NOVEMBER, 22, 1963);
     Date newYearsEve(DECEMBER, 31, 2011);
     Date inaugurationDay(21, JANUARY, 2013);
     Date electionDay(6, NOVEMBER, 2012);
     cout << boolalpha;
     cout << "moonLanding = " << moonLanding << endl;
     cout << "kennedyAssassination = " << kennedyAssassination << endl;
     cout << "moonLanding < kennedyAssassination = " << (moonLanding < kennedyAssassination) << endl;
     cout << "moonLanding > kennedyAssassination = " << (moonLanding > kennedyAssassination) << endl;
     cout << "moonLanding == kennedyAssassination = " << (moonLanding == kennedyAssassination) << endl;
     cout << "moonLanding == moonLanding = " << (moonLanding == moonLanding) << endl;
     cout << "inaugurationDay - electionDay = " << inaugurationDay - electionDay << endl;
     cout << "New Year's Eve = " << newYearsEve << endl;
     cout << "New Year's Day = " << newYearsEve + 1 << endl;
     for (Date d = electionDay; d <= inaugurationDay; d++)
     {
         cout << d << endl;
     }
    /*********************Problem 2*******************/
    /* Using enqueue method to obtain a queue containing: Genesis Exodus Leviticus Numbers Deuteronomy
     * List the queue
     * Reverse the queue
     * List the queue
     * A sample OUTOUT: The queue contains: Genesis Exodus Leviticus Numbers Deuteronomy
     *                  The queue contains: Deuteronomy Numbers Leviticus Exodus Genesis
     */

    //TODO
    cout << "Problem 2: " << endl;
    Queue<string> q;
    q.enqueue("Genesi");
    q.enqueue("Exodus");
    q.enqueue("Leviticus");
    q.enqueue("Numbers");
    q.enqueue("Deuteronomy");
    listQueue(q);
    reverseQueue(q);
    listQueue(q);

    /*********************Problem 3*******************/
    cout << "Problem 3: " << endl;
    cout << "Morse code translator" << endl;
    /* A sample translator:
     *                     > SOS
     *                     ... --- ...
     *                     > ... --- ...
     *                     SOS
     */
    //TODO
    string ans;
    cin.ignore();
    while (true)
    {
       string line = trim(getLine("> "));
       if (line.length() == 0)
       {
           break;
       }
       else if (isupper(line[0]))
       {
           ans = translateLettersToMorse(line);
           cout << ans << endl;
       }
       else if (line[0] == '.' or line[0] == '-')
       {
           ans = translateMorseToLetters(line);
           cout << ans << endl;
       }
    }
    return 0;
}
