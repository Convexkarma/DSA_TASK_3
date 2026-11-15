/* CCS 2214 - Task 3: Q1_Circular_Queue
   Name: Emmanuel Kibet
   REG_NO: CIT-227-043/2025
   COURSE: Software Engineering
   TASK: TASK_3 */

#include <stdbool.h>
#include <stdio.h>

#define CAPACITY 5
typedef struct {
    int data[CAPACITY];
    int front;  /* Index of the next item to remove. */
    int count;  /* Distinguishes empty from full. */
} CircularQueue;

bool enqueue(CircularQueue *q, int value) {
    if (q->count == CAPACITY) return false;
    int rear = (q->front + q->count) % CAPACITY;
    q->data[rear] = value;
    q->count++;
    return true;
}

bool dequeue(CircularQueue *q, int *value) {
    if (q->count == 0) return false;
    *value = q->data[q->front];
    q->front = (q->front + 1) % CAPACITY;
    q->count--;
    return true;
}

void display(const CircularQueue *q) {
    for (int i = 0; i < q->count; i++)
        printf("%d ", q->data[(q->front + i) % CAPACITY]);
    putchar('\n');
}

int main(void) {
    CircularQueue q = {0};
    int value;
    for (int i = 1; i <= CAPACITY; i++) enqueue(&q, i * 10);
    if (!enqueue(&q, 60)) puts("Overflow: queue is full.");
    dequeue(&q, &value);
    printf("Removed: %d\n", value);
    dequeue(&q, &value);
    printf("Removed: %d\n", value);
    enqueue(&q, 60); /* Reuses physical index 0. */
    enqueue(&q, 70); /* Reuses physical index 1. */
    printf("After wraparound: ");
    display(&q);
    while (dequeue(&q, &value)) printf("Dequeued: %d\n", value);
    if (!dequeue(&q, &value)) puts("Underflow: queue is empty.");
    return 0;
}
