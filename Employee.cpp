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
ostream& operator<<(ostream& o, const Employee& e){
    Person *p = new Employee();
    *p = e;
    o << "Ma Nhan vien: " << e.ID << "; ";
    p->Show();
    o << "; Luong: " << e.salary << "; ";
    delete p;
    return o;
}
unsigned int Employee::getSalary()
{
    return this->salary;
}
void Employee::setSalary(unsigned int newSalary)
{
    this->salary = newSalary;
}

Position Employee::getPosition()
{
    return this->position;
}
void Employee::setPositon(Position newPosition)
{
    this->position = newPosition;
}