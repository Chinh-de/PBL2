#include "EmpManage.h"

EmpManage::EmpManage()
{ }
EmpManage::~EmpManage()
{ }
void EmpManage::add(const Employee& e) {
    this->Emp.add(e);
}
void EmpManage::remove(const Employee& e){
    this->Emp.remove(e);
}
void EmpManage::display(){
    this->Emp.display();
}
void EmpManage::update(){
    cout << "123";
}
Employee EmpManage::find(int& ID)
{
    Node<Employee>* tempNode = this->Emp.getHead();
    while (tempNode != nullptr) 
    {
        if (tempNode->data.getID() == ID) return tempNode->data;
        tempNode = tempNode->next;
    }
}
list<Employee> EmpManage::find(string& name, string& phone)
{
    list<Employee> Found;
    if( name == "x" && phone == "x" ) return Found;
    Node<Employee>* tempNode;
    tempNode = this->Emp.getHead();
    while (tempNode != nullptr) 
    {
        if ( ( tempNode->data.getName() == name || name == "x" ) && ( tempNode->data.getPhone() == phone || phone == "x" ) ) 
            Found.add(tempNode->data);
        tempNode = tempNode->next;
    }
    if ( Found.getHead() == nullptr ) cout << "khong tim thay!";
    return Found;
}