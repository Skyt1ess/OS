#include <stdio.h>
#include <string.h>

int main() {
    printf("Enter the string no longer than 256 symbols:\n");
    char s[256];
    scanf("%s", &s); // read string no longer than 256 symbols
    int len = strlen(s);//get length of string

    for (int i = 0; i < len/2; i++) { // for every symbol in 0 to len/2 swap opposite symbols
        char tmp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = tmp;
    }

    printf("Reverse string of given:\n%s", s); //print reversed string
}


