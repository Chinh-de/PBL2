#include "Database.h"
using namespace std;

Database Database::instance; //khoi tao database truoc tien

Database::Database() {}

Database::~Database() {}

Database& Database::DB_Instance() {
    return instance;
}

ProdManage& Database::getProdManage()
{
    return this->productM;
}

EmpManage& Database::getEmpManage()
{
    return this->employeeM;
}

CusManage& Database::getCusManage()
{
    return this->customerM;
}

InvManage& Database::getInvManage()
{
    return this->invoiceM;
}

void Database::readData()
{
    instance.customerM.readfromfile("customer.txt");
    instance.employeeM.readfromfile("employee.txt");
    instance.productM.readfromfile("product.txt");
    instance.invoiceM.readfromfile("invoice.txt", "invoice_detail.txt");
}

void Database::saveData()
{
    instance.customerM.writetofile("customer.txt");
    instance.employeeM.writetofile("employee.txt");
    instance.productM.writetofile("product.txt");
    instance.invoiceM.writetofile("invoice.txt", "invoice_detail.txt");
}

