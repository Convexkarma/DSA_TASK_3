/* CCS 2214 - Task 3: Q6_Sparse_Matrix
   Name: Emmanuel Kibet
   REG_NO: CIT-227-043/2025
   COURSE: Software Engineering
   TASK: TASK_3 */

#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define MAX_TERMS (MAX_ROWS * MAX_COLS)

/* Row 0 is metadata: rows, columns, number of non-zero entries.
   Rows 1..count contain: row index, column index, value. */
int to_sparse(int rows, int cols, const int matrix[MAX_ROWS][MAX_COLS],
              int triplets[MAX_TERMS + 1][3]) {
    int count = 0;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (matrix[r][c] != 0) {
                count++;
                triplets[count][0] = r;
                triplets[count][1] = c;
                triplets[count][2] = matrix[r][c];
            }
        }
    }
    triplets[0][0] = rows;
    triplets[0][1] = cols;
    triplets[0][2] = count;
    return count;
}

int main(void) {
    const int matrix[MAX_ROWS][MAX_COLS] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };
    int triplets[MAX_TERMS + 1][3];
    int count = to_sparse(4, 5, matrix, triplets);
    puts("rows columns nonzeros (metadata)");
    printf("%d %d %d\n", triplets[0][0], triplets[0][1], triplets[0][2]);
    puts("row column value (zero-based indices)");
    for (int i = 1; i <= count; i++)
        printf("%d %d %d\n", triplets[i][0], triplets[i][1], triplets[i][2]);
    return 0;
}
