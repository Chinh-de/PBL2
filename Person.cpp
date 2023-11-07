#include "Person.h"
Person::Person(int ID, string name, string phoneNumber, string email, bool gender, string address)
    :ID(ID), Name(name), PhoneNumber(phoneNumber), Email(email), Gender(gender), Address(address)
{ }
Person::void Show()
{
    cout << "; Ten: " << this->Name << "; So Dien Thoai: " << this->PhoneNumber;
    cout << "; Gioi tinh: ";
    if(this->Gender) cout << "Nam ;";
    else cout << "Nu ;";
    cout << " email: " << email << "; Dia chi: " << Address; 
}
