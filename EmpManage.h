#include "Employee.h"
#include "list.cpp"
#include "Manage.h"
#pragma once

class EmpManage : public Manage<Employee> {
    protected:
        list<Employee> Emp;
    public:
        EmpManage();
        ~EmpManage();
        void readfromfile(string);
        void add(const Employee&);
        void add();
        void remove(const Employee&);
        void update(Employee&);
        void display();
        Node<Employee>* find(int&);
        list<Employee> find(string&, string&);
};