#include<stdio.h>

float max_profit(int profit[],int weight[],float profit_weight[],int max_weight){
      for(int i=0;i<7-1;i++){
        for(int j=i+1;j<7;j++){
          if(profit_weight[j] > profit_weight[i]){  // profit weight in decreasing order
            float temp = profit_weight[j];
            profit_weight[j] = profit_weight[i];
            profit_weight[i] = temp;
          
        
    // profit in decreasing order
          int temp1 = profit[j];
          profit[j] = profit[i];
          profit[i] = temp1;
        
         // weight in decreasing order
          int temp2 = weight[j];
          weight[j] = weight[i];
          weight[i] = temp2;
          }
      }
    }
      float max_profit = 0;
      int remaining_wt = max_weight;
      
      for(int i=0;i<7;i++){
        if(remaining_wt >= weight[i]){

          max_profit+= profit[i];
          remaining_wt-= weight[i];
        }
        else{
          max_profit += profit[i] * ((float)remaining_wt/weight[i]);      
          break;  // fraction lene ke baad full hojata hai knapsack
        }           
      }
  return max_profit;
}

int main(){
//  int obj[7] = {1,2,3,4,5,6,7};  No need to take this
  int profit[7] = {5,10,15,7,8,9,4};
  int weight[7] = {1,3,5,4,1,3,2}; 
  float profit_weight[7];
  
  for(int i=0; i<7;i++){
     profit_weight[i] = (float)profit[i]/weight[i];  
  }
printf("P/W Ratio :- ");
for(int i=0;i<7;i++){
  printf(" %.2f ",profit_weight[i]);
}
int max_weight = 15;

float result = max_profit(profit,weight,profit_weight,max_weight);
printf("\nTotal Profit = %.2f",result);
}