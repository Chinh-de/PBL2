#include "Person.h"
class Customer : public Person
{
    public:
        Customer(int = 0, string = "", string = "", string = "", bool = 0, string = "");           
        ~Customer();
        void Show();
        friend ostream& operator<<(ostream&, const Customer&);       
};