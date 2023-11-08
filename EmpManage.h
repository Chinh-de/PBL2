#include "Employee.h"
#include "list.h"

class EmpManage : Manage {
    protected:
        list<Employee> Emp;
    public:
        EmpManage();
        ~EmpManage();
        void Add();
        void Remove();
        void Update();
        void Dispay();
};