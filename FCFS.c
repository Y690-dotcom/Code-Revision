#include<stdio.h>
int main(){
int bt[10],wt[10],tat[10],at[10];
int n,i,j,temp;
float avg_wt=0,avg_tat=0;
printf("Enter the number of processes : ");
scanf("%d",&n);
for(i=0 ; i<n ; i++){
  printf("Enter the burst time for processes %d : ",i+1);
  scanf("%d",&bt[i]);
}
wt[0] = 0;
for(i=1 ;i<n ;i++){
  wt[i] = wt[i-1] + bt[i-1];
}
for(i=0 ; i<n ; i++){
  tat[i] = wt[i] + bt[i];
}

for(i=0 ;i<n ;i++){
avg_tat = avg_tat + tat[i];
avg_wt = avg_wt + wt[i];
}

printf("\nProcess\tBT\tWT\tTT\n");
for(i=0 ; i<n ;i++){
  printf("P%d\t%d\t%d\t%d\n",i+1,bt[i],wt[i],tat[i]);
}

printf("Average Waiting Time = %f",avg_wt/n);
printf("\nAverage Turnaround Time = %f",avg_tat/n);

return 0;
}