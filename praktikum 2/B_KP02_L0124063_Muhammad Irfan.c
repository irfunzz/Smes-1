#include <stdio.h>

int main() {
    // membuat program menggunakan switch, for / do while, break / continue
    // membuat program untuk memesan makanan dan minuman di restoran

    int makanan, minuman;
    int harga = 0;
    int jml;
    char pesanLagi;
    int salahMakanan =0;
    int salahMinuman =0;

    do {
        printf ("apa yang ingin kamu makan:\n1. Nasi Rendang - 10.0000,00\n2. Nasi Ayam - 7.000,00\n3. Nasi Ikan - 7.000,00\n4. Tidak Makan/Lanjut\n");
        while (1) {
            printf("(Masukkan nomor): ");
            if (scanf("%d", &makanan) != 1 || makanan < 1 || makanan > 4) {
                printf("Masukkan yang benar!\n");
                salahMakanan++;
                if (salahMakanan == 3) {
                    printf("Apakah kamu tidak mengerti bahasa manusia?\n");
                    continue;
                }
                while (getchar() != '\n');
                continue;
            } else {
                break;
            }
        }
        switch (makanan) {
            case 1:
                printf ("kamu memilih Nasi Rendang\n jumlah:");
                scanf ("%d", &jml);
                harga += 10000 * jml;
                break;
            case 2:
                printf ("kamu memilih Nasi Ayam\n jumlah:");
                scanf ("%d", &jml);
                harga += 7000 * jml; ;
                break;
            case 3:
                printf ("kamu memilih Nasi Ikan\n jumlah:");
                scanf ("%d", &jml);
                harga += 7000 * jml;
                break;
            case 4:
                printf("kamu memilih untuk tidak memesan makanan lagi\n");
                break;
            default:
                printf("masukkan yang benar");
                break;
        }
        if (makanan != 4 ) {
            printf ("Apakah kamu ingin memesan lagi (Y/N):");
            scanf (" %c", &pesanLagi);
        } else {
            pesanLagi = 'N';
        }
    } while (pesanLagi == 'Y' || pesanLagi == 'y');

    do {
        printf("Apa yang ingin kamu minum:\n1. Air Putih - 2.000,00\n2. Es Teh - 3.000,00\n3. Tidak Minum\n4. Selesai\n");
        while (1) {
            printf("(Masukkan nomor): ");
            if (scanf("%d", &minuman) != 1 || minuman < 1 || minuman > 4) {
                printf("Masukkan yang benar!\n");
                salahMinuman++;
                if (salahMinuman == 3) {
                    printf("Apakah kamu tidak mengerti bahasa manusia?\n");
                    continue;
                }
                while (getchar() != '\n');
                continue;
            } else {
                break;
            }
        }
        switch (minuman) {
            case 1:
                printf ("Kamu memilih Air Putih\n jumlah:");
                scanf ("%d", &jml);
                harga += 2000 * jml;
                break;
            case 2:
                printf ("Kamu memilih Es Teh\n jumlah:");
                scanf ("%d", &jml);
                harga += 3000 * jml;
                break;
            case 3:
                printf("anda tidak memesan minum:\n");
                harga += 0;
                break;
            case 4:
                printf("kamu telah selesai memesan");
                break;
            default:
                printf("masukkan yang benar");
                break;
        }
        if (minuman != 4) {
            printf ("apakah anda ingin memesan minuman lagi (Y/N)");
            scanf (" %c", &pesanLagi);
        } else {
            pesanLagi = 'N';
        }

    } while (pesanLagi == 'Y' || pesanLagi == 'y');

    printf ("harga yang harus anpda bayar adalah: %d,00", harga);

    return 0;
}