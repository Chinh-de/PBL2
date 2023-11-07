#include <iostream>
#include <string>
using namespace std;
// khai bao them tai nguyen
void login();
int checklogin();
void MenuManager();
void MenuEmplyee();
int main()
{
    //docfile dang nhap
    //docfile person
    //docfile lichsumuahang

    string accout, password;
    lg: {
    //dang nhap
    cin >> accout >> password;
    if(checklogin(accout, password) ==1) MenuManager();
    else if(checklogin(accout, password) ==2)  MenuEmplyee();
        else goto lg;
    }
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

}
void MenuManager()
{
    /* 
    1. cá nhân như trên
    2.thống kê: theo năm, theo tháng, theo ngày (chọn hãng hoặc tất cả) : bán bn sp, tổng tiền.
    3. sản phẩm. 1. hiển thị như trên 2. sửa 3. xóa 4. thêm mới
    4 nhân viên: xem danh sách, tìm nhân viên, sửa nhân viên, xóa nhân viên,thêm nv
    5. bán hàng như trên
    6. khách hàng: như trên
    7.đổi mk(code sau)
    */
}
