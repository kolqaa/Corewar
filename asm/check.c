#include <stdio.h>

int main(void) {
  printf("\n----- Integer numbers -----\n\n");
  printf("type %15s%5s \n", "|", "size");
  printf("%s %15s %2d\n", "char", "|", sizeof(char));
  printf("%s %15s %2d\n", "signed char", "|", sizeof(signed char));
  printf("%s %15s %2d\n", "unsigned char", "|", sizeof(unsigned char));
  printf("%s %10s %2d\n", "short int", "|", sizeof(short int));
  printf("%s %10s %2d\n", "signed short int", "|", sizeof(signed short int));
  printf("%s %10s %2d\n", "short signed", "|", sizeof(signed short));
  printf("%s %10s %2d\n", "unsigned short", "|", sizeof(unsigned short));
  printf("%s %16s %2d\n", "pint", "|", sizeof(int));
  printf("%s %16s %2d\n", "signed int", "|", sizeof(signed int));
  printf("%s %16s %2d\n", "unsigned int", "|", sizeof(unsigned int));
  printf("%s %11s %2d\n", "long int", "|", sizeof(long int));
  printf("%s %6s %2d\n", "long long int", "|", sizeof(long long int));
  printf("\n----- Floating point numbers -----\n\n");
  printf("%s %14s %2d\n", "float", "|", sizeof(float));
  printf("%s %13s %2d\n", "double", "|", sizeof(double));
  printf("%s %8s %2d\n", "long double", "|", sizeof(long double));

  return 0;
}
