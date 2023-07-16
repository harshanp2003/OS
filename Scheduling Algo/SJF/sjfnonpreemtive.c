/*In SJF, the process that has the lest burst time is executed first.
 * In this nonpreemptive version, the process cannot be stopped once it starts to execute, even if another proccess has smaller Burst time*/ \
#include<stdio.h>
#include <stdlib.h>

typedef struct process
{
    int Id, AT, BT, CT, TAT, WT, isCompl;
} pro;

pro p[15];

void main()
{
    int n, total_WT = 0, total_TAT = 0;
    float avg_WT = 0, avg_TAT = 0;
    printf("\nEnter the number of processes:\n");
    scanf("%d", &n);
    printf("\nEnter the arrival time and burst time of the process:\n");
    printf("AT BT\n");
    for (int i = 0; i < n; i++)
    {
        p[i].Id = (i + 1);
        scanf("%d%d", &p[i].AT, &p[i].BT);
        p[i].isCompl = 0;
    }

    int minIndex, minBT, completed = 0, curTime = 0;

    printf("\nGantt Chart:\n\n");
    while (completed != n)
    {
        minIndex = -1;
        minBT = 9999;
        for (int i = 0; i < n; i++)
        {
            if (p[i].AT <= curTime && p[i].isCompl == 0)
            {
                if (p[i].BT < minBT || (p[i].BT == minBT && p[i].AT < p[minIndex].AT))
                {
                    minBT = p[i].BT;
                    minIndex = i;
                }
            }
        }

        if (minIndex == -1)
        {
            curTime++; // If no process which is not completed is present at the current time increment it.
        }
        else
        {
            // As the process is not preempted, the process executes till it is completed, i.e., for it's full BT.
            curTime += p[minIndex].BT;
            p[minIndex].CT = curTime;
            p[minIndex].TAT = p[minIndex].CT - p[minIndex].AT;
            p[minIndex].WT = p[minIndex].TAT - p[minIndex].BT;
            total_TAT += p[minIndex].TAT;
            total_WT += p[minIndex].WT;
            p[minIndex].isCompl = 1;
            completed++;
            printf("| P%d (%d) %d", p[minIndex].Id, p[minIndex].BT, p[minIndex].CT);
        }
    }
    printf("|\n");
    avg_TAT = (float)total_TAT / n;
    avg_WT = (float)total_WT / n;

    // Printing the table of processes with details
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].Id, p[i].AT, p[i].BT, p[i].CT, p[i].TAT, p[i].WT);
    }
    printf("\nAverage TAT = %.2f\nAverage WT = %.2f\n", avg_TAT, avg_WT);
}
/*

| P1 (6) 7| P2 (2) 9| P3 (3) 12| P4 (3) 15| P5 (4) 19|

PID     AT      BT      CT      TAT     WT
1       1       6       7       6       0
2       3       2       9       6       4
3       2       3       12      10      7
4       4       3       15      11      8
5       5       4       19      14      10

Average TAT = 9.40
Average WT = 5.80
*/