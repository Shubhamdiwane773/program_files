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
	P *ptr=head,*temp=(struct node*)malloc(sizeof(struct node));
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
	P*temp=malloc(sizeof(struct node)),*ptr=head;
	int item,flag=0;
	printf("enter the item after u want to add data\n");
	scanf("%d",&item);
	while(ptr!=NULL)
	{
		if(ptr->data==item)
		{
			flag++;
			printf("enter the data\n");
			scanf("%d",&temp->data);
			temp->next=ptr->next;
			temp->prev=ptr;
			ptr->next=temp;
			if(ptr->next!=NULL)
				ptr->next->prev=temp;
		}
		ptr=ptr->next;
	}
	if(flag==0)
		printf("item is not found\n");
}
int add_before()
{
	P *temp=malloc(sizeof(struct node)),*ptr=head;
	int item,flag=0;
	printf("enter the item before u want to add data\n");
	scanf("%d",&item);
	while(ptr!=NULL)
	{
		if(ptr->data==item)
		{
			flag++;
			printf("enter data\n");
			scanf("%d",&temp->data);
			temp->next=ptr;
			temp->prev=ptr->prev;
			ptr->prev->next=temp;
			ptr->prev=temp;
		}
		ptr=ptr->next;
	}
	if(flag==0)
		printf("item is not found\n");
}
int reverse()
{
	P *p1=head,*p2=head->next;
	p1->next=NULL;
	p1->prev=p2;
	while(p2!=NULL)
	{
		p2->prev=p2->next;
		p2->next=p1;
		p1=p2;
		p2=p2->prev;
	}
	head=p1;
	printf("Reverse list is:\n");
}
int delete()
{
	P *ptr=head,*temp;
	int item,flag=0;
	printf("enter the item which u want to delete\n");
	scanf("%d",&item);
	if(head->data==item)
	{
		flag++;
		temp=head;
		head=head->next;
		free(temp);
	}
	ptr=head;
	while(ptr->next!=NULL)
	{
		if(ptr->data==item)
		{
			flag++;
			ptr->next->prev=ptr->prev;
			ptr->prev->next=ptr->next;
		}
		ptr=ptr->next;
	}
	if(ptr->data==item)
	{
		flag++;
		ptr->prev->next=NULL;
	}
	if(flag==0)
		printf("item is not found\n");
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
	reverse();
	print();
	delete();
	print();
}
