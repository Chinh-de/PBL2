#include <iomanip>
#include "invoice.h"
#include "list.cpp"
#include "Manage.h"
#include "CusManage.h"
#include "ProdManage.h"
#include "EmpManage.h"
#pragma once

class InvManage : public Manage<invoice> {
    protected:
        list<invoice> Inv;
    public:
        InvManage();
        ~InvManage();
        void add(const invoice&);
        void remove(const invoice&);
        void update(invoice&);
        void display();
        list<invoice> find(int&, int&, int&);
        list<invoice> find(int&, int&);
        list<invoice> find(int&);
        Node<invoice>* findID(int&);
        void statistic(list<invoice>);
        void printInvoice(int, CusManage, EmpManage);
        int getNewID();
        void sell(int, CusManage&, ProdManage&, EmpManage&);
        void updateCart(invoice&, ProdManage&, CusManage& ,EmpManage&);
        void readfromfile(string, string);
        void writetofile(string, string);
};