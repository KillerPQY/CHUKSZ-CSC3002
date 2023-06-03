/*
 * File: combinatorics.cpp
 * -----------------------
 * This file implements the combinatorics.h interface.
 */

 /* Function definition */

 /*TODO*/
#include<iostream>
#include<string>
using namespace std;

int permutations(int n, int k)
{
    int ans = 1; // define a int variable to store answer
    int temp;  // define a int variable for detecting overflow
    for (int i = 1; i < k + 1; i++) // P(n,k)=  n*(n-1)*(n-2)*(n-3)*...(n-k+1)
    {
        temp = ans;
        ans *= n;
        // detecting overflow
        if (ans / n != temp)
        {
            cout << "The number is too big, it caused overflow!" << endl;
            throw n;
        }
        n -= 1; // n minus 1 every time
    }
    return ans;
}

int combinations(int n, int k)
{
    if (n == k || k == 0) // if n==k or k==0, C(n, k)=1
        return 1;

    int ans = 1;  // define a int variable to store answer
    int temp;  // define a int variable for detecting overflow
    // C(n, k)=C(n, n-k)
    int t;
    if (k >= n - k) // When k>=n-k, t=n-k
        t = n - k;
    else            // When k<n-k, t=k
        t = k;
    // C(n, k)=C(n, n-k)=C(n, t)=(n*(n-1)*(n-2)*(n-3)*...(n-k+1))/(k*(k-1)...1)
    for (int i = 1; i <= t; i++)
    {
        temp = ans;
        ans = ans * (n - i + 1) / i;
        // detecting overflow
        if (ans * i / (n - i + 1) != temp)
        {
            cout << "The number is too big, it caused overflow!" << endl;
            throw n;
        }
    }
    return ans;
}
