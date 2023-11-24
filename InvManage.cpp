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