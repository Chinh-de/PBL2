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
        void add(const Customer&);
        void remove(const Customer&);
        void update(Customer&);
        void display();
        Node<Customer>* find(int&);
        list<Customer> find(string&, string&);
        int getNewID();
};