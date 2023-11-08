#include <iostream>
#include <string>
#include "list.h"
using namespace std;

int main(){
    list<string> l;
    l.add("ngu");
    l.remove("ngu2");
    l.display;
    return 0;
}