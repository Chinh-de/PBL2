#include "Date.h"

Date::Date(string Y, string M, string D)
    : Year(Y), Month(M), Day(D)
{ }
Date::~Date()
{ }

string Date::getYear(){
    return this->Year;
}
string Date::getMonth(){
    return this->Month;
}
string Date::getDay(){
    return this->Day;
}
void Date::setYear(string Y){
    this->Year = Y;
}
void Date::setMonth(string M){
    this->Month = M;
}
void Date::setDay(string D){
    this->Year = D;
}