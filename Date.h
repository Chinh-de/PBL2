#include <iostream>
using namespace std;
#pragma once
class Date{
    protected:
        int Year;
        int Month;
        int Day;
    public:
        Date();
        Date(int, int, int);
        ~Date();
        int getYear();
        int getMonth();
        int getDay();
        void setYear(int);
        void setMonth(int);
        void setDay(int);
};