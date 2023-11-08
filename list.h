#include <iostream>
#include "Node.h"
using namespace std;

template <typename T>
class list
{
    private:
        Node<T> *head;
    public:
        list();
        ~list();
        void add(const T&);
        void remove(const T&);
        void display();
        //void update();
};
