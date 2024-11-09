#include <stdio.h>

int main () {
  int nilai;

  printf("masukkan nilai anda : ");
  scanf("%d", &nilai);

  if (nilai >= 85) {
    printf ("IPK kamu adalah 4.00\nSkor kamu adalah A");
  } else if (nilai < 85 && nilai >= 80 ) {
    printf ("IPK kamu adalah 3.70\nSkor kamu adalah A-");
  } else if (nilai < 80 && nilai >= 75 ) {
    printf ("IPK kamu adalah 3.30\nSkor kamu adalah B+");
  } else if (nilai < 75 && nilai >= 70 ) {
    printf ("IPK kamu adalah 3.00\nSkor kamu adalah B");
  } else if (nilai < 70 && nilai >= 65 ) {
    printf ("IPK kamu adalah 2.70\nSkor kamu adalah C+");
  } else if (nilai < 65 && nilai >= 60 ) {
    printf ("IPK kamu adalah 2.00\nSkor kamu adalah C");
  } else if (nilai < 60 && nilai >= 55 ) {
    printf ("IPK kamu adalah 1.00\nSkor kamu adalah D");
  } else {
    printf ("IPK kamu adalah 0.00\nSkor kamu adalah E");
  }

  if (nilai > 100 || nilai < 0) {
    printf ("nilai tidak valid");
  }

  return 0;
}
