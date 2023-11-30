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
   // list<string> nullserial;
    //serial = nullserial; không cần thiết vì nó tự gọi hàm dựng
}
product::~product()
{ }
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
    << "so luong con: " << this->getQuantity() << " may";
    this->serial.display();
}
ostream& operator<<(ostream& o, const product& p){
    o << "Ten san pham: " << p.name << endl
    << "Gia ban: " << p.price << endl
    << "Thong so:" << endl
    << "CPU: " << p.CPU << endl
    << "RAM: " << p.RAM << endl
    << "Man hinh: " << p.screen << endl
    << "O cung: " << p.hard_disk << endl
    << "GPU: " << p.GPU << endl
    << "He dieu hang: " << p.OS << endl
    << "so luong con: " << p.quantity << " may";
    product *temp = new product();
    *temp = p;
    temp->serial.display();
    delete temp;
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
    this->serial.add(newSerial);
    this->setQuantity (this->getQuantity() + 1);
}
void product::removeSerial(string& rSerial)
{
    this->serial.remove(rSerial);
    this->setQuantity(this->getQuantity() - 1);
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
    Node<string>* tempNode = this->serial.getHead();
     while (tempNode != nullptr) 
    {
        if (tempNode->data == s) return true;
        tempNode = tempNode->next;
    }
    return false;
}


