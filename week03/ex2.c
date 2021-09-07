#include <stdio.h>


int main() {
    int k[10] = {2, 3, 14, 5, 36, 27, 8, 9, 10, 11};
    int size = sizeof(k)/sizeof(k[0]);
    bubble_sort(k, size);
    print_arr(k, size);

}


void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}


void print_arr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
