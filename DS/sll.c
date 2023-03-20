#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *link;
}P;
P *head=NULL;
int add_beg()
{
	P *temp=malloc(sizeof(struct node));
	printf("enter the data\n");
	scanf("%d",&temp->data);
	temp->link=head;
	head=temp;
}
int add_end()
{
	P *temp=malloc(sizeof(struct node)), *ptr=head;
	while(ptr->link!=NULL)
		ptr=ptr->link;
	printf("enter the data\n");
	scanf("%d",&temp->data);
	temp->link=NULL;
	ptr->link=temp;
}
int print()
{
	P *ptr=head;
	while(ptr)
	{
		printf("%d ",ptr->data);
		ptr=ptr->link;
	}
}

	
int main()
{
	add_beg();
	add_end();
	add_end();
	add_end();
	add_end();
	print();
}
