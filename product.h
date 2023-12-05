#include <iostream>
#include <string>
#include "list.cpp"
#pragma once
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
        string brand;
    public:
        product();
        product(string, string, unsigned int, unsigned int, string, int, string, int, string , string, string);
        product(const product& other);
        ~product();
        product& operator=(const product& other);
        void show();
        friend ostream& operator<<(ostream&, const product&);
        bool operator!=(const product&);
        bool operator==(const product&);
        string getName();
        string getID() const;
        unsigned int getPrice();
        unsigned int getImportPrice();
        unsigned int Profit();
        string getCPU();
        int getRAM();
        string getScreen();
        int getHardDisk();
        string getGPU();
        string getOS();
        int getQuantity();
        string getBrand();
        void setName(string);
        void setID(string);
        void setPrice(unsigned int);
        void setImportPrice(unsigned int);
        void setCPU(string);
        void setRAM(int);
        void setScreen(string);
        void setHardDisk(int);
        void setGPU(string);
        void setOS(string);
        void setQuantity(int);
        void setBrand(string&);
        void addSerial(string&);
        void removeSerial(string&);
        bool isSerial(string&);
        list<string>& getSerial();
        bool operator>(product&); //so sanh gia
        bool operator<(product&); //so sanh gia
};