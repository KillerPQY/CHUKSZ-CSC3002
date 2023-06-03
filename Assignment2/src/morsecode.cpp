/*
 * File: morsecode.cpp
 * -------------------
 * This file implements the morsecode.h interface.
 * You need "#include" the proper header file and write the function definition.
 */

// TODO
#include <iostream>
#include <string>
#include "tokenscanner.h"
#include "map.h"
using namespace std;
/*
 * Function: createMorseCodeMap
 * Usage: Map<string> map = createMorseCodeMap();
 * ----------------------------------------------
 * Returns a map in which each uppercase letter is mapped into its
 * Morse code equivalent.
 */

// Create letter-morse map.
Map<string,string> createMorseCodeMap() {
   Map<string,string> map;
   map["A"] = ".-";
   map["B"] = "-...";
   map["C"] = "-.-.";
   map["D"] = "-..";
   map["E"] = ".";
   map["F"] = "..-.";
   map["G"] = "--.";
   map["H"] = "....";
   map["I"] = "..";
   map["J"] = ".---";
   map["K"] = "-.-";
   map["L"] = ".-..";
   map["M"] = "--";
   map["N"] = "-.";
   map["O"] = "---";
   map["P"] = ".--.";
   map["Q"] = "--.-";
   map["R"] = ".-.";
   map["S"] = "...";
   map["T"] = "-";
   map["U"] = "..-";
   map["V"] = "...-";
   map["W"] = ".--";
   map["X"] = "-..-";
   map["Y"] = "-.--";
   map["Z"] = "--..";
   return map;
}


//TODO
Map<string, string> invertMap(const Map<string, string> & map)
{
    Map<string, string> invertmap;
    // Use rang-for loop to go through letter-morse map.
    for (const string & key1: map)
    {
        // Invert key and value to get morse-letter map.
        string value = map.get(key1);
        // Check whether there are two keys in the original map have the same value or not.
        for (const string & key2: invertmap)
        {
            if (value == key2)
            {
                cout << "Exists two keys in the original map have the same value." << endl;
                throw map;
            }
        }
        invertmap.put(value, key1);
    }
    return invertmap;
}

// Create the global maps to use.
const Map<std::string,std::string> LETTERS_TO_MORSE = createMorseCodeMap();
const Map<std::string,std::string> MORSE_TO_LETTERS = invertMap(LETTERS_TO_MORSE);

string translateLettersToMorse(std::string line)
{
    string result = ""; // To store result.
    for (int i = 0; i < line.size(); ++i)
    {
        string s(1, line[i]);  // Convert char to string.
        if (s == " ")  // Meeeting space, so print a space.
        {
            result += s;
        }
        else if (isupper(s[0]))  // According to letter-morse map, find morse.
        {
            result += LETTERS_TO_MORSE.get(s);
        }
    }
    return result;
}

string translateMorseToLetters(std::string line)
{
    string result = "";
    string temp;
    TokenScanner scanner;
    scanner.ignoreWhitespace();  // Let scanner ignore whichspace
    scanner.addWordCharacters("-.");  // Add "-" and "." into scanning sequence.
    scanner.setInput(line);
    while (scanner.hasMoreTokens())
       {
        temp = scanner.nextToken();
        // If the sequence is valid morse, get letter and add it into result.
        if (MORSE_TO_LETTERS.containsKey(temp))
           {
            result += MORSE_TO_LETTERS.get(temp);
           }
       }
    return result;
}
