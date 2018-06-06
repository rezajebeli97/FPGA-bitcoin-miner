#include <iostream>
#include "crypto.h"

using namespace std;

int main() {

    bool temp [16] = {0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1};
    crypto().pars(temp, 16);
    string s = "";
    cin >> s;
    crypto cryp;
    int totalLength = cryp.pars(s);

    bool first_hash[256];
    cryp.SHA256(totalLength , first_hash);
//    for (int i = 0; i < 64; i++) {
//        string hex = crypto().binToHex(first_hash + i*4*sizeof(bool));
//        cout<<hex;
//    }




    bool version[32];
    cryp.hexToBin("02000000",version);

    bool prev_block[256];
    cryp.hexToBin("17975b97c18ed1f7e255adf297599b55330edab87803c8170100000000000000",prev_block);

    bool timestamp[32];
    cryp.hexToBin("358b0553",timestamp);

    bool diff[32];
    cryp.hexToBin("5350f119",diff);

    bool final_hash[256];

    cryp.mining(version , prev_block , first_hash , timestamp , diff , final_hash);

    for (int i = 0; i < 64; i++) {
        string hex = crypto().binToHex(final_hash + i*4*sizeof(bool));
        cout<<hex;
    }



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


//    bool tmp1[4] = {1,1,0,1};
//
//    cout << crypto().binToHex(tmp1);

    return 0;
}