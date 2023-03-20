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
	while(ptr->next!=NULL)
		ptr=ptr->next;
	printf("enter the data\n");
	scanf("%d",&temp->data);
	temp->next=NULL;
	temp->prev=ptr;
	ptr->next=temp;
}
int add_after()
{
	int item;
	P *temp=malloc(sizeof(struct node)),*ptr=head;
	printf("enter the item after u want to add data\n");
	scanf("%d",&item);
	while(ptr!=NULL)
	{
		if(ptr->data==item)
		{
			printf("enter the data\n");
			scanf("%d",&temp->data);
			temp->next=ptr->next;
			temp->prev=ptr;
			ptr->next=temp;
		}
		ptr=ptr->next;
	}
}
int add_before()
{
	int item;
	P *temp=malloc(sizeof(struct node)),*ptr=head;
	printf("enter the item before u want to add data\n");
	scanf("%d",&item);
	while(ptr!=NULL)
	{
		if(ptr->data==item)
		{
			printf("enter the data\n");
			scanf("%d",&temp->data);
			temp->next=ptr;
			temp->prev=ptr->prev;
			ptr->prev->next=temp;
			ptr->prev=temp;
		}
		ptr=ptr->next;
	}
}
int delete()
{
	int item;
	P *ptr=head;
	printf("enter the item which u want to delete\n");
	scanf("%d",&item);
	if(head->data==item)
	{
		head=head->next;
		head->prev=NULL;
	}
	ptr=head;
	while(ptr->next!=NULL)
	{
		if(ptr->data==item)
		{
			ptr->next->prev=ptr->prev;
			ptr->prev->next=ptr->next;
		}
		ptr=ptr->next;
	}
	if(ptr->data==item)
		ptr->prev->next=NULL;
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
int reverse()
{
	int item;
	P *p1=head,*p2=head->next;
	p1->next=NULL;
	p2->prev=p2;
	while(p2!=NULL)
	{
		p2->prev=p2->next;
		p2->next=p1;
		p1=p2;
		p2=p2->prev;
	}
	head=p1;
}

int main()
{
	add_beg();
	add_end();
	add_end();
	add_end();
	add_end();
	print();
	add_after();
	print();
	add_before();
	print();
	delete();
	print();
	reverse();
	print();
}
