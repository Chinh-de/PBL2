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
int Person::GetID(){
    return this->ID;
}
void Person::SetID(int id){
    this->ID = id;
}
string Person::GetName(){
    return this->Name;
}
void Person::SetName(string n){
    this->Name = n;
}
string Person::GetPhone(){
    return this->Phone;
}
void Person::SetPhone(string p){
    this->Phone = p;
}
string Person::GetEmail(){
    return this->Email;
}
void Person::SetEmail(string e){
    this->Email = e;
}
bool Person::GetGender(){
    return this->Gender;
}
void Person::SetGender(bool g){
    this->Gender = g;
}
string Person::GetAddress(){
    return this->Address;
}
void Person::SetAddress(string a){
    this->Address = a;
}