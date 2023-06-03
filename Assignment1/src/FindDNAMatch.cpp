/*
 * File: FindDNAMatch.cpp
 * ----------------------
 * This file implements the FindDNAMatch.h interface.
 */

 /* Function definition */

 /*TODO*/
#include<iostream>
using namespace std;

int findDNAMatch(string s1, string s2, int start = 0)
{
    string temp;  // define a variable to store the matching DNA sequence of s1
    int pos;  // define a variable to store answer
    // according to A-T, C-G, find the matching DNA sequence of s1
    int n = s1.size();
    for (int i = 0; i < n; ++i)
    {
        if (s1[i] == 'A')
            temp.push_back('T');
        else if (s1[i] == 'G')
            temp.push_back('C');
        else if (s1[i] == 'C')
            temp.push_back('G');
        else if (s1[i] == 'T')
            temp.push_back('A');
        // detect if the s1 DNA sequence makes sense
        else
        {
            cout << "The DNA sequence can only has A, G , C, T letters." << endl;
            throw s1;
        }
    }
    // detect if the s2 DNA sequence makes sense
    for (int j = 0; j < n; ++j)
    {
        if (s2[j] != 'A' && s2[j] != 'G' && s2[j] != 'C' && s2[j] != 'T')
        {
            cout << "The DNA sequence can only has A, G , C, T letters." << endl;
            throw s2;
        }
    }
    pos = s2.find(temp, start);  // find the first position of the matching DNA sequence of s1 in s2
    return pos;
}

string matchingStrand(string strand)
{
    string ans;  // define a variable to store answer
    // according to A-T, C-G, other-X, find the matching DNA sequence of the strand
    int n = strand.size();
    for (int i = 0; i < n; ++i)
    {
        if (strand[i] == 'A')
            ans.push_back('T');
        else if (strand[i] == 'G')
            ans.push_back('C');
        else if (strand[i] == 'C')
            ans.push_back('G');
        else if (strand[i] == 'T')
            ans.push_back('A');
        else
            ans.push_back('X');
    }
    return ans;
}

void findAllMatches(string s1, string s2)
{
    string temp = matchingStrand(s1);  // find the matching DNA sequence of s1
    // detect if the s1 DNA sequence makes sense
    if (temp.find('X') != -1)
    {
        cout << "The DNA sequence can only has A, G , C, T letters." << endl;
        throw s1;
    }
    // detect if the s2 DNA sequence makes sense
    int n = s2.size();
    for (int i = 0; i < n; ++i)
    {
        if (s2[i] != 'A' && s2[i] != 'G' && s2[i] != 'C' && s2[i] != 'T')
        {
            cout << "The DNA sequence can only has A, G , C, T letters." << endl;
            throw s2;
        }
    }
    // find the first position of the matching DNA sequence of s1 in s2
    int pos = s2.find(temp);
    if (pos == -1)  // if it can't find, cout s1 can't bind to s2
        cout << s1 << " can't bind to " << s2 << endl;
    else  // if it can find, use a while loop to find the first position index of all the matching DNA sequence that can be bound
    {
        while (pos != -1)
        {
            cout << pos << endl;
            pos = s2.find(temp, pos + 1);  // the next time search begins with the next index
        }
    }

}
