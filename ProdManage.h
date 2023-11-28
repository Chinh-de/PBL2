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
        void add(const product&);
        void add();
        void remove(const product&);
        void update(product&);
        void display();
        void display(bool);
        void displayOption();
        product find(string &);
        list<product> filter(); 
};