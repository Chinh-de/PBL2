#include "Customer.h"
Customer::Customer(int ID, string name, string phoneNumber, string email, bool gender, string address)
    :Person(ID, name, phoneNumber, email, gender, address)
{ }
Customer::~Customer()
{ }
void Customer::Show()
{
    cout << "Ma khach hang: " << this->ID << "; ";
    this->Person::Show();
}