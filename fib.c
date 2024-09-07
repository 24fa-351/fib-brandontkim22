#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rfibonacci(int n) {
   if (n == 1) {
      return 0;
   } else if (n <= 2) {
      return 1;
   }

   return rfibonacci(n - 1) + rfibonacci(n - 2);
}

int ifibonacci(int n) {
   if (n == 1) {
      return 0;
   } else if (n == 2) {
      return 1;
   }

   int a = 0;
   int b = 1;
   int result = 0;

   for (int i = 3; i <= n; i++) {
      result = a + b;
      a = b;
      b = result;
   }

   return result;
}

int main(int argc, char* argv[]) {
   int n;
   sscanf(argv[1], "%d", &n);

   char method = argv[2][0];
   char* filename = argv[3];

   FILE *fptr = fopen(filename, "r");
   
   int file_n;
   fscanf(fptr, "%d", &file_n);
   fclose(fptr);
   
   n += file_n;

   int number = 0;
   if (method == 'i') {
      number = ifibonacci(n);
   } else if (method == 'r') {
      number = rfibonacci(n);
   } else {
      number = 0;
   }

   printf("%d", number);

   return 0;
}
