#include <stdio.h>
#include <stdlib.h>

void accept(int arr[10][10],int m, int n){
printf("Type elements here: ");
for(int i=0; i < m; i++){
   for(int j=0;j < n; j++){
     scanf("%d",&arr[i][j]);
     }
    }
 }

 void display(int arr[10][10],int m, int n){
 printf("Displaying elements: \n");
  for(int i=0;i < m ; i++){
     for(int j=0 ; j< n ;j++){
        printf(" %d", arr[i][j]);
        }
        printf("\n");
      }
  }
 void saddle_point(int arr[10][10], int m, int n){
     int min;
     int max;
     int min_value_index;
     for(int i=0;i<m;i++){
         min=arr[i][0];
         min_value_index=0;
         for(int j=0;j<n;j++){
             if(arr[i][j]<min){
                 min=arr[i][j];
                 min_value_index=j;
             }
         }
         max=arr[0][min_value_index];
         for(int k=0;k<m;k++){
             if(arr[k][min_value_index]>max){
                 max=arr[k][min_value_index];
             }
         }
          if(max==min){
              printf("Saddle Point is %d",max);
              return;
          }
          
         }
         printf("No Saddle Point");
     
 }

int main() {
    int matrix[10][10], m,n;
    printf("Enter number of rows: ");
    scanf("%d",&m);
    printf("Enter number of columns: ");
    scanf("%d",&n);
    accept(matrix,m,n);
    display(matrix,m,n);
    saddle_point(matrix,m,n);
    return 0;
}
