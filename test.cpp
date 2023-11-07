#include <iostream>
#include <string>
#include "product.h"
using namespace std;

int main(){
    product p1;
    p1.show();
    string p2 = p1.get_product_name();
    cout << p2 << endl;

    return 0;
}