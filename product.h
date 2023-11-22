#include <iostream>
#include <string>
#include "list.cpp"
using namespace std;

class product
{
    protected:
        string productID;
        string name;
        int quantity;
        list<string> serial;
        unsigned int price;
    private:    
        unsigned int import_price;
        string CPU;
        int RAM;
        string screen;
        int hard_disk;
        string GPU;
        string OS;

    public:
        product();
        ~product();
        void show();
        string getProductName();
        string getproductID();
        unsigned int getPrice();
        unsigned int getImportPrice();
        string getCPU();
        int getRAM();
        string getScreen();
        int getHardDisk();
        string getGPU();
        string getOS();
        int getQuantity();
        void setProductName(string);
        void setproductID(string);
        void setPrice(unsigned int);
        void setImportPrice(unsigned int);
        void setCPU(string);
        void setRAM(int);
        void setScreen(string);
        void setHardDisk(int);
        void setGPU(string);
        void setOS(string);
        void setQuantity(int);
        void addSerial(string&);
        void removeSerial(string&);
};