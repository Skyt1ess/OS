#include <stdio.h>
/**
this solution of swap without 3rd variable
will not correct with float values, but task is for int
**/
void swap(int *first, int *second) {
    *first = *first + *second;
    *second = *first - *second;
    *first = *first - *second;
}


int main() {
    int first, second;
    printf("Enter two integers separated by a space:\n");
    scanf("%d%d", &first, &second);

    printf("Swapped values:\n");
    swap(&first, &second);
    printf("%d %d", first, second);
}


