#include <iostream>
using namespace std;

class Manage{
    protected:
        virtual void Add() = 0;
        virtual void Display() = 0;
        virtual void Update() = 0;
        virtual void Remove() = 0;
};