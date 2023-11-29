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
    //readallData;
}
void Database::saveData()
{
    //writeallData;
}