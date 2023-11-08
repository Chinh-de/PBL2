#include "Employee.h"
Employee::Employee(int ID, string name, string phoneNumber, string email, bool gender, string address, unsigned int salary, Position positon)
    :Person(ID, name, phoneNumber, email, gender, address)
{
    this->salary = salary;
    this->position = position;
}
Employee::~Employee()
{ }
void Employee::Show()
{
    cout<< "Ma Nhan vien: " << this->ID << "; ";
    this->Person::Show();
    cout<< "; Luong: " << this->salary << "; ";
}
unsigned int Employee::getsalary()
{
    return this->salary;
}
void Employee::setsalary(unsigned int newSalary)
{
    this->salary = newSalary;
}

Position Employee::getposition()
{
    return this->position;
}
void Employee::setpositon(Position newPosition)
{
    this->position = newPosition;
}