#include "Customer.h"
#include "list.cpp"
#include "Manage.h"

class CusManage : public Manage<Customer> {
    protected:
        list<Customer> Cus;
    public:
        CusManage();
        ~CusManage();
        void add(const Customer&);
        void remove(const Customer&);
        void update(Customer&);
        void display();
        Customer find(int&);
        list<Customer> find(string&, string&);
};