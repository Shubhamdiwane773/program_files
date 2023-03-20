#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *link;
}P;
P*head=NULL;
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
	P *temp=malloc(sizeof(struct node)),*ptr=head;
	while(ptr->link!=NULL)
		ptr=ptr->link;
	printf("enter the data\n");
	scanf("%d",&temp->data);
	temp->link=NULL;
	ptr->link=temp;
}
int print()
{
	P*ptr=head;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->link;
	}
	printf("\n");
}
int cnt_node()
{
	P *ptr=head;
	int cnt=0;
	while(ptr!=0)
	{
		cnt++;
		ptr=ptr->link;
	}
	printf("number of node=%d\n",cnt);
}
int reverse()
{
	P *ptr=head,*next=NULL,*prev=NULL;
	while(ptr!=NULL)
	{
		next=ptr->link;
		ptr->link=prev;
		prev=ptr;
		ptr=next;
	}
	head=prev;
}
int middle_element()
{
	P *hp=head,*lp=head;
	while(hp!=NULL && hp->link!=NULL)
	{
		hp=hp->link->link;
		lp=lp->link;
	}
	printf("middle element is=%d\n",lp->data);
}
int delete_middle()
{
	P *lp=head,*hp=head,*ptr=head;
	while(hp!=NULL && hp->link!=NULL)
	{
		hp=hp->link->link;
		lp=lp->link;
	}
	printf("The middle element is =%d\n",lp->data);
	while(ptr->link!=lp)
		ptr=ptr->link;
	ptr->link=lp->link;
}
int add_middle()
{
	P *hp=head,*lp=head,*ptr=head,*temp=malloc(sizeof(struct node));
	while(hp!=NULL && hp->link!=NULL)
	{
		hp=hp->link->link;
		lp=lp->link;
	}
	printf("The middle element is=%d\n",lp->data);
	while(ptr->link!=lp)
		ptr=ptr->link;
	printf("enter the element\n");
	scanf("%d",&temp->data);
	temp->link=lp;
	ptr->link=temp;
}
int add_pos()
{
	P *temp=malloc(sizeof(struct node)),*ptr=head;
	int cnt=1,pos;
	printf("enter the position where u want to add the new element\n");
	scanf("%d",&pos);
	printf("enter the data\n");
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
int main()
{
	add_beg();
	add_end();
	add_end();
	add_end();
	add_end();
	print();
	cnt_node();
	reverse();
	print();
	middle_element();
	delete_middle();
	print();
	add_middle();
	print();
	add_pos();
	print();
}
