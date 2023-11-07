#include <iostream>
#include <string>
using namespace std;

class product {
    protected:
        string product_id;
        string name;
        unsigned int price;
        unsigned int import_price;
        string CPU;
        string RAM;
        string screen;
        string hard_disk;
        string GPU;
    public:
        product();
        ~product();
        void show();
        string get_product_name();
};