#include "Person.h"
enum Position 
{
    manager = 1,
    salesperson = 0
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
        unsigned int getSalary();
        void setSalary(unsigned int);   
        Position getPosition();
        void setPositon(Position);     
};

