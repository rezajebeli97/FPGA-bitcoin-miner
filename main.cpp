#include <iostream>
#include "crypto.h"

using namespace std;

int main() {
    string s = "";
    cin >> s;
    bool input [10000];
    for (int i = 0; i < 10000; i++) {
        input[i] = false;
    }
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

    for (int i = 0; i < 512; i++) {
        cout << input[i];
    }
    return 0;
}