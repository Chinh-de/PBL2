#include <iostream>
using namespace std;
#pragma once
class Date{
    protected:
        string Year;
        string Month;
        string Day;
    public:
        Date();
        Date(string, string, string);
        ~Date();
        string getYear();
        string getMonth();
        string getDay();
        void setYear(string);
        void setMonth(string);
        void setDay(string);
};