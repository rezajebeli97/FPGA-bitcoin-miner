//
// Created by Ali on 5/25/2018 AD.
//

#include "crypto.h"
#include <iostream>

crypto::crypto() {
    for (int i = 0; i < 10000; i++) {
        input[i] = false;
    }
}

bool *crypto::toBinary(int value, bool output[8]) {
    for(int i = 7; i >= 0; i--){
        output[i] = value % 2;
        value /= 2;
    }
    return;
}

bool* crypto::toBinary64(int value, bool output[64]){
    for(int i = 63; i >= 0; i--){
        output[i] = value % 2;
        value /= 2;
    }
    return output;
}

int crypto::pars(string s) {

    int currentIndex = 0;
    for(int i = 0; i < s.length(); i++)
    {
        bool temp [8];
        toBinary(int(s.at(i)), temp);

        for(int j = 0; j < 8; j++)
        {
            input[i*8 + j] = temp[j];
        }
    }
    currentIndex = s.length()*8;
    int k = 448 - ((currentIndex + 1)%512);
    if(k < 0)
        k += 512;
    input[currentIndex] = true;
    currentIndex += k + 1;

    bool temp [64];
    toBinary64(s.length()*8, temp);
    for (int i = currentIndex; i < currentIndex + 64; i++) {
        input[i] = temp[i - currentIndex];
    }

    int totalLength = currentIndex + 64;
    return  totalLength;

}

bool *crypto::xOr(bool *var1, bool *var2, bool *var3, bool output[32]) {
    for (int i = 0; i < 32; i++) {
        output[i] = var1[i] xor var2[i] xor var3[i];
    }
    return;
}

void crypto::add(bool var1[32], bool var2[32] , bool output[32]) {
    bool carry = false;
    for (int i = 31; i >= 0; i--) {
        output[i] = var1[i] xor var2[i] xor carry;
        carry = (carry and (var1[i] or var2[i])) or (var1[i] and var2[i]);
    }
    return ;
}

void crypto::add4(bool *var1, bool *var2, bool *var3, bool *var4 , bool output[32]) {
    bool tmp1[32];
    add(var1 , var2 , tmp1);
    bool tmp2[32];
    add(var3 , var4 , tmp2);
    add ( tmp1 , tmp2 , output);
    return;
}

bool* crypto::ROT(bool x[32] , int n){
    static bool output[32];
    for(int i = 0; i < 32; i++){
        output[i] = x[(32+(i-n)%32)%32];
    }
    return output;
}

bool* crypto::SHF(bool x[32] , int n){
    static bool output[32];
    for(int i = 0 ; i < n ; i++){
        output[i]=0;
    }
    for(int i = n ; i < 32 ; i++){
        output[i] = x[(i-n)%32];
    }
    return output;
}

bool* crypto::ro0(bool x[32]){
    return xOr( ROT(x,17) , ROT(x,14) , SHF(x,12) );
}

bool* crypto::ro1(bool x[32]){
    return xOr( ROT(x,9) , ROT(x,19) , SHF(x,9) );
}

bool **crypto::w(bool x[512]) {
    bool **wArray = 0;
    wArray = new bool*[64];
    for (int i = 0; i < 64; ++i) {
        wArray[i] = new bool [32];
    }

    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 32; j++) {
            wArray[i][j] = x[i*32 +j];
        }
    }

    for (int i = 16; i < 64; i++) {

    }

    return static_cast<bool **>(wArray);
}


