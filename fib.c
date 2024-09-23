#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Recursive fib(); fib(1) == 0
int rfib(int n) {
   if (n == 1) {
      return 0;
   } else if (n <= 2) {
      return 1;
   }

   return rfib(n - 1) + rfib(n - 2);
}                                   

// Iterative fib(); fib(1) == 0
int ifib(int n) {
   if (n == 1) {
      return 0;
   } else if (n == 2) {
      return 1;                       
   }

   int previous = 0;
   int current = 1;
   int result = 0;                    

   for (int ix = 3; ix <= n; ++ix) {
      result = previous + current;
      previous = current;
      current = result;
   }                                  

   return result;
}                                     

int main(int argc, char* argv[]) {
   int n_input;
   sscanf(argv[1], "%d", &n_input);

   char type = argv[2][0];

   FILE *fptr = fopen(argv[3], "r");
   
   int file_n;
   fscanf(fptr, "%d", &file_n);
   fclose(fptr);
   
   n_input += file_n;

   int result = 0;
   if (type == 'i') {
      result = ifib(n_input);
   } else if (type == 'r') {
      result = rfib(n_input);
   } else {
      result = 0;
   }

   printf("%d", result);

   return 0;
}