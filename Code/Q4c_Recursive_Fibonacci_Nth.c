/* CCS 2214 - Task 3: Q4c_Recursive_Fibonacci_Nth
   Name: Emmanuel Kibet
   REG_NO: CIT-227-043/2025
   COURSE: Software Engineering
   TASK: TASK_3
   Fibonacci F(N): F(0)=0 and F(1)=1.
   main validates the input before invoking the recursive function. */
#include <stdio.h>

unsigned long long fibonacci(unsigned n, unsigned long long memo[94]) {
    if (n <= 1) return n;
    if (memo[n] != 0) return memo[n];
    memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
    return memo[n];
}

int main(void) {
    int n;
    puts("Fibonacci F(N): F(0)=0 and F(1)=1");
    puts("Enter N (0 to 93):");
    if (scanf("%d", &n) != 1 || n < 0 || n > 93) {
        puts("Invalid input: enter an integer from 0 to 93.");
        return 1;
    }
    unsigned long long memo[94] = {0};
    printf("F(%d) = %llu\n", n, fibonacci((unsigned)n, memo));
    return 0;
}
