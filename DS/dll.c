#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
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
	while(ptr->next!=NULL)
		ptr=ptr->next;
	printf("enter your data\n");
	scanf("%d",&temp->data);
	temp->prev=ptr;
	temp->next=NULL;
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
}
int main()
{
	add_beg();
	add_end();
	add_end();
	print();
}
