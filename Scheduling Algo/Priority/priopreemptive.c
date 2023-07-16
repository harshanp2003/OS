#include <stdio.h>
#include <stdlib.h>
//Lower the number higher the priority
typedef struct process
{
    int Id, AT, BT, CT, TAT, WT, priority;
} pro;

pro p[15];

void main()
{
    int n, tempBT[15], total_WT = 0, total_TAT = 0;
    float avg_WT = 0, avg_TAT = 0;
    printf("\nEnter the number of processes:\n");
    scanf("%d", &n);
    printf("\nEnter the arrival time, burst time and priority of the process:\n");
    printf("AT BT p\n");
    for (int i = 0; i < n; i++)
    {
        p[i].Id = (i + 1);
        scanf("%d%d%d", &p[i].AT, &p[i].BT, &p[i].priority);
        tempBT[i] = p[i].BT;
    }

    printf("\nGantt Chart:\n");
    int minIndex, minPriority, completed = 0, curTime = 0;
    while (completed != n)
    {
        minIndex = -1;
        minPriority = 9999;
        for (int i = 0; i < n; i++)
        {
            if (p[i].AT <= curTime && p[i].BT > 0)
            {
                if (p[i].priority < minPriority || (p[i].priority == minPriority && p[i].AT < p[minIndex].AT))
                {
                    minPriority = p[i].priority;
                    minIndex = i;
                }
            }
        }

        curTime++;

        if (minIndex != -1)
        {
            p[minIndex].BT--;
            printf("| P%d %d", p[minIndex].Id, curTime);
            if (p[minIndex].BT == 0)
            {
                p[minIndex].CT = curTime;
                p[minIndex].TAT = p[minIndex].CT - p[minIndex].AT;
                p[minIndex].WT = p[minIndex].TAT - tempBT[minIndex];
                total_TAT += p[minIndex].TAT;
                total_WT += p[minIndex].WT;
                completed++;
            }
        }
    }
    printf("|\n");
    avg_TAT = (float)total_TAT / n;
    avg_WT = (float)total_WT / n;

    // Printing the table of processes with details
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\tP\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].Id, p[i].AT, tempBT[i], p[i].CT, p[i].TAT, p[i].WT, p[i].priority);
    }
    printf("\nAverage TAT = %.2f\nAverage WT = %.2f\n", avg_TAT, avg_WT);
}
/*
Gantt Chart:
| P1 1| P2 2| P2 3| P3 4| P3 5| P4 6| P4 7| P4 8| P4 9| P2 10| P2 11| P2 12| P2 13| P1 14| P1 15| P1 16| P1 17| P1 18| P1 19| P1 20| P1 21| P1 22|

PID     AT      BT      CT      TAT     WT      P
1       0       10      22      22      12      5
2       1       6       13      12      6       4
3       3       2       5       2       0       2
4       5       4       9       4       0       0

Average TAT = 10.00
Average WT = 4.50
*/