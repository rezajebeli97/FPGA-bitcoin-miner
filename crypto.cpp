//
// Created by Ali on 5/25/2018 AD.
//

#include "crypto.h"
#include <iostream>

using namespace std;

crypto::crypto() {}

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