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
  
  void transpose(int arr[10][10], int m, int n){
  printf("Displaying transpose: \n");
  for(int i=0; i < m ; i++){
     for(int j=0 ; j< n ; j++){
       printf("%d", arr[j][i]);
       }
       printf("\n");
      }
    }
    
  void addition(int arr1[10][10],int arr2[10][10],int m, int n){
  int sum[10][10];
  printf("Addition of the two matrices: \n");
  for(int i=0; i < m ; i++){
     for(int j=0;j < n ; j++){
       sum[i][j]=arr1[i][j]+arr2[i][j];
       }
     }
     display(sum,m,n);
    }
    
    void subtract(int arr1[10][10], int arr2[10][10], int m, int n){
    int difference[10][10];
    printf("Subtraction of the two matrices: \n");
    for(int i=0; i < m; i++){
       for(int j=0; j <n ; j++){
         difference[i][j]=arr1[i][j]-arr2[i][j];
         }
       }
       display(difference,m,n);
      }
      
     void multiply(int arr1[10][10], int arr2[10][10],int m, int n){ 
     int product[10][10];
     
     printf("Multiplication of the two matrices: \n");
     for (int i=0; i < m ; i++){
         for(int j=0; j < n ; j ++){
           product[i][j]=0;
            for(int k=0 ; k<n ; k++){
               product[i][j]+=arr1[i][k]*arr2[k][j];
            }
           }
         }
         display(product,m,n);
        }
      
 int main(){
 printf("Main Function\n");
 int a[10][10], m,n, b[10][10];
 printf("Enter number of rows: ");
 scanf("%d",&m);
 printf("Enter number of columns: ");
 scanf("%d",&n);
 printf("Matrix 1: ");
  accept(a,m,n);
  display(a,m,n);
  printf(" Matrix 2: ");
  accept(b,m,n);
  display(b,m,n);
  
  int ch;
 while(1){ 
    printf("1 for Addition\n");
    printf ("2 for Subtraction\n");
    printf("3 for Multiplication\n");
    printf("4 for Transpose\n");
    printf("5 for Exit\n");
    printf("Enter your choice: \n");
   scanf("%d",&ch);
    switch(ch){
         case 1: addition(a,b,m,n);
         break;
         case 2: subtract(a,b,m,n);
         break;
         case 3 : multiply(a,b,m,n);
         break;
        case 4 : transpose(a,m,n);
        break;
        case 5: exit(0);
  
        }
     }
     return 0;
  
 }
  
  
  
