#include "order.h"

order::order()
{
    this->productID = 0;
    this->name = "";
    this->price = 0;
    this->quantity = 0;
    this->total = 0;
   // list<string> nullserial;
    //serial = nullserial;
}
order::~order()
{   }

unsigned int order::updateTotal()
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
    o << _order.productID << "  " << _order.name << "   " << _order.price << "  " << _order.quantity << "  "; _order.serial.display;
    return o;
}



