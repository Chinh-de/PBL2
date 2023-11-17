#include "Employee.h"
#include "list.cpp"
#include "Manage.h"

class EmpManage : public Manage<Employee> {
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