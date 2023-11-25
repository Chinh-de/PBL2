#include "ProdManage.h"
#include <conio.h>
ProdManage::ProdManage()
{ }
ProdManage::~ProdManage()
{ }
void ProdManage::add(const product& p) {
    this->Prod.add(p);
}
void ProdManage::remove(const product& p){
    this->Prod.remove(p);
}
void ProdManage::display(){
    this->Prod.display();
}
void ProdManage::update(product& _product){
    int input;
    int choice = 1;
    int MaxChoice = 10;
    do{
        system("cls");
        cout<<"Chon thong tin can cap nhat:"<< endl;
            cout << (choice == 1 ? "->":"  ") << "Ten san pham: " << _product.getName() << endl;
            cout << (choice == 2 ? "->":"  ") << "Gia ban: " << _product.getPrice() << endl;
            cout << (choice == 3 ? "->":"  ") << "Gia nhap: " << _product.getImportPrice() << endl;
            cout << (choice == 4 ? "->":"  ") << "CPU: " << _product.getCPU() << endl;
            cout << (choice == 5 ? "->":"  ") << "RAM: " << _product.getRAM() << " GB" << endl;
            cout << (choice == 6 ? "->":"  ") << "Man hinh: " << _product.getScreen() << endl;
            cout << (choice == 7 ? "->":"  ") << "O cung: " << _product.getHardDisk() << " GB" << endl;
            cout << (choice == 8 ? "->":"  ") << "GPU: " << _product.getGPU() << endl;
            cout << (choice == 9 ? "->":"  ") << "He Dieu Hanh: " << _product.getOS() << endl;
            cout << (choice == 10 ? "->":"  ") << "Thoat! " << endl;
            input = getch();

            if (input == 80) //phim mui ten xuong
            { 
                if (choice == MaxChoice) choice = 1; // quay tro lai dau danh sach
                else choice++;
            }else if (input == 72) //phim mui ten len
            {
                if (choice == 1) choice = MaxChoice; //chay vong xuong cuoi danh sach
                else choice--;
            }

        if(input == 13)  //phim enter
        {
            string _name;
            unsigned int _price;
            unsigned int _iprice;
            string _CPU;
            int _RAM = 0;
            string _Screen;
            int _Disk;
            string _GPU;
            string _OS;
            switch (choice)
            {
                using namespace std;
                case 1:
                    cout << "Nhap ten san pham moi : ";
                    getline(cin, _name);
                    _product.setName(_name);
                    break;
                case 2:
                    cout << "Nhap gia ban moi : ";
                    cin >> _price;
                    _product.setPrice(_price);
                    break;
                case 3:
                    cout << "Nhap gia nhap moi : ";
                    cin >> _iprice;
                    _product.setImportPrice(_iprice);
                    break;
                case 4:
                    cout << "Cap nhat CPU moi : ";
                    getline(cin,_CPU);
                    _product.setCPU(_CPU);
                    break;
                case 5:
                    cout << "Cap nhat dung luong RAM moi (GB): ";
                    cin >> _RAM;
                    _product.setRAM(_RAM);
                    break; 
                case 6:
                    cout << "Cap nhat thong so ma hinh moi : ";
                    getline(cin,_Screen);
                    _product.setScreen(_Screen);
                    break;                      
                case 7:
                    cout << "Cap nhat dung luong o cung moi (GB): ";
                    cin >> _Disk;
                    _product.setHardDisk(_Disk);
                    break;                      
                case 8:
                    cout << "Cap nhat GPU moi : ";
                    getline(cin,_GPU);
                    _product.setGPU(_GPU);
                    break;
                case 9:
                    cout << "Cap nhat He dieu hanh moi : ";
                    getline(cin,_OS);
                    _product.setOS(_OS);
                    break;                                                   
                case 10:
                    cout << "Da thoat khoi cap nhat" << endl;
                    return;
                    break;
                default: cout << "Loi du lieu";
            }
        }
    }while (input != '0');
}

void ProdManage::sort(bool type)
{
    //type = false sap xep tu giam, = true tang 
    
    //tao ban sao cua danh sach san pham
    list<product> sortprice;
    Node<product>* tempNode = this->Prod.getHead();
    while (tempNode != nullptr) 
    {
        sortprice.add(tempNode->data);
        tempNode = tempNode->next;
    }    
    sortprice.mergeSort(sortprice.getHead(),type);
    sortprice.display();
}

product ProdManage::find(int &ID)
{
    Node<product>* tempNode = this->Prod.getHead();
    while (tempNode != nullptr) 
    {
        if (tempNode->data.getID() == ID) return tempNode->data;
        tempNode = tempNode->next;
    }
    return tempNode->data;
}

list<product> filter()
{
    //sao chep list ban dau
    list<product> copy;
    Node<product>* tempNode = this->Prod.getHead();
    while (tempNode != nullptr) 
    {
        copy.add(tempNode->data);
        tempNode = tempNode->next;
    }    

    //loc thuoc tinh 
    int input;
    int choice = 1;
    int MaxChoice = 7;
    do{
        system("cls");
        cout<<"Chon thong tin can cap nhat:"<< endl;
            cout << (choice == 1 ? "->":"  ") << "Hang: " << endl;
            cout << (choice == 2 ? "->":"  ") << "Muc gia: " << _product.getPrice() << endl;
            cout << (choice == 3 ? "->":"  ") << "RAM: " << _product.getImportPrice() << endl;
            cout << (choice == 4 ? "->":"  ") << "Card do hoa: " << _product.getCPU() << endl;
            cout << (choice == 5 ? "->":"  ") << "O cung: " << _product.getRAM() << " GB" << endl;
            cout << (choice == 6 ? "->":"  ") << "He Dieu Hanh: " << _product.getOS() << endl;
            cout << (choice == 7 ? "->":"  ") << "Thoat! " << endl;
            input = getch();

            if (input == 80) //phim mui ten xuong
            { 
                if (choice == MaxChoice) choice = 1; // quay tro lai dau danh sach
                else choice++;
            }else if (input == 72) //phim mui ten len
            {
                if (choice == 1) choice = MaxChoice; //chay vong xuong cuoi danh sach
                else choice--;
            }

        if(input == 13)  //phim enter
        {
            string _brand;
            unsigned int _sprice;
            unsigned int _eprice;
            string _CPU;
            int _RAM = 0;
            string _Screen;
            int _Disk;
            string _GPU;
            string _OS;
            switch (choice)
            {
                using namespace std;
                case 1:
                    //xet brand bằng swichcase
                    break;
                case 2:
                    cout << "Nhap gia bat dau : ";
                    cin >> _sprice;
                    cout << "Nhap gia ket thuc : ";
                    cin >> _eprice;
                    Node<product>* tempNode = this->copy.getHead();
                    while (tempNode != nullptr) 
                    {
                        if (tempNode->data.getPrice() < _sprice || tempNode->data.getPrice > _eprice) copy.remove(tempNode->data);
                        tempNode = tempNode->next;
                    }
                    copy.display();
                    system("pause");              
                    break;
                case 3:
                    // cout << "RAM : ";
                    // //chon ram
                    break;
                case 4:
                    // cout << "Cap nhat CPU moi : ";
                    // getline(cin,_CPU);
                    // _product.setCPU(_CPU);
                    break;
                case 5:
                    // cout << "Cap nhat dung luong RAM moi (GB): ";
                    // cin >> _RAM;
                    // _product.setRAM(_RAM);
                    break; 
                case 6:
                    // cout << "Cap nhat thong so ma hinh moi : ";
                    // getline(cin,_Screen);
                    // _product.setScreen(_Screen);
                    break;                      
                case 7:
                    cout << "Da thoat khoi cap nhat" << endl;
                    return;
                    break;
                default: cout << "Loi du lieu";
            }
        }
    }while (input != '0');
} 


