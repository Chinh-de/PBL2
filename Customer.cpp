#include "Customer.h"
Customer::Cusomer(int ID, string name, string phoneNumber, string email, Gender gender, string address)
    :Person(ID, name, phoneNumber, email, gender, address)
{ }
Cusomer::~Cusomer()
{ }
Customer::void Show()
{
    cout << "Ma khach hang: " << this->ID << "; ";
    this->Person::Show();
}