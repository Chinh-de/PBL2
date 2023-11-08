#include <iostream>
#include <string>
#include "list.cpp"
using namespace std;

int main(){
    list<string> ngu;
    ngu.add("ngu");
    ngu.add("ngu3");
    ngu.add("ngu2");
    ngu.add("ngu");
    ngu.remove("ngu2");
    ngu.display();
    return 0;
}
