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
        void writetofile(string);
        void add(const Employee&);
        void add();
        void remove(Employee&);
        void update(Employee&);
        void display();
        Node<Employee>* find(int&);
        Node<Employee>* find(string&, string&);
        int getNewID();
};