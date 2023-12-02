#include "product.h"

product::product(){
    this->productID = "0";
    this->name = "";
    this->price = 0;
    this->CPU = "";
    this->RAM = 0;
    this->GPU = "";
    this->hard_disk = 0;
    this->import_price = 0;
    this->screen = "";
    this->quantity = 0;
    this->OS = "";
    this->serial = nullptr;
}
product::product(string ID, string _name, unsigned int _price, unsigned int _import_price, string _CPU, int _RAM, 
                string _screen, int _hard_disk, string _GPU, string _OS)
            : productID(ID), name(_name), price(_price), import_price(_import_price), CPU(_CPU), RAM(_RAM),
              screen(_screen),hard_disk(_hard_disk), GPU(_GPU), OS(_OS)
{ 
    this->quantity = 0;
    this->serial = nullptr;
}
product::product(const product& other) 
{
    this->productID = other.productID;
    this->name = other.name;
    this->quantity = other.quantity;
    this->price = other.price;
    this->import_price = other.import_price;
    this->CPU = other.CPU;
    this->RAM = other.RAM;
    this->screen = other.screen;
    this->hard_disk = other.hard_disk;
    this->GPU = other.GPU;
    this->OS = other.OS;
    if (other.serial != nullptr) {
        this->serial = new string[other.quantity];
        for (int i = 0; i < other.quantity; ++i) {
            this->serial[i] = other.serial[i];
        }
    } else {
        this->serial = nullptr;
    }
}

product::~product()
{
    delete[] serial;

}

product& product::operator=(const product& other) {
    if (this != &other) {  
        delete[] this->serial;
        this->productID = other.productID;
        this->name = other.name;
        this->quantity = other.quantity;
        this->price = other.price;
        this->import_price = other.import_price;
        this->CPU = other.CPU;
        this->RAM = other.RAM;
        this->screen = other.screen;
        this->hard_disk = other.hard_disk;
        this->GPU = other.GPU;
        this->OS = other.OS;
        if (other.serial != nullptr) {
            this->serial = new string[other.quantity];
            for (int i = 0; i < other.quantity; ++i) {
                this->serial[i] = other.serial[i];
            }
        } else {
            serial = nullptr;
        }
    }
    return *this;
}

void product::show(){
    cout << "Ten san pham: " << this->name << endl
    << "Ten san ban: " << this->price << endl
    << "Thong so:" << endl
    << "CPU: " << this->CPU << endl
    << "RAM: " << this->RAM << "GB" << endl
    << "Man hinh: " << this->screen << endl
    << "O cung: " << this->hard_disk << "GB" << endl
    << "GPU: " << this->GPU << endl
    << "He dieu hang: " << this->OS << endl
    << "so luong con: " << this->quantity << " may";
}
ostream& operator<<(ostream& o,const product& p){
    o << "Ten san pham: " << p.name << endl
    << "Gia ban: " << p.price << endl
    << "Thong so:" << endl
    << "CPU: " << p.CPU << endl
    << "RAM: " << p.RAM << endl
    << "Man hinh: " << p.screen << endl
    << "O cung: " << p.hard_disk << endl
    << "GPU: " << p.GPU << endl
    << "He dieu hang: " << p.OS << endl
    << "so luong con: " << p.quantity << " may" << endl;
    o << "So serial: ";
    for(int i = 0; i < p.quantity; i++)
    {
        o << *(p.serial + i ) << ", ";
    }
    o << endl;
    return o;
}
bool product::operator!=(const product& p){
    return (this->productID != p.productID);
}
bool product::operator==(const product& p){
    return (this->productID == p.productID);
}
string product::getName(){
    return this->name;
}
string product::getID() const
{
    return this->productID;
}
unsigned int product::getPrice(){
    return this->price;
}
unsigned int product::getImportPrice(){
    return this->import_price;
}
unsigned int product::Profit(){
    return (this->price - this->import_price); 
}
string product::getCPU(){
    return this->CPU;
}
int product::getRAM(){
    return this->RAM;
}
string product::getScreen(){
    return this->screen;
}
int product::getHardDisk(){
    return this->hard_disk;
}
string product::getGPU(){
    return this->GPU;
}
string product::getOS()
{
    return this->OS;
}
int product::getQuantity()
{
    return this->quantity;
}
void product::setName(string n){
    this->name = n;
}
void product::setID(string id){
    this->productID = id;
}
void product::setImportPrice(unsigned int p){
    this->import_price = p;
}
void product::setPrice(unsigned int p){
    this->price = p;
}
void product::setCPU(string c){
    this->CPU = c;
}
void product::setRAM(int r){
    this->RAM = r;
}
void product::setScreen(string s){
    this->screen = s;
}
void product::setHardDisk(int h){
    this->hard_disk = h;
}
void product::setGPU(string g){
    this->GPU = g;
}
void product::setOS(string newOS){
    this->OS = newOS;
}
void product::setQuantity(int newQuantity)
{
    this->quantity = newQuantity;
}
void product::addSerial(string& newSerial)
{
    string* newSerialArray = new string[this->quantity + 1];
    for (int i = 0; i < this->quantity; ++i) 
    {
        newSerialArray[i] = serial[i];
    }
    newSerialArray[this->quantity] = newSerial;
    ++this->quantity;
    delete[] this->serial;
    this->serial = newSerialArray;
}
void product::removeSerial(string& rSerial)
{
    int indexToRemove = -1;
    for (int i = 0; i < this->quantity; ++i) 
    {
        if (this->serial[i] == rSerial) 
        {
            indexToRemove = i;
            break;
        }
    }
    if (indexToRemove != -1) 
    {
        string* newSerialArray = new string[this->quantity - 1];
        for (int i = 0, j = 0; i < this->quantity; ++i) 
        {
            if (i != indexToRemove) 
            {
                newSerialArray[j++] = serial[i];
            }
        }
        --this->quantity;
        delete[] this->serial;
        this->serial = newSerialArray;
    }
}
string* product::getSerial()
{
    return this->serial;
}
bool product::operator>(product& p)
{
    return this->getPrice() > p.getPrice();
}
bool product::operator<(product& p)
{
    return this->getPrice() < p.getPrice();
}
bool product::isSerial(const string& s)
{
    for (int i = 0; i < this->quantity; ++i)
        if (this->serial[i] == s) return true;
    return false;  
}


