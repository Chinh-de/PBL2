#include "Person.h"
class Customer : protected Person
{
    public:
        Customer(int = 0, string = "", string = "", string = "", bool = 0, string = "");           
        ~Customer();
        void Show();     
};