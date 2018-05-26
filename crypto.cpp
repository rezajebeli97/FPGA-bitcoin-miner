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

void crypto::toBinary(int value, bool output[8]) {
    for(int i = 7; i >= 0; i--){
        output[i] = value % 2;
        value /= 2;
    }
    return;
}

void crypto::toBinary32(int value, bool output[32]){
    for(int i = 31; i >= 0; i--){
        output[i] = value % 2;
        value /= 2;
    }
    return;
}

void crypto::toBinary64(int value, bool output[64]){
    for(int i = 63; i >= 0; i--){
        output[i] = value % 2;
        value /= 2;
    }
    return;
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

void crypto::xOr(bool *var1, bool *var2, bool *var3, bool output[32]) {
    for (int i = 0; i < 32; i++) {
        output[i] = var1[i] xor var2[i] xor var3[i];
    }
    return;
}

void crypto::aNd(bool *var1, bool *var2, bool *output) {
    for (int i = 0; i <32 ; i++) {
        output[i] = var1[i] and var2[i];
    }
    return;
}

void crypto::nOt(bool *var1, bool *output) {
    for (int i = 0; i <32 ; i++) {
        output[i] = not var1[i];
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

void crypto::sub(bool *var1, bool *var2, bool *output) {
    bool onesComp_var2[32];
    nOt(var2 , onesComp_var2);
    bool one[32];
    for (int i = 0; i < 31 ; i++) {
        one[i] = 0;
    }
    one[31] = 1;

    add3(var1 , onesComp_var2 , one , output);
}

void crypto::add3(bool *var1, bool *var2, bool *var3, bool *output) {
    bool tmp1[32];
    add(var1 , var2 , tmp1);
    add(tmp1 , var3 , output);
}

void crypto::add4(bool *var1, bool *var2, bool *var3, bool *var4 , bool output[32]) {
    bool tmp1[32];
    add(var1 , var2 , tmp1);
    bool tmp2[32];
    add(var3 , var4 , tmp2);
    add ( tmp1 , tmp2 , output);
    return;
}

void crypto::add5(bool *var1, bool *var2, bool *var3, bool *var4, bool *var5, bool *output) {
    bool tmp1[32];
    add(var1 , var2 , tmp1);
    bool tmp2[32];
    add(tmp1 , var3 , tmp2);
    bool tmp3[32];
    add(tmp2 , var4 , tmp3);
    add(tmp3 , var5 , output);
    return;
}


void crypto::ROT(bool x[32] , int n , bool output[32]){
    for(int i = 0; i < 32; i++){
        output[i] = x[(32+(i-n)%32)%32];
    }
    return ;
}

void crypto::SHF(bool x[32] , int n , bool output[32]){
    for(int i = 0 ; i < n ; i++){
        output[i]=0;
    }
    for(int i = n ; i < 32 ; i++){
        output[i] = x[(i-n)%32];
    }
    return ;
}

void crypto::ro0(bool x[32] , bool output[32]){
    bool output1[32];
    ROT(x,17 , output1);
    bool output2[32];
    ROT(x,14 , output2);
    bool output3[32];
    SHF(x,12 , output3);
    xOr( output1 , output2 , output3 , output);
    return;
}

void crypto::ro1(bool x[32] , bool output[32]){
    bool output1[32];
    ROT(x,9 , output1);
    bool output2[32];
    ROT(x,19 , output2);
    bool output3[32];
    SHF(x,9 , output3);
    xOr( output1 , output2 , output3 , output);
}

void crypto::w(bool x[512] , bool output[64][32]) {

    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 32; j++) {
            output[i][j] = x[i*32 +j];
        }
    }

    for (int i = 16; i < 64; i++) {
        bool output1[32],output2[32];
        ro1(output[i-1] , output1);
        ro0(output[i-12] , output2);
        add4(output1 , output[i-6] , output2 , output[i-15] , output[i]);
        bool output3[32];
        permutation(output[i] , output3);
        for (int j = 0; j < 32; j++) {
            output[i][j] = output3[j];
        }
    }
    return ;
}

void crypto::permutation(bool *x, bool *output) {
    for (int i = 0; i < 7; i++) {
        output[i] = x[32-i];
    }
    for (int i = 8; i < 15; i++) {
        output[i] = x[i+8];
    }
    for (int i = 16; i < 31; i++) {
        output[i] = x[32-i];
    }
}

void crypto::SHA256(int length, bool output[256]) {

    bool H0[32], H1[32], H2[32], H3[32], H4[32], H5[32], H6[32], H7[32];
    bool K[64][32];

    for (int k = 0; k < length/512 ; k++) {


        bool block[512];
        for (int i = 0; i < 512; i++) {
            block[i] = input[i + k*512];
        }

        bool wArray[64][32];
        w(block, wArray);

        bool A[32], B[32], C[32], D[32], E[32], F[32], G[32], H[32];

        toBinary32(0x6a09e667, H0);
        toBinary32(0xbb67ae85, H1);
        toBinary32(0x3c6ef372, H2);
        toBinary32(0xa54ff53a, H3);
        toBinary32(0x510e527f, H4);
        toBinary32(0x9b05688c, H5);
        toBinary32(0x1f83d9ab, H6);
        toBinary32(0x5be0cd19, H7);

        for (int i = 0; i < 64; i++) {
            bool T1[32], T2[32];
            for (int j = 0; j < 32; j++) {
                A[i] = H0[i];
                B[i] = H1[i];
                C[i] = H2[i];
                D[i] = H3[i];
                E[i] = H4[i];
                F[i] = H5[i];
                G[i] = H6[i];
                H[i] = H7[i];
            }
            bool sigma1e[32], Chefg[32];
            sigma1(E, sigma1e);
            Ch(E, F, G, Chefg);
            add5(H, sigma1e, Chefg, K[i], wArray[i], T2);

            bool sigma0a[32], Majabc[32], cPlusd[32], sigma2cPlusd[32];
            add3(sigma0a, Majabc, sigma2cPlusd, T1);

            for (int j = 0; j < 32; j++) {
                H[i] = G[i];
                F[i] = E[i];
                D[i] = C[i];
                B[i] = A[i];
                G[i] = F[i];
                C[i] = B[i];
            }
            add(D, T1, E);
            bool T1_3[32];
            add3(T1, T1, T1, T1_3);
            sub(T1_3, T2, A);

            bool H0_output[32], H1_output[32], H2_output[32], H3_output[32]
            , H4_output[32], H5_output[32], H6_output[32], H7_output[32];
            add(A, H0, H0_output);
            add(B, H1, H1_output);
            add(C, H2, H2_output);
            add(D, H3, H3_output);
            add(E, H4, H4_output);
            add(F, H5, H5_output);
            add(G, H6, H6_output);
            add(H, H7, H7_output);

            for (int j = 0; j < 32; j++) {
                H0[i] = H0_output[i];
                H1[i] = H1_output[i];
                H2[i] = H2_output[i];
                H3[i] = H3_output[i];
                H4[i] = H4_output[i];
                H5[i] = H5_output[i];
                H6[i] = H6_output[i];
                H7[i] = H7_output[i];
            }
        }
    }

    bool finalH[256];
    for (int i = 0; i <32 ; i++) {
        finalH[i] = H0[i];
    }
    for (int i = 32; i <64 ; i++) {
        finalH[i] = H1[i];
    }
    for (int i = 64; i <96 ; i++) {
        finalH[i] = H2[i];
    }
    for (int i = 96; i <128 ; i++) {
        finalH[i] = H3[i];
    }
    for (int i = 128; i <160 ; i++) {
        finalH[i] = H4[i];
    }
    for (int i = 160; i <192 ; i++) {
        finalH[i] = H5[i];
    }
    for (int i = 192; i <224 ; i++) {
        finalH[i] = H6[i];
    }
    for (int i = 224; i <256 ; i++) {
        finalH[i] = H7[i];
    }
}

