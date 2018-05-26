#include <iostream>
#include "crypto.h"

using namespace std;

int main() {
    string s = "";
    cin >> s;
    crypto cryp;
    int totalLength = cryp.pars(s);

    for (int i = 0; i < totalLength; i++) {
//        cout << cryp.input[i];
    }
    bool temp1 [32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1};
    bool temp2 [32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0};
    bool *temp3 = cryp.add(temp1, temp2);
    cout << "hello";
    for (int j = 0; j < 32; j++) {
        cout << temp3[j];
    }
    return 0;
}