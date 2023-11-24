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