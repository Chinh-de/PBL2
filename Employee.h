#include "Person.h"
enum Position 
{
    manager = 1;
    salesperson
};

class Employee :: protected Person
{
    protected:
        unsigned int salary;
        Position position;
    public:
        Employee(int = 0, string = "", string = "", string = "", Gender = male, string = "", unsinged int = 0, Position = manager);           
        ~Employee();
        void Show();
        unsigned int getsalary();
        void setsalary(unsigned int);   
        Position getposition();
        void setpositon(Positon);     
};

