#include <iostream>
using namespace std;

class Person{
    protected:
        int ID;
        string Name, Phone, Email;
        bool Gender;
        string Address;
    public:
        Person(int = 0, string = "", string = "", string = "", bool = true, string = "");
        ~Person();
        virtual void Show();
        int getID();
        void setID(int);
        string getName();
        void setName(string);
        string getPhone();
        void setPhone(string);
        string getEmail();
        void setEmail(string);
        bool getGender();
        void setGender(bool);
        string getAddress();
        void setAddress(string);
};