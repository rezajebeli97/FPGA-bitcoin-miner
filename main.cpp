#include <iostream>
#include "crypto.h"

using namespace std;

int main() {
    string s = "";
    cin >> s;
    crypto cryp;
    int totalLength = cryp.pars(s);



//    for (int i = 0; i < totalLength; i++) {
//        cout << cryp.input[i];
//    }
//    bool temp1 [32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1};
//    bool temp2 [32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};
//    bool temp3 [32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1};
//    bool temp4 [32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0};
//    bool temp5 [32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1};
//    bool temp6 [32];
//    cryp.sub(temp1, temp2, temp6);
//    cout << "hello";
//    for (int j = 0; j < 32; j++) {
//        cout << temp6[j];
//    }


//    bool tmp1[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};
//    bool tmp2[32];
//    crypto().add5(tmp1 , tmp1 , tmp1 , tmp1, tmp1 , tmp2);
//    for(int i = 0; i < 32; i++)
//    {
//        cout << tmp2[i];
//    }
//

    bool tmp[256];
    cryp.SHA256(totalLength , tmp);
    cout << endl << endl;
    for (int i = 0; i < 64; i++) {
        string hex = crypto().binToHex(tmp + i*4*sizeof(bool));
        cout<<hex;
    }

//    bool tmp1[4] = {1,1,0,1};
//
//    cout << crypto().binToHex(tmp1);

    return 0;
}