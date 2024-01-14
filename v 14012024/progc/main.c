#include "header.h"

int main(int argc, char **argv) {
  if (argc > 1) {
    printf("Arguments passés \n");
    for (int i = 1; i < argc; i++) {
      printf("%s\n", argv[i]);
      printf("----------\n");
    }
  } else {
    printf("Aucun argument n'a été passé\n");
  }

  return 0;
}
