/* CCS 2214 - Task 3: Q4b_Recursive_Factorial
   Name: Emmanuel Kibet
   REG_NO: CIT-227-043/2025
   COURSE: Software Engineering
   TASK: TASK_3
   Factorial of N.
   main validates the input before invoking the recursive function. */
#include <stdio.h>

unsigned long long factorial(unsigned n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int main(void) {
    int n;
    puts("Factorial of N");
    puts("Enter N (0 to 20):");
    if (scanf("%d", &n) != 1 || n < 0 || n > 20) {
        puts("Invalid input: enter an integer from 0 to 20.");
        return 1;
    }
    printf("Factorial = %llu\n", factorial((unsigned)n));
    return 0;
}
