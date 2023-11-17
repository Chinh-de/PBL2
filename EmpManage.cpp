#include "EmpManage.h"

EmpManage::EmpManage()
{ }
EmpManage::~EmpManage()
{ }
void EmpManage::add(const& Employee e) {
    this->Emp.add(e);
}
void EmpManage::remove(const& Employee e){
    this->Emp.remove(e);
}
void EmpManage::display(){
    this->Emp.display();
}