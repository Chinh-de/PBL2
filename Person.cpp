#include "Person.h"
Person::Person(int ID, string name, string phoneNumber, string email, Gender gender, string address)
    :ID(ID), name(name), phone(phoneNumber), email(email), gender(gender), address(address)
{ }

Person::void Show()
{
    cout << "; Ten: " << this->name << "; So Dien Thoai: " << this->phone;
    cout << "; Gioi tinh: ";
    if(this->gender == male) cout << "Nam ;";
    if(this->gender == female)cout << "Nu ;";
    if(this->gender == orther)cout << "Khac ;";
    cout << " email: " << email << "; Dia chi: " << address; 
}

Person:: int getID()
{
    return this->ID;
}

Person:: void setID(int newID)
{
    this->ID = newID;
}

Person:: string getname()
{
    return this->name;
}

Person:: void setname(string newName)
{
    this->name = newname;
}

Person:: string getphone()
{    
    return this->phone;
}

Person:: void setphone(string newPhone)
{
    this->phone = newPhone;
}

Person:: string getemail()
{
    return this->email;
}

Person:: void setemail(string newEmail)
{
    this->email = newEmail;
}

Person:: Gender getgender()
{
    return this->gender;
}

Person:: void setgender(Gender newGender)
{
    this->gender = newGender;
}

Person:: string getaddress()
{
    return this->address;
}

Person:: void setaddress(string newAddress)
{
    this->address = newAddress;
}
