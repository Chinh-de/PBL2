#include <iostream>
#pragma once
using namespace std;
template<typename T>

class Manage{
    protected:
        virtual void add(const T&) = 0;
        virtual void display() = 0;
        virtual void update() = 0;
        virtual void remove(const T&) = 0;
};