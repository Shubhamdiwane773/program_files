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
	// temp->link=head;

}
int print()
{
	P *ptr=head;
	while(ptr->link!=head)
	{
		printf("%d ",ptr->data);
		ptr=ptr->link;
	}
}
int main()
{
	add_beg();
//	add_end();
//	add_end();
	print();
}
