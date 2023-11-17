#include "ProdManage.h"

ProdManage::ProdManage()
{ }
ProdManage::~ProdManage()
{ }
void ProdManage::add(const product& p) {
    this->Emp.add(p);
}
void ProdManage::remove(const product& p){
    this->Emp.remove(p);
}
void ProdManage::display(){
    this->Emp.display();
}
void ProdManage::update(){
    cout << "123";
}