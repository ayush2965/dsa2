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
      
     void multiply(int arr1[10][10], int arr2[10][10],int m1, int n1, int m2, int n2){ 
     int product[10][10];
     
     printf("Multiplication of the two matrices: \n");
     for (int i=0; i < m1 ; i++){
         for(int j=0; j < n2 ; j ++){
           product[i][j]=0;
            for(int k=0 ; k<n1 ; k++){
               product[i][j]+=arr1[i][k]*arr2[k][j];
            }
           }
         }
         display(product,m1,n2);
        }
      
 int main(){
 printf("Main Function\n");
 int a[10][10], m1,n1,m2,n2, b[10][10];
 printf("Enter number of rows of matrix 1: ");
 scanf("%d",&m1);
 printf("Enter number of columns of matrix 1: ");
 scanf("%d",&n1);
  printf("Enter number of rows of matrix 2: ");
 scanf("%d",&m2);
 printf("Enter number of columns of matrix 2: ");
 scanf("%d",&n2);
 printf("Matrix 1: ");
  accept(a,m1,n1);
  display(a,m1,n1);
  printf(" Matrix 2: ");
  accept(b,m2,n2);
  display(b,m2,n2);
  
  int ch;
 while(1){ 
    printf("\n");
    printf("1 for Addition\n");
    printf ("2 for Subtraction\n");
    printf("3 for Multiplication\n");
    printf("4 for Transpose\n");
    printf("5 for Exit\n");
    printf("Enter your choice: \n");
    scanf("%d",&ch);
    printf("\n");
    
    switch(ch){
      case 1: 
         if(m1!=m2||n1!=n2){
             printf("Addition not possible\n");
         }else{
         addition(a,b,m1,n1);
         }
         break;
      case 2:
         if(m1!=m2||n1!=n2){
             printf("Subtraction not possible\n");
         }else{
         subtract(a,b,m1,n1);
         }
         break;
      case 3 :
         if(n1!=m2){
             printf("Multiplication not possible\n");
         }else{
         multiply(a,b,m1,n1,m2,n2);
         }
         break;
      case 4 : transpose(a,m1,n1);
        break;
      case 5: exit(0);
  
        }
     }
     return 0;
  
 }
  
  
  
