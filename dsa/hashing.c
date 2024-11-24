#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int hashTable[SIZE];
void insert(int key)
{
    int index = key % SIZE;
    while (hashTable[index] != -1)
        index = (index + 1) % SIZE;
    hashTable[index] = key;
}
void display()
{
    for (int i = 0; i < SIZE; i++)
        printf("%d ", hashTable[i]);
    printf("\n");
}
int main()
{
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
    insert(10);
    insert(20);
    insert(30);

    display();
    return 0;
}
