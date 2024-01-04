#include "order.h"

order::order()
{
    this->total = 0;
    this->quantity = 0;
    this->productID = "0";
    this->name = "";
    this->price = 0;   
}

order::order(const string& pID, const string& pname, unsigned int pprice, unsigned int  total)
{
    this->total = total;
    this->quantity = 0;
    this->productID = pID;
    this->name = pname;
    this->price = pprice;    
}

order::order(const order& other)
{
    this->productID = other.productID;
    this->name = other.name;
    this->price = other.price;
    this->quantity = other.quantity;
    this->serial = other.serial;
    this->total = other.total;
}
order::~order()
{   }

order& order::operator=(const order& other)
{
    if (this != &other) {
        this->productID = other.productID;
        this->name = other.name;
        this->price = other.price;
        this->quantity = other.quantity;
        this->serial = other.serial;
        this->total = other.total;
    }
    return *this;
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
    o << "Ma San Pham: " << _order.productID << "; Ten san Pham: " << _order.name << endl << "Don gia: " << _order.price << "; So Luong " << _order.quantity << "; Tong Tien " << _order.total << endl;
    o << "So serial: ";
    Node<string>* currentNode = _order.serial.getHead();
    while (currentNode != nullptr) 
    {
        o << currentNode->data << ", ";
        currentNode = currentNode->next;
    }
    o << endl;
    return o;
}

bool order::operator!=(const order& other) const {
    return this->getID() != other.getID();
}
bool order::operator==(const order& other) const {
    return this->getID() == other.getID();
}







