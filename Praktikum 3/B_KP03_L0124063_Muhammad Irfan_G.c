

#include <stdio.h>

int main() {
    int luas[4][3] = {
        {225 * 335, 299 * 278, 300 * 250},
        {215 * 394, 144 * 718, 300 * 290},
        {200 * 400, 240 * 333, 142 * 619},
        {314 * 298, 411 * 198, 333 * 222}
    };

    int harga_jual[3] = {100, 120, 150};
    int merk1 = 0, merk2 = 0, merk3 = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == 0) {
                merk1 += harga_jual[i] * luas[j][i];
            } else if (i == 1) {
                merk2 += harga_jual[i] * luas[j][i];
            } else if (i == 2) {
                merk3 += harga_jual[i] * luas[j][i];
            }
        }

    }
    printf("%d\n%d\n%d\n", merk1, merk2, merk3);
    return 0;
}

