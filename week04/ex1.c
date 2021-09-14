#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void main() {
    //fork create a new child process with different process id
    //and return child PID for parent and 0 for child
    int n = fork();
    if (n) printf("Hello from parent[PID - %d]\n", getpid());
    else printf("Hello from child[PID - %d]\n", getpid());;
}
