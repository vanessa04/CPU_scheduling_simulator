#include<stdio.h>

int main()


{
//at = arrival_times
//bt = burst_times
//ct = complete_time 
//tat = turn_around_time
//wt = waiting_time

int at[20],bt[20],ct[20],tat[20],wt[20],n,i,j;
float atat=0,awt=0,act=0;
printf("\nEnter the Number of processes: ");
scanf("%d",&n);
printf("\nEnter Arrival Time: ");

for(i=0;i<n;i++)
{  
printf("p[%d]",i+1);
scanf("%d",&at[i]);
}

printf("\nEnter burst time: ");

for(i=0;i<n;i++)
{
scanf("%d",&bt[i]);
}

ct[0]=bt[0];

printf("%d \n",ct[0]);

for(i=1;i<n;i++)
{
ct[i]=ct[i-1]+bt[i];
}

for(i=0;i<n;i++)
{
tat[i]=ct[i]-at[i];
wt[i]=tat[i]-bt[i];
}

printf("\nProcess\t\tAT\t\tBT\t\tCT\t\tTAT\tWT");

for(i=0;i<n;i++)
{
printf("\n p[%d]\t\t%d\t\t%d\t\t%d\t\t%d\t%d",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
act=act+ct[i];
awt=awt+wt[i];
atat=atat+tat[i];
}

act=act/n;
awt=awt/n;
atat=atat/n;
printf("\nThe average completion time is %f\n",act);
printf("The average waiting time is %f\n",awt);
printf("The avg turn around time is %f\n",atat);
 return 0;
}