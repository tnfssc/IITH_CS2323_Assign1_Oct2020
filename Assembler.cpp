#include<iostream>
#include "tables/addr_gen.hpp"

using namespace std;

int main () {
    cout << "Initializing...";
    JSObject addr = addrGen();
    cout << addr["zero"] << " " << addr["at"];
    return 0;
}
