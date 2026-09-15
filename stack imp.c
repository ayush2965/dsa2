#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define size 20
int top=-1;
char stk[size];
void emptystr(char arr[20]){
	for(int i=0;i<size;i++){
		arr[i]='\0';
	}
}
		
void reverse(char *arr){
	
	int len = strlen(arr)-1;
	int start =0;
	char temp;
	while (start<len){
		temp=arr[start];
		arr[start]=arr[len];
		arr[len]=temp;
		start++;
		len--;
	}
}

int icp_post(char ch){
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

int isp_post(char ch){
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

int icp_pre(char ch){
	if(ch=='+' || ch== '-'){
		return 1;
	}
	if(ch=='*' || ch== '/'){
		return 2;
	}
	if(ch=='^'){
		return 3;
	}
	if(ch==')'){
		return 5;
	}else{
		return 0;
	}
}

int isp_pre(char ch){
	if(ch=='+' || ch== '-'){
		return 1;
	}
	if(ch=='*' || ch== '/'){
		return 2;
	}
	if(ch=='^'){
		return 4;
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
		//printf("Pop Operation performed succesfully\n");
		return elem;
		
	}
	
}

void infix_to_postfix(char infix[], char postfix[]){
	
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
					while(!isempty() && isp_post(stk[top])>=icp_post(tkn)){
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
	printf("Postfix String: %s\n",postfix);

}

void infix_to_prefix(char infix[], char prefix[]){

	reverse(infix);

	int i = 0;
	int k=0;
	char tkn=infix[i];
	
	while(tkn!='\0'){
	
		if(isalpha(tkn)){
			prefix[k]=infix[i];
			k++;
		}else{
			if(tkn==')'){
				push(')');
			}else{
				if(tkn=='('){
					while((tkn=pop())!=')'){
						prefix[k]=tkn;
						k++;
					}
				}else{
					while(!isempty() && isp_pre(stk[top])>icp_pre(tkn)){
						prefix[k]=pop();
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
		prefix[k]=pop();
		k++;
	}
	reverse(prefix);
	printf("Prefix String: %s\n",prefix);
	
}

	
	

int main(){

	char postfix[size];
	char prefix[size];
	char infix[size];	
	
	
	int ch;
	while(1){
		printf("\n");
		printf("\n");
		printf("1 to covert infix to prefix\n");
		printf("2 to convert infix to postfix\n");
		printf("3 to exit\n");
		printf("Enter your choice: ");
		
		scanf("%d",&ch);
		
		switch(ch){
		
			case 1:
			top=-1;
			emptystr(infix);
			emptystr(prefix);
			printf("Enter the infix string: ");
			scanf(" %s",infix);
			infix_to_prefix(infix,prefix);
			break;
			
			case 2:
			top=-1;
			emptystr(infix);
			emptystr(postfix);
			printf("Enter the infix string: ");
			scanf(" %s",infix);
			infix_to_postfix(infix,postfix);
			break;
			
			case 3:
			printf("Program over\n");
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
