#include "Date.h"

Date::Date(string Y, string M, string D)
    : Year(Y), Month(M), Day(D)
{ }
Date::~Date()
{ }

string Date::GetYear(){
    return this->Year;
}
string Date::GetMonth(){
    return this->Month;
}
string Date::GetDay(){
    return this->Day;
}
void Date::SetYear(string Y){
    this->Year = Y;
}
void Date::SetMonth(string M){
    this->Month = M;
}
void Date::SetDay(string D){
    this->Year = D;
}