#include <stdio.h>
struct Process
{
    int ID, AT, BT, WT, TT, RT, CT;
    float ntt;
}
P[10];
int n;
int q[10]; // queue
int front = -1, rear = -1;
void enqueue(int i)
{
    if (rear == 10)
        printf("overflow");
    rear++;
    q[rear] = i;
    if (front == -1)
        front = 0;
}
int dequeue()
{
    if (front != -1){
        int temP = q[front];
        if (front == rear)
            front = rear = -1;
        else
            front++;
        return temP;  
    }
}
int isInQueue(int i)
{
    int k;
    for (k = front; k <= rear; k++)
    {
        if (q[k] == i)
            return 1;
    }
    return 0;
}
void sortByArrival()
{
    struct Process temP;
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
        {
            if (P[i].AT > P[j].AT)
            {
                temP = P[i];
                P[i] = P[j];
                P[j] = temP;
            }
        }
}
void main()
{
    int i, j, time = 0, sum_BT = 0, tq,temp1=0,flag=0;
    float avgWT = 0,avgTT=0;
    printf("Enter no of Processes:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        P[i].ID = i + 1;
        printf("\nEnter the arrival time and burst time of Process %d: ", P[i].ID);
        scanf("%d%d", &P[i].AT, &P[i].BT);
        P[i].RT = P[i].BT;
        P[i].CT = 0;
        sum_BT += P[i].BT;
    }
    printf("\nEnter the time quantum:");
    scanf("%d", &tq);
    sortByArrival();
    enqueue(0);
    printf("Process execution order: ");
    if(P[0].AT>0){
        flag=1;
        printf("| IDLE till %d\t",P[0].AT);  
    }
    for (time = P[0].AT; time < sum_BT;)
    {
        i = dequeue();
        if (P[i].RT <= tq)
        {

            time += P[i].RT;
            printf("| P%d (%d) %d ", P[i].ID,P[i].RT,time);
            P[i].RT = 0;
            P[i].CT = 1;
            P[i].WT = time - P[i].AT - P[i].BT;
            P[i].TT = time - P[i].AT;
            P[i].ntt = ((float)P[i].TT / P[i].BT);
            for (j = 0; j < n; j++)
            {
               
                if (P[j].AT <= time && P[j].CT != 1 && isInQueue(j) != 1)
                {
                    enqueue(j);
                }
            }
        }
        else
        {
            time += tq;
            P[i].RT -= tq;
            printf("| P%d (%d) %d ", P[i].ID,tq,time);
            for (j = 0; j < n; j++)
            {
                if (P[j].AT <= time && P[j].CT != 1 && i != j && isInQueue(j) != 1)
                {
                    enqueue(j);
                }
            }
            enqueue(i);
        }
    }
    printf("\nID\tAT\tBT\tTT\tWT");
    for (i = 0; i < n; i++)
    {
        avgWT += P[i].WT;
        avgTT +=P[i].TT;
        printf("\n%d\t%d\t%d\t%d\t%d\n",P[i].ID,P[i].AT,P[i].BT,P[i].TT,P[i].WT);
    }
    printf("\nAverage Waiting time:%f\n", avgWT / n);
    printf("\nAverage Turnaround time:%f\n", avgTT / n);
}
