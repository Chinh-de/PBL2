#include <iomanip>
#include <conio.h>
#include <string.h>
#include <iostream>
#include "CusManage.h"
#include "EmpManage.h"
#include "InvManage.h"
#include "ProdManage.h"
using namespace std;
// khai bao them tai nguyen

CusManage customerManage;
EmpManage employeeManage;
ProdManage productManage;
InvManage invoiceManage;
Employee user;

void login();
void MenuManager();
void MenuEmployee();
int main()
{
    //docfile dang nhap
    //docfile person
    //docfile lichsumuahang
    customerManage.read();
    int Close;
    lg:;
    Close = 0;
    login();
    if (user.getPosition() == manager)
        MenuManager();
    else if (user.getPosition() == salesperson)
        MenuEmployee();
    cout << "\n\t Dong chuong trinh?\n\t\t1:Co   0:Khong\n";
    cin >> Close;
    if (Close == 1) return 1;
    else goto lg;
}
void login(){
    int userID;
    string password;
    system("cls");
    do{
        cout << "DANG NHAP" << endl << "Ten tai khoan: "; cin >> userID; 
        cout << "Mat khau: "; cin >> password;
        Employee temp;
        temp = employeeManage.find(userID);
        if (temp != nullptr){
            if (temp.getPassword() == password)
                user = temp;
                system("cls");
                cout << "Dang nhap thanh cong";
                system("pause");
            else {
                system("cls");
                cout << "Sai mat khau!";
            }
        }
        else {
            system("cls");
            cout << "Sai ten tai khoan!";
        }
    } while (user.getID() == 0 && userID != 0 && password != "x");
}

void MenuEmployee()
{
    //swichcase
    /*
    1. Cá nhân -> gọi show() thông tin nhân viên;
    2. sản phẩm-> gọi hàm show danh sách sản phẩm từ qlsp  -> 1.sắp xếp theo giá tăng 2. giá giảm 3. tìm kiếm 4. trở lại
    3. Bán hàng -> qlđơnhàng.new gọi đến qlkh.new or .tìm để thêm khách hàng. nhập sp+sl, gọi quản lí sản phẩm để kiểm tra còn hàng ko. tính tiền , nhập phương thức thanh toán, lấy giờ , in hóa đơn, giảm số lượng sp.  
    4. khách hàng: 1.xem danh sách qlkh.show()   2.tìm khách hàng qlsh.tim ->show ra thông tin kh.show + lịch sử mua hàng qldonhang.tim 3. thêm kh
    5.đổi mk//code sau
    */
    int option, t;
    bool over = false;
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
        switch option{
            case 1:
                system("cls");
                user.Show();
                break;
            case 2:
                int next_option = 1;
                do{
                    system("cls");
                    cout << ((next_option == 1) ? "->" : "  ") << "Danh sach san pham" << endl;
                    cout << ((next_option == 2) ? "->" : "  ") << "Tim san pham" << endl;
                    if (t == 72) next_option--;
                    else if (t == 80) next_option++;
                    if (next_option < 1) next_option = 2;
                    if (next_option > 2) next_option = 1;
                }while(t != 13);
                if (next_option == 1)
                    productManage.displayOption();
                else {
                    system("cls");
                    string id;
                    cout << "Nhap ID san pham: "; cin >> id;
                    productManage.find(id).show();
                }
                break;
            case 3:
                int next_option = 1;
                do{
                    system("cls");
                    cout << ((next_option == 1) ? "->" : "  ") << "Danh sach khach hang" << endl;
                    cout << ((next_option == 2) ? "->" : "  ") << "Tim khach hang" << endl;
                    t = getch();
                    if (t == 72) next_option--;
                    else if (t == 80) next_option++;
                    if (next_option < 1) next_option = 2;
                    if (next_option > 2) next_option = 1;
                }while(t != 13);
                if(next_option == 1)
                    customerManage.display();
                else {
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
                        int id;
                        cout << "Nhap ma khach hang: "; cin >> id;
                        customerManage.find(id);
                    }
                    else {
                        system("cls");
                        string name, phone;
                        cout << "Ten khach hang: "; cin >> name;
                        cout << "So dien thoai: "; cin >> phone;
                        customerManage.find(name, phone);
                    }
                }
                break;
            case 4:
                // user.sell(customerManage, productManage, invoiceManage);
                cout << "Het hang roi";
                break;                
            case 5:
                int next_option = 1;
                do{
                    system("cls");
                    cout << ((next_option == 1) ? "->" : "  ") << "Tim hoa don" << endl;
                    cout << "Danh sach hoa don:" << endl;
                    cout << ((next_option == 2) ? "->" : "  ") << "Theo nam" << endl;
                    cout << ((next_option == 3) ? "->" : "  ") << "Theo thang" << endl;
                    cout << ((next_option == 4) ? "->" : "  ") << "Theo ngay" << endl;
                    t = getch();
                    if (t == 72) next_option--;
                    else if (t == 80) next_option++;
                    if (next_option < 1) next_option = 4;
                    if (next_option > 4) next_option = 1;
                }while(t != 13);
                switch (next_option){
                    case 1:
                        int id;
                        cout << "Nhap ma hoa don: "; cin >> id;
                        invoiceManage.find(id).display();
                    case 2:
                        int y;
                        cout << "Nhap nam: "; cin >> y;
                        invoiceManage.find(y).display();
                    case 3:
                        int m, y;
                        cout << "Nhap lan luot thang, nam: "; cin >> m >> y;
                        invoiceManage.find(m, y).display();
                    case 4:
                        int d, m, y;
                        cout << "Nhap lan luot ngay, thang, nam: "; cin >> d >> m >> y;
                        invoiceManage.find(d, m, y).display();
                }
                break;
            case 6:
                user.changePassword();
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
                user.Show();
                break;
            case 2:
                int next_option = 1;
                do{
                    system("cls");
                    cout << ((next_option == 1) ? "->" : "  ") << "Hien thi theo nam: " <<endl;
                    cout << ((next_option == 2) ? "->" : "  ") << "Hien thi theo thang: " <<endl;
                    cout << ((next_option == 3) ? "->" : "  ") << "Hien thi theo ngay: " <<endl;
                    t = getch();
                    if (t == 72) next_option--;
                    else if (t == 80) next_option++;
                    if (next_option < 1) next_option = 3;
                    if (next_option > 3) next_option = 1;
                }while(t != 13);
                if (next_option == 1){
                    int y;
                    cout << "Nhap nam: "; cin >> y;
                    invoiceManage.statistic(invoiceManage.find(y));
                }
                else if (next_option == 2){
                    int m, y;
                    cout << "Nhap lan luot thang, nam: "; cin >> y;
                    invoiceManage.statistic(invoiceManage.find(m, y));
                }
                else {
                    int d, m, y;
                    cout << "Nhap lan luot ngay, thang, nam: "; cin >> d >> m >> y;
                    invoiceManage.statistic(invoiceManage.find(d, m, y));
                }
                break;
            case 3:
                int next_option = 1;
                do{
                    system("cls");
                    cout << ((next_option == 1) ? "->" : "  ") << "Danh sach san pham" << endl;
                    cout << ((next_option == 2) ? "->" : "  ") << "Tim san pham" << endl;
                    cout << ((next_option == 3) ? "->" : "  ") << "Them loai san pham moi" << endl;
                    cout << ((next_option == 4) ? "->" : "  ") << "Cap nhat thong tin san pham" << endl;
                    cout << ((next_option == 5) ? "->" : "  ") << "Xoa san pham" << endl;
                    cout << ((next_option == 6) ? "->" : "  ") << "Them so seri san pham" << endl;
                    t = getch();
                    if (t == 72) next_option--;
                    else if (t == 80) next_option++;
                    if (next_option < 1) next_option = 6;
                    if (next_option > 6) next_option = 1;
                }while(t != 13);
                switch(next_option){
                    case 1:
                        productManage.displayOption();
                        break;
                    case 2:
                        system("cls");
                        string id;
                        cout << "Nhap ID san pham: "; cin >> id;
                        productManage.find(id).show();
                        break;
                    case 3:
                        system("cls");
                        productManage.add();
                        break;
                    case 4:
                        system("cls");
                        string id;
                        cout << "Nhap ID san pham can cap nhat: "; cin >> id;
                        productManage.update(productManage.find(id));
                        break;
                    case 5:
                        system("cls");
                        string id;
                        cout << "Nhap ID san pham can xoa: "; cin >> id;
                        productManage.remove(productManage.find(id));
                        break;
                    case 6:
                        system("cls");
                        string id;
                        string seri;
                        cout << "Nhap ID san pham can them so seri: "; cin >> id;
                        cout << "Nhap so seri: "; cin >> seri;
                        productManage.find(id).addSerial(seri);
                        break;
                }
                break;
            case 4:
                int next_option = 1;
                do{
                    system("cls");
                    cout << ((next_option == 1) ? "->" : "  ") << "Danh sach nhan vien" << endl;
                    cout << ((next_option == 2) ? "->" : "  ") << "Them nhan vien moi" << endl;
                    cout << ((next_option == 3) ? "->" : "  ") << "Cap nhat thong tin nhan vien" << endl;
                    cout << ((next_option == 4) ? "->" : "  ") << "Xoa nhan vien" << endl;
                    t = getch();
                    if (t == 72) next_option--;
                    else if (t == 80) next_option++;
                    if (next_option < 1) next_option = 4;
                    if (next_option > 4) next_option = 1;
                }while(t != 13);
                switch (next_option){
                    case 1:
                        system("cls");
                        employeeManage.display();
                        break;
                    case 2:
                        system("cls");
                        employeeManage.add();
                        break;
                    case 3:
                        system("cls");
                        int id;
                        cout << "Nhap ID nhan vien: "; cin >> id;
                        employeeManage.update(employeeManage.find(id));
                        break;
                    case 4:
                        system("cls");
                        int id;
                        cout << "Nhap ID nhan vien: "; cin >> id;
                        employeeManage.remove(employeeManage.find(id));
                        break;
                }
                break;
            case 5:
                int next_option = 1;
                do{
                    system("cls");
                    cout << ((next_option == 1) ? "->" : "  ") << "Danh sach khach hang" << endl;
                    cout << ((next_option == 2) ? "->" : "  ") << "Tim khach hang" << endl;
                    t = getch();
                    if (t == 72) next_option--;
                    else if (t == 80) next_option++;
                    if (next_option < 1) next_option = 2;
                    if (next_option > 2) next_option = 1;
                }while(t != 13);
                if(next_option == 1)
                    customerManage.display();
                else {
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
                        int id;
                        cout << "Nhap ma khach hang: "; cin >> id;
                        customerManage.find(id);
                    }
                    else {
                        system("cls");
                        string name, phone;
                        cout << "Ten khach hang: "; cin >> name;
                        cout << "So dien thoai: "; cin >> phone;
                        customerManage.find(name, phone);
                    }
                }
                break;
            case 6:
                // user.sell(customerManage, productManage, invoiceManage);
                cout << "Het hang roi";
                break;
            case 7:
                int next_option = 1;
                do{
                    system("cls");
                    cout << ((next_option == 1) ? "->" : "  ") << "Tim hoa don" << endl;
                    cout << "Danh sach hoa don:" << endl;
                    cout << ((next_option == 2) ? "->" : "  ") << "Theo nam" << endl;
                    cout << ((next_option == 3) ? "->" : "  ") << "Theo thang" << endl;
                    cout << ((next_option == 4) ? "->" : "  ") << "Theo ngay" << endl;
                    t = getch();
                    if (t == 72) next_option--;
                    else if (t == 80) next_option++;
                    if (next_option < 1) next_option = 4;
                    if (next_option > 4) next_option = 1;
                }while(t != 13);
                switch (next_option){
                    case 1:
                        int id;
                        cout << "Nhap ma hoa don: "; cin >> id;
                        invoiceManage.find(id).display();
                    case 2:
                        int y;
                        cout << "Nhap nam: "; cin >> y;
                        invoiceManage.find(y).display();
                    case 3:
                        int m, y;
                        cout << "Nhap lan luot thang, nam: "; cin >> m >> y;
                        invoiceManage.find(m, y).display();
                    case 4:
                        int d, m, y;
                        cout << "Nhap lan luot ngay, thang, nam: "; cin >> d >> m >> y;
                        invoiceManage.find(d, m, y).display();
                }
                break;
            case 8:
                user.changePassword();
                break;
            case 9:
                over = true;
                break;
        } 
    }while(over != true);
}