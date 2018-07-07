#include <iostream>
#include "crypto.h"

using namespace std;

int main() {

    string s = "";
    cin >> s;
    crypto cryp;
    int totalLength = cryp.pars(s);

    bool first_hash[256];
    cryp.SHA256(totalLength , first_hash);
    for (int i = 0; i < 64; i++) {
        string hex = crypto().binToHex(first_hash + i*4*sizeof(bool));
        cout<<hex;
    }

/*
    bool a[32] = {0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,1};
    bool b[32] = {0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,1};
    bool c[32] = {0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1};
    bool sig0[32] , sig1[32] , sig2[32] , ch_sig[32] , maj_sig[32];
    cryp.sigma0(a , sig0);
    cryp.sigma1(a , sig1);
    cryp.sigma2(a , sig2);
    cryp.Ch(a,b,c,ch_sig);
    cryp.Maj(a,b,c,maj_sig);

    cout << "sig0 : ";
    cryp.printBinaryArray(sig0 , 32);
    cout << endl << "sig1 : ";
    cryp.printBinaryArray(sig1 , 32);
    cout << endl << "sig2 : ";
    cryp.printBinaryArray(sig2 , 32);
    cout << endl<< "Ch : ";
    cryp.printBinaryArray(ch_sig , 32);
    cout << endl << "Maj : ";
    cryp.printBinaryArray(maj_sig , 32);
    cout << endl;
*/

//    bool version[32];
//    cryp.hexToBin("02000000",version);
//
//    bool prev_block[256];
//    cryp.hexToBin("17975b97c18ed1f7e255adf297599b55330edab87803c8170100000000000000",prev_block);
//
//    bool timestamp[32];
//    cryp.hexToBin("358b0553",timestamp);
//
//    bool diff[32];
//    cryp.hexToBin("5350f119",diff);
//
//    bool final_hash[256];
//
//    cryp.mining(version , prev_block , first_hash , timestamp , diff , final_hash);
//
//    for (int i = 0; i < 64; i++) {
//        string hex = crypto().binToHex(final_hash + i*4*sizeof(bool));
//        cout<<hex;
//    }


    return 0;
}