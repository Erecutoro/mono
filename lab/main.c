#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int isSorted(int size, int arr[size]) {
    for (int i = 0; i < size; i++)
        if (arr[i] > arr[i + 1])
            return 0;
    return 1;
}

void print_arr(int size, int arr[size]) {
    for (int i = 0; i < size; i++)
        printf("%d, ", arr[i]);
    printf("\n");
}

void bubble_sort(int size, int arr[size]) {
    int tmp = 0;
    time_t start, end;

    start = clock();
    while(!isSorted(size, arr)) {
        for (int i = 0; i < size; i++) {
            if (arr[i] > arr[i + 1]) {
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
            }
        }
    }
    end = clock();
    print_arr(size, arr);
    printf("time: %f s\n", (double)(end - start) / CLOCKS_PER_SEC);
}

int main() {
    int size = 4000;
    int arr[size];

    for (int i = 0; i < size; i++) {
        arr[i] = rand();
    }
    print_arr(size, arr);
    bubble_sort(size, arr);
}