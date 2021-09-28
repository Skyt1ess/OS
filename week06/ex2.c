#include<stdio.h>

int AT[1000], BT[1000], CT[1000], WT[1000], TAT[1000], NUM[1000], timer = 0, totalTT = 0, totalWT = 0;

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
    CT[0] = AT[0] + BT[0];
    TAT[0] = CT[0] - AT[0];
    WT[0] = TAT[0] - BT[0];
    totalTT += TAT[0];
    totalWT += WT[0];
    for (int i = 1; i < n; i++) {
        int tmp = CT[i - 1], ind = i - 1;
        int low = BT[i];
        for (int j = i; j < n; j++) {
            if (tmp >= AT[j] && low >= BT[j]) {
                low = BT[j];
                ind = j;
            }
        }
        CT[ind] = tmp + BT[ind];
        TAT[ind] = CT[ind] - AT[ind];
        WT[ind] = TAT[ind] - BT[ind];
        totalTT += TAT[ind];
        totalWT += WT[ind];
        swap(&CT[i], &CT[ind]);
        swap(&AT[i], &AT[ind]);
        swap(&BT[i], &BT[ind]);
        swap(&WT[i], &WT[ind]);
        swap(&TAT[i], &TAT[ind]);
        swap(&NUM[i], &NUM[ind]);
    }

    for(int i = 0; i < n; i++){
        printf("Process[%d]:Waiting time %d, Turn around time %d, Completion time %d\n", NUM[i], WT[i], TAT[i], CT[i]);
    }

    printf("Average Turnaround time: %f\n", (.0 + totalTT) / n);
    printf("Average waiting time: %f\n", (.0 + totalWT)  / n);
    return 0;
}
