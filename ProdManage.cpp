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

void ProdManage::sort(bool type)
{
    //type = false sap xep tu giam, = true tang 
    
    //tao ban sao cua danh sach san pham
    list<product> sortprice;
    Node<product>* tempNode = this->Prod.getHead();
    while (tempNode != nullptr) 
    {
        sortprice.add(tempNode->data);
        tempNode = tempNode->next;
    }    
    sortprice.mergeSort(sortprice.getHead(),type);
    sortprice.display();
}