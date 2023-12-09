#include "ProdManage.h"
#include <conio.h>
#include <fstream>
#include <sstream>

ProdManage::ProdManage()
{ }
ProdManage::~ProdManage()
{ }

void ProdManage::readfromfile(string file)
{
    ifstream inputFile(file);
    string ID, name, CPU, screen, GPU, OS, serial, brand; 
    int quantity, RAM, disk;
    unsigned int price, import_price;
    if (inputFile.is_open()) 
    {
        string line;
        while (getline(inputFile, line))
        {
            istringstream iss(line);
            getline(iss, ID, '|');
            getline(iss, name, '|');
            getline(iss, brand, '|');
            iss >> price;
            iss.ignore(); 
            iss >> import_price;
            iss.ignore(); 
            getline(iss, CPU, '|');
            iss >> RAM;
            iss.ignore(); 
            getline(iss, screen, '|');
            iss >> disk;
            iss.ignore(); 
            getline(iss, GPU, '|');
            getline(iss, OS, '|');
            product newProd(ID, name, price, import_price, CPU, RAM, screen, disk, GPU, OS, brand); 
            iss >> quantity;
            iss.ignore(); 
            for (int i = 0; i < quantity; i++)
            {
                getline(iss, serial, ',');
                newProd.addSerial(serial);
            }
            this->Prod.addAtEnd(newProd);
        }
        inputFile.close();
    } else {
        cerr << "Khong the mo file" << file << endl; //bao loi
    }
}

void ProdManage::writetofile(string file) {
    ofstream outputFile(file, ios::out | ios::trunc);
    if (outputFile.is_open())
    {
        for (Node<product>* current = this->Prod.getHead(); current != nullptr; current = current->next) {
            product currentProd = current->data;
            outputFile << currentProd.getID() << "|"
                       << currentProd.getName() << "|"
                       << currentProd.getBrand() << "|"
                       << currentProd.getPrice() << "|"
                       << currentProd.getImportPrice() << "|"
                       << currentProd.getCPU() << "|"
                       << currentProd.getRAM() << "|"
                       << currentProd.getScreen() << "|"
                       << currentProd.getHardDisk() << "|"
                       << currentProd.getGPU() << "|"
                       << currentProd.getOS() << "|"
                       << currentProd.getQuantity() << "|";

            Node<string>* serials = current->data.getSerial().getHead();
            while (serials != nullptr) 
            {
                
                outputFile << serials->data << ",";
                serials = serials->next;
            }
            outputFile << endl;
        }

        outputFile.close();
    } else {
        cerr << "Khong the ghi du lieu" << endl;
    }
}


void ProdManage::add(const product& p) {
    this->Prod.add(p);
}
void ProdManage::add(){
    product p;
    int RAM, Disk;
    string id, name, CPU, Screen, GPU, OS, brand; 
    unsigned int price, imprice; 
    cout << "Nhap thong tin san pham:" << endl
    << "Ma san pham: "; cin >> id; p.setID(id); cin.ignore();
    cout << "Ten san pham: "; getline(cin, name); p.setName(name);
    cout << "Hang: "; getline(cin, brand); p.setBrand(brand);
    cout << "Gia ban: "; cin >> price; p.setPrice(price); cin.ignore();
    cout << "Gia nhap: "; cin >> imprice; p.setImportPrice(imprice); cin.ignore();
    cout << "CPU: "; getline(cin, CPU); p.setCPU(CPU);
    cout << "Ram: "; cin >> RAM; p.setRAM(RAM); cin.ignore();
    cout << "Man hinh: "; getline(cin, Screen); p.setScreen(Screen);
    cout << "O cung: "; cin >> Disk; p.setHardDisk(Disk); cin.ignore();
    cout << "GPU: "; getline(cin, GPU); p.setGPU(GPU);
    cout << "He dieu hanh: "; getline(cin, OS); p.setOS(OS);
    this->Prod.add(p);
}
void ProdManage::remove(product& p){
    this->Prod.remove(p);
}
void ProdManage::display(){
    this->Prod.display();
}

void ProdManage::display(bool type)
{
    //type = false sap xep giam, = true tang 
    list<product> sortprice = this->Prod; 
    sortprice.mergeSort(type);
    sortprice.display();
}

void ProdManage::displayOption(){
    int input;
    int display_option = 1;
    do{
        system("cls");
        cout << ((display_option == 1) ? "->" : "  ") << "Tat ca san pham" << endl;
        cout << ((display_option == 2) ? "->" : "  ") << "Xem theo gia tang" << endl;
        cout << ((display_option == 3) ? "->" : "  ") << "Xem theo gia giam" << endl;
        input = getch();
        if (input == 72) display_option--;
        else if (input == 80) display_option++;
        if (display_option < 1) display_option = 3;
        if (display_option > 3) display_option = 1;
    }while(input != 13);
    if (display_option == 1) this->display();
    else if (display_option == 2) this->display(true);
    else this->display(false);
}

 void ProdManage::update(product& _prod)
 {
    string ID = _prod.getID();
    product& _product = this->find(ID)->data;
    bool over = false;
    int input, option = 1, MaxOption = 11;
    do{
        system("cls");
        cout<<"Chon thong tin muon thay doi:"<< endl;
            cout << (option == 1 ? "->":"  ") << "Ten san pham: " << _product.getName() << endl;
            cout << (option == 2 ? "->":"  ") << "Hang: " << _product.getBrand() << endl;
            cout << (option == 3 ? "->":"  ") << "Gia ban: " << _product.getPrice() << endl;
            cout << (option == 4 ? "->":"  ") << "Gia nhap: " << _product.getImportPrice() << endl;
            cout << (option == 5 ? "->":"  ") << "CPU: " << _product.getCPU() << endl;
            cout << (option == 6 ? "->":"  ") << "RAM: " << _product.getRAM() << " GB" << endl;
            cout << (option == 7 ? "->":"  ") << "Man hinh: " << _product.getScreen() << endl;
            cout << (option == 8 ? "->":"  ") << "O cung: " << _product.getHardDisk() << " GB" << endl;
            cout << (option == 9 ? "->":"  ") << "GPU: " << _product.getGPU() << endl;
            cout << (option == 10 ? "->":"  ") << "He Dieu Hanh: " << _product.getOS() << endl;
            cout << (option == 11 ? "->":"  ") << "Thoat! " << endl;
            input = getch();

            if (input == 80) //phim mui ten xuong
            { 
                if (option == MaxOption) option = 1; // quay tro lai dau danh sach
                else option++;
            }else if (input == 72) //phim mui ten len
            {
                if (option == 1) option = MaxOption; //chay vong xuong cuoi danh sach
                else option--;
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
            string _brand;
            switch (option)
            {
                case 1:
                    cout << "Nhap ten san pham: ";
                    getline(cin, _name);
                    _product.setName(_name);
                    break;
                case 2:
                    cout << "Nhap hang: ";
                    cin >> _brand;
                    _product.setBrand(_brand);
                    break;    
                case 3:
                    cout << "Nhap gia ban : ";
                    cin >> _price;
                    _product.setPrice(_price);
                    break;
                case 4:
                    cout << "Nhap gia nhap: ";
                    cin >> _iprice;
                    _product.setImportPrice(_iprice);
                    break;
                case 5:
                    cout << "Cap nhat CPU: ";
                    getline(cin,_CPU);
                    _product.setCPU(_CPU);
                    break;
                case 6:
                    cout << "Cap nhat dung luong RAM (GB): ";
                    cin >> _RAM;
                    _product.setRAM(_RAM);
                    break; 
                case 7:
                    cout << "Cap nhat thong so man hinh: ";
                    getline(cin,_Screen);
                    _product.setScreen(_Screen);
                    break;                      
                case 8:
                    cout << "Cap nhat dung luong o cung (GB): ";
                    cin >> _Disk;
                    _product.setHardDisk(_Disk);
                    break;                      
                case 9:
                    cout << "Cap nhat GPU moi: ";
                    getline(cin,_GPU);
                    _product.setGPU(_GPU);
                    break;
                case 10:
                    cout << "Cap nhat He dieu hanh: ";
                    getline(cin,_OS);
                    _product.setOS(_OS);
                    break;                                                   
                case 11:
                    over = true;
                    break;
                default: cout << "Loi du lieu";
            }
        }
    }while (over != true);
}

Node<product>* ProdManage::find(string &ID)
{
    product tempProd;
    tempProd.setID(ID);
    return this->Prod.find(tempProd);
}

// list<product> ProdManage::filter()
// {
//     //sao chep list ban dau
//     list<product> copy;
//     product _product;
//     Node<product>* tempNode = this->Prod.getHead();
//     while (tempNode != nullptr) 
//     {
//         copy.add(tempNode->data);
//         tempNode = tempNode->next;
//     }    

//     //loc thuoc tinh 
//     int input;
//     int option = 1;
//     int MaxOption = 7;
//     do{
//         system("cls");
//         cout<<"Chon thong tin can loc:"<< endl;
//             cout << (option == 1 ? "->":"  ") << "Hang: " << endl;
//             cout << (option == 2 ? "->":"  ") << "Muc gia: " << _product.getPrice() << endl;
//             cout << (option == 3 ? "->":"  ") << "RAM: " << _product.getImportPrice() << endl;
//             cout << (option == 4 ? "->":"  ") << "Card do hoa: " << _product.getCPU() << endl;
//             cout << (option == 5 ? "->":"  ") << "O cung: " << _product.getRAM() << " GB" << endl;
//             cout << (option == 6 ? "->":"  ") << "He Dieu Hanh: " << _product.getOS() << endl;
//             cout << (option == 7 ? "->":"  ") << "Thoat! " << endl;
//             input = getch();

//             if (input == 80) //phim mui ten xuong
//             { 
//                 if (option == MaxOption) option = 1; // quay tro lai dau danh sach
//                 else option++;
//             }else if (input == 72) //phim mui ten len
//             {
//                 if (option == 1) option = MaxOption; //chay vong xuong cuoi danh sach
//                 else option--;
//             }

//         if(input == 13)  //phim enter
//         {
//             string _brand;
//             unsigned int _sprice;
//             unsigned int _eprice;
//             string _CPU;
//             int _RAM = 0;
//             string _Screen;
//             int _Disk;
//             string _GPU;
//             string _OS;
//             switch (option)
//             {
//                 case 1:
//                     //xet brand bằng swichcase
//                     break;
//                 case 2:
//                     cout << "Nhap gia bat dau : ";
//                     cin >> _sprice;
//                     cout << "Nhap gia ket thuc : ";
//                     cin >> _eprice;
//                     Node<product>* tempNode = copy.getHead();
//                     while (tempNode != nullptr) 
//                     {
//                         if (tempNode->data.getPrice() < _sprice || tempNode->data.getPrice() > _eprice) copy.remove(tempNode->data);
//                         tempNode = tempNode->next;
//                     }
//                     copy.display();
//                     system("pause");              
//                     break;
//                 case 3:
//                     // cout << "RAM : ";
//                     // //chon ram
//                     cout << "abc";
//                     break;
//                 case 4:
//                     // cout << "Cap nhat CPU moi : ";
//                     // getline(cin,_CPU);
//                     // _product.setCPU(_CPU);
//                     cout <<
//                     break;
//                 case 5:
//                     // cout << "Cap nhat dung luong RAM moi (GB): ";
//                     // cin >> _RAM;
//                     // _product.setRAM(_RAM);
//                     break; 
//                 case 6:
//                     // cout << "Cap nhat thong so ma hinh moi : ";
//                     // getline(cin,_Screen);
//                     // _product.setScreen(_Screen);
//                     break;                      
//                 case 7:
//                     cout << "Da thoat khoi cap nhat" << endl;
//                     return;
//                     break;
//                 default: cout << "Loi du lieu";
//             }
//         }
//     }while (input != '0');
// } 


