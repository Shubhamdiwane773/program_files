#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int stack[MAX];
int top=-1;
int push()
{
	int data;
	if(top==MAX-1)
	{
		printf("stack is overflow\n");
		return 0;
	}
	      top=top+1;
		printf("enter data\n");
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
	printf("%d item is pop\n",data);
}
int print()
{
	int i;
	if(top==-1)
		printf("stack underflow\n");
	else
	{
		printf("stack element is\n");
		for(i=top;i>=0;i--)
			printf("%d ",stack[i]);
		printf("\n");
	}
}
int peek()
{
	if(top==-1)
	{
		printf("stack underflow\n");
		return 0;
	}
	printf("The element at the top is =%d\n",stack[top]);
}

int main()
{
	print();
	push();
	print();
	push();
	print();
	push();
	push();
	pop();
	print();
	pop();
	print();
	peek();
	print();
}
