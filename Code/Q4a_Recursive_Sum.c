/* CCS 2214 - Task 3: Q4a_Recursive_Sum
   Name: Emmanuel Kibet
   REG_NO: CIT-227-043/2025
   COURSE: Software Engineering
   TASK: TASK_3
   Sum of the first N natural numbers.
   main validates the input before invoking the recursive function. */
#include <stdio.h>

unsigned long long sum_n(unsigned n) {
    if (n == 0) return 0;
    return n + sum_n(n - 1);
}

int main(void) {
    int n;
    puts("Sum of the first N natural numbers");
    puts("Enter N (0 to 1000):");
    if (scanf("%d", &n) != 1 || n < 0 || n > 1000) {
        puts("Invalid input: enter an integer from 0 to 1000.");
        return 1;
    }
    printf("Sum = %llu\n", sum_n((unsigned)n));
    return 0;
}
