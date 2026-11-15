/* CCS 2214 - Task 3: Q4d_Recursive_Fibonacci_Series
   Name: Emmanuel Kibet
   REG_NO: CIT-227-043/2025
   COURSE: Software Engineering
   TASK: TASK_3
   First N Fibonacci terms, beginning with F(0)=0.
   main validates the input before invoking the recursive function. */
#include <stdio.h>

void fibonacci_terms(unsigned remaining, unsigned long long a,
                     unsigned long long b) {
    if (remaining == 0) return;
    printf("%llu", a);
    if (remaining == 1) return;
    putchar(' ');
    if (remaining == 2) {
        printf("%llu", b);
        return; /* Avoid computing an unnecessary, possibly overflowing term. */
    }
    fibonacci_terms(remaining - 1, b, a + b);
}

int main(void) {
    int n;
    puts("First N Fibonacci terms, beginning with F(0)=0");
    puts("Enter N (0 to 94):");
    if (scanf("%d", &n) != 1 || n < 0 || n > 94) {
        puts("Invalid input: enter an integer from 0 to 94.");
        return 1;
    }
    fibonacci_terms((unsigned)n, 0, 1);
    putchar('\n');
    return 0;
}
