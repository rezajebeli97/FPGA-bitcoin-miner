#include <iostream>
#include "crypto.h"

using namespace std;

int main() {
     bool* x;
    x = crypto().toBinary(127);
    cout << crypto().toBinary(127)[1];
    cout << "end";
    return 0;
}