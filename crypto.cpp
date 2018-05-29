//
// Created by Ali on 5/25/2018 AD.
//

#include "crypto.h"
#include <iostream>

crypto::crypto() {
    for (int i = 0; i < 10000; i++) {
        input[i] = false;
    }
    bool out[32];
    toBinary32(0x428a2f98, K[0]);
    toBinary32(0x71374491, K[1]);
    toBinary32(0xb5c0fbcf, K[2]);
    toBinary32(0xe9b5dba5, K[3]);
    toBinary32(0x3956c25b, K[4]);
    toBinary32(0x59f111f1, K[5]);
    toBinary32(0x923f82a4, K[6]);
    toBinary32(0xab1c5ed5, K[7]);
    toBinary32(0xd807aa98, K[8]);
    toBinary32(0x12835b01, K[9]);
    toBinary32(0x243185be, K[10]);
    toBinary32(0x550c7dc3, K[11]);
    toBinary32(0x72be5d74, K[12]);
    toBinary32(0x80deb1fe, K[13]);
    toBinary32(0x9bdc06a7, K[14]);
    toBinary32(0xc19bf174, K[15]);
    toBinary32(0xe49b69c1, K[16]);
    toBinary32(0xefbe4786, K[17]);
    toBinary32(0x0fc19dc6, K[18]);
    toBinary32(0x240ca1cc, K[19]);
    toBinary32(0x2de92c6f, K[20]);
    toBinary32(0x4a7484aa, K[21]);
    toBinary32(0x5cb0a9dc, K[22]);
    toBinary32(0x76f988da, K[23]);
    toBinary32(0x983e5152, K[24]);
    toBinary32(0xa831c66d, K[25]);
    toBinary32(0xb00327c8, K[26]);
    toBinary32(0xbf597fc7, K[27]);
    toBinary32(0xc6e00bf3, K[28]);
    toBinary32(0xd5a79147, K[29]);
    toBinary32(0x06ca6351, K[30]);
    toBinary32(0x14292967, K[31]);
    toBinary32(0x27b70a85, K[32]);
    toBinary32(0x2e1b2138, K[33]);
    toBinary32(0x4d2c6dfc, K[34]);
    toBinary32(0x53380d13, K[35]);
    toBinary32(0x650a7354, K[36]);
    toBinary32(0x766a0abb, K[37]);
    toBinary32(0x81c2c92e, K[38]);
    toBinary32(0x92722c85, K[39]);
    toBinary32(0xa2bfe8a1, K[40]);
    toBinary32(0xa81a664b, K[41]);
    toBinary32(0xc24b8b70, K[42]);
    toBinary32(0xc76c51a3, K[43]);
    toBinary32(0xd192e819, K[44]);
    toBinary32(0xd6990624, K[45]);
    toBinary32(0xf40e3585, K[46]);
    toBinary32(0x106aa070, K[47]);
    toBinary32(0x19a4c116, K[48]);
    toBinary32(0x1e376c08, K[49]);
    toBinary32(0x2748774c, K[50]);
    toBinary32(0x34b0bcb5, K[51]);
    toBinary32(0x391c0cb3, K[52]);
    toBinary32(0x4ed8aa4a, K[53]);
    toBinary32(0x5b9cca4f, K[54]);
    toBinary32(0x682e6ff3, K[55]);
    toBinary32(0x748f82ee, K[56]);
    toBinary32(0x78a5636f, K[57]);
    toBinary32(0x84c87814, K[58]);
    toBinary32(0x8cc70208, K[59]);
    toBinary32(0x90befffa, K[60]);
    toBinary32(0xa4506ceb, K[61]);
    toBinary32(0xbe49a3f7, K[62]);
    toBinary32(0xc67178f2, K[63]);

}

void crypto::toBinary(int value, bool output[8]) {
    for(int i = 7; i >= 0; i--){
        output[i] = value % 2;
        value /= 2;
    }
    return;
}

void crypto::toBinary32(int64_t value, bool output[32]){
    for(int i = 31; i >= 0; i--){
        output[i] = value % 2;
        value /= 2;
    }
    return;
}

void crypto::toBinary64(int64_t value, bool output[64]){
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

void crypto::xOr4(bool *var1, bool *var2, bool *var3, bool *var4, bool *output) {
    for (int i = 0; i < 32; i++) {
        output[i] = var1[i] xor var2[i] xor var3[i] xor var4[i];
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
//    for (int i = 0; i < 7; i++) {
//        output[i] = x[31-i];
//    }
//    for (int i = 8; i < 15; i++) {
//        output[i] = x[i+8];
//    }
//    for (int i = 16; i < 31; i++) {
//        output[i] = x[31-i];
//    }

    for (int i = 0; i < 31; i++) {
        output[i] = x[31-i];
    }
}

void crypto::SHA256(int length, bool output[256]) {

    bool H0[32], H1[32], H2[32], H3[32], H4[32], H5[32], H6[32], H7[32];

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
            sigma0(A , sigma0a);
            Maj(A , B , C , Majabc);
            add(C , D , cPlusd);
            sigma2(cPlusd , sigma2cPlusd);
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
                H0[j] = H0_output[j];
                H1[j] = H1_output[j];
                H2[j] = H2_output[j];
                H3[j] = H3_output[j];
                H4[j] = H4_output[j];
                H5[j] = H5_output[j];
                H6[j] = H6_output[j];
                H7[j] = H7_output[j];
            }
        }
    }

    for (int i = 0; i <32 ; i++) {
        output[i] = H0[i];
    }
    for (int i = 32; i <64 ; i++) {
        output[i] = H1[i-32];
    }
    for (int i = 64; i <96 ; i++) {
        output[i] = H2[i-64];
    }
    for (int i = 96; i <128 ; i++) {
        output[i] = H3[i-96];
    }
    for (int i = 128; i <160 ; i++) {
        output[i] = H4[i-128];
    }
    for (int i = 160; i <192 ; i++) {
        output[i] = H5[i-160];
    }
    for (int i = 192; i <224 ; i++) {
        output[i] = H6[i-192];
    }
    for (int i = 224; i <256 ; i++) {
        output[i] = H7[i-224];
    }

}

void crypto::Ch(bool x[32], bool y[32], bool z[32], bool output[32]) {
    bool out1[32], out2[32], out3[32], yNot[32], xNot[32];
    aNd(x, y, out1);
    nOt(y,yNot);
    aNd(yNot, z, out2);
    nOt(x, xNot);
    aNd(xNot, z, out3);
    xOr(out1, out2, out3, output);
}

void crypto::Maj(bool x[32], bool y[32], bool z[32], bool output[32]) {
    bool out1[32], out2[32], out3[32];
    aNd(x, z, out1);
    aNd(x, y, out2);
    aNd(y, z, out3);
    xOr(out1, out2, out3, output);
}

void crypto::sigma0(bool *var, bool *output) {
    bool out1[32], out2[32], out3[32], out4[32];
    ROT(var, 2, out1);
    ROT(var, 13, out2);
    ROT(var, 22, out3);
    SHF(var, 7, out4);
    xOr4(out1, out2, out3, out4, output);
}

void crypto::sigma1(bool *var, bool *output) {
    bool out1[32], out2[32], out3[32];
    ROT(var, 6, out1);
    ROT(var, 11, out2);
    ROT(var, 25, out3);
    xOr(out1, out2, out3, output);
}

void crypto::sigma2(bool *var, bool *output) {
    bool out1[32], out2[32], out3[32], out4[32];
    ROT(var, 2, out1);
    ROT(var, 3, out2);
    ROT(var, 15, out3);
    SHF(var, 5, out4);
    xOr4(out1, out2, out3, out4, output);
}