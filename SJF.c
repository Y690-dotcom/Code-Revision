#include<stdio.h>
int main(){
int bt[10],wt[10],tat[10],pid[10];
float avg_wt = 0, avg_tat = 0;
int n,i,j,temp;
printf("Enter the number of processes : ");
scanf("%d",&n);
for(i=0;i<n;i++){
  printf("Enter the ID for process%d ",i+1);
  scanf("%d",&pid[i]);
  printf("Enter the burst time for process%d ",i+1);
  scanf("%d",&bt[i]);
}
for(i=0 ; i<n-1 ;i++){
  for(j = i+1 ; j<n ; j++){
    if(bt[i] > bt[j]){
      temp = bt[i];
      bt[i] = bt[j];
      bt[j] = temp;

      temp = pid[i];
      pid[i] = pid[j];
      pid[j] = temp;
    }
  }
}

wt[0] = 0;
for(i=1 ; i<n ;i++){
  wt[i] = wt[i-1] + bt[i-1];
}
for(i=0 ; i<n ;i++){
  tat[i] = bt[i] + wt[i];
}
for(i=0 ; i<n ;i++){
  avg_tat+= tat[i];
  avg_wt += wt[i];
}

printf("Process\tBT\tWT\tTT\n");
for(i=0 ; i<n ;i++){
  printf("P%d\t%d\t%d\t%d\n",pid[i],bt[i],wt[i],tat[i]);
}
printf("\nAverage waiting time = %f",avg_wt/n);
printf("\nAverage turnaround time = %f",avg_tat/n);
  return 0;

}