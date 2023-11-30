#include "order.h"

order::order()
{
    //this->productID = "";
    // this->name = "";
    // this->price = 0;
    // this->quantity = 0;
    this->total = 0;
   // list<string> nullserial;
    //serial = nullserial;
}
order::~order()
{   }

void order::setInvoiceID(int& i){
    this->invoiceID = i;
}

int order::getInvoiceID(){
    return this->invoiceID;
}

void order::updateTotal()
{
    this->total = this->quantity * this->price;
}

unsigned int order::getTotal()
{
    this->updateTotal();
    return this->total;
}

ostream& operator<<(ostream& o, const order& _order)
{
    o << _order.productID << "  " << _order.name << "   " << _order.price << "  " << _order.quantity << "  ";
    order *don = new order();
    *don = _order;
    don->serial.display();
    delete don;
    return o;
}

bool order::operator!=(const order& other) const {
    return this->getID() != other.getID();
}
bool order::operator==(const order& other) const {
    return this->getID() == other.getID();
}

list<string> order::getSerial()
{
    return this->serial;
}





