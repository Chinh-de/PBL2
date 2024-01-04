#include "InvManage.h"
InvManage::InvManage()
{ }
InvManage::~InvManage()
{ }
void InvManage::add(const invoice& c) {
    this->Inv.add(c);
}
void InvManage::remove(invoice& c){
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
    if ( tempList.getHead() == nullptr ) cout << "khong tim thay!" << endl;
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
    if ( tempList.getHead() == nullptr ) cout << "khong tim thay!" << endl;
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
        tempNode = tempNode->next;
    }
    if ( tempList.getHead() == nullptr ) cout << "khong tim thay!" << endl;
    return tempList;
}
list<invoice> InvManage::find(Customer& cus){
    list<invoice> tempList;
    Node<invoice>* tempNode;
    int cusID = cus.getID();
    tempNode = this->Inv.getHead();
    while (tempNode != nullptr) 
    {
        if (tempNode->data.getCustomerID() == cusID)   
            tempList.add(tempNode->data);
        tempNode = tempNode->next;
    }
    if ( tempList.getHead() == nullptr ) cout << "khong tim thay lich su mua hang!" << endl;
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

void InvManage::printInvoice(int invID, CusManage CustomerM, EmpManage EmployeeM)
{
    string filePath = "invoice/";
    filePath += "invoice_" + to_string(invID) + ".txt";
    ofstream outfile(filePath);
    if (!outfile.is_open()) {
        cerr << "Loi mo file de ghi." << endl;
        return;
    }

    invoice inv = this->findID(invID)->data;
    int cusID = inv.getCustomerID();
    Customer cus = CustomerM.find(cusID)->data;
    int empID = inv.getEmployeeID(); 
    Employee emp = EmployeeM.find(empID)->data;

	outfile << setfill('_') << setw(152) << "" << endl << setfill(' ') ;
    outfile << "|" << setw(151) << right << "ITF Store|" << endl;
    outfile << "|" << setw(151) << right << "Dia chi: Lien Chieu, Da Nang|" << endl;
    outfile << "|" << setw(151) << right << "Website: ITFstore.dut|" << endl;
    outfile << "|" << setw(151) << right << "So dien thoai: 0123456xxx|" << endl;
	outfile << setfill('*') << setw(152) << "" << endl << setfill(' ') ;
	outfile << "|" << setw(83) << right << "HOA DON BAN HANG" << setw(68) << right << "|" << endl;
    
    outfile << "|Ma hoa don: " << setw(138) << left << inv.getInvoiceID() << "|" << endl;
    string date = to_string(inv.getDate().getDay()) + "/" + to_string(inv.getDate().getMonth()) + "/" + to_string(inv.getDate().getYear());
    outfile << "|Ngay ban: " << setw(140) << date <<"|" << endl;
    outfile << "|Ma khach hang: " << setw(135) << left << inv.getCustomerID() << "|" << endl;
    outfile << "|Ten khach hang: " << setw(134) << left << cus.getName() << "|" << endl;
    outfile << "|So dien thoai: " << setw(135) << left << cus.getPhone() << "|" << endl;
    outfile << "|Email: " << setw(143) << left << cus.getEmail() << "|" << endl;
    outfile << "|Dia chi: " << setw(141) << left << cus.getAddress() << "|" << endl;
    outfile << "|Nhan vien ban: " << setw(135) << " " << "|"  << endl;
    outfile << "|Ma nhan vien: " << setw(136) << left << emp.getID() << "|" << endl;
    outfile << "|Ten nhan vien: " << setw(135) << left << emp.getName() << "|" << endl;
    outfile << "|" << setw(150) << " " << "|"  << endl;
    outfile << "|" << setfill('-') << setw(151) << right << "|" << endl << setfill(' ') ;
    outfile << "|" << setw(3) << left << "STT";
    outfile << setw(18) << left << "|Ma san pham";
    outfile << setw(51) << left << "|Ten san pham";
    outfile << setw(3) << left << "|SL";
    outfile << setw(49) << left << "|So serial";
    outfile << setw(13) << left << "|Don gia";
    outfile << setw(13) << left << "|Thanh tien" << "|"<< endl;
    outfile << "|" << setfill('-') << setw(151) << right << "|" << endl << setfill(' ') ;
    int i = 0;
    string serial = "";
    for (Node<order>* Norder = inv.getOrder().getHead(); Norder != nullptr; Norder = Norder->next)
    {
        outfile << "|" << setw(3) << left << ++i;
        outfile << "|" << setw(17) << left << Norder->data.getID();
        outfile << "|" << setw(50) << left << Norder->data.getName();
        outfile << "|" << setw(2) << left << Norder->data.getQuantity();
        serial = "";
        for (Node<string>* Nstring = Norder->data.getSerial().getHead(); Nstring != nullptr; Nstring = Nstring->next)
        {
            serial += Nstring->data;
            serial += ",";
        }
        outfile << "|"<< setw(48) << left << serial;
        outfile << "|" << setw(12) << left << Norder->data.getPrice();
        outfile << "|" << setw(12) << left << Norder->data.getTotal() << "|"<< endl;
        outfile << "|" << setfill('-') << setw(151) << right << "|" << endl << setfill(' ') ;
    }
    outfile << "|" << setw(138) << right << "Tong tien: " << setw(12) << left << inv.getTotal() << "|"<< endl;
    outfile << "|" << "Thanh toan: " << setw(138) << left << inv.getPayment() << "|" << endl;
    outfile << setfill('*') << setw(152) << "" << endl << setfill(' ') ;
    outfile.close();
    //in hoa don ra ma hinh
    system("cls");
    ifstream inFile(filePath);
    if (!inFile.is_open()) {
        cerr << "Khong the mo file de doc" << endl;
        return;
    }
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();

}
void InvManage::printInvoice(invoice& inv, CusManage CustomerM, EmpManage EmployeeM)
{
    int cusID = inv.getCustomerID();
    Customer cus = CustomerM.find(cusID)->data;
    int empID = inv.getEmployeeID(); 
    Employee emp = EmployeeM.find(empID)->data;
	cout << setfill('_') << setw(152) << "" << endl << setfill(' ') ;
    cout << "|" << setw(151) << right << "ITF Store|" << endl;
    cout << "|" << setw(151) << right << "Dia chi: Lien Chieu, Da Nang|" << endl;
    cout << "|" << setw(151) << right << "Website: ITFstore.dut|" << endl;
    cout << "|" << setw(151) << right << "So dien thoai: 0123456xxx|" << endl;
	cout << setfill('*') << setw(152) << "" << endl << setfill(' ') ;
	cout << "|" << setw(83) << right << "HOA DON BAN HANG" << setw(68) << right << "|" << endl;
    
    cout << "|Ma hoa don: " << setw(138) << left << inv.getInvoiceID() << "|" << endl;
    string date = to_string(inv.getDate().getDay()) + "/" + to_string(inv.getDate().getMonth()) + "/" + to_string(inv.getDate().getYear());
    cout << "|Ngay ban: " << setw(140) << date <<"|" << endl;
    cout << "|Ma khach hang: " << setw(135) << left << inv.getCustomerID() << "|" << endl;
    cout << "|Ten khach hang: " << setw(134) << left << cus.getName() << "|" << endl;
    cout << "|So dien thoai: " << setw(135) << left << cus.getPhone() << "|" << endl;
    cout << "|Email: " << setw(143) << left << cus.getEmail() << "|" << endl;
    cout << "|Dia chi: " << setw(141) << left << cus.getAddress() << "|" << endl;
    cout << "|Nhan vien ban: " << setw(135) << " " << "|"  << endl;
    cout << "|Ma nhan vien: " << setw(136) << left << emp.getID() << "|" << endl;
    cout << "|Ten nhan vien: " << setw(135) << left << emp.getName() << "|" << endl;
    cout << "|" << setw(150) << " " << "|"  << endl;
    cout << "|" << setfill('-') << setw(151) << right << "|" << endl << setfill(' ') ;
    cout << "|" << setw(3) << left << "STT";
    cout << setw(18) << left << "|Ma san pham";
    cout << setw(51) << left << "|Ten san pham";
    cout << setw(3) << left << "|SL";
    cout << setw(49) << left << "|So serial";
    cout << setw(13) << left << "|Don gia";
    cout << setw(13) << left << "|Thanh tien" << "|"<< endl;
    cout << "|" << setfill('-') << setw(151) << right << "|" << endl << setfill(' ') ;
    int i = 0;
    string serial = "";
    for (Node<order>* Norder = inv.getOrder().getHead(); Norder != nullptr; Norder = Norder->next)
    {
        cout << "|" << setw(3) << left << ++i;
        cout << "|" << setw(17) << left << Norder->data.getID();
        cout << "|" << setw(50) << left << Norder->data.getName();
        cout << "|" << setw(2) << left << Norder->data.getQuantity();
        serial = "";
        for (Node<string>* Nstring = Norder->data.getSerial().getHead(); Nstring != nullptr; Nstring = Nstring->next)
        {
            serial += Nstring->data;
            serial += ",";
        }
        cout << "|"<< setw(48) << left << serial;
        cout << "|" << setw(12) << left << Norder->data.getPrice();
        cout << "|" << setw(12) << left << Norder->data.getTotal() << "|"<< endl;
        cout << "|" << setfill('-') << setw(151) << right << "|" << endl << setfill(' ') ;
    }
    cout << "|" << setw(138) << right << "Tong tien: " << setw(12) << left << inv.getTotal() << "|"<< endl;
    cout << "|" << "Thanh toan: " << setw(138) << left << "Chua thanh toan" << "|" << endl;
    cout << setfill('*') << setw(152) << "" << endl << setfill(' ') ;
}
int InvManage::getNewID()
{
    Node<invoice>* Ninv = this->Inv.getHead();
    if(Ninv == nullptr) return 100000;
    return Ninv->data.getInvoiceID() + 1;
}

void InvManage::sell(int userID, CusManage& customerM, ProdManage& productM, EmpManage& EmployeeM)
{
    invoice newInvoice;
    int cusID;
    int id = this->getNewID();
    newInvoice.setInvoiceID(id);
    newInvoice.setEmployeeID(userID);

    //lay thong tin khach hang
    bool over = false;
    int input, option = 1, next_option =1, MaxOption = 3;

    Customer newcus;
    string cusphone, x = "x";
    Node<Customer>* Ncus;
    do
    {
        system("cls");
        cout<<"Khach hang da mua hang truoc day chua:"<< endl;
        cout << (option == 1 ? "->":"  ") << "Khach hang cu " << endl;
        cout << (option == 2 ? "->":"  ") << "Khach hang moi " << endl;
        cout << (option == 3 ? "->":"  ") << "Tro lai " << endl;
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
                        cout << endl << "Khong tim thay khach hang nao co so dien thoai nay!" << endl << endl << endl;
                        system("pause");
                        break;
                    }
                    newcus = Ncus->data;
                    do
                    {
                        system("cls");
                        cout << newcus << endl;
                        cout << "Xac nhan thong tin: " << endl;
                        cout << (next_option == 1 ? "->":"  ") << "Xac nhan " << endl;
                        cout << (next_option == 2 ? "->":"  ") << "Tro ve " << endl;
                        input = getch();
                        if (input == 72) next_option--;
                        else if (input == 80) next_option++;
                        if (next_option < 1) next_option = 2;
                        if (next_option > 2) next_option = 1;
                    } while(input != 13);
                    switch (next_option)
                    {
                        case 1: cusID = newcus.getID();
                                over = true;
                                break;
                        case 2: over = false; break;
                    }
                    break;
                case 2:
                    newcus = Customer(); //lam moi gia tri cua newcus
                    newcus.setID(customerM.getNewID());
                    customerM.add(newcus);
                    cusID = newcus.getID();
                    customerM.update(newcus);
                    over = true;
                    break;
                case 3:  
                    return;  
                default: cout << "Loi du lieu";
            };
    } while(over != true);
    if (option != 3){
        newInvoice.setCustomerID(cusID);
        newInvoice.updateDate(); //cap nhat thoi gian cho hoa don
        //Tuong tac voi gio hang
        this->updateCart(newInvoice,productM,customerM,EmployeeM);
    }
}

void InvManage::updateCart(invoice& newInv, ProdManage& productM, CusManage& CustomerM, EmpManage& EmployeeM)
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
            cout << (option == 3 ? "->":"  ") << "Xuat hoa don" << endl;
            cout << (option == 4 ? "->":"  ") << "Huy" << endl;
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
        int newQuantity, i, next_option;
        bool isSerial;
        string newSerial;
        if(input == 13)  //phim enter
        {
            switch (option)
            {
                case 1:
                    cout << "Nhap vao ma san pham: ";
                    cin >> prodID;
                    Nprod = productM.find(prodID);
                    if(Nprod == nullptr)
                    {
                        cout << endl << "Khong tim thay san pham. Vui long nhap dung ma san pham! " << endl << endl;
                        system("pause");
                        break;
                    }
                    if(Nprod->data.getQuantity() < 1) 
                    {
                        cout << endl << "San pham nay da het hang. Vui long chon san pham khac! "<< endl << endl;
                        system("pause");
                        break;
                    } 
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
                        cout << endl << "Nhap serial san pham thu: " << i << ": ";
                        //kiem tra serial co ton tai trong database khong?
                        do
                        {
                            cin >> newSerial;
                            isSerial = Nprod->data.isSerial(newSerial);
                            if(!isSerial) cout << "Serial nhap vao khong ton tai. " << "Nhap lai serial san pham thu: " << i << ": ";
                        } while(!isSerial);
                        //dua serial tu san pham ra gio hang
                        Nprod->data.removeSerial(newSerial); 
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
                        cout << "_____________________________________________________________" << endl;
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
                    cout << endl << "Nhap 0 de xoa tat ca san pham: "<< Norder->data.getName()
                         << endl << "Hoac Nhap vao so serial cua san pham can xoa: ";
                    cin >> newSerial;
                    if (newSerial == "0") 
                    {   
                        Nstring = Norder->data.getSerial().getHead();
                        while (Nstring != nullptr) {
                            Nprod->data.addSerial(Nstring->data);
                            Nstring = Nstring->next;
                        }
                        newInv.getOrder().remove(Norder->data);
                    }    
                    else 
                        if(Norder->data.isSerial(newSerial))
                        {
                            Norder->data.removeSerial(newSerial);
                            Nprod->data.addSerial(newSerial);
                        }
                        else
                        {
                            cout << endl << "Khong co san pham mang so serial " << newSerial << " trong gio hang!";
                            system("pause");
                        }   
                        if(Norder->data.getQuantity() == 0) newInv.getOrder().remove(Norder->data);

                    break;
                case 3:
                    system("cls");
                    if(newInv.getOrder().getHead() == nullptr) 
                    {
                        cout << "Hoa Don Rong"; 
                        cout << endl << endl << endl;
                        system("pause");
                    }
                    else
                    {
                        newInv.updateTotal();
                        this->printInvoice(newInv, CustomerM, EmployeeM);
                        cout << endl << endl << endl;
                        system("pause");
                        next_option = 1;
                        do{
                            system("cls");
                            cout << ((next_option == 1) ? "->" : "  ") << "Xac nhan thanh toan" << endl;
                            cout << ((next_option == 2) ? "->" : "  ") << "Tro ve" << endl;
                            input = getch();
                            if (input == 72) next_option--;
                            else if (input == 80) next_option++;
                            if (next_option < 1) next_option = 2;
                            if (next_option > 2) next_option = 1;
                        }while(input != 13);
                        if(next_option == 1)
                        {
                            cout << "Tong gia tri don hang la :" << newInv.getTotal() << endl << "Vui long chon phuong thuc thanh toan: ";
                            cin.clear();
                            cin.ignore(1000, '\n');
                            getline(cin, pay);
                            newInv.setPayment(pay);
                            newInv.complete();
                            this->add(newInv);
                            this->printInvoice(newInv.getInvoiceID(),CustomerM,EmployeeM);
                            input = '0';
                            system("pause");
                            cout << endl << endl;
                        }
                    }
                    break;
                case 4:
                    Norder = newInv.getOrder().getHead();
                    while (Norder != nullptr)
                    {
                        prodID = Norder->data.getID();
                        Nprod = productM.find(prodID);
                        Nstring = Norder->data.getSerial().getHead();
                        while (Nstring != nullptr) {
                            Nprod->data.addSerial(Nstring->data);
                            Nstring = Nstring->next;
                        }
                        newInv.removeOrder(Norder->data.getID());
                        Norder = newInv.getOrder().getHead();
                    }
                    input = '0';
                    break;
                default: cout << "Loi du lieu";
            }
        }
    } while(input != '0');
} 
void InvManage::findtoShow(int& ID)
{
    string filePath = "invoice/";
    filePath += "invoice_" + to_string(ID) + ".txt";
    system("cls");
    ifstream inFile(filePath);
    if (!inFile.is_open()) {
        cerr << "Khong tim thay Hoa don!" << endl;
        return;
    }
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();
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
            iss >> ID;
            iss.ignore(); 
            getline(iss, productID, '|');
            getline(iss, name, '|');
            iss >> price;
            iss.ignore(); 
            iss >> total;
            iss.ignore(); 
            order neworder(productID, name, price, total);
            iss >> quantity;
            iss.ignore(); 
            for(int i = 0; i < quantity; i++)
            {
                getline(iss, serial, ',');
                neworder.addSerial(serial);
            }
            Node<invoice>* found = this->findID(ID);
            if(found != nullptr) 
            {
                found->data.getOrder().addAtEnd(neworder);
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
    ofstream outputInvoice(file, ios::out | ios::trunc);
    ofstream outputOrderDetail(detail_file, ios::out | ios::trunc);
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