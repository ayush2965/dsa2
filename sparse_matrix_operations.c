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
  
  void compact_form(int sparse_matrix[10][10],int compact_matrix[10][10],int m, int n){
      compact_matrix[0][0]=m;
      compact_matrix[0][1]=n;
      int k=1;
      for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
              if(sparse_matrix[i][j]!=0){
                  compact_matrix[k][0]=i;
                  compact_matrix[k][1]=j;
                  compact_matrix[k][2]=sparse_matrix[i][j];
                  k++;
              }
          }
      }
      compact_matrix[0][2]=k-1;
      printf("Compact form of sparse matrix: ");
      display(compact_matrix,k,3);
  }
  
  void simple_transpose(int compact_form[10][10],int simple_transpose[10][10]){
      int m=compact_form[0][0];
      int n=compact_form[0][1];
      int t=compact_form[0][2];
      simple_transpose[0][0]=n;
      simple_transpose[0][1]=m;
      simple_transpose[0][2]=t;
      if(t<=0){
          return;
      }
      int q=1;
      for(int col=0;col<n;col++){
          for(int p=1;p<=t;p++){
              if(compact_form[p][1]==col){
                  simple_transpose[q][0]=compact_form[p][1];
                  simple_transpose[q][1]=compact_form[p][0];
                  simple_transpose[q][2]=compact_form[p][2];
                  q=q+1;
              }
          }
      }
      printf("Simple Transpose of Compact Form: ");
      display(simple_transpose,t+1,3);
  }
  
  void fast_transpose(int compact_form[10][10],int fast_transpose[10][10]){
      int m = compact_form[0][0];
      int n = compact_form[0][1];
      int t = compact_form[0][2];
      int S[n],T[n];
      fast_transpose[0][0] = n;
      fast_transpose[0][1] = m;
      fast_transpose[0][2] = t;
      if(t<=0){
          return;
      }
      for(int i=0;i<n;i++){
          S[i]=0;
          }
      for(int i=1;i<=t;i++){
          S[compact_form[i][1]]=S[compact_form[i][1]]+1;
      }
      T[0]=1;
      for(int i=1;i<n;i++){
          T[i]=T[i-1]+S[i-1];
      }
      for(int i=1;i<=t;i++){
          int j=compact_form[i][1];
          fast_transpose[T[j]][0]=compact_form[i][1];
          fast_transpose[T[j]][1]=compact_form[i][0];
          fast_transpose[T[j]][2]=compact_form[i][2];
          T[j]=T[j]+1;
      }
      
      printf("Fast Transpose of Compact Form: ");
      display(fast_transpose,t+1,3);
  }
  
 int main(){
     
    printf("Main Function\n");
    int sparse[10][10], m,n,compact[10][10],simple_transposed_form[10][10],fast_transposed_form[10][10];
    printf("Enter number of rows: ");
    scanf("%d",&m);
    printf("Enter number of columns: ");
    scanf("%d",&n);
    printf("Sparse Matrix : ");
    accept(sparse,m,n);
    compact_form(sparse,compact,m,n);
    simple_transpose(compact,simple_transposed_form);
    fast_transpose(compact,fast_transposed_form);
    

  return 0;
  
 }
  
  
  
