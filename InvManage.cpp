#include "InvManage.h"
InvManage::InvManage()
{ }
InvManage::~InvManage()
{ }
void InvManage::add(const invoice& c) {
    this->Inv.add(c);
}
void InvManage::remove(const invoice& c){
    //this->Inv.remove(c);
    cout << endl << "Khong the xoa hoa don!" << endl;
}
void InvManage::display(){
    this->Inv.display();
}
void InvManage::update(invoice&){
    cout << endl << "Khong the chinh sua hoa don!" << endl;
}
list<invoice> InvManage::find(int& d, int& m, int& y){
    list<invoice> tempList;
    Node<invoice>* tempNode;
    tempNode = this->Inv.getHead();
    while (tempNode != nullptr) 
    {
        if (tempNode->data.getDate().getDay() == d && tempNode->data.getDate().getMonth() == m && tempNode->data.getDate().getYear() == y)   
            tempList.add(tempNode->data);
        tempNode = tempNode->next;
    }
    if ( tempList.getHead() == nullptr ) cout << "khong tim thay!";
    return tempList;
}
list<invoice> InvManage::find(int& m, int& y){
    list<invoice> tempList;
    Node<invoice>* tempNode;
    tempNode = this->Inv.getHead();
    while (tempNode != nullptr) 
    {
        if (tempNode->data.getDate().getMonth() == m && tempNode->data.getDate().getYear() == y)   
            tempList.add(tempNode->data);
        tempNode = tempNode->next;
    }
    if ( tempList.getHead() == nullptr ) cout << "khong tim thay!";
    return tempList;
}
list<invoice> InvManage::find(int& y){
    list<invoice> tempList;
    Node<invoice>* tempNode;
    tempNode = this->Inv.getHead();
    while (tempNode != nullptr) 
    {
        if (tempNode->data.getDate().getYear() == y)   
            tempList.add(tempNode->data);
        else if (tempNode->data.getCustomerID() == y)   
            tempList.add(tempNode->data);
        tempNode = tempNode->next;
    }
    if ( tempList.getHead() == nullptr ) cout << "khong tim thay!";
    return tempList;
}
void InvManage::statistic(list<invoice> List){
    Node<invoice>* tempNode;
    tempNode = List.getHead();
    int revenue = 0; //doanh thu
    int profit = 0; //loi nhuan
    int sales = 0; //so luong san pham ban duoc 
    while (tempNode != nullptr){
        revenue += tempNode->data.getTotal();
        profit += tempNode->data.getProfit();
        sales += tempNode->data.productSales();
    }
    cout << "Thong ke: " << endl;
    cout << "Doanh thu: " << revenue << endl
    << "Loi nhuan: " << profit << endl
    << "san pham ban duocL " << sales << endl;
    delete tempNode;
}

// invoice InvManage::printInvoice(int& ID, list<Customer>& cusList)
// {
//     //in hoa don ra man hinh
//     //in hoa don ra file trong folder hoa don
//     Node<invoice>* tempInv;
//     tempInv = this->Inv.getHead();
//     while (tempInv != nullptr){
//         if(tempInv->data.getInvoiceID() == ID)
//             break;
//         else tempInv = tempInv->next;
//     }
//     if (tempInv == nullptr) return tempInv->data;
//     Node<Customer>* tempCus;
//     tempCus = cusList.getHead();
//     while (tempCus != nullptr){
//         if(tempCus->data.getID() == tempInv->data.getCustomerID())
//             break;
//         else tempCus = tempCus->next;
//     }
//     if (tempCus == nullptr) return tempInv->data;
//     cout << "Ten khach hang: " << tempCus->data.getName() << endl
//     << "So dien thoai: " <<tempCus->data.getPhone() << endl;
//     Node<order>* tempOrder;
//     Node<string>* tempSerial;
//     tempOrder = tempInv->data.getOrder().getHead();
//     tempSerial = tempOrder->data.get.getHead();
//     while (tempOrder != nullptr){
//         cout << "Ten hang: " << tempOrder->data.getName() << endl
//         << "So luong: " << tempOrder->data.getQuantity() << endl
//         << "Don gia: " << tempOrder->data.getPrice() << endl
//         << "Thanh tien: " << tempOrder->data.getTotal() << endl;
//         while (tempSerial != nullptr){
//             if (tempSerial->next == nullptr)
//                 cout << tempSerial->data << endl;
//             else 
//                 cout << tempSerial->data << ", ";
//         }
//         cout << "Tong cong: " << tempInv->data.getTotal() << endl;
//     }
//     return tempInv->data;
// }

int InvManage::getNewID()
{
    int newID = this->Inv.getHead()->data.getInvoiceID();
    if (!(newID >= 10000000)) newID = 10000000 - 1; //ID dau tien bat dau tu 10000000, neu be hon thi chua co hoa don nao  
    return this->Inv.getHead()->data.getInvoiceID() + 1;
}

// void InvManage::sell(int& userID, CusManage& customerM, ProdManage& productM)
// {
//     invoice newInvoice;
//     int id = this->getNewID();
//     newInvoice.setInvoiceID(id);
//     newInvoice.setEmployeeID(userID);

//     //lay thong tin khach hang
//     int input;
//     int choice = 1;
//     int MaxChoice = 2;
//     do
//     {
//         Customer newcus;
//         string cusphone, x = "x";
//         Node<Customer>* Ncus;
//         do{
//             system("cls");
//             cout<<"Khach hang da mua hang truoc day chua:"<< endl;
//             cout << (choice == 1 ? "->":"  ") << "Khach hang cu " << endl;
//             cout << (choice == 2 ? "->":"  ") << "Khach hang moi " << endl;
//             input = getch();

//             if (input == 80) //phim mui ten xuong
//             { 
//                 if (choice == MaxChoice) choice = 1; // quay tro lai dau danh sach
//                 else choice++;
//             }else if (input == 72) //phim mui ten len
//             {
//                 if (choice == 1) choice = MaxChoice; //chay vong xuong cuoi danh sach
//                 else choice--;
//             }
        
//         }
//         while(input == 13);  //phim enter
//             switch (choice)
//             {
//                 using namespace std;
//                 case 1:
//                     cout << "Nhap so dien thoai de tim kiem khach hang: ";
//                     cin >> cusphone;
//                     Ncus = customerM.find(x,cusphone);
//                     if(Ncus == nullptr)
//                     {
//                         cout << endl << "Khong tim thay khach hang nao co so dien thoai nay!";
//                         system("pause");
//                         break;
//                     }
//                     newcus = Ncus->data;
//                     cout << newcus << endl;
//                     int cusID = newcus.getID();
//                     input = '0';
//                     break;
//                 case 2:
//                     newcus.setID(customerM.getNewID());
//                     customerM.add(newcus);
//                     customerM.update(newcus);
//                     input = '0';
//                     break;
//                 // default: cout << "Loi du lieu";
//             }
//     } while(input == '0');    
//     newInvoice.updateDate(); //cap nhat thoi gian cho hoa don
//     //Tuong tac voi gio hang
//     this->updateCart(newInvoice,productM,customerM);
// }

// void InvManage::updateCart(invoice& newInv, ProdManage& productM, CusManage CustomerM)
// {
//     int input;
//     int choice = 1;
//     int MaxChoice = 2;
//     list<order> cart = newInv.getOrder();
//     do 
//     {
//         system("cls");
//         cart.display();   
//         cout << endl << "Lua chon: " << endl; 
//             cout << (choice == 1 ? "->":"  ") << "Them san pham " << endl;
//             cout << (choice == 2 ? "->":"  ") << "Xoa san pham " << endl;
//             cout << (choice == 3 ? "->":"  ") << "Xuat hoa don" << endl;
//             input = getch();

//             if (input == 80) //phim mui ten xuong
//             { 
//                 if (choice == MaxChoice) choice = 1; // quay tro lai dau danh sach
//                 else choice++;
//             }else if (input == 72) //phim mui ten len
//             {
//                 if (choice == 1) choice = MaxChoice; //chay vong xuong cuoi danh sach
//                 else choice--;
//             }
//         string prodID;
//         Node<product>* Nprod;
//         Node<order>* Norder;
//         order newOrder;
//         int newQuantity;
//         bool isSerial;
//         string newSerial;
//         if(input == 13)  //phim enter
//         {
//             switch (choice)
//             {
//                 using namespace std;
//                 case 1:
//                     cout << "Nhap vao ma san pham: ";
//                     do
//                     {
//                         cin >> prodID;
//                         Nprod = productM.find(prodID);
//                         if(Nprod == nullptr) cout << endl << "Khong tim thay san pham. Vui long nhap dung ma san pham: ";
//                     } while(Nprod == nullptr);
//                     Norder = newInv.findOrder(prodID);
//                     //neu loai san pham chua co trong hoa don thi tao neworder
//                     if(Norder == nullptr)
//                     {   
//                         newOrder.setID(prodID);
//                         newOrder.setName(Nprod->data.getName());
//                         newOrder.setPrice(Nprod->data.getPrice());
//                     }
//                     cout << "Nhap so luong san pham can them: ";
//                     do
//                     {
//                         cin >> newQuantity;
//                         if(newQuantity > Nprod->data.getQuantity()) cout << endl << "Khong du san pham. Vui long nhap lai: ";
//                     } while (newQuantity > Nprod->data.getQuantity());
                    
//                     for (int i = 1; i <= newQuantity ; i++)
//                     {
//                         cout << "Nhap serial san pham thu: " << i << ": ";
//                         //kiem tra serial co ton tai trong database khong?
//                         do
//                         {
//                             product tempProd = productM. 
//                             cin >> newSerial;
//                             isSerial = tempProd.isSerial(newSerial);
//                             if(!isSerial) cout << "Serial nhap vao khong ton tai. " << "Nhap lai serial san pham thu: " << i << ": ";
//                         } while(!isSerial);
//                         //dua serial tu san pham ra gio hang
//                         Nprod->data.removeSerial(newSerial); 
//                         if(Norder == nullptr) newOrder.addSerial(newSerial);
//                         else Norder->data.addSerial(newSerial);
//                         cout << endl <<"Them thanh cong " << newSerial << endl;
//                     }
//                     if(Norder == nullptr) newInv.addOrder(newOrder);
//                     break;
//                 case 2:
//                     cout << "Nhap ma san pham can xoa: ";
//                     cin >> prodID;
//                     Norder = newInv.findOrder(prodID);
//                     if(Norder == nullptr) 
//                     {
//                         cout << endl << "Khong co san pham nay trong gio hang ";
//                         system("pause");
//                         break;
//                     }
//                     cout << endl << "Nhap 0 đe xoa tat ca san pham: "<< Norder->data.getName()
//                          << endl << "Hoac Nhap vao so serial cua san pham can xoa: ";
//                     cin >> newSerial;
//                     if (newSerial == "0") newInv.getOrder().remove(Norder->data);
//                     else if(Norder->data.isSerial(newSerial))
//                             Norder->data.removeSerial(newSerial);
//                          else
//                          {
//                             cout << endl << "Khong co san pham mang so serial " << newSerial << " trong gio hang!";
//                             system("pause");
//                          }   
//                     break;
//                 case 3:
//                     newInv.updateTotal();
//                     newInv.complete();
//                     this->add(newInv);
//                     this->printInvoice(newInv.getInvoiceID(),CustomerM);
//                     input = '0';
//                     break;
//                 default: cout << "Loi du lieu";
//             }
//         }
//     } while(input != '0');
// } 
void InvManage::readfromfile(string file, string detail_file){
    ifstream input(detail_file);
    list<order> tempList;
    int value;
    while (!input.eof()){
        int n = 0;
        string info[20];
        order tempOrder;
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
            n++;
        } while(n <= 4);
        
        if (isdigit(info[0][0]) && isdigit(info[3][0]) && isdigit(info[4][0])){
            value = stoi(info[0]); tempOrder.setInvoiceID(value);
            value = stoi(info[3]); tempOrder.setPrice(value);
            value = stoi(info[4]); tempOrder.setQuantity(value);
        }
        
        tempOrder.setID(info[1]);
        tempOrder.setName(info[2]);
        int m = 4 + tempOrder.getQuantity();
        do {
            Data = "";
            input.get(c);
            while (c != '|' && c != ',' && c != '\n' && !input.eof()){
                Data += c;
                input.get(c);
            }
            tempOrder.addSerial(Data);
            n++;
        } while(n <= m);
        tempList.addAtEnd(tempOrder);
    }
    input.close();
    ifstream input2(file);
    invoice tempInv;
    while(!input2.eof()){
        int n = 0;
        string info[10];
        char c;
        string Data;
        do {
            string Data = "";
            input2.get(c);
            while (c != '|' && c != '\n' && c != '/' && !input2.eof()){
                Data += c;
                input2.get(c);
            }
            info[n] = Data;
            n++;
        } while(n <= 2);
        if (isdigit(info[0][0]) && isdigit(info[0][1]) && isdigit(info[0][2])){
        value = stoi(info[0]); tempInv.setInvoiceID(value);
        value = stoi(info[1]); tempInv.setEmployeeID(value);
        value = stoi(info[2]); tempInv.setCustomerID(value);
        }
        do {
            Data = "";
            input2.get(c);
            while (c != '/' && c != '\n' && !input2.eof()){
                Data += c;
                input2.get(c);
            }
            info[n] = Data;
            n++;
        } while(n <= 5);
        value = stoi(info[3]); tempInv.getDate().setDay(value);
        value = stoi(info[4]); tempInv.getDate().setMonth(value);
        value = stoi(info[5]); tempInv.getDate().setYear(value);
        order* tempOrder = &tempList.getHead()->data;
        while(tempOrder != nullptr){
            if(tempOrder->getInvoiceID() == tempInv.getInvoiceID())
                tempInv.addOrder(*tempOrder);
        }
    }
    this->Inv.addAtEnd(tempInv);
    input2.close();
}