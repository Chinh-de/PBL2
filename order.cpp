#include "order.h"

unsigned int order::total()
{
    return this->purchaseQuantity * this->price;
}
