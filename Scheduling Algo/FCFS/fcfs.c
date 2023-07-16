#include <stdio.h>
struct process
{
    int ID, AT, BT, CT, TAT, WT;
};
void main()
{
    struct process P[10], temp;
    int n, i, j, ct, temp1 = 0;
    float total_tat = 0, total_wt = 0;
    printf("Enter the number of Process: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        P[i].ID = i + 1;
        printf("\nEnter AT for process %d :", i + 1);
        scanf("%d", &P[i].AT);
        printf("Enter BT for process %d :", i + 1);
        scanf("%d", &P[i].BT);
    }
    printf("\nGantt Chart:\n");
    for (i = 0; i < n - 1; i++) //Bubble Sort applied Sorting is done
        for (j = 0; j < n - i - 1; j++)//if some other process starts at after execution is done whose AT  is 0 
            if (P[j].AT > P[j + 1].AT)
            {
                temp = P[j];
                P[j] = P[j + 1];
                P[j + 1] = temp;
            }
    P[0].CT = P[0].AT + P[0].BT;
    ct = P[0].CT;
    if (P[0].AT > 0)
        printf("|Idle till %d", P[0].AT);
    printf("| P%d(%d) %d", P[0].ID, P[0].BT, ct);
    for (i = 1; i < n; i++)
    {
        if (P[i].AT > P[temp1].CT) //In general 2nd process arrival time is greater than 1st process completion time, then idle condition
        {
            printf("|Idle till %d", P[i].AT);
            ct = P[i].AT + P[i].BT;
        }
        else
            ct += P[i].BT;
        P[i].CT = ct;
        temp1 = i;//current process is made as temp1 to compare with next upcoming process
        printf("| P%d(%d) %d", P[i].ID, P[i].BT, ct);
    }
    for (i = 0; i < n; i++)
    {
        P[i].TAT = P[i].CT - P[i].AT;
        P[i].WT = P[i].TAT - P[i].BT;
        total_tat += P[i].TAT;
        total_wt += P[i].WT;
    }
    printf("\n\nID\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", P[i].ID, P[i].AT, P[i].BT, P[i].CT, P[i].TAT, P[i].WT);
    }
    printf("AVG TAT : %.3f\n", total_tat / n);
    printf("AVG WT : %.3f\n", total_wt / n);
}

/*
Enter the number of Process: 5
Gantt Chart:
| P1(3) 3| P2(6) 9| P3(4) 13| P4(5) 18| P5(2) 20

ID      AT      BT      CT      TAT     WT
1       0       3       3       3       0
2       2       6       9       7       1
3       4       4       13      9       5
4       6       5       18      12      7
5       8       2       20      12      10
AVG TAT : 8.600
AVG WT : 4.600
*/