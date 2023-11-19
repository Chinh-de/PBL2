#include "invoice.h"

invoice::invoice()
{
    this->invoiceID = 0;
    this->customerID = 0;
    this->employeeID = 0;
    this->total = 0;
}

invoice::~invoice()
{   }

void invoice::updateTotal()
{
  //code thêm hàm duyệt list  
}

int invoice::getInvoiceID()
{
    return this->invoiceID;
}

int invoice::getEmployeeID()
{
    return this->employeeID;
}

int invoice::getCustomerID()
{
    return this->customerID;
}

unsigned int invoice::getTotal()
{
    this->updateTotal();
    return this->total;
}

Date invoice::getDate()
{
    return this->date;
}

void invoice::setInvoieID(int& ID)
{
    this->invoiceID = ID;
}

void invoice::setEmployeeID(int& ID)
{
    this->employeeID = ID;
}
        
void invoice::setCustomerID(int& ID)
{
    this->customerID = ID;
}

void invoice::setDate(sring& year, string& month, string& day)
{
    this->date.setYear(year);
    this->date.setMonth(month);
    this->date.setDay(day);
}

void invoice::addOrder(order&)
{
    this->listOfOrder.add(order);
}

void invoice::removeOrder(productID)
{
    order rOrder;
    //duyet qua listOfOder tim phan tu
    listOfOrder.remove(rOrder);
}