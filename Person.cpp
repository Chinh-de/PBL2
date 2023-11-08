#include "Person.h"
Person::Person(int ID, string name, string phoneNumber, string email, bool gender, string address)
    :ID(ID), Name(name), Phone(phoneNumber), Email(email), Gender(gender), Address(address)
{ }
Person::~Person()
{ }
void Person::Show()
{
    cout << "; Ten: " << this->Name << "; So Dien Thoai: " << this->Phone;
    cout << "; Gioi tinh: ";
    if(this->Gender) cout << "Nam ;";
    else cout << "Nu ;";
    cout << " email: " << Email << "; Dia chi: " << Address; 
}
