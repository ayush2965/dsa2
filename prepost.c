#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define size 20
int top=-1;
char stk[size][size];

void emptystr(char *arr){
	for(int i=0;i<size;i++){
		arr[i]='\0';
	}
}

	
int isempty(){
	
	if(top==-1){
		return 1;
	}else{
		return 0;
	}

}

int isfull(){
	
	if(top==(size-1)){
		return 1;
	}else{
		return 0;
	}

}

void display(){

	if(isempty()){
		printf("No elements in stack\n");
	}else{

		printf("Stack: \n");
		for(int i=0;i<=top;i++){
			printf("%c ",stk[i]);
		}
	}

}

void push(char elem[]){

	if(isfull()){
		printf("Stack Full / Overflow Condition\n");
	}else{
		strcpy(stk[++top],elem);
	}
	
}

void pop(char*postfixstr){
	
	
	if(isempty()){
		printf("Stack Empty / Underflow Condition\n");
	}else{
		strcpy(postfixstr,stk[top]);
		top--;
		//printf("Pop Operation performed succesfully\n");

		
	}
	
}

void post_in(char *E,char*E1){
	int length =strlen(E);
	char op1[20];
	char op2[20];
	char x;
	for(int i=0;i<length;i++){
		x=E[i];
		char temp[2];
		temp[0]=x;
		temp[1]='\0';
		
		if(isalpha(x)==1){
			push(temp);
		}else{
			pop(op2);
			pop(op1);
			strcpy(E1,"(");
			strcat(E1,op1);
			strcat(E1,temp);
			strcat(E1,op2);
			strcat(E1,")");
			push(E1);
		}
	}
}

void post_pre(char *E,char*E1){
	int length =strlen(E);
	char op1[20];
	char op2[20];
	char x;
	for(int i=0;i<length;i--){
		x=E[i];
		char temp[2];
		temp[0]=x;
		temp[1]='\0';
		
		if(isalpha(x)==1){
			push(temp);
		}else{
			pop(op2);
			pop(op1);
			strcpy(E1,temp);
			strcat(E1,op1);
			strcat(E1,op2);
			push(E1);
		}
	}
}

void pre_in(char *E,char*E1){
	int length =strlen(E);
	char op1[20];
	char op2[20];
	char x;
	for(int i=length-1;i>=0;i--){
		x=E[i];
		char temp[2];
		temp[0]=x;
		temp[1]='\0';
		
		if(isalpha(x)==1){
			push(temp);
		}else{
			pop(op1);
			pop(op2);
			strcpy(E1,"(");
			strcat(E1,op1);
			strcat(E1,temp);
			strcat(E1,op2);
			strcat(E1,")");
			push(E1);
		}
	}
}


void pre_post(char *E,char*E1){
	int length =strlen(E);
	char op1[20];
	char op2[20];
	char x;
	for(int i=length-1;i>=0;i++){
		x=E[i];
		char temp[2];
		temp[0]=x;
		temp[1]='\0';
		
		if(isalpha(x)==1){
			push(temp);
		}else{
			pop(op1);
			pop(op2);
			strcpy(E1,op1);
			strcat(E1,op2);
			strcat(E1,temp);
			push(E1);
		}
	}
}


			


	

int main(){
	char ip[size];
	char op[size];	
	
	int ch;
	while(1){
	
		printf("1 for Postfix to Infix\n");
		printf("2 for Postfix to Prefix\n");
		printf("3 for Prefix to Infix\n");
		printf("4 for Prefix to Postfix\n");
		printf("5 to quit\n");
		printf("Enter the choice\n");
		scanf("%d",&ch);
		
		switch(ch){
		
			case 1:
				printf("Enter the postfix string: ");
				scanf(" %s", ip);
				post_in(ip,op);
				printf("Infix String is: %s\n",op);
				emptystr(ip);
				emptystr(op);
				break;
				
			case 2:
				printf("Enter the postfix string: ");
				scanf(" %s", ip);
				post_pre(ip,op);
				printf("Prefix String is: %s\n",op);
				emptystr(ip);
				emptystr(op);
				break;
				
			case 3:
				printf("Enter the prefix string: ");
				scanf(" %s", ip);
				pre_in(ip,op);
				printf("Infix String is: %s\n",op);
				emptystr(ip);
				emptystr(op);
				break;
				
			case 4:
				printf("Enter the prefix string: ");
				scanf(" %s", ip);
				pre_post(ip,op);
				printf("Postfix String is: %s\n",op);
				emptystr(ip);
				emptystr(op);
				break;
				
			case 5:
				printf("Program Over");
				return 0;
		}
	}
}
	

	
	
	
	
	
	/*int ch;
	while(1){
		
		printf("\n");
		printf("\n");
		printf("1 for push\n");
		printf("2 for pop\n");
		printf("3 to display top\n");
		printf("4 to display stack\n");
		printf("5 to exit\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		printf("\n");
		printf("\n");
		
		
		switch(ch){
			
			case 1:
			printf("Enter the element to be pushed: ");
			scanf(" %c",&element);
			push(element);
			break;
			
			case 2:
			pop();
			break;
			
			case 3:
			printf("Top element is: %c\n",stk[top]);
			break;
			
			case 4:
			display();
			break;
			
			case 5:
			printf("Program over\n");
			return 0;
			
		}
		
	}
	*/
