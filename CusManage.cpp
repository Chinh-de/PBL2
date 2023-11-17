#include "CusManage.h"

CusManage::CusManage()
{ }
CusManage::~CusManage()
{ }
void CusManage::add(const Customer& c) {
    this->Cus.add(c);
}
void CusManage::remove(const Customer& c){
    this->Cus.remove(c);
}
void CusManage::display(){
    this->Cus.display();
}
void CusManage::update(){
    cout << "123";
}