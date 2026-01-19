#include<stdio.h>
int main(){
int bt[10],wt[10],tat[10],ct[10],at[10],pid[10];
int n ,i,j,temp;
float avg_wt = 0,avg_tat=0;        
printf("Enter the number of processes : ");
scanf("%d",&n);

for(i = 0; i<n ; i++){
printf("Enter the ID for Process%d ",i+1);
scanf("%d",&pid[i]);
printf("Enter the arrival time for Process%d ",i+1);
scanf("%d",&at[i]);
printf("Enter the burst time for Process%d ",i+1);
scanf("%d",&bt[i]);
}

for(i=0 ; i< n-1 ;i++){
  for(j=i+1 ; j<n ; j++){
      if(at[i] > at[j]){

        temp = pid[i];       // swap process id
        pid[i] = pid[j];
        pid[j] = temp;

        temp = at[i];      // swap arrival time
        at[i] = at[j];
        at[j] = temp;

        temp = bt[i];   // swap burst time
        bt[i] = bt[j];
        bt[j] = temp;
      }    
  }
}

// completion time

ct[0] = at[0] + bt[0];

for(i=1 ; i<n ;i++){
  if(ct[i-1] < at[i]){
    ct[i] = at[i] + bt[i];  // CPU is idle
  }else{
    ct[i] = ct[i-1] + bt[i];
  }
}
for(i=0 ; i<n ; i++){
tat[i] = ct[i] - at[i];
wt[i] = tat[i] - bt[i];
}
for(i=0;i<n;i++){
  avg_tat = avg_tat + tat[i];
  avg_wt = avg_wt + wt[i];
}

printf("\nProcess\tBT\tWt\tTT\tCT\tAT\n");
for(i=0 ; i<n ;i++){
  printf("P%d\t%d\t%d\t%d\t%d\t%d\n",pid[i],bt[i],wt[i],tat[i],ct[i],at[i]);
}
printf("\nAverage Waiting Time = %.2f",avg_wt/n);
printf("\nAverage Turnaround Time = %.2f",avg_tat/n);



  return 0;
}