#include "product.h"
class order : public product
{  
    private:
        int purchase_quantity;
        list<string> serial;
    public:
        unsigned int total();
        //them phuong thuc
};