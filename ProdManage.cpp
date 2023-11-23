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
//void sort(bool type)
//{
    //type = 0 sap xep tu thap den cao, = 1 tu cao den thap
    
//}