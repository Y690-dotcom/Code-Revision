#include <stdio.h>

int main() {
    int n, i, j;
    int pid[10], at[10], bt[10], ct[10], tat[10], wt[10];
    int temp;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter Process ID for process %d: ", i+1);
        scanf("%d", &pid[i]);
        printf("Enter Arrival Time for process %d: ", i+1);
        scanf("%d", &at[i]);
        printf("Enter Burst Time for process %d: ", i+1);
        scanf("%d", &bt[i]);
    }

    // Sorting based on Arrival Time
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(at[i] > at[j]) {
                // Swap arrival time
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;
                // Swap burst time
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                // Swap process ID
                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    // Calculate Completion Time, Turnaround Time, Waiting Time
    ct[0] = at[0] + bt[0];
    for(i = 1; i < n; i++) {
        if(ct[i-1] < at[i]) {
            ct[i] = at[i] + bt[i];  // CPU is idle
        } else {
            ct[i] = ct[i-1] + bt[i];
        }
    }

    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];   // Turnaround time
        wt[i] = tat[i] - bt[i];   // Waiting time
    }

    // Output
    float total_tat = 0, total_wt = 0;
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
        total_tat += tat[i];
        total_wt += wt[i];
    }

    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);
    printf("Average Waiting Time = %.2f\n", total_wt / n);

    return 0;
}