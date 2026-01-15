#include <stdio.h>
#include <limits.h>

int main() {
    int n, quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], wt[n], tat[n], rem_bt[n];
    for(int i = 0; i < n; i++) {
        printf("Enter Arrival Time for Process %d: ", i);
        scanf("%d", &at[i]);
        printf("Enter Burst Time for Process %d: ", i);
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    int added[n];
    for(int i = 0; i < n; i++) added[i] = 0;

    // Initialize queue and scheduling variables
    int queue[100], front = 0, rear = 0;
    int t = 0; 
    int done = 0;

    // Scheduling loop
    while(done < n) {
        for(int i = 0; i < n; i++) {
            if(!added[i] && at[i] <= t) {
                queue[rear++] = i;
                added[i] = 1;
            }
        }
        // If no process is in the queue, advance time
        if(front == rear) {
            int min_at = INT_MAX;
            for(int i = 0; i < n; i++) {
                if(!added[i] && at[i] < min_at) min_at = at[i];
            }
            if(min_at != INT_MAX) {
                t = min_at;
            }
            continue;
        }
        // Dequeue process
        int idx = queue[front++];
        if(rem_bt[idx] > quantum) {
            t += quantum;
            rem_bt[idx] -= quantum;
            queue[rear++] = idx;
        } else { // Process completes
            t += rem_bt[idx];
            wt[idx] = t - at[idx] - bt[idx];
            tat[idx] = t - at[idx];
            rem_bt[idx] = 0;
            done++;
        }
    }

    printf("\t PROCESS \tARRIVAL TIME\tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n");
    for(int i = 0; i < n; i++) {
        printf("\n\t P%d \t\t %d \t\t %d \t\t %d \t\t %d", i, at[i], bt[i], wt[i], tat[i]);
    }

    float wtavg = 0, tatavg = 0;
    for(int i = 0; i < n; i++) {
        wtavg += wt[i];
        tatavg += tat[i];
    }

    printf("\nAverage Waiting Time: %.2f", wtavg / n);
    printf("\nAverage Turnaround Time: %.2f", tatavg / n);

    return 0;
}

