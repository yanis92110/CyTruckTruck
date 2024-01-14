#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){
    FILE* data = fopen("temp/colonnes.txt", "rw");
    if (data == NULL){
      printf("Ci ciao \n");
      return 1;
    }
    //fprintf(data);

}