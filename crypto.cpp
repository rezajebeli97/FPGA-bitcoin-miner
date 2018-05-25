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

