#include "product.h"
#pragma once
using namespace std;
class order : public product
{  
    private:
        int invoiceID;
        unsigned int total;
    public:
        order();
        ~order();
        void setInvoiceID(int&);
        int getInvoiceID();
        void updateTotal();
        unsigned int getTotal();
        friend ostream& operator<<(ostream&, const order&);
        bool operator!=(const order&) const;
        bool operator==(const order&) const;
};
