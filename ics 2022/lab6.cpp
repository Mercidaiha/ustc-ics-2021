#include <cstdint>
#include <iostream>
#include <fstream>

#define MAXLEN 100
#ifndef LENGTH
//#define LENGTH 3
#endif

int16_t lab1(int16_t a, int16_t b) {
    // initialize
    int16_t r0, r1, r2, r3, r4, r5, r6, result;
    r0 = 1;
    r1 = a;
    r2 = b;
    r3 = 0;
    r4 = 0;
    r5 = 0;
    r6 = 0;

    // calculation
    if(r2 <= 0){
        result = r6;
    }
    else{
        while(r2 > 0){
            r4 = r0;
            r3 = r2 - 1;
            while(r3 > 0){
                r4 = r4 + r4;
                r3 = r3 - 1;
            }
            r5 = r4 & r1;
            if(r5 != 0){
                r6 = r6 + 1;
            }
            r2 = r2 - 1;
        }
        result = r6;
    }

    // return value
    return result;
}

int16_t lab2(int16_t p, int16_t q, int16_t n) {
    // initialize
    int16_t r0, r1, r2, r3, r4, r5, r6, result;
    r0 = n;
    r1 = ~p;
    r2 = ~q + 1;
    r3 = 1;
    r4 = 1;
    r5 = 0;
    r6 = 0;

    // calculation
    r0 = r0 - 2;
    if(r0 < 0){
        result = r4;
    }
    else{
        while(r0 >= 0){
            r5 = r3 & r1;
            r3 = r4;
            r6 = r4;
            r4 = r6 + r2;
            while(r4 > 0){
                r6 = r4;
                r4 = r6 + r2;
            }
            r4 = r6 + r5;
            r0 = r0 - 1;
        }
        result = r4;
    }

    // return value
    return result;
}

int16_t lab3(int16_t n, char s[]) {
    // initialize
    int16_t r0, r1, r2, r3, r4, r5, r6, result;
    r0 = n;
    r1 = 0;
    r2 = 0;
    r3 = 0;
    r4 = 0;
    r5 = 0;
    r6 = 1;

    // calculation
    r0 = r0 - 1;
    if(r0 <= 0){
        r5 = r6;
        r5 = ~r5;
        r5 = r5 + 1;
        r5 = r5 + r2;
        if(r5 < 0){
            r2 = r6;
        }
        result = r2;
    }
    else{
        while(r0 > 0){
            r3 = s[r1];
            r4 = s[r1+1];
            r3 = ~r3 + 1;
            r3 = r3 + r4;
            if(r3 == 0){
                r6 = r6 + 1;
                r1 = r1 + 1;
                r0 = r0 - 1;
            }
            else{
                r5 = r6;
                r5 = ~r5 + 1;
                r5 = r5 + r2;
                if(r5 < 0){
                    r2 = r6;
                }
                r6 = 1;
                r1 = r1 + 1;
                r0 = r0 - 1;
            }
        }
        r5 = r6;
        r5 = ~r5;
        r5 = r5 + 1;
        r5 = r5 + r2;
        if(r5 < 0){
            r2 = r6;
        }
        result = r2;
    }

    // return value
    return result;
}

void lab4(int16_t score[], int16_t *a, int16_t *b) {
    // initialize
    int16_t r0, r1, r2, r3, r4, r5, r6, result_a, result_b, result_ab;
    result_a = 0;
    result_ab = 0;

    // calculation
    for(int i=15; i>0; i--){
        for(int j=0; j<i; j++){
            if(score[j] > score[j+1]){
                int16_t temp = score[j];
                score[j] = score[j+1];
                score[j+1] = temp;
            }
        }
    }
    for(int i=12; i<16; i++){
        if(score[i] >= 85){
            result_a = result_a + 1;
        }
    }
    for(int i=8; i<16; i++){
        if(score[i] >= 75){
            result_ab = result_ab + 1;
        }
    }
    result_b = result_ab - result_a;

    // return value
    *a = result_a;
    *b = result_b;
}

int main() {
    std::fstream file;
    file.open("test.txt", std::ios::in);

    // lab1
    int16_t a = 0, b = 0;
    for (int i = 0; i < LENGTH; ++i) {
        file >> a >> b;
        std::cout << lab1(a, b) << std::endl;
    }

    // lab2
    int16_t p = 0, q = 0, n = 0;
    for (int i = 0; i < LENGTH; ++i) {
        file >> p >> q >> n;
        std::cout << lab2(p, q, n) << std::endl;
    }

    // lab3
    char s[MAXLEN];
    for (int i = 0; i < LENGTH; ++i) {
        file >> n >> s;
        std::cout << lab3(n, s) << std::endl;
    }

    // lab4
    int16_t score[16];
    for (int i = 0; i < LENGTH; ++i) {
        for (int j = 0; j < 16; ++j) {
            file >> score[j];
        }
        lab4(score, &a, &b);
        for (int j = 0; j < 16; ++j) {
            std::cout << score[j] << " ";
        }
        std::cout << std::endl << a << " " << b << std::endl;
    }

    file.close();
    return 0;
}
