#include <iostream>
using namespace std;

class Person{
    protected:
        int ID;
        string Name, Phone, Email;
        bool Genre;
        string Address;
    public:
        Person(int = 0, string = "", string "", string = "", bool = true, string = "");
        ~Person();
        void Show();
};