#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void main() {
    //for N = 3 -> 8 processes, for N = 5 -> 32 processes
    //each process will be divided by 2
    //so the total number of processes will be 2^N
    int N = 5;
    for (int i = 0; i < N; i++) {
        fork();
        sleep(5);
    }
}
