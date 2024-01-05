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
    this->brand = "";
    //serial duoc tu dong tao bang ham dung;
}
product::product(string ID, string _name, unsigned int _price, unsigned int _import_price, string _CPU, int _RAM, 
                string _screen, int _hard_disk, string _GPU, string _OS, string _brand)
            : productID(ID), name(_name), price(_price), import_price(_import_price), CPU(_CPU), RAM(_RAM),
              screen(_screen),hard_disk(_hard_disk), GPU(_GPU), OS(_OS), brand(_brand)
{ 
    this->quantity = 0;
    //serial duoc tu dong tao bang ham dung;
}
product::product(const product& other)
    : productID(other.productID), name(other.name), quantity(other.quantity),
      serial(other.serial), price(other.price), import_price(other.import_price),
      CPU(other.CPU), RAM(other.RAM), screen(other.screen),
      hard_disk(other.hard_disk), GPU(other.GPU), OS(other.OS), brand(other.brand)
{ }
product::~product()
{ }


product& product::operator=(const product& other)
{
    if (this != &other) {
        this->productID = other.productID;
        this->name = other.name;
        this->quantity = other.quantity;
        this->serial = other.serial;
        this->price = other.price;
        this->import_price = other.import_price;
        this->CPU = other.CPU;
        this->RAM = other.RAM;
        this->screen = other.screen;
        this->hard_disk = other.hard_disk;
        this->GPU = other.GPU;
        this->OS = other.OS;
        this->brand = other.brand;
    }
    return *this;
}

void product::show(){
    cout << "Ma san pham: " << this->productID << endl
    << "Ten san pham: " << this->name << endl
    << "Hang: " << this->brand << endl
    << "Gia ban: " << this->price << endl
    << "Thong so:" << endl
    << "CPU: " << this->CPU << endl
    << "RAM: " << this->RAM << "GB" << endl
    << "Man hinh: " << this->screen << endl
    << "O cung: " << this->hard_disk << "GB" << endl
    << "GPU: " << this->GPU << endl
    << "He dieu hanh: " << this->OS << endl
    << "so luong con: " << this->quantity << " may";
}
ostream& operator<<(ostream& o,const product& p){
    o << "Ma san pham: " << p.productID << endl
    << "Ten san pham: " << p.name << endl
    << "Hang: " << p.brand << endl
    << "Gia ban: " << p.price << endl
    << "Thong so:" << endl
    << "CPU: " << p.CPU << endl
    << "RAM: " << p.RAM << "GB" << endl
    << "Man hinh: " << p.screen << endl
    << "O cung: " << p.hard_disk << "GB" << endl
    << "GPU: " << p.GPU << endl
    << "He dieu hanh: " << p.OS << endl
    << "so luong con: " << p.quantity << " may" << endl;
    o << "So serial: ";
    Node<string>* currentNode = p.serial.getHead();
    while (currentNode != nullptr) 
    {
        o << currentNode->data << ", ";
        currentNode = currentNode->next;
    }
    cout << "\n\t\t _______________________________";
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
string product::getBrand()
{
    return this->brand;
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
void product::setBrand(string& newBrand)
{
    this->brand = newBrand;
}
void product::addSerial(string& newSerial)
{
    if (!this->isSerial(newSerial)) 
    {
        this->serial.addAtEnd(newSerial);
        quantity++;
    }
}
void product::removeSerial(string& rSerial)
{
    if (this->isSerial(rSerial)) {
        this->serial.remove(rSerial);
        quantity--;
    }
}
list<string>& product::getSerial()
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
bool product::isSerial(string& s)
{
    Node<string>* currentNode = this->serial.getHead();
    while (currentNode != nullptr) {
        if (currentNode->data == s) {
            return true;
        }
        currentNode = currentNode->next;
    }
    return false;
}


