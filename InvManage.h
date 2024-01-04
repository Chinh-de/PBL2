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
        void remove(invoice&);
        void update(invoice&);
        void display();
        list<invoice> find(int&, int&, int&); //tim hoa don theo thoi gian ngay/thang/nam
        list<invoice> find(int&, int&); // _ theo thang/nam
        list<invoice> find(int&); // _ theo nam
        list<invoice> find(Customer&); //lich su mua hang
        Node<invoice>* findID(int&); // tim theo ID
        void statistic(list<invoice>);
        void printInvoice(int, CusManage, EmpManage); //in hoa don ra file
        void printInvoice(invoice&, CusManage, EmpManage); //in ra man hinh hoa don demo
        void findtoShow(int& ID); //tim hoa don va hien thi hoa don chi tiet ra man hinh
        int getNewID(); //lay ma hoa don moi
        void sell(int, CusManage&, ProdManage&, EmpManage&); //ban hang
        void updateCart(invoice&, ProdManage&, CusManage& ,EmpManage&); //quan li gio hang
        void readfromfile(string, string);
        void writetofile(string, string);
};