#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define size 20
int top=-1;
char stk[size];
char postfix[size];
char infix[size];

int icp(char ch){
	if(ch=='+' || ch== '-'){
		return 1;
	}
	if(ch=='*' || ch== '/'){
		return 2;
	}
	if(ch=='^'){
		return 4;
	}
	if(ch=='('){
		return 5;
	}else{
		return 0;
	}
}

int isp(char ch){
	if(ch=='+' || ch== '-'){
		return 1;
	}
	if(ch=='*' || ch== '/'){
		return 2;
	}
	if(ch=='^'){
		return 3;
	}else{
		return 0;
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

void push(char elem){

	if(isfull()){
		printf("Stack Full / Overflow Condition\n");
	}else{
		top=top+1;
		stk[top]=elem;
	}
	
}

char pop(){
	
	char elem;
	
	if(isempty()){
		printf("Stack Empty / Underflow Condition\n");
	}else{
		elem=stk[top];
		top = top-1;
		printf("Pop Operation performed succesfully\n");
		return elem;
		
	}
	
}

void infix_to_postfix(){
	
	int i = 0;
	int k=0;
	char tkn=infix[i];
	
	while(tkn!='\0'){
	
		if(isalpha(tkn)){
			postfix[k]=infix[i];
			k++;
		}else{
			if(tkn=='('){
				push('(');
			}else{
				if(tkn==')'){
					while((tkn=pop())!='('){
						postfix[k]=tkn;
						k++;
					}
				}else{
					while(!isempty() && isp(stk[top])>=icp(tkn)){
						postfix[k]=pop();
						k++;
					}
					push(tkn);
				}
			}
		}
		i++;
		tkn=infix[i];
	}
	while(!isempty()){
		postfix[k]=pop();
		k++;
	}

}

int main(){

	printf("Enter the infix string: ");
	scanf(" %s",infix);
	printf("%s",infix);
	infix_to_postfix();
	printf("%s",postfix);
	
	
	
	
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
}
