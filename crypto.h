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
    bool input [10000];
    bool K[64][32];
    void toBinary(int value, bool output[8]);
    void toBinary32(int64_t value, bool output[32]);
    void toBinary64(int64_t value, bool output[64]);
    int pars(string s);
    void xOr(bool var1[32], bool var2[32], bool var3[32], bool output[32]);
    void xOr4(bool var1[32], bool var2[32], bool var3[32], bool var4[32], bool output[32]);
    void add(bool var1[32], bool var2[32] , bool output[32]);
    void sub(bool var1[32], bool var2[32] , bool output[32]);
    void add3(bool var1[32], bool var2[32],bool var3[32], bool output[32]);
    void add4(bool var1[32], bool var2[32],bool var3[32], bool var4[32] , bool output[32]);
    void add5(bool var1[32], bool var2[32],bool var3[32], bool var4[32] , bool var5[32] , bool output[32]);
    void ROT(bool x[32] , int n , bool output[32]);
    void SHF(bool x[32] , int n , bool output[32]);
    void ro0(bool x[32] , bool output[32]);
    void ro1(bool x[32] , bool output[32]);
    void w(bool x[512] , bool output[64][32]);
    void permutation(bool x[32] , bool output[32]);
    void nOt(bool var1[32], bool output[32]);
    void aNd(bool var1[32], bool var2[32], bool output[32]);
    void Ch(bool x[32], bool y[32], bool z[32], bool output[32]);
    void Maj(bool x[32], bool y[32], bool z[32], bool output[32]);
    void sigma0(bool var[32], bool output[32]);
    void sigma1(bool var[32], bool output[32]);
    void sigma2(bool var[32], bool output[32]);
    void SHA256(int length , bool output[256]);
};


#endif //CLION_PROJECTS_CRYPTO_H
