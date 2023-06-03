/*
 * File: RemoveComments.cpp
 * ------------------------
 * This file implements the RemoveComments.h interface.
 */


/* Function definition */

/*TODO*/
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

void removeComments(istream& is, ostream& os)
{
    string ans;  // define a variable to store the contents of a line whose comments had been removed
    string line;  // define a variable to store the contents of a line read
    bool single = 0;  // a flag whether find "//"
    bool muti = 0;  // a flag whether find "/*" and "*/"
    // read the istream line by line through the while loop
    while (is)
    {
        line = "";  // reset line variable
        getline(is, line);
        int l = line.size();
        ans = "";  // reset ans variable

        for (int i = 0; i < l; ++i)
        {
            // if i is't the last index and find "//", a single-line comment will be detected
            if (i < l - 1 && line[i] == '/' && line[i + 1] == '/')
            {
                single = 1;
                ++i;
            }
            // if i isn't the last index and find "/*", a mutiple-line comment will be detected
            else if (i < l - 1 && line[i] == '/' && line[i + 1] == '*')
            {
                muti = 1;
                ++i;
            }
            // if i isn't the last index and find "*/", a mutiple-line comment will be ended
            else if (i < l - 1 && muti == 1 && line[i] == '*' && line[i + 1] == '/')
            {
                muti = 0;
                ++i;
            }
            // if single-line comment and mutiple-line comment aren't found, store it into ans
            else if (single == 0 && muti == 0)
            {
                ans += line[i];
            }
        }
        single = 0;  // reset single-line comment flag
        os << ans;  // flow ans into ostream
        // if ans isn't empty, line feed
        if (ans.size() != 0)
        {
            os << endl;
        }
    }
}
