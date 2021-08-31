#include <stdio.h>

//void to print triangle
void print_triangle(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            printf(" ");
        }
        for (int j = 0; j < 2*i + 1; j++) {
            printf("*");
        }
        for (int j = 0; j < n - i - 1; j++) {
            printf(" ");
        }
        printf("\n");
    }
}


int main(int argc, char* argv[]) {
    int n;

    if (argc < 2) { //if program run without needed command line parameters
        printf("Enter height of triangle:\n");
        scanf("%d", &n);
    } else {
        sscanf(argv[1], "%d", &n); //convert command line parameter to int value
    }

    print_triangle(n);
}


