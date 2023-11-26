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
void invoice::show(){
    cout << "Ma hoa don: " << this->invoiceID << endl;
    cout << "Ma khach hang: " << this->customerID << endl;
    cout << "Ma nhan vien: " << this->employeeID << endl;
    cout << "Tong tien: " << this->total << endl;
    this->listOfOrder.display();
}
ostream& operator<<(ostream& o, const invoice& i)
{
    o << "Ma hoa don: " << i.invoiceID << endl;
    o << "Ma khach hang: " << i.customerID << endl;
    o << "Ma nhan vien: " << i.employeeID << endl;
    o << "Tong tien: " << i.total << endl;
    invoice *temp = new invoice();
    *temp = i;
    temp->listOfOrder.display();
    delete temp;
    return o;
}
bool invoice::operator!=(const invoice& i){
    return (this->invoiceID != i.invoiceID);
}
void invoice::updateTotal()
{
    this->total = 0;
    Node<order>* tempNode = this->listOfOrder.getHead();
    while (tempNode != nullptr) 
    {
        this->total += tempNode->data.getTotal();
        tempNode = tempNode->next;
    }
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
unsigned int invoice::getProfit(){
    unsigned int p = 0;
    Node<order>* tempNode = this->listOfOrder.getHead();
    while (tempNode != nullptr) 
    {
        p += tempNode->data.Profit();
        tempNode = tempNode->next;
    }
    return p;
}
unsigned int invoice::productSales(){
    unsigned int s = 0;
    Node<order>* tempNode = this->listOfOrder.getHead();
    while (tempNode != nullptr) 
    {
        s += tempNode->data.getQuantity();
        tempNode = tempNode->next;
    }
    return s;
}
Date invoice::getDate()
{
    return this->date;
}

void invoice::setInvoiceID(int& ID)
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

void invoice::setDate(int& year, int& month, int& day)
{
    this->date.setYear(year);
    this->date.setMonth(month);
    this->date.setDay(day);
}

void invoice::addOrder(order& o)
{
    this->listOfOrder.add(o);
}

void invoice::removeOrder(const int& ID)
{
    Node<order>* tempNode = this->listOfOrder.getHead();
     while (tempNode != nullptr) 
    {
        if (tempNode->data.getID() == ID) {
            listOfOrder.remove(tempNode->data);
            break;
        }
        tempNode = tempNode->next;
    }
    if (tempNode != nullptr) 
        listOfOrder.remove(tempNode->data);
    else cout << "Chua co san pham nay trong gio hang";
}
