#include <iostream>
#include <string>
#include "list.cpp"
using namespace std;

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
    int getRAM();
    string getScreen();
    int getHardDisk();
    string getGPU();
    int getQuantity();
    void setProductName(string);
    void setProductId(string);
    void setPrice(unsigned int);
    void setImportPrice(unsigned int);
    void setCPU(string);
    void setRAM(int);
    void setScreen(string);
    void setHardDisk(int);
    void setGPU(string);
    void setOS(string);
    void setQuantity(int);
    void addSerial(string);
    void removeSerial(string);
};