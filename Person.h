#include <iostream>
using namespace std;
#include <string>

enum Gender 
{
    male,
    female,
    other
};

class Person{
    protected:
        int ID;
        string Name, Phone, Email;
        bool Gender;
        string Address;
    public:
        Person(int = 0, string = "", string = "", string = "", bool = true, string = "");
        ~Person();
        void Show();
        int GetID();
        void SetID(int);
        string GetName();
        void SetName(string);
        string GetPhone();
        void SetPhone(string);
        string GetEmail();
        void SetEmail(string);
        bool GetGender();
        void SetGender(bool);
        string GetAddress();
        void SetAddress(string);
};