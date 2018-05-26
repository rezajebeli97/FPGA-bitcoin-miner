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

bool *crypto::toBinary(int value) {
    bool bin[8];
    for(int i = 7; i >= 0; i--){
        bin[i] = value % 2;
        value /= 2;
    }
    return bin;
}

bool* crypto::toBinary64(int value){
    bool bin[64];
    for(int i = 63; i >= 0; i--){
        bin[i] = value % 2;
        value /= 2;
    }
    return bin;
}

int crypto::pars(string s) {

    int currentIndex = 0;
    for(int i = 0; i < s.length(); i++)
    {
        bool *temp  = crypto().toBinary(int(s.at(i)));

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

    bool *temp = crypto().toBinary64(s.length()*8);
    for (int i = currentIndex; i < currentIndex + 64; i++) {
        input[i] = temp[i - currentIndex];
    }

    int totalLength = currentIndex + 64;
    return  totalLength;

}

bool *crypto::xOr(bool *var1, bool *var2, bool *var3) {
    static bool * temp;
    for (int i = 0; i < 32; i++) {
        temp[i] = var1[i] xor var2[i] xor var3[i];
    }
    return temp;
}

bool *crypto::add(bool var1[32], bool var2[32]) {
    static bool temp [32];
    bool carry = false;
    for (int i = 31; i >= 0; i--) {
        temp[i] = var1[i] xor var2[i] xor carry;
        carry = (carry and (var1[i] or var2[i])) or (var1[i] and var2[i]);
    }
    return temp;
}

bool* crypto::ROT(bool x[32] , int n){
    bool output[32];
    for(int i = 0; i < 32; i++){
        output[i] = 1;
    }
    return output;
}

bool* crypto::SHF(bool x[32] , int n){
    bool output[32];
    for(int i = 0 ; i < n ; i++){
        output[i]=0;
    }
    for(int i = n ; i < 32 ; i++){
        output[i] = x[(i-n)%32];
    }
    return output;
}

//bool* crypto::ro0(bool x[32]){
//    return xOr( ROT(x,17) , ROT(x,14) , SHF(x,12) );
//}
//
//bool* crypto::ro1(bool x[32]){
//    return xOr( ROT(x,9) , ROT(x,19) , SHF(x,9) );
//}