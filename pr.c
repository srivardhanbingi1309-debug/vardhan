#include <stdio.h>
int main()
{
    int bt[20], p[20], pri[20], wt[20], tat[20];
    int i, j, k, n, temp;
    int total_wt = 0, total_tat = 0;
    float avg_wt, avg_tat;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("\nEnter Burst Time for each process:\n");
    for(i = 0; i < n; i++)
    {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
        p[i] = i + 1;
    }

    printf("\nEnter Priority for each process (smaller number = higher priority):\n");
    for(i = 0; i < n; i++)
    {
        printf("P%d: ", i + 1);
        scanf("%d", &pri[i]);
    }

    for(i = 0; i < n; i++)
    {
        for(k = i + 1; k < n; k++)
        {
            if(pri[i] > pri[k])
            {
                temp = pri[i];
                pri[i] = pri[k];
                pri[k] = temp;

                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;

                temp = p[i];
                p[i] = p[k];
                p[k] = temp;
            }
        }
    }

    wt[0] = 0;

    for(i = 1; i < n; i++)
    {
        wt[i] = 0;
        for(j = 0; j < i; j++)
        {
            wt[i] += bt[j];
        }
    }
    for(i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];

        total_wt += wt[i];
        total_tat += tat[i];
    }

    avg_wt = (float)total_wt / n;
    avg_tat = (float)total_tat / n;

    printf("\n-------------------------------------------------------------\n");
    printf("Process\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    printf("-------------------------------------------------------------\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n",
               p[i], bt[i], pri[i], wt[i], tat[i]);
    }

    printf("-------------------------------------------------------------\n");
    printf("Average Waiting Time = %.2f\n", avg_wt);
    printf("Average Turnaround Time = %.2f\n", avg_tat);

    return 0;
}
