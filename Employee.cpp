#include "Employee.h"
Employee::Empolyee(int ID, string name, string phoneNumber, string email, Gender gender, string address, unsigned int salary, Position positon)
    :Person(ID, name, phoneNumber, email, gender, address)
{
    this->salary = salary;
    this->position = position;
}
Employee::~Employee()
{ }
Employee:: void Show()
{
    cout<< "Ma Nhan vien: " << this->ID << "; ";
    this->Person::Show();
    cout<< "; Luong: " << this->salary << "; ";
}
Employee::unsigned int getsalary()
{
    return this->salary;
}
Employee::void setID(unsigned int newSalary)
{
    this->salary = newSalary;
}

Employee::Position getposition()
{
    return this->position;
}
Employee::void setpositon(Position newPositon)
{
    this->position = newPosition;
}