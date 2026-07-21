#include<stdio.h>
#include<stdlib.h>

void accept(int arr[10][10],int m,int n){
	printf("Enter the elements of the array: \n");
	for(int i=0; i<m; i++){
 		for(int j=0;j<n;j++){
         		scanf("%d",&arr[i][j]);
         }
        }
   }
   
void display(int arr[10][10],int m, int n){
	printf("Displaying elements:\n");
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%d ",arr[i][j]);
          }
          printf("\n");
        }
     }
     
void compact_form(int sparse_matrix[10][10],int compact_form[10][10],int m, int n){
	compact_form[0][0]=m;
	compact_form[0][1]=n;
	int k=1;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(sparse_matrix[i][j]!=0){
				compact_form[k][0]=i;
				compact_form[k][1]=j;
				compact_form[k][2]=sparse_matrix[i][j];
				k++;
			}
		}
	}
	compact_form[0][2]=k-1;
	printf("Printing compact form of sparse matrix:\n");
	display(compact_form,k,3);
}

void simple_transpose(int compact_form[10][10], int simple_t_matrix[10][10]){
	int m=compact_form[0][0];
	int n=compact_form[0][1]; 
	int t=compact_form[0][2];

	simple_t_matrix[0][0]=n;
	simple_t_matrix[0][1]=m;
	simple_t_matrix[0][2]=t;
	
	if(t<=0){
		return;
	}
	
	int q=1;
	for(int col=0;col<n;col++){
		for(int p=1;p<=t;p++){
			if(compact_form[p][1]==col){
				simple_t_matrix[q][0]=compact_form[p][1];
				simple_t_matrix[q][1]=compact_form[p][0];
				simple_t_matrix[q][2]=compact_form[p][2];
				q=q+1;
			}
		}
	}
	printf("Printing transpose form of compact matrix using simple transpose: ");
	display(simple_t_matrix, t+1, 3);
}

void fast_transpose(int compact_form[10][10], int fast_t_matrix[10][10]){
	
	int m=compact_form[0][0];
	int n=compact_form[0][1];
	int t=compact_form[0][2];
	
	fast_t_matrix[0][0]=n;
	fast_t_matrix[0][1]=m;
	fast_t_matrix[0][2]=t;
	
	int S[n];
	int T[n];
	
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
		fast_t_matrix[T[j]][0]=compact_form[i][1];
		fast_t_matrix[T[j]][1]=compact_form[i][0];
		fast_t_matrix[T[j]][2]=compact_form[i][2];
		T[j]=T[j]+1;
	}
	
	printf("Printing transpose form of compact matrix using fast transpose: ");
	display(fast_t_matrix, t+1,3);
	
}

void compact_addition(int A[10],int B[10], int C[10]){
	if((A[0][0]==B[0][0]) && (A[0][1]==B[0][1])){
		if((t1==0) && (t2==0)){
			return;
		}
	}
	C[0][0]=A[0][0];
	C[0][1]=A[0][1];
	
	int i,j,k;
	i=j=k=1;
	while((i<=t1) && (j<=t2)){
		if(A[i][0]==B[j][0]){
			if(A[i][1]==B[j][1]){
				int temp=A[i][2]+B[j][2];
				if(temp!=0){
					C[k][0]=A[i][0];
					C[k][1]=A[i][1];
					C[k][2]=temp;
					k=k+1;
				}
				i=i+1;
				j=j+1;
			}else if(A[i][1]<B[j][1]){
				C[k][0]=A[i][0];
				C[k][1]=A[i][1];
				C[k][2]=A[i][2];
				k=k+1;
				i=i+1;
			}else if(A[i][1]>B[j][1]){
				C[k][0]=B[j][0];
				C[k][1]=B[j][1];
				C[k][2]=B[j][2];
				k=k+1;
				j=j+1;
			}
		}else if(A[i][0]<B[j][0]){
		
	
	
	

int main(){
     	
    	 int sparse_matrix[10][10];
    	 int compact_matrix[10][10];
    	 int simple_transposed_matrix[10][10];
    	 int fast_transposed_matrix[10][10];
    	 int m,n;
    	 printf("Enter the number of rows and columns for matrix : ");
    	 scanf("%d %d", &m,&n);
    	 accept(sparse_matrix,m,n);
    	 
    	 int ch;
    	 while(1){
    	 
    	 printf("\n");
    	 printf("1 to display sparse matrix\n");
    	 printf("2 to display compact form of sparse matrix\n");
    	 printf("3 to display transpose using simple transpose\n");
    	 printf("4 to display transpose using fast transpose\n");
    	 printf("5 to exit\n");
    	 printf("Enter the operation to be performed\n");
    	 scanf("%d",&ch);
    	 printf("\n");
    	 
    	 	switch(ch){
    	 		case 1:
    	 			display(sparse_matrix,m,n);
    	 			break;
    	 		case 2:
    	 			compact_form(sparse_matrix,compact_matrix,m,n);
    	 			break;
    	 		case 3:
    	 			simple_transpose(compact_matrix,simple_transposed_matrix);
    	 			break;
    	 		case 4:
    	 			fast_transpose(compact_matrix,fast_transposed_matrix);
    	 			break;
    	 		case 5:
    	 			return 0;
    	 			break;
    	 		}
    	 	}




}
