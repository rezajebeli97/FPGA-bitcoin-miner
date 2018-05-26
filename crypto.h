//
// Created by Ali on 5/25/2018 AD.
//

#ifndef CLION_PROJECTS_CRYPTO_H
#define CLION_PROJECTS_CRYPTO_H

#include <iostream>

using namespace std;

class crypto {
public:
    crypto();
    bool* toBinary(int value);
    bool* toBinary64(int value);
    int pars(string s);
    bool* xOr(bool var1[32], bool var2[32], bool var3[32]);
    bool* add(bool var1[32], bool var2[32]);
    bool input [10000];
    bool* ROT(bool x[32] , int n);
    bool* SHF(bool x[32] , int n);
    bool* ro0(bool x[32]);
    bool* ro1(bool x[32]);
};


#endif //CLION_PROJECTS_CRYPTO_H
