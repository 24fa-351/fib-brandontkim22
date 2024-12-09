#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Recursive fib(); fib(1) == 0
int rfib(int number)
{
   if (number <= 1)
   {
      return 0;
   }
   else if (number == 2)
   {
      return 1;
   }

   return rfib(number - 1) + rfib(number - 2);
}

// Iterative fib(); fib(1) == 0
int ifib(int number)
{
   if (number <= 1)
   {
      return 0;
   }
   else if (number == 2)
   {
      return 1;
   }

   int previous = 0;
   int current = 1;
   int result = 0;

   for (int ix = 3; ix <= number; ++ix)
   {
      result = previous + current;
      previous = current;
      current = result;
   }

   return result;
}

int main(int argc, char *argv[])
{
   if (argc != 4)
   {
      printf("Usage: %s <fibonacci_input> <method_type> <file_name>\n", argv[0]);
      return 1;
   }

   int fibonacci_input;
   sscanf(argv[1], "%d", &fibonacci_input);

   char method_type = argv[2][0];

   FILE *file_ptr = fopen(argv[3], "r");

   int number_within_file;
   fscanf(file_ptr, "%d", &number_within_file);
   fclose(file_ptr);

   fibonacci_input += number_within_file;

   int result = 0;
   if (method_type == 'i')
   {
      result = ifib(fibonacci_input);
   }
   else if (method_type == 'r')
   {
      result = rfib(fibonacci_input);
   }
   else
   {
      result = 0;
   }

   printf("%d", result);

   return 0;
}