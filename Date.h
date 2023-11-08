#include <iostream>
using namespace std;

class Date{
    protected:
        string Year;
        string Month;
        string Day;
    private:
        Date(string, string, string);
        ~Date();
    public:
        string getYear();
        string getMonth();
        string getDay();
        void setYear(string);
        void setMonth(string);
        void setDay(string);
};