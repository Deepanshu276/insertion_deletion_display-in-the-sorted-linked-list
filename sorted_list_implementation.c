#include<stdio.h>
#include<stdlib.h>

//Create a Structure of Linked List.
struct node {
	int data;
	struct node* next;
};

// Q3. a)	Create a program to INSERT element by SORT.
struct node* sortedins(struct node* head)
{	
	struct node* nn; //Define new node we have to add.
	nn = (struct node*)malloc(sizeof(struct node));
	
	printf("Enter value you want to ADD : ");
	scanf("%d",&nn->data);//Assign a value we have to add.
	nn->next=NULL;

	if(head==NULL) // Condition for Empty Node.
	{	head=nn;
	}
	else if (head->next==NULL && head->data<=nn->data) // Condition For Addition in Single Node.
	{	head->next=nn;
	}
	else if (nn->data<head->data) // Condition For Addition in First Node if New Node in Value in Small by Sort.
	{	nn->next = head;
		head=nn;
	}
	else
	{	struct node* ptr;
		struct node* ptrp;
		ptr=head->next;
		ptrp=head;
		while(ptr->data < nn->data && ptr->next != NULL)// Check which element is greater than New element.
		{	ptrp=ptr;
			ptr=ptr->next;
		}
		if(ptr->next==NULL && ptr->data<=nn->data)//Condition For Addition In Last in Sort if doesn't find any value is less.
		{	ptr->next=nn;
		}
		else // Condition For Addition in Sorted Linked List
		{	ptrp->next=nn;
			nn->next=ptr;
		}
	}
	printf("---------Insertion Complete---------\n");
	return head;
}

// Q3. b)	Program to DELETE element in SORT by taking element from user which have to delete.
struct node* delsort(struct node* head)
{	int value,i;
	if(head==NULL)// Underflow Condition .
	{	printf("Linked List is Empty\n");	}
	else
	{	printf("Enter Value you want to DELETE : ");
		scanf("%d",&value);//Taking value from user which have to delete.
		struct node* ptr;
		ptr=head;
		if(ptr->next==NULL)// Condition For deletion By Sort  only single element
		{	if(ptr->data==value)// If element found
			{	head=NULL;
				i=1;
			}
			else // If element doesn't found
			{	i=2;
			}		
		}
		else if(head->data==value)// Condition For deletion if 1st element == value
		{	head=head->next;
			i=1;
		}
		else
		{	struct node* ptrp;
			ptr=head->next;
			ptrp=head;
			while(ptr->data!=value && ptr->next != NULL)// Condition For deletion By Sort check value is present in List or Not.
			{	ptrp=ptr;
				ptr=ptr->next;
			}
			if(ptr->next==NULL && ptr->data==value)// Condition For deletion if last element found.
			{	ptrp->next=NULL;
				i=1;
			}
			else if(ptr->next==NULL && ptr->data!=value) // //Condition for no element == value in list.
			{	i=2;
			}
			else //Condition For deletion By Sort element found.
			{	ptrp->next=ptr->next;
				i=1;
			}
		}
		if(i==1)
		{	free(ptr);
			printf("---------Deletion Complete---------\n");
		}
		else if(i==2)
		{	printf("No element found to delete\n");
		}
	}
	return head;
}

void display(struct node* head)
{	struct node* ptr;
	ptr=head;
	if(head==NULL)
		printf("\t\t\t\tLinked List : Empty");
	else
	{	printf("\t\t\t\tLinked List : ");
		while(ptr->next!=NULL)
		{	printf("%d,",ptr->data);
			ptr=ptr->next;
		}
		printf("%d",ptr->data);
	}
}

void seloperation()
{	struct node* head; // Basic Node
	head=NULL;//No Node
	
	int i;
	char c;
	
	printf("To Check Linked List is Empty or Not          < Press : '0' >.\n");
	printf("To Display Sorted Linked List                 < Press : '1' >.\n");
	printf("To Insertion in Sorted Linked List            < Press : '2' >.\n");
	printf("To Deletion in Sorted Linked List by Value    < Press : '3' >.\n");
	
	do
	{	printf("\n\nPress Key To Perform Operations : ");
		scanf("%d",&i);
		switch(i)
		{	case 0: display(head);
					break;
			case 1: display(head);
			 		break;
			case 2: head=sortedins(head);
		 			display(head);
		 			break;
			case 3: head=delsort(head);
		 			display(head);
		 			break;
			default:printf("You press different value.");
		 			break;	
		}
		fflush(stdin);
		printf("\nFor Continue...........\nPress 'Y' for Yes.\nOther-wise Press Any Key : ");
		scanf("%c",&c);
	}while(c=='Y' || c=='y');

}

// Our Main function
int main()
{	seloperation();
	return 0;
}
