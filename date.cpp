#include "date.h"
#include <stdio.h>
// Date constructor
Date::Date(int year, int month, int day)
{
    SetDate(year, month, day);
}

// Date member function
void Date::SetDate(int year, int month, int day)
{
    m_month = month;
    m_day = day;
    m_year = year;
}

void Date::toString()
{
    printf("Year %i Month %i Day %i", this->getYear(), this->getMonth(), this->getDay());
}