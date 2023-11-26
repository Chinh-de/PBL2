#include "invoice.h"
#include "list.cpp"
#include "Manage.h"
#include "Customer.h"

class InvManage : public Manage<invoice> {
    protected:
        list<invoice> Inv;
    public:
        InvManage();
        ~InvManage();
        void add(const invoice&);
        void remove(const invoice&);
        void update(invoice&);
        void display();
        list<invoice> find(int&, int&, int&);
        list<invoice> find(int&, int&);
        list<invoice> find(int&);
        void statistic(list<invoice>&);
        invoice printInvoice(int&, list<Customer>&);
        int getEndID();
};