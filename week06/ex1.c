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
    int AT[n], BT[n], CT[n], WT[n], TAT[n], NUM[n], timer = 0, totalTT = 0, totalWT = 0;
    for(int i = 0; i < n; i++){
        printf("Arrival time of %d process: ", i + 1);
        scanf("%d", &AT[i]);
        printf("Burst time of %d process: ", i + 1);
        scanf("%d", &BT[i]);
        NUM[i] = i + 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (AT[i] > AT[j]) {
                    swap(&AT[i], &AT[j]);
                    swap(&BT[i], &BT[j]);
                    swap(&NUM[i], &NUM[j]);
            }
        }
    }

    for(int i = 0; i < n; i++){
        WT[i] = max(0, timer - AT[i]);
        TAT[i] = WT[i] + BT[i];
        timer = max(timer + BT[i], AT[i] + BT[i]);
        CT[i] = timer;
        totalTT += TAT[i];
        totalWT += WT[i];
        printf("Process[%d]:Waiting time %d, Turn around time %d, Completion time %d\n", NUM[i], WT[i], TAT[i], CT[i]);
    }

    printf("Average Turnaround time: %f\n", (.0 + totalTT) / n);
    printf("Average waiting time: %f\n", (.0 + totalWT)  / n);
    return 0;
}
