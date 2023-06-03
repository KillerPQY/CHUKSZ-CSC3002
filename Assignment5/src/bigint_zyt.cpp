/*
 * File: bigint.cpp
 * ----------------
 * This file implements the bigint.h interface.
 */

#include <cctype>
#include <string>
#include "bigint.h"
#include "error.h"
#include "set.h"
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
    int start = 0;
    Cell* newCell;
    Cell* now = NULL;
    this->start = NULL;
    while (start < str.length() && str[start] == '0') start ++;
    if (start == str.length()){
        newCell = new Cell;
        newCell->leadingDigits = NULL;
        newCell->finalDigit = 0;
        this->start = newCell;
    }
    for (int i = str.length() - 1;i > start - 1;i --){
        newCell = new Cell;
        newCell->finalDigit = str[i] - '0';
        newCell->leadingDigits = NULL;
        if (now != NULL){
            now->leadingDigits = newCell;
            now = newCell;
        } else{
            now = newCell;
            this->start = now;
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
    Cell* now = start;
    while (now != NULL){
        Cell* temp = now->leadingDigits;
        delete now;
        now = temp;
    }
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
    string str = "";
    char dgt;
    Cell* now = start;
    while (now != NULL){
        dgt = '0' + now->finalDigit;
        str = dgt + str;
        now = now->leadingDigits;
    }
    return str;
}

/*
 * Implementation notes: operator+ and operator*
 * ------------------------------
 * Implement operator+ and operator*, make BigInt surpport addition and
 * multiplication.
 */

BigInt BigInt::operator+(const BigInt & b2) const {
    //TODO
    Cell* pt1 = this->start;
    Cell* pt2 = b2.start;
    int sum,carrier = 0;
    BigInt num(NULL);
    Cell* result;
    Cell* now = NULL;
    while (pt1 != NULL && pt2 != NULL){
        result = new Cell;
        result->leadingDigits = NULL;
        sum = pt1->finalDigit + pt2->finalDigit + carrier;
        carrier = sum/10;
        result->finalDigit = sum % 10;
        pt1 = pt1->leadingDigits;
        pt2 = pt2->leadingDigits;
        if (num.start == NULL){
            num.start = result;
            now = result;
        } else {
            now->leadingDigits = result;
            now = result;
        }
    }
    if (pt1 == NULL){
        pt1 = pt2;
    }
    if (now != NULL){
        while (pt1 != NULL){
            result = new Cell;
            result->leadingDigits = NULL;
            sum = pt1->finalDigit + carrier;
            carrier = sum/10;
            result->finalDigit = sum % 10;
            pt1 = pt1->leadingDigits;
            now->leadingDigits = result;
            now = result;
        }
    }
    if (carrier != 0){
        result = new Cell;
        result->finalDigit = carrier;
        result->leadingDigits = NULL;
        now->leadingDigits = result;
    }
    return num;
}

BigInt BigInt::operator*(const BigInt & b2) const {
    //TODO
    int product;
    string str,str1;
    if (this->start == NULL || b2.start == NULL){
        return BigInt(NULL);
    } else {
        if (start->leadingDigits == NULL && b2.start->leadingDigits == NULL){
            product = start->finalDigit * b2.start->finalDigit;
            return BigInt(to_string(product/10) + "" + to_string(product%10));
        } else{
            if (start->leadingDigits == NULL){
                str = b2.toString();
                return BigInt(to_string(start->finalDigit))*BigInt(to_string(b2.start->finalDigit))
                        + BigInt((BigInt(to_string(start->finalDigit))*BigInt(str.substr(0,str.length() - 1))).toString()+string("0"));
            }
            if (b2.start->leadingDigits == NULL){
                str = (*this).toString();
                return BigInt(to_string(b2.start->finalDigit))*BigInt(to_string(start->finalDigit))
                        + BigInt((BigInt(to_string(b2.start->finalDigit))*BigInt(str.substr(0,str.length() - 1))).toString()+string("0"));
            }
            str = (*this).toString();
            str1 = b2.toString();
            return BigInt(to_string(start->finalDigit))*BigInt(to_string(b2.start->finalDigit)) +
                   BigInt((BigInt(to_string(start->finalDigit))*BigInt(str1.substr(0,str1.length() - 1))).toString() + string("0")) +
                   BigInt((BigInt(to_string(b2.start->finalDigit))*BigInt(str.substr(0,str.length() - 1))).toString() + string("0")) +
                   BigInt((BigInt(str.substr(0,str.length() - 1))*BigInt(str1.substr(0,str1.length() - 1))).toString() + string("00"));
        }
    }
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
