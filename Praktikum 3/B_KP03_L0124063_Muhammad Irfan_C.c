#include <stdio.h>

int main() {
    int luas[5];

    luas[0] = 225 * 335;
    luas[1] = 215 * 394;
    luas[2] = 198 * 400;
    luas[3] = 314 * 298;
    luas[4] = 299 * 278;

    int luas_terbesar = luas[0];

    for (int i = 1; i < 5; i++) {
        if (luas[i]> luas[i-1]) {
            luas_terbesar = luas[i];
        }
    }

    printf("%d", luas_terbesar);
}
