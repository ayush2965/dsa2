circul#include <math.h>
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
				curr=(struct poly*)malloc(sizeof(struct poly));
				printf("Enter the coefficient and power: ");
				scanf("%d %d",&curr -> coef, &curr->exp);
                curr -> next = head;
				prev -> next = curr;
				prev= curr;
				printf("Do you want to add more terms? (Y/N): ");
				scanf(" %c", &ch);
				printf("\n");
				
			}while(ch=='Y');
			
		}
void display(struct poly * head){
			printf("Polynomial:\n");
			struct poly * curr;
			curr = head -> next;
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
                
				curr = curr -> next;
                printf(" ");
			}

		
    
}
int main() {
    struct poly*head;
    head=(struct poly*)malloc(sizeof(struct poly));
    create(head);
    display(head);
    return 0;
}
