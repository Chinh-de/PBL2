#include "ProdManage.h"
#include <conio.h>
#include <fstream>
#include <sstream>

ProdManage::ProdManage()
{ }
ProdManage::~ProdManage()
{ }
void ProdManage::readfromfile(string file){
    ifstream input(file);
    int n = 0;
    int value;
    string info[20];
    while(input.eof() == 0){
        n = 0;
        product tempProd;
        char c;
        string Data;
        do {
            Data = "";
            input.get(c);
            while (c != '|' && c != '\n' && c != ',' && !input.eof()){
                Data += c;
                input.get(c);
            }
            info[n] = Data;
            ++n;
        } while(n <= 10);
        
        if (isdigit(info[2][0]) && isdigit(info[3][0]) && isdigit(info[5][0]) && isdigit(info[7][0]) && isdigit(info[10][0])){
            value = stoi(info[2]); tempProd.setPrice(value);
            value = stoi(info[3]); tempProd.setImportPrice(value);
            value = stoi(info[5]); tempProd.setRAM(value);
            value = stoi(info[7]); tempProd.setHardDisk(value);
            value = stoi(info[10]); tempProd.setQuantity(value);
        }

        tempProd.setID(info[0]);
        tempProd.setName(info[1]);
        tempProd.setCPU(info[4]);
        tempProd.setScreen(info[6]);
        tempProd.setGPU(info[8]);
        tempProd.setOS(info[9]);
        if (tempProd.getQuantity() == 0)
            break;
        int m = (n) + tempProd.getQuantity();
        do{
            Data = "";
            input.get(c);
            while (c!='|' && c != ',' && c != '\n' && !input.eof()){
                Data += c;
                input.get(c);
            }
            tempProd.addSerial(Data);
            n++;
        } while(n <= m);
        cout << "before";
        this->Prod.addAtEnd(tempProd);
        cout << "after";
    }
    input.close();
}

void ProdManage::readfile(string file)
{
    ifstream inputFile(file);
    string ID, name, CPU, screen, GPU, OS, serial; 
    int quantity, RAM, disk;
    unsigned int price, import_price;
    if (inputFile.is_open()) 
    {
        string line;
        while (getline(inputFile, line))
        {
            istringstream iss(line);

            getline(iss, ID, '|');
          //  cout << ID << endl;
            getline(iss, name, '|');
        //  cout << name << endl;
            iss >> price;
            iss.ignore(); // bo ki tu '|'
          //  cout << price;
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
            iss >> quantity;
            iss.ignore(); 
            product newProd(ID, name, quantity, price, import_price, CPU, RAM, screen, disk, GPU, OS); 
            for (int i = 1; i <= quantity; i++)
            {
                getline(iss, serial, ',');
                newProd.addSerial(serial);
            }
            this->Prod.addAtEnd(newProd);
        }
        inputFile.close();   
    } else {
        cerr << "Unable to open file." << endl; //bao loi
    }
}

void ProdManage::add(const product& p) {
    this->Prod.add(p);
}
void ProdManage::add(){
    product p;
    int RAM, Disk;
    string id, name, CPU, Screen, GPU, OS; 
    unsigned int price, imprice; 
    cout << "Nhap thong tin san pham:" << endl
    << "Ma san pham: "; cin >> id; p.setID(id);
    cout << "Ten san pham: "; cin >> name; p.setName(name);
    cout << "Gia ban: "; cin >> price; p.setPrice(price);
    cout << "Gia nhap: "; cin >> imprice; p.setImportPrice(imprice);
    cout << "CPU: "; cin >> CPU; p.setCPU(CPU);
    cout << "Ram: "; cin >> RAM; p.setRAM(RAM);
    cout << "Man hinh: "; cin >> Screen; p.setScreen(Screen);
    cout << "O cung: "; cin >> Disk; p.setHardDisk(Disk);
    cout << "GPU: "; cin >> GPU; p.setGPU(GPU);
    cout << "He dieu hanh: "; cin >> OS; p.setOS(OS);
    this->Prod.add(p);
}
void ProdManage::remove(const product& p){
    this->Prod.remove(p);
}
void ProdManage::display(){
    //this->Prod.display();
    Node<product>* Nserial = this->Prod.getHead();
    while (Nserial != nullptr) 
    {
        cout << Nserial->data << endl;
        Nserial = Nserial->next;
    }
}

void ProdManage::display(bool type)
{
    //type = false sap xep tu giam, = true tang 
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

 void ProdManage::update(product& _product)
 {
    bool over = false;
    int input, option = 1, MaxOption = 10;
    do{
        system("cls");
        cout<<"Chon thong tin muon thay doi:"<< endl;
            cout << (option == 1 ? "->":"  ") << "Ten san pham: " << _product.getName() << endl;
            cout << (option == 2 ? "->":"  ") << "Gia ban: " << _product.getPrice() << endl;
            cout << (option == 3 ? "->":"  ") << "Gia nhap: " << _product.getImportPrice() << endl;
            cout << (option == 4 ? "->":"  ") << "CPU: " << _product.getCPU() << endl;
            cout << (option == 5 ? "->":"  ") << "RAM: " << _product.getRAM() << " GB" << endl;
            cout << (option == 6 ? "->":"  ") << "Man hinh: " << _product.getScreen() << endl;
            cout << (option == 7 ? "->":"  ") << "O cung: " << _product.getHardDisk() << " GB" << endl;
            cout << (option == 8 ? "->":"  ") << "GPU: " << _product.getGPU() << endl;
            cout << (option == 9 ? "->":"  ") << "He Dieu Hanh: " << _product.getOS() << endl;
            cout << (option == 10 ? "->":"  ") << "Thoat! " << endl;
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
            switch (option)
            {
                case 1:
                    cout << "Nhap ten san pham : ";
                    getline(cin, _name);
                    _product.setName(_name);
                    break;
                case 2:
                    cout << "Nhap gia ban : ";
                    cin >> _price;
                    _product.setPrice(_price);
                    break;
                case 3:
                    cout << "Nhap gia nhap : ";
                    cin >> _iprice;
                    _product.setImportPrice(_iprice);
                    break;
                case 4:
                    cout << "Cap nhat CPU : ";
                    getline(cin,_CPU);
                    _product.setCPU(_CPU);
                    break;
                case 5:
                    cout << "Cap nhat dung luong RAM (GB): ";
                    cin >> _RAM;
                    _product.setRAM(_RAM);
                    break; 
                case 6:
                    cout << "Cap nhat thong so man hinh : ";
                    getline(cin,_Screen);
                    _product.setScreen(_Screen);
                    break;                      
                case 7:
                    cout << "Cap nhat dung luong o cung (GB): ";
                    cin >> _Disk;
                    _product.setHardDisk(_Disk);
                    break;                      
                case 8:
                    cout << "Cap nhat GPU moi : ";
                    getline(cin,_GPU);
                    _product.setGPU(_GPU);
                    break;
                case 9:
                    cout << "Cap nhat He dieu hanh : ";
                    getline(cin,_OS);
                    _product.setOS(_OS);
                    break;                                                   
                case 10:
                    over = true;
                    break;
                default: cout << "Loi du lieu";
            }
        }
    }while (over != true);
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


