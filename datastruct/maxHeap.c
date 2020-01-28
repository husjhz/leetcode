#include <stdio.h>
#include <stdlib.h>

struct maxheap {
    int *array;
    int capacity;
    int size;
};

struct maxheap *create(int capacity)
{
    struct maxheap *p;

    p = (struct maxheap*)malloc(sizeof(struct maxheap));
    p->array = (int*)malloc(sizeof(int) * (capacity + 1));
    p->capacity = capacity;
    p->size = 0;

    return p;
}

void push(struct maxheap *p, int x)
{
    int i;

    if (p->size > p->capacity + 1) {
        return;
    }
    i = ++p->size;
    while (i > 1 && x > p->array[i / 2]) {
        p->array[i] = p->array[i / 2];
        i = i / 2;
    }
    p->array[i] = x;
}

int pop(struct maxheap *p, int *px)
{
    int y;
    int i, ci;

    if (p->size == 0) {
        return -1;
    }
    *px = p->array[1];
    y = p->array[p->size];
    i = 1;
    ci = 2;
    while (ci < p->size) {
        if (ci < p->size && p->array[ci] < p->array[ci + 1]) {
            ci++;
        }
        if (p->array[ci] > y) {
            p->array[i] = p->array[ci];
            i = ci;
            ci = 2 * i;
        }
        else {
            break;
        }
    }
    p->size--;
    p->array[i] = y;
    return 0;
}

int main(void)
{
    int array[] = {19, 92, 8, 12, 19, 93, 1, 25};
    int i;
    struct maxheap *p = create(100);
    int data;

    for (i = 0; i < 8; i++) {
        push(p, array[i]);
    }
    for (i = 0; i < 8; i++) {
        if (pop(p, &data) != 0) {
            break;
        }
        printf("%d ", data);
    }
    printf("\n");

    return 0;
}
