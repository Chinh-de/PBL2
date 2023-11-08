#include <iostream>
using namespace std;

class Manage{
    protected:
        virtual void Add() = 0;
        virtual void List() = 0;
        virtual void Update() = 0;
        virtual void Delete() = 0;
};