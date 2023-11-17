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
    cout << " email: " << this->Email << "; Dia chi: " << this->Address; 
}
int Person::getID(){
    return this->ID;
}
void Person::setID(int id){
    this->ID = id;
}
string Person::getName(){
    return this->Name;
}
void Person::setName(string n){
    this->Name = n;
}
string Person::getPhone(){
    return this->Phone;
}
void Person::setPhone(string p){
    this->Phone = p;
}
string Person::getEmail(){
    return this->Email;
}
void Person::setEmail(string e){
    this->Email = e;
}
bool Person::getGender(){
    return this->Gender;
}
void Person::setGender(bool g){
    this->Gender = g;
}
string Person::getAddress(){
    return this->Address;
}
void Person::setAddress(string a){
    this->Address = a;
}
bool Person::operator!=(const Person& e){
    return (this->ID != e.ID);
}