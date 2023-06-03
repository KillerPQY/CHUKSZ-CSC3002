/*
 * File: bigint.cpp
 * ----------------
 * This file implements the bigint.h interface.
 */

#include <cctype>
#include <string>
#include "bigint.h"
#include "error.h"
using namespace std;

/*
 * Implementation notes: BigInt constructor
 * ----------------------------------------
 * The code for this constructor offers a minimal implementation
 * that matches what we would expect on an exam.  In a more
 * sophisticated implementation, it would make sense to include
 * a test to avoid storing leading zeros in the linked list.  In
 * this implementation, calling BigInt("00042") creates a
 * BigInt with a different internal representation than
 * BigInt("42"), which is probably a bad idea.
 */

BigInt::BigInt(string str) {
    //TODO
    this->start = new Cell;
    if (str.length() == 0)
        start->leadingDigits = NULL;
    else {
        Cell* beg = start;
        int l = str.length() - 1;
        while (l >= 0)
        {
            Cell* tp = new Cell;
            tp->finalDigit = str[l] - '0';
            tp->leadingDigits = NULL;
            beg->leadingDigits = tp;
            beg = beg->leadingDigits;
            l--;
        }
    }
}

/*
 * Implementation notes: BigInt destructor
 * ---------------------------------------
 * The code for the destructor is similar to that of the other
 * classes that contain a linked list.  You need to store the
 * pointer to the next cell temporarily so that you still have
 * it after you delete the current cell.
 */

BigInt::~BigInt() {
    //TODO
    Cell* p = start->leadingDigits;
    while (p != NULL) {
        Cell* del = p;
        p = p->leadingDigits;
        delete del;
    }
    delete start;
}




/*
 * Implementation notes: toString
 * ------------------------------
 * This method could also be written as a wrapper method that
 * calls a recursive function that creates the reversed string
 * one character at a time.
 */

string BigInt::toString() const {
    //TODO
    string result = "";
    Cell* p = start;
    if (p == NULL)
        return result;
    p = p->leadingDigits;
    while (p != NULL) {
        result.insert(0, 1, char(p->finalDigit + '0'));
        p = p->leadingDigits;
    }
    return result;
}

/*
 * Implementation notes: operator+ and operator*
 * ------------------------------
 * Implement operator+ and operator*, make BigInt surpport addition and
 * multiplication.
 */

BigInt BigInt::operator+(const BigInt & b2) const {
    //TODO
    BigInt b1 = *this;
    BigInt result("0");
    Cell* c1 = b1.start->leadingDigits;
    Cell* c2 = b2.start->leadingDigits;
    Cell* cr = result.start;
    if (b1.toString().length() <= b2.toString().length()) {
        bool carry = 0;
        while (c1 != NULL) {
            Cell* nc = new Cell;
            nc->leadingDigits = NULL;
            int v;
            if (carry) {
                carry = 0;
                v = c1->finalDigit + c2->finalDigit + 1;
            }
            else
                v = c1->finalDigit + c2->finalDigit;
            if (v >= 10) {
                nc->finalDigit = v - 10;
                carry = 1;
            }
            else
                nc->finalDigit = v;
            cr->leadingDigits = nc;
            cr = cr->leadingDigits;
            c1 = c1->leadingDigits;
            c2 = c2->leadingDigits;
            }
        while (c2 != NULL) {
            Cell* nc = new Cell;
            nc->leadingDigits = NULL;
            int v;
            if (carry) {
                carry = 0;
                v = c2->finalDigit + 1;
            }
            else
                v = c2->finalDigit;
            if (v >= 10) {
                nc->finalDigit = v - 10;
                carry = 1;
            }
            else
                nc->finalDigit = v;
            cr->leadingDigits = nc;
            cr = cr->leadingDigits;
            c2 = c2->leadingDigits;
        }
        if (carry) {
            Cell* nc = new Cell;
            nc->leadingDigits = NULL;
            nc->finalDigit = 1;
            cr->leadingDigits = nc;
            cr = cr->leadingDigits;
        }
        return result;
    }
    else {
        bool carry = 0;
        while (c2 != NULL) {
            Cell* nc = new Cell;
            nc->leadingDigits = NULL;
            int v;
            if (carry) {
                carry = 0;
                v = c1->finalDigit + c2->finalDigit + 1;
            }
            else
                v = c1->finalDigit + c2->finalDigit;
            if (v >= 10) {
                nc->finalDigit = v - 10;
                carry = 1;
            }
            else
                nc->finalDigit = v;
            cr->leadingDigits = nc;
            cr = cr->leadingDigits;
            c1 = c1->leadingDigits;
            c2 = c2->leadingDigits;
            }
        while (c1 != NULL) {
            Cell* nc = new Cell;
            nc->leadingDigits = NULL;
            int v;
            if (carry) {
                carry = 0;
                v = c1->finalDigit + 1;
            }
            else
                v = c1->finalDigit;
            if (v >= 10) {
                nc->finalDigit = v - 10;
                carry = 1;
            }
            else
                nc->finalDigit = v;
            cr->leadingDigits = nc;
            cr = cr->leadingDigits;
            c1 = c1->leadingDigits;
        }
        if (carry) {
            Cell* nc = new Cell;
            nc->leadingDigits = NULL;
            nc->finalDigit = 1;
            cr->leadingDigits = nc;
            cr = cr->leadingDigits;
        }
        return result;
    }
}


BigInt BigInt::recursiveProd(BigInt b1, const BigInt & b2) const {
    BigInt result("0");
    if (b1.toString().length() <= 1) {
        if (b1.start != NULL) {
            for (int i = 0; i < b1.start->leadingDigits->finalDigit; i++) {
                result = result + b2;   // multiply is repeated addition
            }
        }
        return result;
    }

    BigInt lsd(to_string(b1.start->leadingDigits->finalDigit));
    if (b1.start->leadingDigits != NULL) {
        b1.start = b1.start->leadingDigits;
    }

    BigInt msd(b1);
    BigInt lsdResult = recursiveProd(lsd, b2);
    BigInt msdResult = recursiveProd(msd, b2);
    result = lsdResult;
    for (int i = 0; i < 10; i++) {
        result = result + msdResult;
    }
    return result;
}
BigInt BigInt::operator*(const BigInt & b2) const {
    //TODO
    BigInt b1 = *this;
    return recursiveProd(b1, b2);
}
void BigInt::operator=(const BigInt & b2) {
    Cell* pt2 = b2.start;
    this->start = NULL;
    Cell* now = NULL;
    Cell* newCell;
    while (pt2 != NULL){
        newCell = new Cell;
        newCell->finalDigit = pt2->finalDigit;
        newCell->leadingDigits = NULL;
        pt2 = pt2->leadingDigits;
        if (now == NULL){
            now = newCell;
            this->start = now;
        } else {
            now->leadingDigits = newCell;
            now = newCell;
        }
    }
}
BigInt:: BigInt(const BigInt & b2){
    Cell* pt2 = b2.start;
    this->start = NULL;
    Cell* now = NULL;
    Cell* newCell;
    while (pt2 != NULL){
        newCell = new Cell;
        newCell->finalDigit = pt2->finalDigit;
        newCell->leadingDigits = NULL;
        pt2 = pt2->leadingDigits;
        if (now == NULL){
            now = newCell;
            this->start = now;
        } else {
            now->leadingDigits = newCell;
            now = newCell;
        }
    }
}

