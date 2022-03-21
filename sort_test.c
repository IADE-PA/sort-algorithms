#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

int compare(int* a, int* b) {
    return *a - *b;
}

int main() {
    // int numbers[] = {32, 8, 5, 5, 6};
    int** numbers = malloc(sizeof(int*) * 5);
    for(int i = 0; i<5; i++) {
        numbers[i] = malloc(sizeof(int));
    }
    *(numbers[0]) = 32;
    *(numbers[1]) = 8;
    *(numbers[2]) = 5;
    *(numbers[3]) = 5;
    *(numbers[4]) = 6;

    sort((comparable*)numbers, 5, (int (*)(comparable, comparable)) compare);

    for (int i = 0; i < 5; i++) {
        printf("%d ", *(numbers[i]));
    }
    printf("\n");

    for(int i = 0; i<5; i++) {
        free(numbers[i]);
    }
    free(numbers);
    return 0;
}