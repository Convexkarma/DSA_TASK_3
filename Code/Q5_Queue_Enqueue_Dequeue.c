/* CCS 2214 - Task 3: Q5_Queue_Enqueue_Dequeue
   Name: Emmanuel Kibet
   REG_NO: CIT-227-043/2025
   COURSE: Software Engineering
   TASK: TASK_3 */

#include <stdbool.h>
#include <stdio.h>

#define CAPACITY 5
typedef struct {
    int data[CAPACITY];
    int front;
    int rear; /* Next free index, not the index of the last element. */
} Queue;

bool enqueue(Queue *q, int value) {
    if (q->rear == CAPACITY) return false;
    q->data[q->rear++] = value;
    return true;
}

bool dequeue(Queue *q, int *value) {
    if (q->front == q->rear) return false;
    *value = q->data[q->front++];
    if (q->front == q->rear) q->front = q->rear = 0;
    return true;
}

void display(const Queue *q) {
    if (q->front == q->rear) { puts("Queue is empty."); return; }
    for (int i = q->front; i < q->rear; i++) printf("%d ", q->data[i]);
    putchar('\n');
}

int main(void) {
    Queue q = {0};
    int value;
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    printf("Queue: "); display(&q);
    if (dequeue(&q, &value)) printf("Dequeued: %d\n", value);
    printf("Remaining: "); display(&q);
    while (dequeue(&q, &value)) printf("Dequeued: %d\n", value);
    if (!dequeue(&q, &value)) puts("Underflow: queue is empty.");
    enqueue(&q, 40);
    printf("After reuse: "); display(&q);
    return 0;
}
