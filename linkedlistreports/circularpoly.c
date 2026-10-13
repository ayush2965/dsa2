#include <math.h>
#include <stdlib.h>
#include <stdio.h>
struct poly{
    int coef;
    int exp;
    struct poly*next;
};

void create(struct poly * head){

	char ch='Y';
	struct poly*curr;
	struct poly*prev=head;
	do{
		curr = (struct poly*)malloc(sizeof(struct poly));
		printf("\nEnter the coefficient and power: ");
		scanf("%d %d",&curr -> coef, &curr->exp);
                curr->next = head;
		prev->next = curr;
		prev = curr;
		printf("Do you want to add more terms? (Y/N): ");
		scanf(" %c", &ch);
		printf("\n");
				
	}while(ch=='Y');
			
}
void display(struct poly * head){
	struct poly*curr;
	curr = head->next;
	while(curr!= head){
		if(curr->coef==0){
                    curr = curr -> next;
                    continue;
                }else if(curr->coef >0){
                    printf("+ %d",curr->coef);
                }else{
                    printf("- %d",abs(curr->coef));
                }

                if(curr->exp==1){
                    printf("x");
                }else if(curr->exp>1){
                    printf("x^%d",curr->exp);
                }
                
		curr = curr->next;
                printf(" ");
	}

		
    
}

int eval(struct poly * head, int value){
	struct poly*curr;
	curr = (struct poly*)malloc(sizeof(struct poly));
	curr = head->next;
	int sum=0;
	while(curr != head){
		sum += curr->coef*(pow(value,curr->exp));
		curr = curr->next;
	}
	return sum;
}
		
	

void add(struct poly*head1, struct poly*head2){

	struct poly*head3;
	struct poly*t1;
	struct poly*t2;
	struct poly*t3;
	struct poly*temp;
	head3 = (struct poly*)malloc(sizeof(struct poly));
	head3 -> exp = -1;
	head3 -> next = head3;
	t3 = head3;
	t1 = head1 -> next;
	t2 = head2 -> next;
	while(t1->exp != -1 || t2->exp != -1){
		if(t1->exp == t2->exp){
			temp = (struct poly*)malloc(sizeof(struct poly));
			temp->coef = t1->coef + t2 -> coef;
			temp->exp = t1->exp;
			t3->next = temp;
			temp->next = head3;
			t3 = temp;
			t1 = t1->next;
			t2 = t2->next;
		}else if(t1->exp > t2->exp){
			temp = (struct poly*)malloc(sizeof(struct poly));
			temp->coef = t1->coef;
			temp->exp = t1->exp;
			t3->next = temp;
			temp->next = head3;
			t3 = temp;
			t1 = t1->next;
		}else{
			temp = (struct poly*)malloc(sizeof(struct poly));
			temp->coef = t2 -> coef;
			temp->exp = t2->exp;
			t3->next = temp;
			temp->next = head3;
			t3 = temp;
			t2 = t2->next;
		}
	}
	display(head3);
	
} 
int main() {
    int val;
    int ch;
    
   	while(1){
   		printf("\n");
   		printf("1 for polynomial addition\n");
   		printf("2 for polynomial evaluation\n");
   		printf("3 for exit\n");
   		printf("Enter your choice: ");
   		scanf("%d",&ch);
   		printf("\n");
   		printf("\n");
   		switch(ch){
   			
   			case 1:
   				struct poly*head1;
    				struct poly*head2;
    				head1=(struct poly*)malloc(sizeof(struct poly));
    				head2=(struct poly*)malloc(sizeof(struct poly));
    				head1->exp = -1;
    				head2->exp = -1;
    				printf("Creating first polynomial: \n");
   				create(head1);
   				printf("Creating second polynomial: \n");
   				create(head2);
   				printf("Polynomial 1: ");
   				display(head1);
   				printf("\n");
   				printf("Polynomial 2: ");
   				display(head2);
   				printf("\n");
   				printf("Addition: ");
   				add(head1,head2);
   				
   				break;
   			
   			case 2:
   				struct poly*head3;
    				head3=(struct poly*)malloc(sizeof(struct poly));
   				create(head3);
   				printf("Enter the value:");
   				scanf("%d",&val);
   				int ans=eval(head3,val);
   				printf("\nEvaluated answer: %d",ans);
   				break;
   			
   			case 3:
   				printf("Program Over");
   				return 0;

		}
	}
		
}
