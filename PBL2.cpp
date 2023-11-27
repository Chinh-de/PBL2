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
int checklogin(int&, string&);
void MenuManager();
void MenuEmplyee();
int main()
{
    //docfile dang nhap
    //docfile person
    //docfile lichsumuahang

    int userID;
    string password;
    system("cls");
    lg: {
        cout << "DANG NHAP" << endl << "Ten tai khoan: "; cin >> userID; 
        cout << "Mat khau: "; cin >> password;
        if(userID == "ql" && password == "ql") 
            MenuManager();
        // else if(strcmp(username), "nv" == 0 && strcmp(password), "nv" == 0)  MenuEmplyee();
        else goto lg;
    }

}
int checklogin(int& userID, string& password){
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
}

// void MenuEmployee()
// {
//     //swichcase
//     /*
//     1. Cá nhân -> gọi show() thông tin nhân viên;
//     2. sản phẩm-> gọi hàm show danh sách sản phẩm từ qlsp  -> 1.sắp xếp theo giá tăng 2. giá giảm 3. tìm kiếm 4. trở lại
//     3. Bán hàng -> qlđơnhàng.new gọi đến qlkh.new or .tìm để thêm khách hàng. nhập sp+sl, gọi quản lí sản phẩm để kiểm tra còn hàng ko. tính tiền , nhập phương thức thanh toán, lấy giờ , in hóa đơn, giảm số lượng sp.  
//     4. khách hàng: 1.xem danh sách qlkh.show()   2.tìm khách hàng qlsh.tim ->show ra thông tin kh.show + lịch sử mua hàng qldonhang.tim 3. thêm kh
//     5.đổi mk//code sau
//     */
// }
void MenuManager()
{
    int option = 1, t;
    do{
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
            cout << ((option == 9) ? "->" : "  ") << "Thoat" << endl;
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
                    cout << ((next_option == 2) ? "->" : "  ") << "Danh sach san pham" << endl;
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
                        int display_option = 1;
                        do{
                            system("cls");
                            cout << ((display_option == 1) ? "->" : "  ") << "Xem thuong" << endl;
                            cout << ((display_option == 2) ? "->" : "  ") << "Xem theo gia tang" << endl;
                            cout << ((display_option == 3) ? "->" : "  ") << "Xem theo gia giam" << endl;
                            t = getch();
                            if (t == 72) display_option--;
                            else if (t == 80) display_option++;
                            if (option < 1) display_option = 3;
                            if (option > 3) display_option = 1;
                        }while(t != 13);
                        if (display_option == 1) productManage.display();
                        else if (display_option == 2) productManage.display(true);
                        else productManage.display(false);
                        break;
                    case 2:
                        system("cls");
                        int id;
                        cout << "Nhap ID san pham: "; cin >> id;
                        productManage.find(id).show();
                    case 3:
                        system("cls");
                        productManage.add();
                        break;
                    case 4:
                        system("cls");
                        int id;
                        cout << "Nhap ID san pham can cap nhat: "; cin >> id;
                        productManage.update(productManage.find(id));
                        break;
                    case 5:
                        system("cls");
                        int id;
                        cout << "Nhap ID san pham can xoa: "; cin >> id;
                        productManage.remove(productManage.find(id));
                        break;
                    case 6:
                        system("cls");
                        int id;
                        string seri;
                        cout << "Nhap ID san pham can them so seri: "; cin >> id;
                        cout << "Nhap so seri: "; cin >> seri;
                        productManage.find(id).addSerial(seri);
                        break;
                }
            case 4:
                int next_option = 1
                do{
                    system("cls");
                    cout << ((next_option == 1) ? "->" : "  ") << "Danh sach nhan" << endl;
                    cout << ((next_option == 2) ? "->" : "  ") << "Them nhan vien moi" << endl;
                    cout << ((next_option == 3) ? "->" : "  ") << "Cap nhat thong tin nhan vien" << endl;
                    cout << ((next_option == 4) ? "->" : "  ") << "Xoa nhan vien" << endl;
                    cout << ((next_option == 5) ? "->" : "  ") << "Them so seri san pham" << endl;
                    t = getch();
                    if (t == 72) next_option--;
                    else if (t == 80) next_option++;
                    if (option < 1) next_option = 5;
                    if (option > 5) next_option = 1;
                }while(t != 13);
            
        } 
    }while(1);
}
