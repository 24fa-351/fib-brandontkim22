#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rfib(int n) {                     // Recursive fib(). Since
   if (n == 1) {                      // fibonacci #1 is 0, adjust
      return 0;                       // the other values to fit
   } else if (n <= 2) {               // the constraints
      return 1;
   }

   return rfib(n - 1) + rfib(n - 2);  // Using recursion, find fib(n)
}                                   

int ifib(int n) {                     // Iterative fib(). Same as
   if (n == 1) {                      // above, make sure fib(1)
      return 0;                       // is 0. Then adjust the
   } else if (n == 2) {               // other values
      return 1;                       
   }

   int a = 0;                         // Set the initial values for
   int b = 1;                         // the iterative sequence
   int result = 0;                    

   for (int i = 3; i <= n; ++i) {     // Loop till the Nth number
      result = a + b;                 // Update the result and
      a = b;                          // variables for the next
      b = result;                     // iteration
   }                                  

   return result;                     // Return the result.
}                                     

int main(int argc, char* argv[]) {    // cmd line inputs for main()
   int n;                             // Create and store the cmd
   sscanf(argv[1], "%d", &n);         // line integer into a variable

   char type = argv[2][0];            // Store the type of method

   FILE *fptr = fopen(argv[3], "r");  // Open the given file
   
   int file_n;                        // Create and store the integer
   fscanf(fptr, "%d", &file_n);       // within the file into a
   fclose(fptr);                      // variable and close the file
   
   n += file_n;                       // Add the two numbers to get N

   int number = 0;
   if (type == 'i') {                 // If the type of method is 
      number = ifib(n);               // iterative, call ifib(),
   } else if (type == 'r') {          // otherwise call rfib().
      number = rfib(n);
   } else {                           // If the type is invalid,
      number = 0;                     // set number to 0
   }

   printf("%d", number);              // Print the result

   return 0;
}
