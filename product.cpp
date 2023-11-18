#include "product.h"

product::product(){
    //Random ma san pham
    cout << "Ten san pham: "; cin >> this->name;
    cout << "Ten gia nhap: "; cin >> this->import_price;
    cout << "Ten san ban: "; cin >> this->price;
    cout << "Nhap thong so:" << endl
    << "CPU: "; cin >> this->CPU;
    cout << "RAM: "; cin >> this->RAM;
    cout << "Man hinh: "; cin >> this->screen;
    cout << "O cung: "; cin >> this->hard_disk;
    cout << "GPU: "; cin >> this->GPU;

}
product::~product()
{ }
void product::show(){
    cout << "Ten san pham: " << this->name << endl
    << "Ten gia nhap: " << this->import_price << endl
    << "Ten san ban: " << this->price << endl
    << "Thong so:" << endl
    << "CPU: " << this->CPU << endl
    << "RAM: " << this->RAM << endl
    << "Man hinh: " << this->screen << endl
    << "O cung: " << this->hard_disk << endl
    << "GPU: " << this->GPU << endl;
}
string product::getProductName(){
    return this->name;
}
string product::getProductId(){
    return this->product_id;
}
unsigned int product::getPrice(){
    return this->price;
}
unsigned int product::getImportPrice(){
    return this->import_price;
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
int product::getNumberOf()
{
    return this->numberOf;
}
void product::setProductName(string n){
    this->name = n;
}
void product::setProductId(string id){
    this->product_id = id;
}
void product::setPrice(unsigned int p){
    this->price = p;
}
void product::setImportPrice(unsigned int p){
    this->import_price = p;
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
void product::setNumberOf(int newNumberOf)
{
    this->numberOf = newNumberOf;
}
void product::addSerial(string newSerial)
{
    serial.add(newSerial);
}
void removeSerial(string rSerial)
{
    serial.remove(rSerial);
}


