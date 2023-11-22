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
    // this->listOfOrder.display();
}
ostream& operator<<(ostream& o, const invoice& i)
{
    o << "Ma hoa don: " << i.invoiceID << endl;
    o << "Ma khach hang: " << i.customerID << endl;
    o << "Ma nhan vien: " << i.employeeID << endl;
    o << "Tong tien: " << i.total << endl;
    // i.listOfOrder.display();
    return o;
}
bool invoice::operator!=(const invoice& i){
    return (this->invoiceID != i.invoiceID);
}
void invoice::updateTotal()
{
  this->total = 0;
  Node<order>* tempNode = this->listOfOrder.head;
    while (tempNode != nullptr) 
    {
        this->total += tempNode->data.getTotal;
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

Date invoice::getDate()
{
    return this->date;
}

<<<<<<< HEAD
void invoice::setInvoiceID(int& ID)
=======
void invoice::setInvoieID(int ID)
>>>>>>> aaa9f08726ef2e39cdf76386995a22d7f113c249
{
    this->invoiceID = ID;
}

void invoice::setEmployeeID(int ID)
{
    this->employeeID = ID;
}
        
void invoice::setCustomerID(int ID)
{
    this->customerID = ID;
}

void invoice::setDate(string year, string month, string day)
{
    this->date.setYear(year);
    this->date.setMonth(month);
    this->date.setDay(day);
}

void invoice::addOrder(order o)
{
    this->listOfOrder.add(o);
}

<<<<<<< HEAD
void invoice::removeOrder(const string& ID)
{
    Node<order>* tempNode = this->listOfOrder.head;
    while (tempNode != nullptr) 
    {
        if (tempNode->data.getproductID == ID) break;
        tempNode = tempNode->next;
    }
    if (tempNode != nullptr) 
        cout << "Chua co san pham nay trong gio hang";
    else listOfOrder.remove(rOrder);
}
=======
// void invoice::removeOrder(productID)
// {
//     order rOrder;
//     //duyet qua listOfOder tim phan tu
//     listOfOrder.remove(rOrder);
// }
>>>>>>> aaa9f08726ef2e39cdf76386995a22d7f113c249
