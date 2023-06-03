/*
 * File: BanishLetters.cpp
 * -----------------------
 * This file implements the BanishLetters.h interface
 */

/* Function definition */

/*TODO*/
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int BanishLetters()
{
    string infile;
    string outfile;
    string ban;
    cout << "Input file: ";  // let user input ifstream's name
    cin >> infile;
    cout << "Output file: ";  // let user input ofstream's name
    cin >> outfile;
    cout << "Letters to banish: ";  // let user input letters to ban
    cin >> ban;
    ifstream is;  // define a variable to store ifstream
    ofstream os;  // define a variable to store ofstream
    is.open(infile, ios::in);
    os.open(outfile, ios::out);
    /* define variables to store the contents of a line whose
    comments had been removed and to store the contents of a line read */
    string line, ans;
    int l, banl;
    bool flag = 1;  // define a flag to determine whether find letters to ban
    banl = ban.size();
    // read the istream line by line through the while loop
    while (is)
    {
        line = "";  // reset line variable
        ans = "";  // reset ans variable
        getline(is, line);
        l = line.size();
        for (int i = 0; i < l; ++i)
        {
            flag = 1;  // reset flag
            for (int j = 0; j < banl; ++j)
            {
                // if find letters to ban, set flag = 0
                if (line[i] == toupper(ban[j]) || line[i] == tolower(ban[j]))
                {
                    flag = 0;
                    break;
                }
            }
            // if flag = 1, store it into ans
            if (flag == 1)
            {
                ans += line[i];
            }
        }
        os << ans << endl;  // flow ans into ostream
    }
    return 0;
}

