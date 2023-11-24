#include "CusManage.h"

CusManage::CusManage()
{ }
CusManage::~CusManage()
{ }
void CusManage::add(const Customer& c) {
    this->Cus.add(c);
}
void CusManage::remove(const Customer& c){
    this->Cus.remove(c);
}
void CusManage::display(){
    this->Cus.display();
}
void CusManage::update(Customer& c){
    cout << "123";
}
Customer CusManage::find(int& ID)
{
    Node<Customer>* tempNode = this->Cus.getHead();
    while (tempNode != nullptr) 
    {
        if (tempNode->data.getID() == ID) return tempNode->data;
        tempNode = tempNode->next;
    }
    return tempNode->data;
}
list<Customer> CusManage::find(string& name, string& phone)
{
    list<Customer> Found;
    if( name == "x" && phone == "x" ) return Found;
    Node<Customer>* tempNode;
    tempNode = this->Cus.getHead();
    while (tempNode != nullptr) 
    {
        if ( ( tempNode->data.getName() == name || name == "x" ) && ( tempNode->data.getPhone() == phone || phone == "x" ) ) 
            Found.add(tempNode->data);
        tempNode = tempNode->next;
    }
    if ( Found.getHead() == nullptr ) cout << "khong tim thay!";
    return Found;
}