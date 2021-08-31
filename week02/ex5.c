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


//void to print square
void print_square(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("*");
        }
        printf("\n");
    }
}


//void to print vertical line
void print_line(int n) {
    for (int i = 0; i < n; i++) {
        printf("*\n");
    }
}


int main(int argc, char* argv[]) {
    int height, type;

    if (argc < 3) { //if program run without needed command line parameters
        printf("Enter type of figure(1 - triangle, 2 - square, 3 - line):\n");
        scanf("%d", &type);
        printf("Enter height of figure:\n");
        scanf("%d", &height);
    } else {//convert command line parameters to int value
        sscanf(argv[1], "%d", &type);
        sscanf(argv[2], "%d", &height);
    }

    if (type == 1) print_triangle(height); else
    if (type == 2) print_square(height); else
    if (type == 3) print_line(height); else
    printf("Incorrect type of figure!\n"); //if chosen type of figure incorrect
}


