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
        system("cls");
        if (option == 1) cout << "\t>";
        cout << "\tThong tin ca nhan" << endl;
        if (option == 2) cout << "\t>";
        cout <<"\tThong ke ban hang" << endl;
        if (option == 3) cout << "\t>";
        cout << "\tQuan li san pham" << endl;
        if (option == 4) cout << "\t>";
        cout << "\tQuan li nhan vien" << endl;
        if (option == 5) cout << "\t>";
        cout << "\tBan hang" << endl;
        if (option == 6) cout << "\t>";
        cout << "\tQuan li khach hang" << endl;
        if (option == 7) cout << "\t>";
        cout << "\tLich su ban hang" << endl;
        if (option == 8) cout << "\t>";
        cout << "\tDoi mat khau" << endl;
        if (option == 9) cout << "\t>";
        cout << "\tThoat" << endl;
        t = getch();
        if (t == 72) option--;
        else if (t == 80) option++;
        if (option < 1) option = 9;
        if (option > 9) option = 1;
    } while (t != 13);
    system("cls");
    switch (option){
        case 1:
            user.Show();
            break;
        case 2:
            cout << 

    }
}
