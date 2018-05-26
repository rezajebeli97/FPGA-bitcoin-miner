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
    bool* toBinary(int value, bool output[8]);
    bool* toBinary64(int value, bool output[64]);
    int pars(string s);
    bool* xOr(bool var1[32], bool var2[32], bool var3[32], bool output[32]);
    void add(bool var1[32], bool var2[32] , bool output[32]);
    void add4(bool var1[32], bool var2[32],bool var3[32], bool var4[32] , bool output[32]);
    bool input [10000];
    void ROT(bool x[32] , int n , bool output[32]);
    void SHF(bool x[32] , int n , bool output[32]);
    bool* ro0(bool x[32] , bool output[32]);
    bool* ro1(bool x[32] , bool output[32]);
    bool** w(bool x[512]);
};


#endif //CLION_PROJECTS_CRYPTO_H
