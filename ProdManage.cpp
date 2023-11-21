#include "ProdManage.h"

ProdManage::ProdManage()
{ }
ProdManage::~ProdManage()
{ }
void ProdManage::add(const product& p) {
    this->Prod.add(p);
}
void ProdManage::remove(const product& p){
    this->Prod.remove(p);
}
void ProdManage::display(){
    this->Prod.display();
}
void ProdManage::update(){
    cout << "123";
}