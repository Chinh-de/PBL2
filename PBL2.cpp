#include <iomanip>
#include <conio.h>
#include <string.h>
#include <iostream>
#include "CusManage.h"
#include "EmpManage.h"
#include "InvManage.h"
#include "ProdManage.h"
#include "Database.h"
using namespace std;
Database& myDatabase = Database::DB_Instance();
CusManage& customerManage = myDatabase.getCusManage();
EmpManage& employeeManage = myDatabase.getEmpManage();
ProdManage& productManage = myDatabase.getProdManage();
InvManage& invoiceManage = myDatabase.getInvManage();
Employee* user;

bool login();
bool check_userID(string);
void MenuManager();
void MenuEmployee();
void title();
int main()
{
    title();
    int Close;
    Database::readData();
    lg1:;
    Close = 0;
    if(login()){
        system("cls");
        cout << "Dang nhap thanh cong" << endl;
        system("pause");
    }
    else goto lg2;
    if (user->getID() == 0){
        return 0;
    }
    if (user->getPosition() == manager)
        MenuManager();
    else if (user->getPosition() == salesperson)
        MenuEmployee();
    lg2:;
    Database::saveData();
    cout << "\n\t Dong chuong trinh?\n\t   1:Co   0:Khong\n";
    cin >> Close;
    if (Close == 1) return 1;
    else goto lg1;
    return 0;
}
void title() {
    system("cls");
    cout << "\t\t\t\tTRUONG DAI HOC BACH KHOA - DAI HOC DA NANG\n";
    cout << "\t\t\t\t\t KHOA CONG NGHE THONG TIN\n\n";
    cout << "\t\t\t\t\tDU AN CO SO LAP TRINH\n";
    cout << "\t\t\t XAY DUNG HE THONG QUAN LI KINH DOANH LAPTOP\n\n";
    cout << "\tNguoi huong dan: ThS. Mai Van Ha\n\n";
    cout << "\tSinh vien thuc hien:\n";
    cout << "\tTen: Nguyen Che Dinh\tMa sinh vien: 102220223\tLop: 22T_DT5\tNhom:22Nh14a\n";
    cout << "\tTen: Nguyen Trieu Huy\tMa sinh vien: 102220233\tLop: 22T_DT5\tNhom:22Nh14a\n";
    cout << "\t\t\t\t\t ***copyright by Dinh & Huy***\n";
    cout << "\n\n\t\t\t\t~~~~~~ NHAN PHIM BAT KI DE TIEP TUC ~~~~~~";
    _getch();
    system("cls");
}
bool login(){
    int userID;
    string id;
    string password;
    system("cls");
    Node<Employee>* temp;
    cout << endl << "DANG NHAP" << endl;
    cout << "Ma nhan vien: "; cin >> id;
    while (1){
        if (id == "x") return false;
        if (!check_userID(id)){
            cout << "Ma nhan vien chi duoc chua so 0-9: ";
            cin >> id;
        }
        else 
        {
            userID = stoi(id);
            temp = employeeManage.find(userID);
            if (temp == nullptr){
                cout << "Ma nhan vien khong ton tai: ";
                cin >> id;
            }
            else break;
        }
    } 
    cout << "Mat khau: ";
    password = "";
    char ch;
    while (true) {
        ch = _getch();

        if (ch == 13) // Enter 
            break;
        else if (ch == 8) { // Backspace 
            if (!password.empty()) {
                cout << "\b \b"; //xoa bot *
                password.pop_back();
            }
        }
        else {
            password.push_back(ch);
            cout << '*';
        }
    }
    while (temp->data.getPassword() != password){
        system("cls"); 
        if (password == "x") return false;               
        cout << "Sai mat khau, vui long nhap lai: ";
        ch = 0; password = ""; 
        while (true) {
            ch = _getch();

            if (ch == 13) // Enter 
                break;
            else if (ch == 8) { // Backspace 
                if (!password.empty()) {
                    cout << "\b \b"; //xoa bot *
                    password.pop_back();
                }
            }
            else {
                password.push_back(ch);
                cout << '*';
            }
        }

    }
    user = &(temp->data);
    return true;
}
bool check_userID(string id){
    for (int i = 0; i < id.length(); i++){
        if (!isdigit(id[i]))
          return false;
    }
    return true;
}
void MenuEmployee()
{
    int option, t;
    bool over = false;
    int id, next_option, d, m, y;
    string sid;
    do{
        option = 1;
        do{
            system("cls");
            cout << ((option == 1) ? "->" : "  ") << "Thong tin ca nhan" << endl;
            cout << ((option == 2) ? "->" : "  ") << "San pham" << endl;
            cout << ((option == 3) ? "->" : "  ") << "Khach hang" << endl;
            cout << ((option == 4) ? "->" : "  ") << "Ban hang" << endl;
            cout << ((option == 5) ? "->" : "  ") << "Lich su ban hang" << endl;
            cout << ((option == 6) ? "->" : "  ") << "Doi mat khau" << endl;
            cout << ((option == 7) ? "->" : "  ") << "Dang xuat" << endl;
            t = getch();
            if (t == 72) option--;
            else if (t == 80) option++;
            if (option < 1) option = 7;
            if (option > 7) option = 1;
        } while (t != 13);
        switch (option){
            case 1:
                system("cls");
                user->Show();
                cout << endl;
                system("pause");
                break;
            case 2:
                next_option = 1;
                do{
                    system("cls");
                    cout << ((next_option == 1) ? "->" : "  ") << "Danh sach san pham" << endl;
                    cout << ((next_option == 2) ? "->" : "  ") << "Tim san pham" << endl;
                    cout << ((next_option == 3) ? "->" : "  ") << "Quay lai" << endl;
                    t = getch();
                    if (t == 72) next_option--;
                    else if (t == 80) next_option++;
                    if (next_option < 1) next_option = 3;
                    if (next_option > 3) next_option = 1;
                }while(t != 13);
                switch (next_option){
                    case 1:
                        productManage.displayOption();
                        break;
                    case 2:
                        system("cls");
                        sid;
                        cout << "Nhap ID san pham: "; cin >> sid;
                        productManage.find(sid)->data.show();
                        break;
                    case 3:
                        break;
                }
                system("pause");
                break;
            case 3:
                next_option = 1;
                do{
                    system("cls");
                    cout << ((next_option == 1) ? "->" : "  ") << "Danh sach khach hang" << endl;
                    cout << ((next_option == 2) ? "->" : "  ") << "Tim khach hang" << endl;
                    cout << ((next_option == 3) ? "->" : "  ") << "Quay lai" << endl;
                    t = getch();
                    if (t == 72) next_option--;
                    else if (t == 80) next_option++;
                    if (next_option < 1) next_option = 3;
                    if (next_option > 3) next_option = 1;
                }while(t != 13);
                if(next_option == 1){
                    system("cls");
                    customerManage.display();
                    system("pause");
                }
                else if (next_option == 2){
                    int find_option = 1;
                    do {
                        system("cls");
                        cout << ((find_option == 1) ? "->" : "  ") << "Tim theo ma khach hang" << endl;
                        cout << ((find_option == 2) ? "->" : "  ") << "Tim theo ten va so dien thoai" << endl;
                        cout << ((find_option == 3) ? "->" : "  ") << "Huy" << endl;
                        t = getch();
                        if (t == 72) find_option--;
                        else if (t == 80) find_option++;
                        if (find_option < 1) find_option = 3;
                        if (find_option > 3) find_option = 1;
                    } while (t != 13);
                    if (find_option == 1) {
                        system("cls");
                        cout << "Nhap ma khach hang: "; cin >> id;
                        Node<Customer>* fcus = customerManage.find(id);
                        if(fcus!= nullptr)
                        {
                            cout << "__________________________________________________________________________" << endl;
                            fcus->data.Show();
                            cout << endl << "Lich su mua hang: " << endl << endl;
                            invoiceManage.find(fcus->data).display();
                        }
                        else
                        {
                            cout << "Khong tim thay khach hang nay!" << endl;
                        }
                        system("pause");
                    }
                    else if (find_option == 2){
                        system("cls");
                        string name, phone;
                        cout << "Ten khach hang: "; cin >> name;
                        cout << "So dien thoai: "; cin >> phone;
                        Node<Customer>* fcus = customerManage.find(name, phone);
                        if(fcus!= nullptr)
                        {
                            cout << "__________________________________________________________________________" << endl;
                            fcus->data.Show();
                            cout << endl << "Lich su mua hang: " << endl << endl;
                            invoiceManage.find(fcus->data).display();
                        }
                        else
                        {
                            cout << "Khong tim thay khach hang nay! " << endl;
                        }
                        system("pause");
                    }
                }
                break;
            case 4:
                invoiceManage.sell(user->getID(), customerManage, productManage, employeeManage);
                break;                
            case 5:
                next_option = 1;
                do{
                    system("cls");
                    cout << ((next_option == 1) ? "->" : "  ") << "Tim hoa don" << endl;
                    cout << "Danh sach hoa don:" << endl;
                    cout << ((next_option == 2) ? "->" : "  ") << "Theo nam" << endl;
                    cout << ((next_option == 3) ? "->" : "  ") << "Theo thang" << endl;
                    cout << ((next_option == 4) ? "->" : "  ") << "Theo ngay" << endl;
                    cout << ((next_option == 5) ? "->" : "  ") << "Quay lai" << endl;
                    t = getch();
                    if (t == 72) next_option--;
                    else if (t == 80) next_option++;
                    if (next_option < 1) next_option = 5;
                    if (next_option > 5) next_option = 1;
                }while(t != 13);
                switch (next_option){
                    case 1:
                        cout << "Nhap ma hoa don: "; cin >> id;
                        cout << "_________________________________________________________________________________" << endl;
                        invoiceManage.findtoShow(id);
                        system("pause");
                        break;
                    case 2:
                        cout << "Nhap nam: "; cin >> y;
                        cout << "_________________________________________________________________________________" << endl;
                        invoiceManage.find(y).display();
                        system("pause");
                        break;
                    case 3:
                        cout << "Nhap lan luot thang, nam: "; cin >> m >> y;
                        cout << "_________________________________________________________________________________" << endl;
                        invoiceManage.find(m, y).display();
                        system("pause");
                        break;
                    case 4:
                        cout << "Nhap lan luot ngay, thang, nam: "; cin >> d >> m >> y;
                        cout << "_________________________________________________________________________________" << endl;
                        invoiceManage.find(d, m, y).display();
                        system("pause");
                        break;
                    case 5:
                        break;
                }
                break;
            case 6:
                user->changePassword();
                system("pause");
                break;
            case 7:
                over = true;
                break;
        }
    } while(over != true);    
}
void MenuManager()
{
    int option, t;
    bool over = false;
    int id, next_option, d, m, y;
    string sid;
    do{
        option = 1;
        do{
            system("cls");
            cout << ((option == 1) ? "->" : "  ") << "Thong tin ca nhan" << endl;
            cout << ((option == 2) ? "->" : "  ") << "Thong ke ban hang" << endl;
            cout << ((option == 3) ? "->" : "  ") << "Quan li san pham" << endl;
            cout << ((option == 4) ? "->" : "  ") << "Quan li nhan vien" << endl;
            cout << ((option == 5) ? "->" : "  ") << "Quan li khach hang" << endl;
            cout << ((option == 6) ? "->" : "  ") << "Ban hang" << endl;
            cout << ((option == 7) ? "->" : "  ") << "Lich su ban hang" << endl;
            cout << ((option == 8) ? "->" : "  ") << "Doi mat khau" << endl;
            cout << ((option == 9) ? "->" : "  ") << "Dang xuat" << endl;
            t = getch();
            if (t == 72) option--;
            else if (t == 80) option++;
            if (option < 1) option = 9;
            if (option > 9) option = 1;
        } while (t != 13);
        system("cls");
        switch(option){
            case 1:
                system("cls");
                user->Show();
                system("pause");
                break;
            case 2:
                next_option = 1;
                do{
                    system("cls");
                    cout << ((next_option == 1) ? "->" : "  ") << "Hien thi theo nam: " <<endl;
                    cout << ((next_option == 2) ? "->" : "  ") << "Hien thi theo thang: " <<endl;
                    cout << ((next_option == 3) ? "->" : "  ") << "Hien thi theo ngay: " <<endl;
                    cout << ((next_option == 4) ? "->" : "  ") << "Quay lai" <<endl;
                    t = getch();
                    if (t == 72) next_option--;
                    else if (t == 80) next_option++;
                    if (next_option < 1) next_option = 4;
                    if (next_option > 4) next_option = 1;
                }while(t != 13);
                switch (next_option){
                    case 1:
                        cout << "Nhap nam: "; cin >> y;
                        invoiceManage.statistic(invoiceManage.find(y));
                        system("pause");
                        break;
                    case 2:
                        cout << "Nhap lan luot thang, nam: "; cin >> y;
                        invoiceManage.statistic(invoiceManage.find(m, y));
                        system("pause");
                        break;
                    case 3:
                        cout << "Nhap lan luot ngay, thang, nam: "; cin >> d >> m >> y;
                        invoiceManage.statistic(invoiceManage.find(d, m, y));
                        system("pause");
                        break;
                    case 4:
                        break;
                }
                break;
            case 3:
                next_option = 1;
                do{
                    system("cls");
                    cout << ((next_option == 1) ? "->" : "  ") << "Danh sach san pham" << endl;
                    cout << ((next_option == 2) ? "->" : "  ") << "Tim san pham" << endl;
                    cout << ((next_option == 3) ? "->" : "  ") << "Them mau san pham moi" << endl;
                    cout << ((next_option == 4) ? "->" : "  ") << "Cap nhat thong tin san pham" << endl;
                    cout << ((next_option == 5) ? "->" : "  ") << "Xoa mau san pham" << endl;
                    cout << ((next_option == 6) ? "->" : "  ") << "Them san pham moi" << endl;
                    cout << ((next_option == 7) ? "->" : "  ") << "Quay lai" << endl;
                    t = getch();
                    if (t == 72) next_option--;
                    else if (t == 80) next_option++;
                    if (next_option < 1) next_option = 7;
                    if (next_option > 7) next_option = 1;
                }while(t != 13);
                switch(next_option){
                    case 1:
                        productManage.displayOption();
                        system("pause");
                        break;
                    case 2:
                        system("cls");
                        cout << "Nhap ID san pham: "; cin >> sid;
                        if(productManage.find(sid) == nullptr) cout << endl << "Khong tim thay san pham nay" << endl;
                        else productManage.find(sid)->data.show();
                        system("pause");
                        break;
                    case 3:
                        system("cls");
                        productManage.add();
                        break;
                    case 4:
                        system("cls");
                        cout << "Nhap ID san pham can cap nhat: "; cin >> sid;
                        productManage.update(productManage.find(sid)->data);
                        system("pause");
                        break;
                    case 5:
                        system("cls");
                        cout << "Nhap ID mau san pham can xoa: "; cin >> sid;
                        productManage.remove(productManage.find(sid)->data);
                        system("pause");
                        break;
                    case 6:
                        system("cls");
                        string seri;
                        int count;
                        cout << "Nhap ma san pham can them: "; 
                        cin >> sid;
                        Node<product>* prod = productManage.find(sid);
                        if (prod == nullptr)
                        {
                            cout << "Ma san pham nhap vao khong ton tai!" << endl;
                        }
                        else
                        {
                            cout << "Nhap so luong can them: "; cin >> count;
                            for (int i = 0; i < count; i++)
                            {
                                cout << "Nhap so serial thu " << i+1 << ": "; cin >> seri;
                                prod->data.addSerial(seri);
                                cout << endl << "Them thanh cong san pham co so serial: " << seri << endl;
                            }
                        }
                        cout << endl << endl << endl;
                        system("pause");
                        break;
                }
                break;
            case 4:
                next_option = 1;
                do{
                    system("cls");
                    cout << ((next_option == 1) ? "->" : "  ") << "Danh sach nhan vien" << endl;
                    cout << ((next_option == 2) ? "->" : "  ") << "Tim nhan vien" << endl;
                    cout << ((next_option == 3) ? "->" : "  ") << "Them nhan vien moi" << endl;
                    cout << ((next_option == 4) ? "->" : "  ") << "Cap nhat thong tin nhan vien" << endl;
                    cout << ((next_option == 5) ? "->" : "  ") << "Xoa nhan vien" << endl;
                    cout << ((next_option == 6) ? "->" : "  ") << "Quay lai" << endl;
                    t = getch();
                    if (t == 72) next_option--;
                    else if (t == 80) next_option++;
                    if (next_option < 1) next_option = 6;
                    if (next_option > 6) next_option = 1;
                }while(t != 13);
                switch (next_option){
                    case 1:
                        system("cls");
                        employeeManage.display();
                        system("pause");
                        break;
                    case 2:
                    {
                        system("cls");
                        int find_option = 1;
                        do {
                            system("cls");
                            cout << ((find_option == 1) ? "->" : "  ") << "Tim theo ma nhan vien" << endl;
                            cout << ((find_option == 2) ? "->" : "  ") << "Tim theo ten va so dien thoai" << endl;
                            t = getch();
                            if (t == 72) find_option--;
                            else if (t == 80) find_option++;
                            if (find_option < 1) find_option = 2;
                            if (find_option > 2) find_option = 1;
                        } while (t != 13);
                        if (find_option == 1) {
                            system("cls");
                            cout << "Nhap ma nhan vien: "; cin >> id;
                            cout << endl;
                            Node<Employee>* femp = employeeManage.find(id);
                            if(femp!= nullptr)
                                femp->data.Show();
                            else
                                cout << "Khong tim thay nhan vien nay!" << endl;
                            system("pause");
                        }
                        else{
                            system("cls");
                            string name, phone;
                            cin.ignore();
                            cout << "Ten khach hang: "; getline(cin, name);
                            cout << "So dien thoai: "; cin >> phone;
                            Node<Employee>* femp = employeeManage.find(id);
                            cout << endl;
                            if(femp!= nullptr)
                                femp->data.Show();
                            else
                                cout << "Khong tim thay nhan vien nay!" << endl;
                            system("pause");
                        }
                        break;
                    }
                    case 3:
                        system("cls");
                        employeeManage.add();
                        system("pause");
                        break;
                    case 4:
                        system("cls");
                        cout << "Nhap ID nhan vien: "; cin >> id;
                        employeeManage.update(employeeManage.find(id)->data);
                        system("pause");
                        break;
                    case 5:
                        system("cls");
                        cout << "Nhap ID nhan vien: "; cin >> id;
                        employeeManage.remove(employeeManage.find(id)->data);
                        system("pause");
                        break;
                    case 6:
                        break;
                }
                break;
            case 5:
                next_option = 1;
                do{
                    system("cls");
                    cout << ((next_option == 1) ? "->" : "  ") << "Danh sach khach hang" << endl;
                    cout << ((next_option == 2) ? "->" : "  ") << "Tim khach hang" << endl;
                    cout << ((next_option == 3) ? "->" : "  ") << "Quay lai" << endl;
                    t = getch();
                    if (t == 72) next_option--;
                    else if (t == 80) next_option++;
                    if (next_option < 1) next_option = 3;
                    if (next_option > 3) next_option = 1;
                }while(t != 13);
                switch (next_option){
                    case 1:
                        customerManage.display();
                        system("pause");
                        break;
                    case 2:
                        int find_option = 1;
                        do {
                            system("cls");
                            cout << ((find_option == 1) ? "->" : "  ") << "Tim theo ma khach hang" << endl;
                            cout << ((find_option == 2) ? "->" : "  ") << "Tim theo ten va so dien thoai" << endl;
                            t = getch();
                            if (t == 72) find_option--;
                            else if (t == 80) find_option++;
                            if (find_option < 1) find_option = 2;
                            if (find_option > 2) find_option = 1;
                        } while (t != 13);
                        if (find_option == 1) {
                            system("cls");
                            cout << "Nhap ma khach hang: "; cin >> id;
                            Node<Customer>* fcus = customerManage.find(id);
                            if(fcus!= nullptr)
                            {
                                cout << "__________________________________________________________________________" << endl;
                                fcus->data.Show();
                                cout << endl << "Lich su mua hang: " << endl << endl;
                                invoiceManage.find(fcus->data).display();
                            }
                            else
                            {
                                cout << "Khong tim thay khach hang nay!" << endl;
                            }
                            system("pause");
                        }
                        else {
                            system("cls");
                            string name, phone;
                            cin.ignore();
                            cout << "Ten khach hang: "; getline(cin, name);
                            cout << "So dien thoai: "; cin >> phone;
                            Node<Customer>* fcus = customerManage.find(name, phone);
                            if(fcus!= nullptr)
                            {
                                cout << "__________________________________________________________________________" << endl;
                                fcus->data.Show();
                                cout << endl << "Lich su mua hang: " << endl << endl;
                                invoiceManage.find(fcus->data).display();
                            }
                            else
                            {
                                cout << "Khong tim thay khach hang nay!" << endl;
                            }
                            system("pause");
                        }
                        break;
                }
                break;
            case 6:
                invoiceManage.sell(user->getID(), customerManage, productManage, employeeManage);
                break;
            case 7:
                next_option = 1;
                do{
                    system("cls");
                    cout << ((next_option == 1) ? "->" : "  ") << "Tim hoa don" << endl;
                    cout << "Danh sach hoa don:" << endl;
                    cout << ((next_option == 2) ? "->" : "  ") << "Theo nam" << endl;
                    cout << ((next_option == 3) ? "->" : "  ") << "Theo thang" << endl;
                    cout << ((next_option == 4) ? "->" : "  ") << "Theo ngay" << endl;
                    cout << ((next_option == 5) ? "->" : "  ") << "Quay lai" << endl;
                    t = getch();
                    if (t == 72) next_option--;
                    else if (t == 80) next_option++;
                    if (next_option < 1) next_option = 5;
                    if (next_option > 5) next_option = 1;
                }while(t != 13);
                switch (next_option){
                    case 1:
                        cout << "Nhap ma hoa don: "; cin >> id;
                        cout << "_________________________________________________________________________________" << endl;
                        invoiceManage.findtoShow(id);
                        system("pause");
                        break;
                    case 2:
                        cout << "Nhap nam: "; cin >> y;
                        cout << "_________________________________________________________________________________" << endl;
                        invoiceManage.find(y).display();
                        system("pause");
                        break;
                    case 3:
                        cout << "Nhap lan luot thang, nam: "; cin >> m >> y;
                        cout << "_________________________________________________________________________________" << endl;
                        invoiceManage.find(m, y).display();
                        system("pause");
                        break;
                    case 4:
                        cout << "Nhap lan luot ngay, thang, nam: "; cin >> d >> m >> y;
                        cout << "_________________________________________________________________________________" << endl;
                        invoiceManage.find(d, m, y).display();
                        system("pause");
                        break;
                    case 5:
                        break;
                }
                break;
            case 8:
                user->changePassword();
                system("pause");
                break;
            case 9:
                user = nullptr;
                over = true;
                break;
        } 
    }while(over != true);
}