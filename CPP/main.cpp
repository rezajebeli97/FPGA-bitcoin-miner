#include <iostream>
#include "crypto.h"

using namespace std;

int main() {
    const int size = 32;
    bool s[size] = {0,1,1,0, 0,0,0,1,
                   0,1,1,0, 0,0,1,0,
                   0,1,1,0, 0,0,1,1,
                   0,1,1,0, 0,1,0,0};

    cout << "input : abcd" << endl;
    crypto cryp;
    int totalLength = cryp.pars(s , size);

    bool first_hash[256];
    cryp.SHA256(totalLength , first_hash);
    cout << "message hash is : " << endl;
    for (int i = 0; i < 64; i++) {
        string hex = crypto().binToHex(first_hash + i*4*sizeof(bool));
        cout<<hex;
    }
    cout << endl;

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

    cout << "final hash is : " << endl;
    for (int i = 0; i < 64; i++) {
        string hex = crypto().binToHex(final_hash + i*4*sizeof(bool));
        cout<<hex;
    }

    return 0;
}