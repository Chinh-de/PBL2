#include "product.h"

product::product(){
    //Random ma san pham
    // cout << "Ten san pham: "; cin >> this->name;
    // cout << "Ten san ban: "; cin >> this->price;
    // cout << "Nhap thong so:" << endl
    // << "CPU: "; cin >> this->CPU;
    // cout << "RAM: "; cin >> this->RAM;
    // cout << "Man hinh: "; cin >> this->screen;
    // cout << "O cung: "; cin >> this->hard_disk;
    // cout << "GPU: "; cin >> this->GPU;
    this->product_id = NULL;
    this->name = NULL;
    this->price = 0;
    this->CPU = NULL;
    this->RAM = NULL;
    this->GPU = NULL;
    this->hard_disk = NULL;
    this->screen = NULL;
    this->quantity = 0;
    this->OS = NULL;
    list<string> newserial;
    serial = newserial;
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
string product::getOS()
{
    return this->OS;
}
int product::getQuantity()
{
    return this->quantity;
}
void product::setProductName(string n){
    this->name = n;
}
void product::setProductId(string id){
    this->product_id = id;
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
void setNum
void product::addSerial(string newSerial)
{
    serial.add(newSerial);
}
void product::removeSerial(string rSerial)
{
    this->serial.remove(rSerial);
}


