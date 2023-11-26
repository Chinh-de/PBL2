#include "InvManage.h"
InvManage::InvManage()
{ }
InvManage::~InvManage()
{ }
void InvManage::add(const invoice& c) {
    this->Inv.add(c);
}
void InvManage::remove(const invoice& c){
    this->Inv.remove(c);
}
void InvManage::display(){
    this->Inv.display();
}
void InvManage::update(invoice&){
    cout << "123";
}
list<invoice> InvManage::find(int& d, int& m, int& y){
    list<invoice> tempList;
    Node<invoice>* tempNode;
    tempNode = this->Inv.getHead();
    while (tempNode != nullptr) 
    {
        if (tempNode->data.getDate().getDay() == d && tempNode->data.getDate().getMonth() == m && tempNode->data.getDate().getYear() == y)   
            tempList.add(tempNode->data);
        tempNode = tempNode->next;
    }
    if ( tempList.getHead() == nullptr ) cout << "khong tim thay!";
    delete tempNode;
    return tempList;
}
list<invoice> InvManage::find(int& m, int& y){
    list<invoice> tempList;
    Node<invoice>* tempNode;
    tempNode = this->Inv.getHead();
    while (tempNode != nullptr) 
    {
        if (tempNode->data.getDate().getMonth() == m && tempNode->data.getDate().getYear() == y)   
            tempList.add(tempNode->data);
        tempNode = tempNode->next;
    }
    if ( tempList.getHead() == nullptr ) cout << "khong tim thay!";
    delete tempNode;
    return tempList;
}
list<invoice> InvManage::find(int& n){
    list<invoice> tempList;
    Node<invoice>* tempNode;
    tempNode = this->Inv.getHead();
    while (tempNode != nullptr) 
    {
        if (tempNode->data.getDate().getYear() == n)   
            tempList.add(tempNode->data);
        else if (tempNode->data.getCustomerID() == n)   
            tempList.add(tempNode->data);
        tempNode = tempNode->next;
    }
    if ( tempList.getHead() == nullptr ) cout << "khong tim thay!";
    delete tempNode;
    return tempList;
}
void InvManage::statistic(list<invoice>& List){
    Node<invoice>* tempNode;
    tempNode = List.getHead();
    int revenue = 0; //doanh thu
    int profit = 0; //loi nhuan
    int sales = 0; //so luong san pham ban duoc 
    while (tempNode != nullptr){
        revenue += tempNode->data.getTotal();
        profit += tempNode->data.getProfit();
        sales += tempNode->data.productSales();
    }
    cout << "Thong ke ngay: " << endl;
    cout << "Doanh thu: " << revenue << endl
    << "Loi nhuan: " << profit << endl
    << "san pham ban duocL " << sales << endl;
    delete tempNode;
}

invoice InvManage::printInvoice(int& ID, list<Customer>& cusList)
{
    //in hoa don ra man hinh
    //in hoa don ra file trong folder hoa don
    Node<invoice>* tempInv;
    tempInv = this->Inv.getHead();
    while (tempInv != nullptr){
        if(tempInv->data.getInvoiceID() == ID)
            break;
        else tempInv = tempInv->next;
    }
    if (tempInv == nullptr) return *tempInv;
    Node<Customer>* tempCus;
    tempCus = cusList.getHead();
    while (tempCus != nullptr){
        if(tempCus->data.getID() == tempInv->data.getCustomerID)
            break;
        else tempCus = tempCus->next;
    }
    if (tempCus == nullptr) return *tempInv;
    << "Ten khach hang: " << tempCus->data.getName() << endl
    << "So dien thoai: " <<tempCus->data.getPhone() << endl;
    Node<order>* tempOrder;
    Node<string>* tempSerial;
    tempOrder = tempInv->data.listOfOrder.getHead();
    tempSerial = tempOrder->data.serial.getHead();
    while (tempOrder != nullptr){
        cout << "Ten hang: " << tempOrder->data.getName() << endl
        << "So luong: " << tempOrder->data.getQuantity() << endl
        << "Don gia: " << tempOrder->data.getPrice() << endl
        << "Thanh tien: " << tempOrder->data.getTotal() << endl;
        while (tempSerial != nullptr){
            if (tempSerial->next == nullptr)
                cout << tempSerial->data << endl;
            else 
                cout << tempSerial->data << ", ";
        }
        cout << "Tong cong: " << tempInv->data.getTotal() << endl;
    }
}
/*
void InvManage::sell()
{
    //swich case chon
    //khach hang cu: chon tim theo ID or SDT
    //khach hang moi: tao khach hang moi kh1, add khach hang vo roi goi qlkh.update(kh1.getid)
    
    //tao hoa don moi voi ID hoa don +1 tu cai hoa don gan nhat
    //lay thong tin nhan vien khach hang set cho hoa don
    //lay thoi gianhien tai set cho hoa don
    //vong lap them san pham: nhap IDsp, nhap sl, nhap serial;
    //dua trang thai hoa don thanh hoan thanh goi complete();
    //goi ham in hoa don    
} */
int InvManage::getEndID()
{
    return this->Inv.getHead()->data.getInvoiceID();
}
