#include "invoice.h"

invoice::invoice() 
    : invoiceID(0), employeeID(0), customerID(0),
     total(0), payment(""), status(false)
{   }
invoice::invoice(int invoiceID, int employeeID, int customerID,
         unsigned int total, string payment, const Date& date)
        : invoiceID(invoiceID), employeeID(employeeID), customerID(customerID),
         total(total), payment(payment), date(date), status(false)
{   }
invoice::invoice(const invoice& other)
{
    this->invoiceID = other.invoiceID;
    this->employeeID = other.employeeID;
    this->customerID = other.customerID;
    this->date = other.date;
    this->total = other.total;
    this->payment = other.payment;
    this->listOfOrder = other.listOfOrder;
    this->status = other.status;
}
invoice::~invoice()
{   }
void invoice::show(){
    cout << "Ma hoa don: " << this->invoiceID << endl;
    cout << "Ma khach hang: " << this->customerID << endl;
    cout << "Ma nhan vien: " << this->employeeID << endl;
    cout << "Phuong thuc thanh toan: " << this->payment << endl;
    cout << "Tong tien: " << this->total << endl;
    this->listOfOrder.display();
}
invoice& invoice::operator=(const invoice& other) {
    if (this != &other) {
        this->invoiceID = other.invoiceID;
        this->employeeID = other.employeeID;
        this->customerID = other.customerID;
        this->total = other.total;
        this->payment = other.payment;
        this->date = other.date;
        this->listOfOrder = other.listOfOrder;
        this->status = other.status;
    }
    return *this;
}
ostream& operator<<(ostream& o, const invoice& i)
{
    o << "Ma hoa don: " << i.invoiceID << endl;
    o << "Ma khach hang: " << i.customerID << endl;
    o << "Ma nhan vien: " << i.employeeID << endl;
    o << "Phuong thuc thanh toan: " << i.payment << endl;
    o << "Tong tien: " << i.total << endl;
    invoice *temp = new invoice();
    *temp = i;
    temp->listOfOrder.display();
    cout << "\t\t\t__________________________________________________" << endl;
    delete temp;
    return o;
}
bool invoice::operator!=(const invoice& i){
    return (this->invoiceID != i.invoiceID);
}
bool invoice::operator==(const invoice& i){
    return (this->invoiceID == i.invoiceID);
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
string invoice::getPayment()
{
    return this->payment;
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
    if(status == false) this->invoiceID = ID;
}

void invoice::setEmployeeID(int& ID)
{
    if(status == false) this->employeeID = ID;
}
        
void invoice::setCustomerID(int& ID)
{
   if(status == false) this->customerID = ID;
}
void invoice::setPayment(string& pay)
{
    if(status == false) this->payment = pay;
}
void invoice::addOrder(order& o)
{
    if(status == false) this->listOfOrder.add(o);
}

list<order>& invoice::getOrder()
{
    return this->listOfOrder;
}

void invoice::removeOrder(const string& ID)
{
    if(status == false) 
    {
        Node<order>* tempNode = this->findOrder(ID);
        if (tempNode != nullptr) 
            listOfOrder.remove(tempNode->data);
        else cout << endl << "Chua co san pham nay trong gio hang!";
    }
}
    
Node<order>* invoice::findOrder(const string& ID)
{
    order tempOrder;
    tempOrder.setID(ID);
    return this->listOfOrder.find(tempOrder);
}


void invoice::updateDate()
{
    if(status == false) getCurrent(this->date);
}
void invoice::complete()
{
    this->status = true;
}