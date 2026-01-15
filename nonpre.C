#include <stdio.h>

typedef struct {
    int at, bt, pri, p;
} Process;

int main() {
    Process processes[20];
    int wt[20], tat[20], i, n;
    float wtavg, tatavg;
        printf("\nEnter the number of processes: ");
        scanf("%d", &n);

    for(i=0;i<n;i++) {
        processes[i].p = i;
        printf("\nEnter Arrival Time for Process %d: ", i);
         scanf("%d", &processes[i].at);
          printf("Enter Burst Time for Process %d: ", i);
            scanf("%d", &processes[i].bt);
          printf("Enter Priority for Process %d: ", i);
            scanf("%d", &processes[i].pri);
    }

    int current_time = 0;
    int completed = 0;
    int is_completed[20] = {0};
    wtavg = tatavg = 0;

    // Scheduling loop
    while(completed < n) {
        int selected = -1;
        int highest_pri = 999;
        for(i=0;i<n;i++) {
            if(!is_completed[i] && processes[i].at <= current_time && processes[i].pri < highest_pri) {
                highest_pri = processes[i].pri;
                selected = i;
            }
        }
        
        // If no process is ready, increment time
        if(selected == -1) {
            current_time++;
        } else {
            wt[selected] = current_time - processes[selected].at;
            current_time += processes[selected].bt;
            tat[selected] = current_time - processes[selected].at;
            wtavg += wt[selected];
            tatavg += tat[selected];
            is_completed[selected] = 1;
            completed++;
        }
    }

    printf("\n\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n");

    for(i=0;i<n;i++) {
        printf("\n\t P%d \t\t %d \t\t %d \t\t %d", processes[i].p, processes[i].bt, wt[i], tat[i]);
    }

        printf("\nAverage Waiting Time: %f", wtavg/n);
        printf("\nAverage Turnaround Time: %f", tatavg/n);
    return 0;
}