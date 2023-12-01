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

void read();
void login();
void MenuManager();
void MenuEmployee();
int main()
{
   // product bug;
   // string s1 = "seri1", s2 = "seri2";
   // bug.addSerial(s1);
   // bug.addSerial(s2);
   // cout << bug;
   // bug.show();
   // productManage.add(bug);
    //productManage.display();
    //docfile dang nhap
    //docfile person
    //docfile lichsumuahang
    cout << "abc\n";
    read();
    cout << "abc\n";
    int Close;
    cout << "abc\n";
    //productManage.display();
    //employeeManage.display();
    //invoiceManage.display();
    //customerManage.display();
    system("pause");
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
void read(){
    customerManage.readfromfile("customer.txt");
    employeeManage.readfromfile("employee.txt");
    productManage.readfromfile("product.txt");
    //invoiceManage.readfromfile("invoice.txt", "invoice_detail.txt");
}
void login(){
    int userID;
    string password;
    system("cls");
    do{
        cout << "DANG NHAP" << endl << "Ten tai khoan: "; cin >> userID; 
        cout << "Mat khau: "; cin >> password;
        Employee temp;
        temp = employeeManage.find(userID)->data;
        if (temp.getID() != 0){
            if (temp.getPassword() == password){                
                user = temp;
                system("cls");
                cout << "Dang nhap thanh cong" << endl;
                system("pause");
            }
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
                user.Show();
                system("pause");
                break;
            case 2:
                next_option = 1;
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
                    sid;
                    cout << "Nhap ID san pham: "; cin >> sid;
                    productManage.find(sid)->data.show();
                }
                system("pause");
                break;
            case 3:
                next_option = 1;
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
                if(next_option == 1){
                    system("cls");
                    customerManage.display();
                    system("pause");
                }
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
                        cout << "Nhap ma khach hang: "; cin >> id;
                        customerManage.find(id)->data.Show();
                        system("pause");
                    }
                    else {
                        system("cls");
                        string name, phone;
                        cout << "Ten khach hang: "; cin >> name;
                        cout << "So dien thoai: "; cin >> phone;
                        customerManage.find(name, phone)->data.Show();
                        system("pause");
                    }
                }
                break;
            case 4:
                // user.sell(customerManage, productManage, invoiceManage);
                cout << "Het hang roi";
                system("pause");
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
                    t = getch();
                    if (t == 72) next_option--;
                    else if (t == 80) next_option++;
                    if (next_option < 1) next_option = 4;
                    if (next_option > 4) next_option = 1;
                }while(t != 13);
                switch (next_option){
                    case 1:
                        cout << "Nhap ma hoa don: "; cin >> id;
                        invoiceManage.find(id).display();
                        system("pause");
                        break;
                    case 2:
                        cout << "Nhap nam: "; cin >> y;
                        invoiceManage.find(y).display();
                        system("pause");
                        break;
                    case 3:
                        cout << "Nhap lan luot thang, nam: "; cin >> m >> y;
                        invoiceManage.find(m, y).display();
                        system("pause");
                        break;
                    case 4:
                        cout << "Nhap lan luot ngay, thang, nam: "; cin >> d >> m >> y;
                        invoiceManage.find(d, m, y).display();
                        system("pause");
                        break;
                }
                break;
            case 6:
                user.changePassword();
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
                user.Show();
                system("pause");
                break;
            case 2:
                next_option = 1;
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
                    cout << "Nhap nam: "; cin >> y;
                    invoiceManage.statistic(invoiceManage.find(y));
                    system("pause");
                }
                else if (next_option == 2){
                    cout << "Nhap lan luot thang, nam: "; cin >> y;
                    invoiceManage.statistic(invoiceManage.find(m, y));
                    system("pause");
                }
                else {
                    cout << "Nhap lan luot ngay, thang, nam: "; cin >> d >> m >> y;
                    invoiceManage.statistic(invoiceManage.find(d, m, y));
                    system("pause");
                }
                break;
            case 3:
                next_option = 1;
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
                        system("pause");
                        break;
                    case 2:
                        system("cls");
                        cout << "Nhap ID san pham: "; cin >> sid;
                        productManage.find(sid)->data.show();
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
                        cout << "Nhap ID san pham can xoa: "; cin >> sid;
                        productManage.remove(productManage.find(sid)->data);
                        system("pause");
                        break;
                    case 6:
                        system("cls");
                        string seri;
                        cout << "Nhap ID san pham can them so seri: "; cin >> sid;
                        cout << "Nhap so seri: "; cin >> seri;
                        productManage.find(sid)->data.addSerial(seri);
                        system("pause");
                        break;
                }
                break;
            case 4:
                next_option = 1;
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
                        system("pause");
                        break;
                    case 2:
                        system("cls");
                        employeeManage.add();
                        system("pause");
                        break;
                    case 3:
                        system("cls");
                        cout << "Nhap ID nhan vien: "; cin >> id;
                        employeeManage.update(employeeManage.find(id)->data);
                        system("pause");
                        break;
                    case 4:
                        system("cls");
                        cout << "Nhap ID nhan vien: "; cin >> id;
                        employeeManage.remove(employeeManage.find(id)->data);
                        system("pause");
                        break;
                }
                break;
            case 5:
                next_option = 1;
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
                if(next_option == 1){
                    customerManage.display();
                    system("pause");
                } 
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
                        cout << "Nhap ma khach hang: "; cin >> id;
                        customerManage.find(id)->data.Show();
                        system("pause");
                    }
                    else {
                        system("cls");
                        string name, phone;
                        cout << "Ten khach hang: "; cin >> name;
                        cout << "So dien thoai: "; cin >> phone;
                        customerManage.find(name, phone)->data.Show();
                        system("pause");
                    }
                }
                break;
            case 6:
                invoiceManage.sell(user.getID(), customerManage, productManage);
                cout << "Het hang roi";
                system("pause");
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
                    t = getch();
                    if (t == 72) next_option--;
                    else if (t == 80) next_option++;
                    if (next_option < 1) next_option = 4;
                    if (next_option > 4) next_option = 1;
                }while(t != 13);
                switch (next_option){
                    case 1:
                        cout << "Nhap ma hoa don: "; cin >> id;
                        invoiceManage.find(id).display();
                        system("pause");
                    case 2:
                        cout << "Nhap nam: "; cin >> y;
                        invoiceManage.find(y).display();
                        system("pause");
                    case 3:
                        cout << "Nhap lan luot thang, nam: "; cin >> m >> y;
                        invoiceManage.find(m, y).display();
                        system("pause");
                    case 4:
                        cout << "Nhap lan luot ngay, thang, nam: "; cin >> d >> m >> y;
                        invoiceManage.find(d, m, y).display();
                        system("pause");
                }
                break;
            case 8:
                user.changePassword();
                system("pause");
                break;
            case 9:
                over = true;
                break;
        } 
    }while(over != true);
}