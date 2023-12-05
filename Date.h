#include <iostream>
#include <ctime>
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
        Date(const Date&);
        Date& operator=(const Date&);
        ~Date();
        int getYear();
        int getMonth();
        int getDay();
        void setYear(int);
        void setMonth(int);
        void setDay(int);
        friend void getCurrent(Date&);
};