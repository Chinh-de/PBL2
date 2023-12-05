#include "list.cpp"
#include "order.h"
#include "Date.h"
#include <iostream>
#include <string>
#pragma once
using namespace std;

class invoice
{
    private:
        int invoiceID;
        int employeeID;
        int customerID;
        unsigned int total;
        string payment;
        Date date;
        list<order> listOfOrder;
        bool status; //true da hoan thanh; false chua hoan thanh 
    public:
        invoice();
        invoice(int, int, int, unsigned int, string, const Date&);
        invoice(const invoice&);
        ~invoice();
        invoice& operator=(const invoice&);
        void show();
        friend ostream& operator<<(ostream&, const invoice&);
        bool operator!=(const invoice&);
        bool operator==(const invoice&);
        void updateTotal();
        int getInvoiceID();
        int getEmployeeID();
        int getCustomerID();
        unsigned int getTotal();
        unsigned int getProfit();
        unsigned int productSales();
        Date getDate();
        string getPayment();
        void setInvoiceID(int&);
        void setEmployeeID(int&);
        void setCustomerID(int&);
        void setPayment(string&);
        void addOrder(order&);
        list<order>& getOrder();
        void removeOrder(const string&);
        Node<order>* findOrder(const string &);
        void updateDate();
        void complete();
};