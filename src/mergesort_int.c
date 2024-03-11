#include <stdlib.h>
#include "sort_int.h"

void merge(int collection[],
           int low, int mid, int high) {
    int i = low, j = mid + 1, k = 0;
    int *temp = malloc((high - low + 1) * sizeof(int));
    // Enquanto houver elementos em ambas as metades
    // copia o menor entre os elementos das duas metades
    while (i <= mid && j <= high) {
        if (collection[i] < collection[j]) {
            temp[k++] = collection[i++];
        } else {
            temp[k++] = collection[j++];
        }
    }
    // Termina de copiar a primeira metade
    while (i <= mid)
        temp[k++] = collection[i++];
    // Termina de copiar a segunda metade
    while (j <= high)
        temp[k++] = collection[j++];
    // Copia array temporário para original
    for (i = low, k = 0; i <= high; i++, k++)
        collection[i] = temp[k];
    free(temp);
}

void mergesort(int collection[],
               int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergesort(collection, low, mid);
        mergesort(collection, mid + 1, high);
        merge(collection, low, mid, high);
    }
}

void sort(int collection[], const int size) {
    mergesort(collection, 0, size-1); 
}