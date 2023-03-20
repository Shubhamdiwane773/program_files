#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int queue[MAX];
int rear=-1;
int front=-1;
int enqueue()
{
	if(rear==MAX-1)
	{
		printf("queue underflow\n");
		return 0;
	}
	if(front==-1)
		front=0;
	rear=rear+1;
	printf("enter the data\n");
	scanf("%d",&queue[rear]);
}
int dequeue()
{
	if(front==-1 || front==rear+1)
	{
		printf("queue overflow\n");
		return 0;
	}
	printf("%d element is dequeue\n",queue[front]);
	front=front+1;
}
int peek()
{
	if(front==-1 || front==rear+1)
	{
		printf("queue underflow\n");
		return 0;
	}
	printf("%d is peek element\n",queue[front]);
}
int print()
{
	int i;
	if(front==-1 || front==rear+1)
	{
		printf("queue underflow\n");
		return 0;
	}
	printf("queue element is\n");
	for(i=front;i<=rear;i++)
		printf("%d ",queue[i]);
	printf("\n");
}
int main()
{
	int choice;
	while(1)
	{
		printf("1.enqueue 2. dequeue 3.peek 4.print 5.exit\n");
		printf("enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: enqueue();
				break;
			case 2: dequeue();
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
