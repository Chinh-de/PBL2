#include "EmpManage.h"

EmpManage::EmpManage()
{ }
EmpManage::~EmpManage()
{ }
void EmpManage::add(const Employee& e) {
    this->Emp.add(e);
}
void EmpManage::readfromfile(string file){
    ifstream inputFile(file);
    int ID; 
    bool gender;
    string temp, name, phone, email, address, pass;
    unsigned int salary;
    Position pos;
    if (inputFile.is_open()) 
    {
        string line;
        while (getline(inputFile, line))
        {
            istringstream iss(line);
            iss >> ID;
            iss.ignore(); 
            getline(iss, name, '|');
            getline(iss, phone, '|');
            getline(iss, email, '|');
            getline(iss, temp, '|');
            if(temp == "Nu") gender = true;
            else gender = false;
            getline(iss, address, '|');
            iss >> salary;
            iss.ignore();
            getline(iss, temp, '|');
            if(temp == "manager") pos = manager;
            else pos = salesperson;
            getline(iss, pass, '|');
            Employee newemp(ID, name, phone, email, gender, address, salary, pos, pass);
            this->Emp.addAtEnd(newemp);
        }
        inputFile.close();
    } else {
        cerr << "Khong the mo file" << file << endl; //bao loi
    }
}
void EmpManage::writetofile(string file)
{
    ofstream outputFile(file, ios::out | ios::trunc);
    if (outputFile.is_open()) {
        for (Node<Employee>* current = this->Emp.getHead(); current != nullptr; current = current->next) {
            Employee currentEmp = current->data;
            outputFile << currentEmp.getID() << "|";
            outputFile << currentEmp.getName() << "|";
            outputFile << currentEmp.getPhone() << "|";
            outputFile << currentEmp.getEmail() << "|";
            if (currentEmp.getGender() == true) outputFile << "Nu|";
            else outputFile << "Nam|";
            outputFile << currentEmp.getAddress() << "|";
            outputFile << currentEmp.getSalary() << "|";
            if (currentEmp.getPosition() == manager ) outputFile << "manager|";
            else if (currentEmp.getPosition() == salesperson ) outputFile << "salesperson|";
            outputFile << currentEmp.getPassword() << "|";
            outputFile << endl;
        }
        outputFile.close();
    } else {
        cerr << "Khong the ghi du lieu" << endl;
    }
}
void EmpManage::add(){
    int ID; unsigned int salary;
    string name, phone, email, address, password, pos;
    bool gender;
    Position position;
    cout << "Nhap thong tin: " << endl;
    ID = this->getNewID(); cin.ignore();
    cout << "Ten nhan vien: "; getline(cin, name);
    cout << "So dien thoai: "; getline(cin, phone);
    cout << "Email: "; getline(cin, email);
    cout << "Gioi tinh(Nam = 0, Nu = 1): "; cin >> gender; cin.ignore();
    cout << "Dia chi: "; getline(cin, address);
    cout << "Luong: "; cin >> salary; cin.ignore();
    cout << "Vi tri cong viec (manager hoac salesperson): "; getline(cin, pos);
    if (pos == "manager") position = manager;
    if (pos == "salesperson") position = salesperson;  
    cout << "Dat mat khau tai khoan nhan vien: "; getline(cin, password);
    Employee e(ID, name, phone, email, gender, address, salary, position, password);
    this->Emp.add(e);
}
void EmpManage::remove(Employee& e){
    this->Emp.remove(e);
}
void EmpManage::display(){
    this->Emp.display();
}
void EmpManage::update(Employee& _emp) 
{
    int ID = _emp.getID();
    Employee& _employee = this->find(ID)->data;
    int input;
    int choice = 1;
    int MaxChoice = 7;

    do {
        system("cls");
        cout << "Nhap thong tin nhan vien:" << endl;
        cout << (choice == 1 ? "->" : "  ") << "Ten: " << _employee.getName() << endl;
        cout << (choice == 2 ? "->" : "  ") << "SDT: " << _employee.getPhone() << endl;
        cout << (choice == 3 ? "->" : "  ") << "Email: " << _employee.getEmail() << endl;
        cout << (choice == 4 ? "->" : "  ") << "Gioi tinh: " << (_employee.getGender() ? "Nu" : "Nam") << endl;
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
                    cout << "Nhap gioi tinh (1: Nu, 0: Nam): ";
                    cin >> gender;
                    cin.ignore(); 
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
Node<Employee>* EmpManage::find(string& name, string& phone)
{
    Node<Employee>* Found;
    if( name == "x" && phone == "x" ) return Found;
    Node<Employee>* tempNode;
    tempNode = this->Emp.getHead();
    while (tempNode != nullptr) 
    {
        if ( ( tempNode->data.getName() == name || name == "x" ) && ( tempNode->data.getPhone() == phone || phone == "x" ) ) 
            Found = tempNode;
        tempNode = tempNode->next;
    }
    return Found;
}

int EmpManage::getNewID()
{
    Node<Employee>* Nemp = this->Emp.getHead();
    if(Nemp == nullptr) return 100;
    return Nemp->data.getID() + 1;
}