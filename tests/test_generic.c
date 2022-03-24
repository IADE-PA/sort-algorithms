#include <stdlib.h>
#include "unity/unity.h"

#include "../src/sort.h"

#define NUMBERS_SIZE 10
int** numbers;

void setUp(void) {
    numbers = (int**)malloc(sizeof(int*) * NUMBERS_SIZE);
    for (int i = 0; i < NUMBERS_SIZE; i++) {
        numbers[i] = (int*)malloc(sizeof(int));
    }
    *(numbers[0]) = 1;
    *(numbers[1]) = 7;
    *(numbers[2]) = 2;
    *(numbers[3]) = 8;
    *(numbers[4]) = 3;
    *(numbers[5]) = 10;
    *(numbers[6]) = 9;
    *(numbers[7]) = 6;
    *(numbers[8]) = 5;
    *(numbers[9]) = 4;
}

void tearDown(void) {
    for (int i = 0; i < NUMBERS_SIZE; i++) {
        free(numbers[i]);
    }
    free(numbers);
}

int compare(int* a, int* b) {
    return *a - *b;
}

void test_simple_int_array(void) {
    sort((comparable*)numbers, NUMBERS_SIZE, (int (*)(comparable, comparable))compare);
    // TEST_ASSERT_EQUAL_INT_ARRAY(numbers, ((int[]){1, 2, 3, 4, 5, 6, 7, 8, 9, 10}), NUMBERS_SIZE);
}

void test_single_element_array(void) {
}

// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_simple_int_array);
    RUN_TEST(test_single_element_array);
    return UNITY_END();
}