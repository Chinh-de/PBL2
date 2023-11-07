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
        string GetYear();
        string GetMonth();
        string GetDay();
        void SetYear(string);
        void SetMonth(string);
        void SetDay(string);
};