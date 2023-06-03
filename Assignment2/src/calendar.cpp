/*
 * File: calendar.cpp
 * ------------------
 * This file implements the calendar.h interface
 * You need "include" the proper header file and write the function definition.
 */

// TODO
#include <iostream>
#include <string>
#include <sstream>
#include "calendar.h"
using namespace std;

string monthToString(Month month)
{
    switch (month)
    {
        case JANUARY:
            return "JANUARY";
        case FEBRUARY:
            return "FEBRUARY";
        case MARCH:
           return "MARCH";
        case APRIL:
            return "APRIL";
        case MAY:
            return "MAY";
        case JUNE:
            return "JUNE";
        case JULY:
            return "JULY";
        case AUGUST:
            return "AUGUST";
        case SEPTEMBER:
            return "SEPTEMBER";
        case OCTOBER:
            return "OCTOBER";
        case NOVEMBER:
            return "NOVEMBER";
        case DECEMBER:
            return "DECEMBER";
        // If the month does not match any of the enumeration constants,
        // return ???.
        default:
            return "???";
    }
}

int daysInMonth(Month month, int year)
{
    // 1, 3, 5, 7, 8, 10, 12 months are 31 days
    // 4, 6, 9, 11 are 30 days.
    // 2, leap year is 29 days, other is 28 days.
    switch (month)
    {
        case APRIL:
        case JUNE:
        case SEPTEMBER:
        case NOVEMBER:
            return 30;
        case FEBRUARY:
        {
            if (isLeapYear(year))
                return 29;
            else
                return 28;
        }
    default:
        return 31;
    }
}

bool isLeapYear(int year)
{
    // Years that are divisible (by 400) or (by 4 but not by 100) are leap years.
    return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}

Month operator++(Month & month, int)
{
    Month ans = month;  // Create a Month to store old month.
    month = Month(month + 1);  // Update old month.
    return ans;  // Return old month.
}

// initDate function can be used in constructors
void Date::initDate(int dd, Month mm, int yyyy)
{
    bool flag = 0;
    // deal with wrong month input
    for (Month i = JANUARY; i <= DECEMBER; i++)
    {
        if (mm == i)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        throw mm;
    }
    // deal with wrong day input
    if (dd < 1 || dd > daysInMonth(mm, yyyy))
    {
        throw dd;
    }
    day = dd;
    month = mm;
    year = yyyy;
    dayInYear = day;
    for (Month i = JANUARY; i < month; i++)
    {
        dayInYear += daysInMonth(i, year);
    }
}

// Default constructor.
Date::Date()
{
    year = 1900;
    month = JANUARY;
    day = 1;
    dayInYear = 1;
}

// constructor Date(int theday, Month themonth, int theyear).
Date::Date(int day, Month month, int year)
{
    initDate(day, month, year);
}

// constructor Date(Month themonth, int theday, int theyear).
Date::Date(Month month, int day, int year)
{
    initDate(day, month, year);
}

// get day in date
int Date::getDay()
{
    return day;
}

// get month in date
Month Date::getMonth()
{
    return month;
}

// get year in date
int Date::getYear()
{
    return year;
}

// Returns the string representation of the date in the form dd-mmm-yyyy
string Date::toString()
{
    stringstream res;
    switch (month)
    {
    case JANUARY:
    {
        res << day << "-" << "Jan" << "-" << year;
        return res.str();
    }
    case FEBRUARY:
    {
        res << day << "-" << "Feb" << "-" << year;
        return res.str();
    }
    case MARCH:
    {
        res << day << "-" << "Mar" << "-" << year;
        return res.str();
    }
    case APRIL:
    {
        res << day << "-" << "Apr" << "-" << year;
        return res.str();
    }
    case MAY:
    {
        res << day << "-" << "May" << "-" << year;
        return res.str();
    }
    case JUNE:
    {
        res << day << "-" << "Jun" << "-" << year;
        return res.str();
    }
    case JULY:
    {
        res << day << "-" << "Jul" << "-" << year;
        return res.str();
    }
    case AUGUST:
    {
        res << day << "-" << "Aug" << "-" << year;
        return res.str();
    }
    case SEPTEMBER:
    {
        res << day << "-" << "Sep" << "-" << year;
        return res.str();
    }
    case OCTOBER:
    {
        res << day << "-" << "Oct" << "-" << year;
        return res.str();
    }
    case NOVEMBER:
    {
        res << day << "-" << "Nov" << "-" << year;
        return res.str();
    }
    case DECEMBER:
    {
        res << day << "-" << "Dec" << "-" << year;
        return res.str();
    }
    // If the month does not exist, return day-???-year
    default:
        res << day << "-" << "???" << "-" << year;
        return res.str();
    }
}

// Override the << operator of Date class
ostream & operator<<(ostream & os, Date date)
{
    // Output the date
    os << date.toString();
    return os;
}

// Override the ==, !=, <, <=, >, >= operators of Date class
bool operator==(Date d1, Date d2)
{
    return (d1.getYear() == d2.getYear() && d1.getMonth() == d2.getMonth() && d1.getDay() == d2.getDay());
}
bool operator!=(Date d1, Date d2)
{
    return !(d1 == d2);  // If the dates are not equal, then d1 != d2.
}
bool operator<(Date d1, Date d2)
{
    // Small year || same year, small month || same year, same month, small day
    return (d1.getYear() < d2.getYear() ||
            (d1.getYear() == d2.getYear() && d1.getMonth() < d2.getMonth()) ||
            (d1.getYear() == d2.getYear() && d1.getMonth() == d2.getMonth() && d1.getDay() < d2.getDay()));
}
bool operator<=(Date d1, Date d2)
{
    // small || equal
    return ((d1 < d2) || (d1 == d2));
}
bool operator>(Date d1, Date d2)
{
    // Big year || same year, big month || same year, same month, big day
    return (d1.getYear() > d2.getYear() ||
            (d1.getYear() == d2.getYear() && d1.getMonth() > d2.getMonth()) ||
            (d1.getYear() == d2.getYear() && d1.getMonth() == d2.getMonth() && d1.getDay() > d2.getDay()));
}
bool operator>=(Date d1, Date d2)
{
    // big || equal
    return ((d1 > d2) || (d1 == d2));
}

// Override the + operator.
Date operator+(Date date, int delta)
{
    int mdays = daysInMonth(date.month, date.year);  // Create a int to store max days in now month
    date.day = date.day + delta;
    // if days bigger than max days, month+1, days-max days
    while (date.day > mdays)
    {
        date.month = Month(date.month + 1);
        date.day -= mdays;
        // if month bigger than 12, year+1, month-12
        while (date.month > 12)
        {
            date.year += 1;
            date.month = Month(date.month - 12);
        }
    }
    return date;
}
// Override the - operator.
Date operator-(Date date, int delta)
{
    int mdays = daysInMonth(Month(date.month - 1), date.year);  // // Create a int to store max days in previous month
    date.day = date.day - delta;
    // if days <= 0, month-1, days+max previous month days
    while (date.day <= 0)
    {
        date.month = Month(date.month - 1);
        date.day += mdays;
        // if month <= 0, year-1, month+12
        while (date.month <= 0)
        {
            date.year -= 1;
            date.month = Month(date.month + 12);
        }
    }
    return date;
}
// Override the - operator so that it can get difference of two dates.
int operator-(Date d1, Date d2)
{
    int result = 0;
    // if same year, use dayInYear to subtract each other
    if (d1.getYear() == d2.getYear())
    {
       int dayInYear1, dayInYear2;
       // Find out what day d1 is in that year.
       dayInYear1 = d1.getDay();
       for (Month i = JANUARY; i < d1.getMonth(); i++)
       {
           dayInYear1 += daysInMonth(i, d1.getYear());
       }
       // Find out what day d2 is in that year.
       dayInYear2 = d2.getDay();
       for (Month i = JANUARY; i < d2.getMonth(); i++)
       {
           dayInYear1 += daysInMonth(i, d2.getYear());
       }
       // Find the absolute value of the difference of d1 and d2.
       if (d1 >= d2)
       {
           result = dayInYear1 - dayInYear2;
           return result;
       }
       else
       {
           result = dayInYear2 - dayInYear1;
           return result;
       }
    }
    // if different year, get the difference based on the number of days d1 through d2 or d2 through d1
    else if (d1.getYear() > d2.getYear())
    {
        while (d1 != d2)
        {
             d2 += 1;
             result += 1;
        }
        return result;
    }
    else
    {
        while (d1 != d2)
        {
             d1 += 1;
             result += 1;
        }
        return result;
    }
}

// Override the +=, -= operators
Date & operator+=(Date & date, int delta)
{
    // Have overrided the + operator.
    date = date + delta;
    return date;
}
Date & operator-=(Date & date, int delta)
{
    // Have overrided the - operator.
    date = date - delta;
    return date;
}

// Override the ++ prefix
Date operator++(Date & date)
{
    date += 1;
    return date;
}
// Override the ++ suffix
Date operator++(Date & date, int)
{
    Date temp = date;
    date += 1;
    return temp;
}
// Override the -- prefix
Date operator--(Date & date)
{
    date -= 1;
    return date;
}
// Override the -- suffix
Date operator--(Date & date, int)
{
    Date temp = date;
    date -= 1;
    return temp;
}
