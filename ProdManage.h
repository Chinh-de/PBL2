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
        void writetofile(string file);
        void add(const product&);
        void add();
        void remove(product&);
        void update(product&);
        void display();
        Node<product>* find(string&);
        void display(bool);
        void displayOption();
};