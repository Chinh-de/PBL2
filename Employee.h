#include "Person.h"
#include "CusManage.h"
#include "ProdManage.h"
#include "InvManage.h"
#pragma once
enum Position 
{
    manager = 1,
    salesperson = 0
};

class Employee : public Person
{
    protected:
        unsigned int salary;
        Position position;
        string password;
    public:
        Employee(int = 0, string = "", string = "", string = "", bool = 0, string = "", unsigned int = 0, Position = manager, string = "");           
        ~Employee();
        void Show();
        friend ostream& operator<<(ostream&, const Employee&);
        unsigned int getSalary();
        void setSalary(unsigned int);
        Position getPosition();
        void setPositon(Position);
        string getPassword();
        void setPassword(string&);
        bool changePassword();
        void sell(CusManage&, ProdManage&, InvManage&);
};

