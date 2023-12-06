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
        else if (tempNode->data.getInvoiceID() == y)   
            tempList.add(tempNode->data);
        tempNode = tempNode->next;
    }
    if ( tempList.getHead() == nullptr ) cout << "khong tim thay!";
    return tempList;
}
Node<invoice>* InvManage::findID(int& ID)
{
    invoice tempInv; 
    tempInv.setInvoiceID(ID);
    return this->Inv.find(tempInv);
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
        tempNode = tempNode->next;
    }
    cout << "Thong ke: " << endl;
    cout << "Doanh thu: " << revenue << endl
    << "Loi nhuan: " << profit << endl
    << "san pham ban duoc: " << sales << endl;
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
    Node<invoice>* Ninv = this->Inv.getHead();
    if(Ninv == nullptr) return 10000000;
    return Ninv->data.getInvoiceID() + 1;
}

void InvManage::sell(int userID, CusManage& customerM, ProdManage& productM)
{
    invoice newInvoice;
    int cusID;
    int id = this->getNewID();
    newInvoice.setInvoiceID(id);
    newInvoice.setEmployeeID(userID);

    //lay thong tin khach hang
    bool over = false;
    int input , option = 1, MaxOption = 2;

    Customer newcus;
    string cusphone, x = "x";
    Node<Customer>* Ncus;
    do
    {
        system("cls");
        cout<<"Khach hang da mua hang truoc day chua:"<< endl;
        cout << (option == 1 ? "->":"  ") << "Khach hang cu " << endl;
        cout << (option == 2 ? "->":"  ") << "Khach hang moi " << endl;
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
            switch (option)
            {
                case 1:
                    cout << "Nhap so dien thoai de tim kiem khach hang: ";
                    cin >> cusphone;
                    Ncus = customerM.find(x,cusphone);
                    if(Ncus == nullptr)
                    {
                        cout << endl << "Khong tim thay khach hang nao co so dien thoai nay!";
                        system("pause");
                        break;
                    }
                    newcus = Ncus->data;
                    cout << newcus << endl;
                    system("pause");
                    cusID = newcus.getID();
                    over = true;
                    break;
                case 2:
                    newcus.setID(customerM.getNewID());
                    customerM.add(newcus);
                    customerM.update(newcus);
                    over = true;
                    break;
                // default: cout << "Loi du lieu";
            };
    } while(over != true);    
    newInvoice.updateDate(); //cap nhat thoi gian cho hoa don
    //Tuong tac voi gio hang
    this->updateCart(newInvoice,productM,customerM);
}

void InvManage::updateCart(invoice& newInv, ProdManage& productM, CusManage CustomerM)
{
    int input;
    int option = 1;
    int MaxOption = 4;
    list<order> cart = newInv.getOrder();
    do 
    {
        system("cls");
        cart.display();   
        cout << endl << "Lua chon: " << endl; 
            cout << (option == 1 ? "->":"  ") << "Them san pham " << endl;
            cout << (option == 2 ? "->":"  ") << "Xoa san pham " << endl;
            cout << (option == 4 ? "->":"  ") << "Xuat hoa don" << endl;
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
        string prodID, pay;
        Node<product>* Nprod;
        Node<order>* Norder;
        Node<string>* Nstring;
        order newOrder;
        int newQuantity, i;
        bool isSerial;
        string newSerial;
        if(input == 13)  //phim enter
        {
            switch (option)
            {
                case 1:
                    cout << "Nhap vao ma san pham: ";
                    do
                    {
                        cin >> prodID;
                        Nprod = productM.find(prodID);
                        if(Nprod == nullptr) cout << endl << "Khong tim thay san pham. Vui long nhap dung ma san pham: ";
                        if(Nprod->data.getQuantity() < 1) cout << endl << "San pham nay da het hang. Vui long chon san pham khac: ";
                    } while(Nprod == nullptr && Nprod->data.getQuantity() < 1);
                    Norder = newInv.findOrder(prodID);
                    //neu loai san pham chua co trong hoa don thi tao neworder
                    if(Norder == nullptr)
                    {   
                        newOrder.setID(prodID);
                        newOrder.setName(Nprod->data.getName());
                        newOrder.setPrice(Nprod->data.getPrice());
                    }
                    cout << "Nhap so luong san pham can them: ";
                    do
                    {
                        cin >> newQuantity;
                        if(newQuantity > Nprod->data.getQuantity()) cout << endl << "Khong du san pham. Vui long nhap lai: ";
                    } while (newQuantity > Nprod->data.getQuantity());
                    
                    for (int i = 1; i <= newQuantity ; i++)
                    {
                        cout << "Nhap serial san pham thu: " << i << ": ";
                        //kiem tra serial co ton tai trong database khong?
                        do
                        {
                            cin >> newSerial;
                            isSerial = Nprod->data.isSerial(newSerial);
                            if(!isSerial) cout << "Serial nhap vao khong ton tai. " << "Nhap lai serial san pham thu: " << i << ": ";
                        } while(!isSerial);
                        //dua serial tu san pham ra gio hang
                        Nprod->data.removeSerial(newSerial); //loi o day
                        if(Norder == nullptr) 
                        {
                            newOrder.addSerial(newSerial);
                            newOrder.updateTotal();
                        }
                        else
                        {
                            Norder->data.addSerial(newSerial);
                            Norder->data.updateTotal();
                        }
                        cout << endl <<"Them thanh cong " << newSerial << endl;
                    }
                    if(Norder == nullptr) newInv.addOrder(newOrder);
                    break;
                case 2:
                    cout << "Nhap ma san pham can xoa: ";
                    cin >> prodID;
                    Norder = newInv.findOrder(prodID);
                    if(Norder == nullptr) 
                    {
                        cout << endl << "Khong co san pham nay trong gio hang ";
                        system("pause");
                        break;
                    }
                    Nprod = productM.find(prodID);
                    cout << endl << "Nhap 0 đe xoa tat ca san pham: "<< Norder->data.getName()
                         << endl << "Hoac Nhap vao so serial cua san pham can xoa: ";
                    cin >> newSerial;
                    if (newSerial == "0") 
                    {
                        newQuantity = newInv.getOrder().find(Norder->data)->data.getQuantity();
                        list<string> serials = newInv.getOrder().find(Norder->data)->data.getSerial();
                        
                        Nstring = Norder->data.getSerial().getHead();
                        while (Nstring != nullptr) {
                            Nprod->data.addSerial(Nstring->data);
                            Nstring = Nstring->next;
                        }
                        newInv.getOrder().remove(Norder->data);
                    }    
                    else if(Norder->data.isSerial(newSerial))
                         {
                            Norder->data.removeSerial(newSerial);
                            Nprod->data.addSerial(newSerial);
                         }
                         else
                         {
                            cout << endl << "Khong co san pham mang so serial " << newSerial << " trong gio hang!";
                            system("pause");
                         }   
                    break;
                case 3:
                    system("cls");
                    newInv.updateTotal();
                    cout << "Tong gia tri don hang la :" <<newInv.getTotal() <<"Vui long chon phuong thuc thanh toan: " << endl;
                    cin >> pay;
                    newInv.setPayment(pay);
                    newInv.complete();
                    this->add(newInv);
                    //this->printInvoice(newInv.getInvoiceID(),CustomerM);
                    input = '0';
                    break;
                default: cout << "Loi du lieu";
            }
        }
    } while(input != '0');
} 

void InvManage::readfromfile(string file, string detail_file)
{
    ifstream inputFile(file);
    int ID, empID, cusID, day, month, year;
    unsigned int total;
    Date date;
    string temp, payment;
    if (inputFile.is_open()) 
    {
        string line;
        while (getline(inputFile, line))
        {
            istringstream iss(line);
            getline(iss, temp, '|');
            ID = stoi(temp);
            getline(iss, temp, '|');
            empID = stoi(temp);
            getline(iss, temp, '|');
            cusID = stoi(temp);
            getline(iss, temp, '/');
            day = stoi(temp);
            getline(iss, temp, '/');
            month = stoi(temp);
            getline(iss, temp, '|');
            year = stoi(temp);
            getline(iss, temp, '|');
            total = stoul(temp);
            getline(iss, payment, '|');
            date.setDay(day); date.setMonth(month); date.setYear(year);
            invoice newInv(ID, empID, cusID, total, payment, date);
            this->Inv.addAtEnd(newInv);
        }
        inputFile.close();
    } else {
        cerr << "Khong the mo file" << file << endl; //bao loi
    }
    ifstream inputFileOrder(detail_file);
    string productID, name, serial;
    unsigned int price;
    int quantity;
    if (inputFileOrder.is_open()) 
    {
        string line;
        while (getline(inputFileOrder, line))
        {
            istringstream iss(line);
            getline(iss, temp, '|');
            ID = stoi(temp);
            getline(iss, productID, '|');
            getline(iss, name, '|');
            getline(iss, temp, '|');
            price = stoul(temp);
            getline(iss, temp, '|');
            total = stoul(temp);
            order neworder(productID, name, price, total);
            getline(iss, temp, '|');
            quantity= stoi(temp);
            for(int i = 0; i < quantity; i++)
            {
                getline(iss, serial, ',');
                neworder.addSerial(serial);
            }
            Node<invoice>* found = this->findID(ID);
            if(found != nullptr) 
            {
                found->data.addOrder(neworder);
            }
            else cout << endl << "Loi du lieu! Khong tim thay hoa don so " << ID << endl;
        }
        for( Node<invoice>* Ninv = this->Inv.getHead(); Ninv != nullptr; Ninv = Ninv->next)
        {
            Ninv->data.complete(); //dua hoa don ve trang thai hoan thanh;
        }
        inputFileOrder.close();
    } else {
        cerr << "Khong the mo file" << file << endl; //bao loi
    }

}

void InvManage::writetofile(string file, string detail_file)
{
    ofstream outputInvoice(file);
    ofstream outputOrderDetail(detail_file);
    if (outputInvoice.is_open() && outputOrderDetail.is_open())
    {
        for (Node<invoice>* current = this->Inv.getHead(); current != nullptr; current = current->next) 
        {
            invoice currentInv = current->data;
            outputInvoice << currentInv.getInvoiceID() << "|";
            outputInvoice << currentInv.getEmployeeID() << "|";
            outputInvoice << currentInv.getCustomerID() << "|";
            outputInvoice << currentInv.getDate() << "|";
            outputInvoice << currentInv.getTotal() << "|";
            outputInvoice << currentInv.getPayment() << "|";
            outputInvoice << endl;
            for (Node<order>* Norder = currentInv.getOrder().getHead(); Norder != nullptr; Norder = Norder->next)
            {
               order currentOrder = Norder->data;
               outputOrderDetail << currentInv.getInvoiceID() << "|";
               outputOrderDetail << currentOrder.getID() << "|";
               outputOrderDetail << currentOrder.getName() << "|";
               outputOrderDetail << currentOrder.getPrice() << "|";
               outputOrderDetail << currentOrder.getTotal() << "|";
               outputOrderDetail << currentOrder.getQuantity() << "|";
               Node<string>* serial = currentOrder.getSerial().getHead();
               while(serial != nullptr)
               {
                    outputOrderDetail << serial->data << ",";
                    serial = serial->next;
               }
                outputOrderDetail << endl;
            }
        }
        outputInvoice.close();
        outputOrderDetail.close();       
    } else
    {
        cerr << "Khong the ghi du lieu" << endl;
    }
}