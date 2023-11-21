#include "invoice.h"
#include "list.cpp"
#include "Manage.h"

class InvManage : public Manage<invoice> {
    protected:
        list<invoice> Inv;
    public:
        InvManage();
        ~InvManage();
        void add(const invoice&);
        void remove(const invoice&);
        void update();
        void display();
};