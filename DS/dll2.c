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
	printf("enter the data\n");
	scanf("%d",&temp->data);
	temp->next=head;
	temp->prev=NULL;
	head=temp;
}
int add_end()
{
	P *temp=malloc(sizeof(struct node)),*ptr=head;
	printf("enter the data\n");
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
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}
int add_after()
{
	int item;
	P *temp=malloc(sizeof(struct node)),*ptr=head;
	printf("enter item after u want to add \n");
	scanf("%d",&item);
	printf("enter the data\n");
	scanf("%d",&temp->data);
	while(ptr!=NULL)
	{
		if(ptr->data==item)
		{
			temp->next=ptr->next;
			temp->prev=ptr;
			ptr->next=temp;
		if(ptr->next!=NULL)
			ptr->next->prev=temp;
		}
		ptr=ptr->next;
	}
}
int add_before()
{
	P *temp=malloc(sizeof(struct node)),*ptr=head;
	int item;
	printf("enter the item before u want to add\n");
	scanf("%d",&item);
	printf("enter the data\n");
	scanf("%d",&temp->data);
	while(ptr!=NULL)
	{
		if(ptr->data==item)
		{
			temp->next=ptr;
			temp->prev=ptr->prev;
			ptr->prev->next=temp;
			ptr->prev=temp;
		}
		ptr=ptr->next;
	}
}

int main()
{
	add_beg();
	add_end();
	add_end();
	add_end();
	add_end();
	add_beg();
	print();
	add_after();
	print();
	add_before();
	print();
}
