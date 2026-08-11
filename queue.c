#include<stdio.h>
#include <stdlib.h>

#define size 5

int front=-1;
int rear=-1;

struct printer_queue{

	int job_id;
	char title[20];
	
};

int isfull(){
	
	if(rear==size-1){
		return 1;
	}else{
		return 0;
		}
		
}

int isempty(){
	
	if(rear==front){
		return 1;
	}else{
		return 0;
	}
	
}


void display(struct printer_queue q[]){

	printf("Queue:\n");
	printf("JobId   Title\n");
	
	for(int i=front+1;i<=rear;i++){
		printf("%d    %s ",q[i].job_id, q[i].title);
		printf("\n");
	}
	
}

void enqueue(struct printer_queue q[], struct printer_queue n){
	
	if(isfull()){
		printf("Queue is full (Overflow Condition) \n");
	}else{
		rear=rear+1;
		q[rear]=n;
	}

}

void dequeue(struct printer_queue q[]){
	
	if(isempty()){
		printf("Queue is empty (Underflow Condition)\n");
	}else{
		front=front+1;
		printf("Queue element:  %d   %s  was deleted \n",q[front].job_id, q[front].title);
	}
	
}


int main(){

	struct printer_queue queue[size];
	struct printer_queue element;
	
	int ch;
	while(1){
		printf("\n");
		printf("1 for enqueue\n");
		printf("2 for dequeue\n");
		printf("3 to display queue\n");
		printf("4 to exit\n");
		printf("Enter the operation to be performed: ");
		scanf("%d",&ch);
		printf("\n");
		
		switch(ch){
			
			case 1:
				printf("Enter job to be enqueued: ");
				scanf("%d %s",&element.job_id, element.title);
				enqueue(queue,element);
				break;

			case 2:
				dequeue(queue);
				break;
				
			case 3:
				display(queue);
				break;
				
			case 4:
				printf("Program Over\n");
				return 0;
		}
	}				
	
}

