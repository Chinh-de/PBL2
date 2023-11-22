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
    this->productID = "";
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
   // list<string> nullserial;
    //serial = nullserial; không cần thiết vì nó tự gọi hàm dựng
}
product::~product()
{ }
void product::show(){
    cout << "Ten san pham: " << this->name << endl
    << "Ten gia nhap: " << this->import_price << endl
    << "Ten san ban: " << this->price << endl
    << "Thong so:" << endl
    << "CPU: " << this->CPU << endl
    << "RAM: " << this->RAM << "GB" << endl
    << "Man hinh: " << this->screen << endl
    << "O cung: " << this->hard_disk << "GB" << endl
    << "GPU: " << this->GPU << endl;
    cout << "so luong con: " << getQuantity() << " may";
}
string product::getProductName(){
    return this->name;
}
string product::getproductID(){
    return this->productID;
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
void product::setproductID(string id){
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
    this->serial.add(newSerial);
    this->setQuantity (this->getQuantity() + 1);
}
void product::removeSerial(string& rSerial)
{
    this->serial.remove(rSerial);
    this->setQuantity(this->getQuantity() - 1);

}


