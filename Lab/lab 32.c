#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
void createHashTable(int hashTable[]) {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }
}
int hashFunction(int key) {
    return key % SIZE;
}
void insert(int hashTable[], int key) {
    int index = hashFunction(key);
    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;
    }
    hashTable[index] = key;
}
int search(int hashTable[], int key) {
    int index = hashFunction(key);
    int startIndex = index;
    while (hashTable[index] != -1) {
        if (hashTable[index] == key) {
            return index;
        }
        index = (index + 1) % SIZE;
        if (index == startIndex) {
            return -1; // Element not found
        }
    }
    return -1; 
}
void displayHashTable(int hashTable[]) {
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != -1) {
            printf("Index %d: %d\n", i, hashTable[i]);
        } else {
            printf("Index %d: Empty\n", i);
        }
    }
}
int main() {
    int hashTable[SIZE];
    createHashTable(hashTable);
    insert(hashTable, 10);
    insert(hashTable, 20);
    insert(hashTable, 30);
    insert(hashTable, 25);
    insert(hashTable, 35);
    insert(hashTable, 50);
    displayHashTable(hashTable);
    int key = 25;
    int result = search(hashTable, key);
    if (result != -1) {
        printf("Element %d found at index %d\n", key, result);
    } else {
        printf("Element %d not found in the hash table\n", key);
    }
    return 0;
}
