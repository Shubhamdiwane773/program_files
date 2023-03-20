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
	printf("enter your data\n");
	scanf("%d",&temp->data);
	temp->link=head;
	head=temp;
}
int add_end()
{
	P *temp=malloc(sizeof(struct node)),*ptr=head;
	while(ptr->link!=NULL)
		ptr=ptr->link;
	printf("enter your data\n");
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
	printf("\n");
}
int delete_middle()
{
	P *hp=head,*lp=head,*ptr=head;
	while(hp!=NULL && hp->link!=NULL)
	{
		hp=hp->link->link;
		lp=lp->link;
	}
	printf("middle element is= %d\n",lp->data);
	while(ptr->link!=lp)
		ptr=ptr->link;
	ptr->link=lp->link;
}
int add_middle()
{
	P *lp=head,*hp=head,*ptr=head,*temp=malloc(sizeof(struct node));
	while(hp!=NULL && hp->link!=NULL)
	{
		lp=lp->link;
		hp=hp->link->link;
	}
	printf("middle element is=%d\n",lp->data);
	while(ptr->link!=lp)
		ptr=ptr->link;
	printf("enter your data\n");
	scanf("%d",&temp->data);
	temp->link=lp;
	ptr->link=temp;
}
int add_position()
{
	P *ptr=head,*temp=malloc(sizeof(struct node));
	int pos=0,cnt=1;
	printf("enter the position where u want to add element\n");
	scanf("%d",&pos);
	printf("enter your data\n");
	scanf("%d",&temp->data);
	while(ptr->link!=NULL)
	{
		cnt++;
		if(cnt==pos)
		{
			temp->link=ptr->link;
			ptr->link=temp;
		}
		ptr=ptr->link;
	}
}
int reverse()
{
	P *next=NULL,*prev=NULL,*ptr=head;
	while(ptr!=NULL)
	{
		next=ptr->link;
		ptr->link=prev;
		prev=ptr;
		ptr=next;
	}
	head=prev;
}
int main()
{
	add_beg();
	add_end();
	add_end();
	add_end();
	add_end();
	print();
	delete_middle();
	print();
	add_middle();
	print();
	add_position();
	print();
	reverse();
	print();
}
