#include<stdio.h>

int max(int a, int b) {
    if (a > b) return a;
    return b;
}

void swap(int *first, int *second) {
    *first = *first + *second;
    *second = *first - *second;
    *first = *first - *second;
}

int min(int a, int b) {
    if (a > b) return b;
    return a;
}



int main(){
    int n;
    printf("Number of processes:\n");
    scanf("%d", &n);
    int AT[n], BT[n], CT[n], WT[n], TAT[n], NUM[n], timer = 0, totalTT = 0, totalWT = 0, Q;
    for(int i = 0; i < n; i++){
        printf("Arrival time of %d process: ", i + 1);
        scanf("%d", &AT[i]);
        printf("Burst time of %d process: ", i + 1);
        scanf("%d", &BT[i]);
        NUM[i] = i + 1;
    }

    printf("Quantum number ");
    scanf("%d", &Q);

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (AT[i] > AT[j]) {
                    swap(&AT[i], &AT[j]);
                    swap(&BT[i], &BT[j]);
                    swap(&NUM[i], &NUM[j]);
            }
        }
    }

    int remBT[n];
    for (int i = 0; i < n; i++) {
        remBT[i] = BT[i];
    }

    while(1) {
        int ok = 1;
        for (int i = 0; i < n; i++) {
            if (remBT[i] > 0) {
                ok = 0;
                if (remBT[i] > Q) {
                    timer += Q;
                    CT[i] = timer;
                    remBT[i] -= Q;
                } else {
                    timer += remBT[i];
                    CT[i] = timer;
                    WT[i] = timer - BT[i];
                    remBT[i] = 0;
                }
            }
        }
        if (ok) break;
    }

    for (int i = 0; i < n; i++) {
        TAT[i] = BT[i] + WT[i];
    }

    for(int i = 0; i < n; i++){
        printf("Process[%d]:Waiting time %d, Turn around time %d, Completion time %d\n", NUM[i], WT[i], TAT[i], CT[i]);
    }

    printf("Average Turnaround time: %f\n", (.0 + totalTT) / n);
    printf("Average waiting time: %f\n", (.0 + totalWT)  / n);
    return 0;
}
