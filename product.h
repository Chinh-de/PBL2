#include <iostream>
#include <string>
#include "list.h"
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
    private:    
        int amount;
        list<string> seri;
    public:
        product();
        ~product();
        void show();
        string getProductName();
        string getProductId();
        unsigned int getPrice();
        unsigned int getImportPrice();
        string getCPU();
        string getRAM();
        string getScreen();
        string getHardDisk();
        string getGPU();
        int getamount();
        void setProductName(string);
        void setProductId(string);
        void setPrice(unsigned int);
        void setImportPrice(unsigned int);
        void setCPU(string);
        void setRAM(string);
        void setScreen(string);
        void setHardDisk(string);
        void setGPU(string);
        void setamount(int);
};