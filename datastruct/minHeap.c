#include <stdio.h>
#include <stdlib.h>

struct minheap {
    int *array;
    int capacity;
    int size;
};

struct minheap *create(int capacity)
{
    struct minheap *p;

    p = (struct minheap*)malloc(sizeof(struct minheap));
    p->array = (int*)malloc(sizeof(int) * (capacity + 1));
    p->capacity = capacity;
    p->size = 0;
    return p;
}

void push(struct minheap *p, int x)
{
    int i;

    if (p->size > p->capacity + 1) {
        return;
    }
    i = ++p->size;
    while (i > 1 && x < p->array[i / 2]) {
        p->array[i] = p->array[i / 2];
        i = i / 2;
    }
    p->array[i] = x;
}

int pop(struct minheap *p, int *px)
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
        if (ci < p->size && p->array[ci + 1] < p->array[ci]) {
            ci++;
        }
        if (y > p->array[ci]) {
            p->array[i] = p->array[ci];
            i = ci;
            ci = 2 * i;
        }
        else {
            break;
        }
    }
    p->array[i] = y;
    p->size--;
    return 0;
}

int main(void)
{
    int array[] = {19, 92, 8, 12, 19, 93, 1, 25};
    int i, j;
    struct minheap *p = create(100);
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
