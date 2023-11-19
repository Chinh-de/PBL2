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
        //chi khai bao thong tin lien quan khong khai doi tuong
    public:
        invoice();
        ~invoice();


};