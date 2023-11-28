#include "CusManage.h"
#include "ProdManage.h"
#include "InvManage.h"
#include "Employee.h"
Employee::Employee(int ID, string name, string phoneNumber, string email, bool gender, string address, unsigned int salary, Position positon)
    :Person(ID, name, phoneNumber, email, gender, address)
{
    this->salary = salary;
    this->position = position;
}
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
    invoice newInv;
    newInv.setInvoiceID(invID);

    //lay thong tin nhan vien khach hang set cho hoa don
    newInv.setCustomerID(cusID);
    newInv.setEmployeeID(empID);

    //lay thoi gian hien tai set cho hoa don
    newInv.updateDate();

    //vong lap them san pham: nhap IDsp, nhap sl, nhap serial;
    choice = 1;
    MaxChoice = 3;
    system("cls");
    cout << newInv;
    cout << endl << "lua chon tren gio hang:" << endl;
        cout << (choice == 1 ? "->":"  ") << "Them san pham " << endl;
        cout << (choice == 2 ? "->":"  ") << "Loai bo san pham " << endl;
        cout << (choice == 3 ? "->":"  ") << "Thoat " << endl;
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
    if(input == 13)  //phim enter
    {
        string newProductID;
        int newQuantity;
        int i;
        order newOrder;
        string newSerial;
        Node<order>* tempNode;
        product tempProd;
        switch (choice)
        {
            using namespace std;
            case 1:
                cout << "Nhap ma san pham: ";
                while(1)
                {
                    cin >> newProductID;
                    tempProd = prodmanage.find(newProductID);
                    if(tempProd.getID != 0) break;
                    else cout << "Khong ton tai san pham voi ma san pham nay. Vui long nhap lai ma san pham: "; 
                }
                tempNode = newInv.findOrder(newProductID); 
                if( tempNode != null)
                {
                        //truong hop loai san pham da co trong gio hang
                    cout << "Nhap so luong san pham can them: ";
                    cin >> newQuantity;
                    //nhap vao so luong serial tuong ung
                    for (i = 1; i <= newQuantity ; i++)
                    {
                        cout << "Nhap serial san pham thu: " << i << ": ";
                        //kiem tra serial co ton tai trong database khong?
                        while(1)
                        {
                            cin >> newSerial;
                            if(tempProd.isSerial(newSerial)) break;
                            else cout << "Serial nhap vao khong ton tai. " << "Nhap lai serial san pham thu: " << i << ": ";
                        }
                        //dua serial tu lop san pham ra gio hang
                        tempProd.removeSerial(newSerial); //chi thay doi gia tri cua ban sao
                        tempNode->data.addSerial(newSerial);
                        cout << endl <<"Them thanh cong " << newSerial;
                    }

                }
                else
                {
                        
                }


                
                // //neu da ton tai thi tro newOrder den, neu chua thi khoi tao thuoc tinh cho newOrder;
                // if( tempNode != null) newOrder = &tempNode->data;
                // else{
                //         newOrder->setID(newProductID);
                //         newOrder->setName(tempProd.getName());
                //         newOrder->setPrice(tempProd.getPrice());
                //         newOrder->setQuantity(0);
                //     }
                // cout << "Nhap so luong san pham can them: ";
                // cin >> newQuantity;
                // newOrder.setQuantity(newOrder.getQuantity + newQuantity);
                // //nhap vao so luong serial tuong ung
                // for (i = 1; i <= newQuantity ; i++)
                // {
                //     cout << "Nhap serial san pham thu: " << i << ": ";
                //     //kiem tra serial co ton tai trong database khong?
                //     while(1)
                //     {
                //         cin >> newSerial;
                //         if(tempProd.isSerial(newSerial)) break;
                //         else cout << "Serial nhap vao khong ton tai. " << "Nhap lai serial san pham thu: " << i << ": ";
                //     }
                //     //dua serial tu lop san pham ra gio hang
                //     tempProd.removeSerial(newSerial); 
                //     newOrder.addSerial(newSerial);
                // }
                
                // newInv.addOrder(newOrder);
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

    //dua trang thai hoa don thanh hoan thanh goi complete();
    //goi ham in hoa don    
} 
