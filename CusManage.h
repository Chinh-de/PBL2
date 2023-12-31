#include "Customer.h"
#include "list.cpp"
#include "Manage.h"
#pragma once

class CusManage : public Manage<Customer> {
    protected:
        list<Customer> Cus;
    public:
        CusManage();
        ~CusManage();
        void readfromfile(string);
        void writetofile(string);
        void add(const Customer&);
        void remove(Customer&);
        void update(Customer&);
        void display();
        Node<Customer>* find(int&);
        Node<Customer>* find(string&, string&);
        int getNewID();
};