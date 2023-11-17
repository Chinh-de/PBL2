#include "Employee.h"
#include "list.cpp"

class EmpManage {
    protected:
        list<Employee> Emp;
    public:
        EmpManage();
        ~EmpManage();
        void add(const Employee&);
        void remove(const Employee&);
        void update();
        void display();
};