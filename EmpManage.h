#include "Employee.h"
#include "list.cpp"

class EmpManage : Manage {
    protected:
        list<Employee> Emp;
    public:
        EmpManage();
        ~EmpManage();
        void add(const& Employee);
        void remove(const& Employee);
        void update();
        void display();
};