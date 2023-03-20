#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int stack[MAX];
int top=-1;
int print()
{
	int i;
	if(top==-1)
	{
		printf("stack underflow\n");
		return 0;
	}
	printf("stack element is\n");
	for(i=top;i>=0;i--)
		printf("%d ",stack[i]);
	printf("\n");
}
int push()
{
	int data;
	if(top==MAX-1)
	{
		printf("stack overflow\n");
		return 0;
	}
	top=top+1;
	printf("enter the data\n");
	scanf("%d",&data);
	stack[top]=data;
}
int pop()
{
	int data;
	if(top==-1)
	{
		printf("stack underflow\n");
		return 0;
	}
	data=stack[top];
	top=top-1;
	printf("%d element is pop\n",data);
}
int peek()
{
	int data;
	if(top==-1)
	{
		printf("stack underflow\n");
		return 0;
	}
	data=stack[top];
	printf("The element at the top is=%d\n",data);
}
/*
int main()
{
	print();
	push();
	push();
	push();
	push();
	print();
	peek();
	pop();
	pop();
	print();
	peek();
	print();
}*/
int main()
{
	int choice;
	while(1)
	{
	       	printf("1.push 2.pop 3.peek 4.print 5.exit \n");
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
			default : printf("wrong choice . enter correct choice\n");
		}
	}
}
