#include <stdio.h>

int heap[100], n = 0;

void insert(int x) {
    int i, p, temp;

    heap[n] = x;
    i = n;
    n++;

    while (i > 0) {
        p = (i - 1) / 2;

        if (i % 2 == 1) {       // Min level
            if (heap[i] > heap[p]) {
                temp = heap[i];
                heap[i] = heap[p];
                heap[p] = temp;
            } else break;
        } else {                // Max level
            if (heap[i] < heap[p]) {
                temp = heap[i];
                heap[i] = heap[p];
                heap[p] = temp;
            } else break;
        }
        i = p;
    }
}

int search(int key) {
	int i;
    for (i = 0; i < n; i++)
        if (heap[i] == key)
            return 1;
    return 0;
}

int main() {
    int ch, x, i;

    while (1) {
        printf("\n1.Insert\n2.Search\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        if (ch == 1) {
            printf("Enter element: ");
            scanf("%d", &x);
            insert(x);
        }
        else if (ch == 2) {
            printf("Enter key: ");
            scanf("%d", &x);

            if (search(x))
                printf("Key found\n");
            else
                printf("Key not found\n");
        }
        else if (ch == 3) {
            printf("Heap: ");
            for (i = 0; i < n; i++)
                printf("%d ", heap[i]);
            printf("\n");
        }
        else
            break;
    }

    return 0;
}
