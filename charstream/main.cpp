#include <iostream>
#include "charstream.h"

using namespace std;

// Just to test the implementation.
int main() {
    charstream cst;
    
    cst.push('H');
    cst.push("i! Hello World!");
    
    charstream c = cst[3];
    
    cout << cst.next() << cst.next() << endl;
    cout << (string) c << (string) c;
    
    charstream c2 = "hello!";
    cout << (string) c2 << endl;
    
    charstream newcst = cst.flush();
    cout << (string) newcst;
    
    return 0;
}
