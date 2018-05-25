//
// Created by Ali on 5/25/2018 AD.
//

#ifndef CLION_PROJECTS_CRYPTO_H
#define CLION_PROJECTS_CRYPTO_H


class crypto {
public:
    crypto();
    bool* toBinary(int value);
    bool* toBinary64(int value);
    bool* ROT(bool x[32] , int n);
    bool* SHF(bool x[32] , int n);
    bool* ro0(bool x[32]);
    bool* ro1(bool x[32]);
};


#endif //CLION_PROJECTS_CRYPTO_H
