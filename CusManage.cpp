#include "CusManage.h"

CusManage::CusManage()
{ }
CusManage::~CusManage()
{ }
void CusManage::readfromfile(string file){
    ifstream input(file);
    int n = 0;
    string info[10];
    while(!input.eof()){
        n = 0;
        Node<Customer>* tempNode = this->Cus.getHead();
        do{
            char c;
            string Data = "";
            input.get(c);
            while (c != '|' && c != '\n' && !input.eof()){
                Data += c;
                input.get(c);
            }
            info[n] = Data;
            n++;
        }while (n <= 5);
        tempNode->data.setID(stoi(info[0]));
        tempNode->data.setName(info[1]);
        tempNode->data.setPhone(info[2]);
        tempNode->data.setEmail(info[3]);
        tempNode->data.setGender((info[4] == "Nu"));
        tempNode->data.setAddress(info[5]);
        this->Cus.addAtEnd(tempNode->data);
        tempNode = tempNode->next;
    }
    input.close();
}
void CusManage::add(const Customer& c) {
    this->Cus.add(c);
}
void CusManage::remove(const Customer& c){
    this->Cus.remove(c); 
}
void CusManage::display(){
    this->Cus.display();
}
void CusManage::update(Customer& _customer) {
    int input;
    int choice = 1;
    int MaxChoice = 6;

    do {
        system("cls");
        cout << "Nhap thong tin khach hang:" << endl;
        cout << (choice == 1 ? "->" : "  ") << "Ten: " << _customer.getName() << endl;
        cout << (choice == 2 ? "->" : "  ") << "SDT: " << _customer.getPhone() << endl;
        cout << (choice == 3 ? "->" : "  ") << "Email: " << _customer.getEmail() << endl;
        cout << (choice == 4 ? "->" : "  ") << "Gioi tinh: " << (_customer.getGender() ? "Nam" : "Nu") << endl;
        cout << (choice == 5 ? "->" : "  ") << "Dia chi: " << _customer.getAddress() << endl;
        cout << (choice == 6 ? "->" : "  ") << "Thoat" << endl;
        input = getch();

        if (input == 80) {
            if (choice == MaxChoice) choice = 1;
            else choice++;
        } else if (input == 72) {
            if (choice == 1) choice = MaxChoice;
            else choice--;
        }
        string name, phone, mail, adress;
        bool gender;

        if (input == 13) {
            switch (choice) {
                case 1:
                    cout << "Nhap ten moi: ";
                    getline(cin, name);
                    _customer.setName(name);
                    break;
                case 2:
                    cout << "Nhap so dien thoai moi: ";
                    getline(cin, phone);
                    _customer.setPhone(phone);
                    break;
                case 3:
                    cout << "Nhap email moi: ";
                    getline(cin, mail);
                    _customer.setEmail(mail);
                    break;
                case 4:
                    cout << "Nhap gioi tinh (1: Nu, 0: Nam): ";
                    cin >> gender;
                    _customer.setGender;
                    break;
                 case 5:
                    cout << "Nhap dia chi moi: ";
                    getline(cin, _customer.Address);
                    break;    
                case 6:
                    cout << "Da thoat khoi cap nhat" << endl;
                    return;
                default:
                    cout << "Loi du lieu" << endl;
            }
        }
    } while (input != '0');
}

Node<Customer>* CusManage::find(int& ID)
{
    Customer tempCus;
    tempCus.setID(ID);
    return this->Cus.find(tempCus);
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

int CusManage::getNewID()
{
    newID = this->Cus.getHead()->data.getID();
    if (!(newID < 10000)) return 10000; //khach hang dau tien se co ID 10000
    return this->Cus.getHead()->data.getID() + 1;
}
