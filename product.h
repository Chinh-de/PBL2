#include <iostream>
#include <string>
#include "list.cpp"
using namespace std;

<<<<<<< HEAD
class product {
    protected:
        string product_id;
        string name;
        unsigned int price;
        string screen;
        string CPU;
        string RAM;
        string hard_disk;
        string GPU;
        string OS;
    private:
        int quantity;
        list<string> serial;
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
        string getOS();
        int getQuantity();
        void setProductName(string);
        void setProductId(string);
        void setPrice(unsigned int);
        void setImportPrice(unsigned int);
        void setCPU(string);
        void setRAM(string);
        void setScreen(string);
        void setHardDisk(string);
        void setGPU(string);
        void setOS(string);
        void setQuantity(int);
        void addSerial(string);
        void removeSerial(string);
=======
class product
{
protected:
    string product_id;
    string name;
    unsigned int price;
    unsigned int import_price;
    string CPU;
    int RAM;
    string screen;
    int hard_disk;
    string GPU;

private:
    int numberOf;
    list<string> serial;

public:
    product();
    ~product();
    void show();
    string getProductName();
    string getProductId();
    unsigned int getPrice();
    unsigned int getImportPrice();
    string getCPU();
    int getRAM();
    string getScreen();
    int getHardDisk();
    string getGPU();
    int getNumberOf();
    void setProductName(string);
    void setProductId(string);
    void setPrice(unsigned int);
    void setImportPrice(unsigned int);
    void setCPU(string);
    void setRAM(int);
    void setScreen(string);
    void setHardDisk(int);
    void setGPU(string);
    void setNumberOf(int);
    void addSerial(string);
    void removeSerial(string);
>>>>>>> ca3bc8612379a34491cd0de7e32115f36afa25ce
};