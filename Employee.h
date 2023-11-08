#include "Person.h"
enum Position 
{
    manager = 1,
    salesperson = 2
};

class Employee : protected Person
{
    protected:
        unsigned int salary;
        Position position;
    public:
        Employee(int = 0, string = "", string = "", string = "", bool = 0, string = "", unsigned int = 0, Position = manager);           
        ~Employee();
        void Show();
        unsigned int getsalary();
        void setsalary(unsigned int);   
        Position getposition();
        void setpositon(Position);     
};

