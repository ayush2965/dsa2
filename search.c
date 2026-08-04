#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
struct students{
	int roll_no;
	char name[20];
	float percentage; 
};
	

void accept(struct students database[10], int n){
	printf("Enter student details:\n");
	for(int i=0; i<n;i++){
	
		printf("Enter roll number, name and percentage of the student %d: ", i+1);
		scanf("%d %s %f", &database[i].roll_no, database[i].name, &database[i].percentage);
		
		}
				
}	

void display(struct students database[10], int n){ 

    printf("Roll Number               Name                 Percentage\n");
    
    for(int i=0;i<n;i++){
    	
        printf("%d                        %s                 %f\n",database[i].roll_no,database[i].name,database[i].percentage);
 
	}				
		
}


void linear_search( struct students database[10], int n,int key){
	
	int flag=1;
	printf("Executing linear search: \n");
	for(int i=0;i<n;i++){
	
		if(database[i].roll_no==key){
			printf("Student found:\n");
			printf("Roll Number: %d\n", database[i].roll_no);
			printf("Name: %s\n", database[i].name);
			printf("Percentage: %f\n", database[i].percentage);
			flag=0;
			break;
		}
	}
		
		if(flag==1){
			printf("Student was not found\n");
		}
		
}


void selection_sort(struct students database[10], int n){
    
    int minpos;
    for(int i=0;i<(n-1);i++){
        minpos=i;
        for(int j=(i+1);j<n;j++){
            if(database[j].percentage<database[minpos].percentage){
                minpos=j;
            }
        }
        if(minpos!=i){
            struct students temp=database[i];
            database[i]=database[minpos];
            database[minpos]=temp;
        }
        printf("Pass %d:\n",i+1);
    	display(database,n);
    }
    printf("Sorted in ascending order by percentage using selection sort:\n");
    display(database,n);
}


void insertion_sort(struct students database[10], int n){
    
    struct students key;
    for(int i=1;i<n;i++){
    	
        key=database[i];
        int j=i-1;
        while(j>=0 && strcmp(database[j].name,key.name)>0){
            database[j+1]=database[j];
            j=j-1;
        }
        database[j+1]=key;
        printf("Pass %d:\n",i);
    	display(database,n);
    }
    printf("Sorted in ascending order by name using insertion sort:\n");
    display(database,n);
}


void shell_sort(struct students database[10], int n){
    
    int k=1;
    int gap=n/2;
    int swapped;
    do{
        do{
            swapped=0;
            for(int i=0;i<n-gap;i++){
                if(database[i].roll_no>database[i+gap].roll_no){
                    struct students temp=database[i];
                    database[i]=database[i+gap];
                    database[i+gap]=temp;
                    swapped=1;
                }
            }
            
        }while(swapped==1);
        gap=gap/2;
        printf("Pass %d:\n",k);
    	display(database,n);
    	k++;
    	
    }while(gap>=1);
   	printf("Sorted in ascending order by percentage using shell sort:\n");
    display(database,n);
}


void binary_search(struct students database[10], int n, int key){
	
	int high=n-1;
	int low=0;
	int mid;
	int flag=1;
	printf("Executing normal binary search: \n");
	while(low<=high){
	
		mid=(low+high)/2;
		
		if(database[mid].roll_no==key){
			printf("\n");
			printf("Student found:\n");
			printf("Roll Number: %d\n", database[mid].roll_no);
			printf("Name: %s\n", database[mid].name);
			printf("Percentage: %f\n", database[mid].percentage);
			printf("\n");
			flag=0;
			break;
			
			
		}else if(key > database[mid].roll_no ){
			
			low=mid+1;
		
		}else{
			
			high=mid-1;
			
		}
		
	}
	if (flag==1){
		printf("\n");
		printf("Student Record not found.\n ");
		printf("\n");
	}
	
}

void recursive_binary_search(struct students database[10], int n, int low,int high, int key){
	
	int flag=1;
	if(low>high){
		printf("Student Record Not found\n");
		return;
		}
	
	int mid=(low+high)/2;
	if(database[mid].roll_no==key){
			printf("\n");
			printf("Student found:\n");
			printf("Roll Number: %d\n", database[mid].roll_no);
			printf("Name: %s\n", database[mid].name);
			printf("Percentage: %f\n", database[mid].percentage);
			printf("\n");
			flag=0;
	}else if(key > database[mid].roll_no ){
			recursive_binary_search(database,n,mid+1,high,key);
	}else{
			recursive_binary_search(database,n,low,mid-1,key);
			
	     }
}
	

int main(){
		
		struct students s[10];
		struct students sorts[10];
		int no_of_students;
		int key;
		
	
		printf("Enter the number of students: ");
		scanf("%d",&no_of_students);
	
		
		int ch;
		while(1){
			
			printf("\n");
			printf("\n");
			printf("1 for Linear Search\n");
			printf("2 for Normal Binary Search\n");
			printf("3 for Recursive Binary Search\n");
			printf("4 for Selection Sort\n");
			printf("5 for Insertion Sort\n");
			printf("6 for Shell Sort\n");
			printf("7 for Exit\n");
			printf("Enter your choice: ");
			scanf("%d",&ch);
			printf("\n");
			printf("\n");
			
			switch(ch){
				case 1:
					accept(s,no_of_students);
					printf("Enter key/roll number to be searched: ");
					scanf("%d", &key);
					linear_search(s,no_of_students,key);
					break;
				case 2:
					accept(s,no_of_students);
					shell_sort(s,no_of_students);
					printf("Enter key/roll number to be searched: ");
					scanf("%d", &key);
					binary_search(s,no_of_students,key);
					break;
				case 3:
					accept(s,no_of_students);
					shell_sort(s,no_of_students);
				    printf("Enter key/roll number to be searched: ");
					scanf("%d", &key);
					recursive_binary_search(s,no_of_students,0,no_of_students-1,key);
					break;
				case 4:
				    printf("Executing Selection Sort: \n");
				    selection_sort(sorts,no_of_students);
				    break;
				case 5:
				    printf("Executing Insertion Sort: \n");
				    insertion_sort(sorts,no_of_students);
				    break;
				case 6:
				    printf("Executing Shell Sort: \n");
				    shell_sort(sorts,no_of_students);
				    break;
				
				case 7:
					return 0;
			}
		}
		
		
	
}
