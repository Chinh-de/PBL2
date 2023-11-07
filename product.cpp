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
string product::get_product_name(){
    return this->name;
}