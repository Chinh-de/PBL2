#include "Product.h"
#include "list.cpp"
#include "Manage.h"
#pragma once

class ProdManage : public Manage<product> {
    protected:
        list<product> Prod;
    public:
        ProdManage();
        ~ProdManage();
        void readfromfile(string);
        void add(const product&);
        void add();
        void remove(const product&);
        void update(product&);
        void display();
        void sort(bool);
        Node<product>* find(string&);
        void display(bool);
        void displayOption();
        list<product> filter(); 
};