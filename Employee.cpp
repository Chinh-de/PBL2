#include "Employee.h"
Employee::Employee(int ID, string name, string phoneNumber, string email, bool gender, string address, unsigned int salary, Position position, string password)
    :Person(ID, name, phoneNumber, email, gender, address), salary(salary), position(position), password(password)
{ }
Employee::~Employee()
{ }
void Employee::Show()
{
    cout<< "Ma Nhan vien: " << this->ID << "; ";
    cout << "Chuc vu: ";
    if (this->position == manager) cout << "quan li; ";
    if (this->position == salesperson) cout << "nhan vien; ";   
    this->Person::Show();
    cout<< "; Luong: " << this->salary << endl;
}
ostream& operator<<(ostream& o, const Employee& e){
    Person *p = new Employee();
    *p = e;
    o << "Ma Nhan vien: " << e.ID << "; ";
    o << "Chuc vu: ";
    if (e.position == manager) o << "quan li";
    if (e.position == salesperson) o << "nhan vien; ";
    p->Person::Show();
    o << "; Luong: " << e.salary << "; ";
    delete p;
    return o;
}
unsigned int Employee::getSalary()
{
    return this->salary;
}
void Employee::setSalary(unsigned int newSalary)
{
    this->salary = newSalary;
}

Position Employee::getPosition()
{
    return this->position;
}
void Employee::setPositon(Position newPosition)
{
    this->position = newPosition;
}
string Employee::getPassword(){
    return this->password;
}
void Employee::setPassword(string p){
    this->password = p;
}
bool Employee::changePassword(){
    string old_pass, new_pass;
    do{
        cout << "Nhap mat khau cu: "; cin >> old_pass;
        if (old_pass != this->password && old_pass != "x")
            cout << "SAI MAT KHAU, vui long nhap lai hoac nhan 'x' de quay ve menu chinh" << endl;
        else break;
    } while (old_pass != this->password && old_pass != "x");
    if (old_pass == "x")
        return false;
    cout << "Nhap mat khau moi: "; cin >> new_pass;
    this->setPassword(new_pass);
    cout << "Doi mat khau thanh cong" << endl;
    system("pause");
    return true;
}

