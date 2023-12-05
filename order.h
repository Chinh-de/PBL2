#include "product.h"
#pragma once
using namespace std;
class order : public product
{  
    private:
        unsigned int total;
    public:
        order();
        order(const string&, const string&, unsigned int, unsigned int);
        order(const order&);
        order& operator=(const order& other);
        ~order();
        void updateTotal();
        unsigned int getTotal();
        friend ostream& operator<<(ostream&, const order&);
        bool operator!=(const order&) const;
        bool operator==(const order&) const;
};
