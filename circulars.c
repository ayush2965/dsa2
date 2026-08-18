#include<stdio.h>
#include <stdlib.h>

#define n 5

int front=0;
int rear=0;

struct printer_queue{

	int job_id;
	char title[20];
	
};




void display(struct printer_queue q[]){
	
	int i=(front+1)%n;
	printf("Queue:\n");
	printf("JobId   Title\n");
	while(i!=rear){
		printf("%d    %s    %d",q[i].job_id, q[i].title,i);
		printf("\n");
		i=(i+1)%n;
		
	}	

	/*
	printf("Queue:\n");
	printf("JobId   Title\n");
	int i=(front+1)%n;
	while(i<=rear){
		printf("%d    %s ",q[i].job_id, q[i].title);
		printf("\n");
		i=(i+1)%n;
	}
	*/
	
}


void enqueue(struct printer_queue q[], struct printer_queue element){
	
	if((rear+1)%n==front){
		printf("Queue is full (Overflow Condition)\n");
	}else{
		rear=(rear+1)%n;
		q[rear]=element;
	}
}


void dequeue(struct printer_queue q[]){
	
	if(front==rear){
		printf("Queue is empty (Underflow Condition)\n");
	}else{
		front=(front+1)%n;
		printf("Removed element at index %d\n",front);
	}
}
		
int main(){
	
	struct printer_queue queue[n];
	struct printer_queue elem;
	int ch;
	while(1){
	
		printf("\n");
		printf("1 for enqueue\n");
		printf("2 for dequeue\n");
		printf("3 for display\n");
		printf("4 for exit\n");
		printf("Enter the choice: ");
		scanf("%d", &ch);
		printf("\n");
		
		switch(ch){
			
			case 1:
			printf("Enter the job id and title: ");
			scanf("%d %s",&elem.job_id, elem.title);
			enqueue(queue,elem);
			break;
			
			case 2:
			dequeue(queue);
			printf("Dequeue performed successfully\n");
			break;
			
			case 3:
			display(queue);
			break;
			
			case 4:
			printf("Program Over");
			return 0;
			
		}
	}
}
			
			
		
		
		
	
