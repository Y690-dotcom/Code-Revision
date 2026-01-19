#include <stdio.h>

int main() {
    int n, i, j;
    int process[10], burst[10], waiting[10], turnaround[10];
    int temp, total_waiting = 0, total_turnaround = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input burst times
    for (i = 0; i < n; i++) {
        printf("Enter burst time for P%d: ", i + 1);
        scanf("%d", &burst[i]);
        process[i] = i + 1;
    }

    // Sort burst times (SJF logic)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (burst[i] > burst[j]) {
                // Swap burst times
                temp = burst[i];
                burst[i] = burst[j];
                burst[j] = temp;

                // Swap process IDs
                temp = process[i];
                process[i] = process[j];
                process[j] = temp;
            }
        }
    }

    // Calculate waiting time
    waiting[0] = 0;
    for (i = 1; i < n; i++) {
        waiting[i] = waiting[i - 1] + burst[i - 1];
        total_waiting += waiting[i];
    }

    // Calculate turnaround time
    for (i = 0; i < n; i++) {
        turnaround[i] = waiting[i] + burst[i];
        total_turnaround += turnaround[i];
    }

    // Display results
    printf("\nProcess\tBurst\tWaiting\tTurnaround\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", process[i], burst[i], waiting[i], turnaround[i]);
    }

    printf("\nAverage Waiting Time: %.2f", (float)total_waiting / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)total_turnaround / n);

    return 0;
}