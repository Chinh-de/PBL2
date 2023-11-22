#include "list.cpp"
#include "order.h"
#include "Date.h"
#include <iostream>
#include <string>
using namespace std;

class invoice : 
{
    private:
        int invoiceID;
        int employeeID;
        int customerID;
        unsigned int total;
        Date date;
        list<order> listOfOrder;
    public:
        invoice();
        ~invoice();
        void updateTotal();
        int getInvoiceID();
        int getEmployeeID();
        int getCustomerID();
        unsigned int getTotal();
        Date getDate();
        void setInvoiceID(int&);
        void setEmployeeID(int&);
        void setCustomerID(int&);
        void setDate(string&, string&, string&);
        void addOrder(order&);
        void removeOrder(const string&);
        void updateTotal();

};