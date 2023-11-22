#include "product.h"
using namespace std;
class order : public product
{  
    private:
        unsigned total;
    public:
        order();
        ~order();
        void updateTotal();
        unsigned int getTotal();
        friend ostream& operator<<(ostream&, const order&);
        bool operator!=(const order&);
};
