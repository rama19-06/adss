#include <stdio.h>
#define SIZE 10
int hashTable[SIZE];
void insert(int key) {
    int index = key % SIZE;
    int i = 0;
    while (hashTable[(index + i) % SIZE] != -1) {
        i++;
        if (i == SIZE) {
            printf("Hash table is full!\n");
            return;
        }
    }
    hashTable[(index + i) % SIZE] = key;
    printf("Inserted successfully.\n");
}
void search(int key) {
    int index = key % SIZE;
    int i;
    for (i = 0; i < SIZE; i++) {
        int pos = (index + i) % SIZE;
        if (hashTable[pos] == key) {
            printf("Element found at index %d\n", pos);
            return;
        }
        if (hashTable[pos] == -1)
            break;
    }
    printf("Element not found.\n");
}
void display() {
    int i;
    printf("\nHash Table:\n");
    for (i = 0; i < SIZE; i++) {
        if (hashTable[i] == -1)
            printf("[%d] : Empty\n", i);
        else
            printf("[%d] : %d\n", i, hashTable[i]);
    }
}
int main() {
    int choice, key, i;
    // Initialize hash table
    for (i = 0; i < SIZE; i++)
        hashTable[i] = -1;
    while (1) {
        printf("\n--- HASHING ---\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter element to search: ");
                scanf("%d", &key);
                search(key);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
