#include <stdio.h>
#include <stdlib.h>

#include <memory.h>



int main() {
    int n;

    printf("Enter count of integers:\n");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(n));

    for (int i = 0; i < n; i++) {
        *(arr + i) = i;
        printf("%d ", *(arr + i));
    }

    free(arr);
}
