#include "Date.h"

Date::Date()
{ }
Date::Date(int D, int M, int Y)
    : Day(D), Month(M), Year(Y)
{ }
Date::Date(const Date& other)
    : Year(other.Year), Month(other.Month), Day(other.Day)
{   }
Date::~Date()
{ }
Date& Date::operator=(const Date& other)
{
    if (this != &other) {
        this->Year = other.Year;
        this->Month = other.Month;
        this->Day = other.Day;
    }
    return *this;
}
int Date::getYear(){
    return this->Year;
}
int Date::getMonth(){
    return this->Month;
}
int Date::getDay(){
    return this->Day;
}
void Date::setYear(int Y){
    this->Year = Y;
}
void Date::setMonth(int M){
    this->Month = M;
}
void Date::setDay(int D){
    this->Day = D;
}
void getCurrent(Date& Current)
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    Current.setYear(1900 + ltm->tm_year);
    Current.setMonth(1 + ltm->tm_mon);
    Current.setDay(ltm->tm_mday);
}
