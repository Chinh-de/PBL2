#include "EmpManage.h"

EmpManage::EmpManage()
{ }
EmpManage::~EmpManage()
{ }
void EmpManage::add(const Employee& e) {
    this->Emp.add(e);
}
void EmpManage::readfromfile(string file){
    ifstream input(file);
    int n = 0;
    string info[10];
    while(!input.eof()){
        n = 0
        Node<Employee>* tempNode = this->Emp.getHead();
        do {
            char c;
            string Data = "";
            input.get(c);
            while (c != '|' && c != '\n' && !input.eof()){
                Data += c;
                input.get(c);
            }
            info[n] = Data;
            n++;
        } while(n <= 8);
        tempNode->data.setID(stoi(info[0]));
        tempNode->data.setName(info[1]);
        tempNode->data.setPhone(info[2]);
        tempNode->data.setEmail(info[3]);
        tempNode->data.setGender((info[4] == "Nu"));
        tempNode->data.setAddress(info[5]);
        tempNode->data.setSalary(stoi(info[6]));
        tempNode->data.setPositon(info[7] == "manager" ? manager : salesperson);
        tempNode->data.setPassword(info[8]);
        this->Emp.addAtEnd(tempNode->data);
        tempNode = tempNode->next;
    }
    input.close();
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
void EmpManage::update(Employee& _employee) {
    int input;
    int choice = 1;
    int MaxChoice = 7;

    do {
        system("cls");
        cout << "Nhap thong tin nhan vien:" << endl;
        cout << (choice == 1 ? "->" : "  ") << "Ten: " << _employee.getName() << endl;
        cout << (choice == 2 ? "->" : "  ") << "SDT: " << _employee.getPhone() << endl;
        cout << (choice == 3 ? "->" : "  ") << "Email: " << _employee.getEmail() << endl;
        cout << (choice == 4 ? "->" : "  ") << "Gioi tinh: " << (_employee.getGender() ? "Nam" : "Nu") << endl;
        cout << (choice == 5 ? "->" : "  ") << "Dia chi: " << _employee.getAddress() << endl;
        cout << (choice == 6 ? "->" : "  ") << "Luong: " << _employee.getSalary() << endl;
        cout << (choice == 7 ? "->" : "  ") << "Thoat" << endl;
        input = getch();

        if (input == 80) {
            if (choice == MaxChoice) choice = 1;
            else choice++;
        } else if (input == 72) {
            if (choice == 1) choice = MaxChoice;
            else choice--;
        }
        string name, phone, mail, address;
        bool gender;
        unsigned int salary;

        if (input == 13) {
            switch (choice) {
                case 1:
                    cout << "Nhap ten moi: ";
                    getline(cin, name);
                    _employee.setName(name);
                    break;
                case 2:
                    cout << "Nhap so dien thoai moi: ";
                    getline(cin, phone);
                    _employee.setPhone(phone);
                    break;
                case 3:
                    cout << "Nhap email moi: ";
                    getline(cin, mail);
                    _employee.setEmail(mail);
                    break;
                case 4:
                    cout << "Nhap gioi tinh (1: Nam, 0: Nu): ";
                    cin >> gender;
                    _employee.setGender(gender);
                    break;
                case 5:
                    cout << "Nhap dia chi moi: ";
                    getline(cin, address);
                    _employee.setAddress(address);
                    break;
                case 6:
                    cout << "Nhap luong moi: ";
                    cin >> salary;
                    _employee.setSalary(salary);
                    break;
                case 7:
                    cout << "Da thoat khoi cap nhat" << endl;
                    return;
                default:
                    cout << "Loi du lieu" << endl;
            }
        }
    } while (input != '0');
}

Node<Employee>* EmpManage::find(int& ID)
{
    Employee tempEmp;
    tempEmp.setID(ID);
    return this->Emp.find(tempEmp);
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