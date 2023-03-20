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
	P *temp=(struct node*)malloc(sizeof(struct node));
	printf("enter data\n");;
	scanf("%d",&temp->data);
	temp->link=head;
	head=temp;
}
int add_end()
{
	P *temp=(struct node*)malloc(sizeof(struct node)),*ptr=head;
	printf("enter the data\n");
	scanf("%d",&temp->data);
	while(ptr->link!=NULL)
		ptr=ptr->link;
	temp->link=NULL;
	ptr->link=temp;
}
int print()
{
	P *ptr=head;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->link;
	}
	printf("\n");
}
int reverse()
{
	P *prev=NULL,*next=NULL,*ptr=head;
	while(ptr!=NULL)
	{
		next=ptr->link;
		ptr->link=prev;
		prev=ptr;
		ptr=next;
	}
	head=prev;
	printf("reverse list is:\n");
}
int delete()
{
	P *ptr=head,*temp;
	int item,flag;
	printf("enter the item which u want to delete\n");
	scanf("%d",&item);
	if(head->data==item)
	{
		flag++;
		temp=head;
		head=head->link;
		free(temp);
	}
	ptr=head;
	while(ptr->link!=NULL)
	{
		if(ptr->link->data==item)
		{
			flag++;
			temp=ptr->link;
			ptr->link=ptr->link->link;
			free(temp);
		}
		ptr=ptr->link;
	}
	if(flag==0)
		printf("item is not found \n");

}
int main()
{
	add_beg();
	add_end();
	add_end();
	add_end();
	add_end();
	print();
	reverse();
	print();
	delete();
	print();
}
