#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *link;
}P;
P *top=NULL;
int push() // add_beg logic
{
	P *temp=(struct node*)malloc(sizeof(struct node));
	printf("enter data\n");
	scanf("%d",&temp->data);
	temp->link=top;
	top=temp;
}
int pop()// delete first element logic
{
	if(top==NULL)
	{
		printf("stack underflow\n");
		return 0;
	}
	P *temp=NULL;
	printf("pop item is=%d\n",top->data);
	temp=top;
	top=top->link;
	free(temp);
}
int print()
{
	P *temp=top;
	if(top==NULL)
	{
		printf("stack underflow\n");
		return 0;
	}
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->link;
	}
	printf("\n");
}
int peek()
{
	if(top==NULL)
	{
		printf("stack underflow\n");
		return 0;
	}
	printf("The top element is=%d\n",top->data);
}
int main()
{
	int choice;
	while(1)
	{
		printf("1.push 2.pop 3.peek 4.print 5.exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: push();
				break;
			case 2: pop();
				break;
			case 3: peek();
				break;
			case 4: print();
				break;
			case 5: exit(0);
			default: printf("wrong choice. enter correct choice\n");
		}
	}
}
