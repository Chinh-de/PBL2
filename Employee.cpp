#include "Employee.h"
Employee::Employee(int ID, string name, string phoneNumber, string email, bool gender, string address, unsigned int salary, Position positon, string password)
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
    cout<< "; Luong: " << this->salary << "; ";
}
ostream& operator<<(ostream& o, const Employee& e){
    Person *p = new Employee();
    *p = e;
    o << "Ma Nhan vien: " << e.ID << "; ";
    o << "Chuc vu: ";
    if (e.position == manager) o << "quan li; ";
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
void Employee::setPassword(string& p){
    this->password = p;
}
bool Employee::changePassword(){
    string old_pass, new_pass;
    do{
        cout << "Nhap mat khau cu: "; cin >> old_pass;
        if (old_pass != this->password)
            cout << "SAI MAT KHAU, vui long nhap lai hoac nhan 'x' de quay ve menu chinh" << endl;
    } while (old_pass != this->password || old_pass != x);
    if (old_pass == "x")
        return false;
    cout << "Nhap mat khau moi: "; cin >> new_pass;
    this->setPassword(new_pass);
    cout << "Doi mat khau thanh cong";
    return true;
}

void Employee::sell(CusManage& cusmanage, ProdManage& prodmanage, InvManage& invmanage)
{
    int cusID, invID, empID = this->getID();
    int input;
    int choice = 1;
    int MaxChoice = 2;
    system("cls");
    cout<<"Khach hang da mua hang truoc day chua:"<< endl;
        cout << (choice == 1 ? "->":"  ") << "Khach hang cu: " << endl;
        cout << (choice == 2 ? "->":"  ") << "Khach hang moi: " << endl;
        input = getch();

        if (input == 80) //phim mui ten xuong
        { 
            if (choice == MaxChoice) choice = 1; // quay tro lai dau danh sach
            else choice++;
        }else if (input == 72) //phim mui ten len
        {
            if (choice == 1) choice = MaxChoice; //chay vong xuong cuoi danh sach
            else choice--;
        }
    Customer newcus;
    string cusphone, x = "x";
    if(input == 13)  //phim enter
    {
        switch (choice)
        {
            using namespace std;
            case 1:
                cout << "Nhap so dien thoai de tim kiem khach hang: ";
                cin >> cusphone;
                newcus = cusmanage.find(x,cusphone).getHead(); //chi tim bang so dien thoai bo qua ten
                cout << newcus << endl;
                cusID = newcus.getID();
                break;
            case 2:
                cusID =cusmanage.getEndID() + 1;
                newcus.setID(cusID);
                cusmanage.add(newcus);
                cusmanage.update(newcus);            
                break;             
            default: cout << "Loi du lieu";
        }
    }
    //swich case chon
    //khach hang cu: chon tim theo ID or SDT
    //khach hang moi: tao khach hang moi kh1, add khach hang vo roi goi qlkh.update(kh1.getid)
    invID = invmanage.getEndID() +1;
    //tao hoa don moi voi ID hoa don +1 tu cai hoa don gan nhat
    invoice newinv;
    newinv.setInvoiceID(invID);
    //lay thong tin nhan vien khach hang set cho hoa don
    newinv.setCustomerID(cusID);
    newinv.setEmployeeID(empID);
    //lay thoi gianhien tai set cho hoa don
    //vong lap them san pham: nhap IDsp, nhap sl, nhap serial;
    //dua trang thai hoa don thanh hoan thanh goi complete();
    //goi ham in hoa don    
} 
