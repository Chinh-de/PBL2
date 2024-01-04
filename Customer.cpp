#include "Customer.h"
Customer::Customer(int ID, string name, string phoneNumber, string email, bool gender, string address)
    :Person(ID, name, phoneNumber, email, gender, address)
{ }
Customer::~Customer()
{ }
void Customer::Show()
{
    cout << "Ma khach hang: " << this->ID << endl;
    cout << "Ten: " << this->Name << endl << "So Dien Thoai: " << this->Phone << endl;
    cout << "Gioi tinh: ";
    if(this->Gender) cout << "Nu";
    else cout << "Nam";
    cout << endl << "email: " << this->Email << endl << "Dia chi: " << this->Address << endl;
    cout << "\t\t\t *******" << endl;
}
ostream& operator<<(ostream& o, const Customer& e){
    Person *p = new Customer();
    *p = e;
    p->Person::Show();
    delete p;
    return o;
}