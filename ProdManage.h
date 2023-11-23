#include "Product.h"
#include "list.cpp"
#include "Manage.h"

class ProdManage : public Manage<product> {
    protected:
        list<product> Prod;
    public:
        ProdManage();
        ~ProdManage();
        void add(const product&);
        void remove(const product&);
        void update();
        void display();
        void sort(bool);
        
};