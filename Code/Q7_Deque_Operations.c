/* CCS 2214 - Task 3: Q7_Deque_Operations
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
    int count;
} Deque;

bool insert_front(Deque *d, int value) {
    if (d->count == CAPACITY) return false;
    d->front = (d->front - 1 + CAPACITY) % CAPACITY;
    d->data[d->front] = value;
    d->count++;
    return true;
}

bool insert_rear(Deque *d, int value) {
    if (d->count == CAPACITY) return false;
    int rear = (d->front + d->count) % CAPACITY;
    d->data[rear] = value;
    d->count++;
    return true;
}

bool delete_front(Deque *d, int *value) {
    if (d->count == 0) return false;
    *value = d->data[d->front];
    d->front = (d->front + 1) % CAPACITY;
    d->count--;
    return true;
}

bool delete_rear(Deque *d, int *value) {
    if (d->count == 0) return false;
    int rear = (d->front + d->count - 1) % CAPACITY;
    *value = d->data[rear];
    d->count--;
    return true;
}

void display(const Deque *d) {
    for (int i = 0; i < d->count; i++)
        printf("%d ", d->data[(d->front + i) % CAPACITY]);
    putchar('\n');
}

int main(void) {
    Deque d = {0};
    int value;
    insert_rear(&d, 20);
    insert_front(&d, 10);
    insert_rear(&d, 30);
    printf("Deque: "); display(&d);
    if (delete_front(&d, &value)) printf("Deleted front: %d\n", value);
    if (delete_rear(&d, &value)) printf("Deleted rear: %d\n", value);
    printf("Remaining: "); display(&d);
    delete_rear(&d, &value);
    if (!delete_front(&d, &value)) puts("Underflow: deque is empty.");
    return 0;
}
