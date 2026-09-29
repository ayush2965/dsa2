
/*
 * Assignment: Singly Linked List Operations (student records)
 *
 * Complete every function marked TODO. Do NOT change main() or the
 * input/output format - your program is graded automatically.
 *
 * The list uses a header node: head->next is the first record,
 * head->next == NULL means the list is empty.
 *
 * INPUT: one command per line (no prompts are printed)
 *   C n                 create a new list from the next n lines "regno name"
 *                       (any existing list is freed first)
 *   I pos regno name    insert at position pos (1 = front, len+1 = end)
 *   D pos               delete the record at position pos (1..len)
 *   P                   print the list
 *   L                   print the number of records
 *   R                   reverse the list (by changing pointers)
 *   S                   sort ascending by regno (by relinking nodes,
 *                       NOT by swapping data)
 *   M n                 read n more records (already sorted by regno) and
 *                       merge them into the current (sorted) list
 *   Q                   quit
 *
 * OUTPUT:
 *   P  ->  "101:Asha -> 102:Ravi -> 105:Meera"   or   "EMPTY"
 *   L  ->  the length, e.g. "3"
 *   I / D with an invalid position print "INVALID"
 *   All other commands print nothing.
 *
 * Names contain no spaces and are at most 19 characters.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 20

typedef struct node {
    int regno;
    char name[NAME_LEN];
    struct node *next;
} node;

/* Allocate and return an empty list (header node, next = NULL). */
node *new_list(void)
{
        struct node* head;
	head=(struct node*)malloc(sizeof(struct node));
	head -> next = NULL;
	return head;
}

/* Number of records in the list (header not counted). */
int length(node *head)
{
	
    	struct node *curr;
	int len=0;
	if(head -> next == NULL){
		return 0;
	}
	curr = head -> next;
	while(curr!=NULL){
		len++;
		curr = curr -> next;
	}
	return len;
}

/* Free every record node; keep the header and leave the list empty. */
void clear_list(node *head)
{
    /* TODO */
}

/* Add a record at the end of the list. */
void append(node *head, int regno, const char *name)
{
   
    struct node*curr;
    curr=head;
    node*newnode= (struct node*)malloc(sizeof(struct node));
    newnode->regno=regno;
    strcpy(newnode->name,name);
    newnode->next=NULL;
    while(curr->next!=NULL){

    		curr=curr->next;
    		
    	}
    	curr -> next = newnode;
    }

/* Insert at 1-based position pos. Return 1 on success, 0 if pos is invalid. */
int insert_at(node *head, int pos, int regno, const char *name)
{
  /*  int i=1;
    curr = (struct node*)malloc(sizeof(struct node));
    int k=length();
    if(pos>(k+1)){
    	return 0;
    	
    }else{
    	while((curr!=NULL)&&(i<pos)){
    		i++;
    		curr=curr->next;
    		
    	}
    	
    		*/
    
}

/* Delete record at 1-based position pos. Return 1 on success, 0 if invalid. */
int delete_at(node *head, int pos)
{
    /* TODO */
    return 0;
}

/* Print the list in the exact format described above. */
void display(node *head)
{
	struct node* curr;
	curr = head -> next;
	while(curr !=NULL){
		printf("%d:%s", curr -> regno, curr ->name);
		printf(" -> ");
		curr = curr -> next;
	}
	printf("\n");
}

/* Reverse the list in place by changing next pointers. */
void reverse(node *head)
{
    /* TODO */
}

/* Sort ascending by regno by relinking nodes. */
void sort_list(node *head)
{
    /* TODO */
}

/* Merge sorted list head2 into sorted list head1 (result in head1).
 * Reuse the existing nodes; leave head2 empty afterwards. */
void merge(node *head1, node *head2)
{
    /* TODO */
}

/* ---------------- provided - do not modify ---------------- */
void read_records(node *head, int n)
{
    int i, regno;
    char name[NAME_LEN];

    for (i = 0; i < n; i++) {
        if (scanf("%d %19s", &regno, name) != 2)
            return;
        append(head, regno, name);
    }
}

int main(void)
{
    node *list = new_list(), *other = new_list();
    char cmd[4];
    int n, pos, regno;
    char name[NAME_LEN];

    while (scanf("%3s", cmd) == 1) {
        switch (cmd[0]) {
        case 'C':
            scanf("%d", &n);
            clear_list(list);
            read_records(list, n);
            break;
        case 'I':
            scanf("%d %d %19s", &pos, &regno, name);
            if (!insert_at(list, pos, regno, name))
                printf("INVALID\n");
            break;
        case 'D':
            scanf("%d", &pos);
            if (!delete_at(list, pos))
                printf("INVALID\n");
            break;
        case 'P': display(list); break;
        case 'L': printf("%d\n", length(list)); break;
        case 'R': reverse(list); break;
        case 'S': sort_list(list); break;
        case 'M':
            scanf("%d", &n);
            clear_list(other);
            read_records(other, n);
            merge(list, other);
            break;
        case 'Q':
            clear_list(list); clear_list(other);
            free(list); free(other);
            return 0;
        default:
            printf("UNKNOWN\n");
        }
    }
    clear_list(list); clear_list(other);
    free(list); free(other);
    return 0;
}





/*		#include<stdio.h>
		#include <stdlib.h>
		struct stud{
			int reg_no;
			char name[20];
			struct stud*next;
		};



		void create(struct stud * head){

			char ch='Y';
			struct stud*curr;
			struct stud*prev=head;
			do{
				curr=(struct stud*)malloc(sizeof(struct stud));
				curr -> next = NULL;
				printf("Enter the registration number and the name of the student: ");
				scanf("%d %s",&curr -> reg_no, curr->name);
				prev -> next = curr;
				prev= curr;
				printf("Do you want to add more records? (Y/N): ");
				scanf(" %c", &ch);
				printf("\n");
				
			}while(ch=='Y');
			
		}
			
		void display(struct stud * head){
			printf("reg_no    name \n");
			struct stud * curr;
			curr = head -> next;
			while(curr -> next != NULL){
				printf("%d         %s   ", curr -> reg_no, curr ->name);
				printf("\n");
				curr = curr -> next;
			}

		}

		int length(struct stud * head){
			struct stud *curr;
			int len=0;
			if(head -> next == NULL){
				return 0;
			}
			curr = head -> next;
			while(curr!=NULL){
				len++;
				curr = curr -> next;
			}
			return len;
		}
			
		int main(){

			struct stud * head;
			head=(struct stud*)malloc(sizeof(struct stud));
			head -> next = NULL;
			create(head);
			display(head);
			int l = length(head);
			printf("%d",l);
			
		}
*/
