#include "EmpManage.h"

EmpManage::EmpManage()
{ }
EmpManage::~EmpManage()
{ }
void EmpManage::add(const Employee& e) {
    this->Emp.add(e);
}
void EmpManage::add(){
    int ID; unsigned int salary;
    string name, phone, email, address, password;
    bool gender;
    Position position;
    cout << "Nhap thong tin: " << endl
    << "Ma nhan vien: "; cin >> ID;
    cout << "Ten nhan vien: "; cin >> name;
    cout << "So dien thoai: "; cin >> phone;
    cout << "Email: "; cin >> email;
    cout << "Gioi tinh(Nam = 0, Nu = 1): "; cin >> gender;
    cout << "Dia chi: "; cin >> address;
    cout << "Luong: "; cin >> salary;
    cout << "Vi tri cong viec: "; cin >> position;
    cout << "Dat mat khau tai khoan nhan vien: "; cin >> password;
    Employee e(ID, name, phone, email, gender, address, salary, position, password);
    this->Emp.add(e);
}
void EmpManage::remove(const Employee& e){
    this->Emp.remove(e);
}
void EmpManage::display(){
    this->Emp.display();
}
void EmpManage::update(Employee& e){
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
    return tempNode->data;
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
    return Found;
}