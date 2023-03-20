#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
}P;
P *head=NULL;
int add_beg()
{
	P *temp=malloc(sizeof(struct node));
	printf("enter your data\n");
	scanf("%d",&temp->data);
	temp->next=head;
	temp->prev=NULL;
	head=temp;
}
int add_end()
{
	P *temp=malloc(sizeof(struct node)),*ptr=head;
	printf("enter your data\n");
	scanf("%d",&temp->data);
	while(ptr->next!=NULL)
		ptr=ptr->next;
	temp->next=NULL;
	temp->prev=ptr;
	ptr->next=temp;
}
int print()
{
	P *ptr=head;
	while(ptr)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}
int main()
{
	add_beg();
	add_end();
	add_end();
	print();
}
