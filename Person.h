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
        string name, phone, email;
        bool gender;
        string address;
    public:
        Person(int = 0, string = "", string "", string = "", Gender = male, string = "");
        ~Person();
        void Show();
        int getID();
        void setID(int);
        string getname();
        void setname(string);
        string getphone();
        void setphone(string);
        string getemail();
        void setemail(string);
        Gender getgender();
        void setgender(Gender);
        string getaddress();
        void setaddress(string);
        
};