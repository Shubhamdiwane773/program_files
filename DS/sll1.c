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
	P *lp=head,*hp=head,*ptr=head;
	while(hp!=NULL && hp->link!=NULL)
	{
		lp=lp->link;
		hp=hp->link->link;
	}
	printf("the middle element is=%d\n",lp->data);
	while(ptr->link!=lp)
	{
		ptr=ptr->link;
	}
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
        printf("the middle element is=%d\n",lp->data);
        while(ptr->link!=lp)
        {
                ptr=ptr->link;
        }
	printf("enter the data\n");
	scanf("%d",&temp->data);
	temp->link=lp;
        ptr->link=temp;
}
int count()
{
	P *ptr=head;
	int cnt=0;
	while(ptr)
	{
		ptr=ptr->link;
		cnt++;
	}
	printf("the number of node is =%d\n",cnt);
}
int add_pos()
{
	P *temp=malloc(sizeof(struct node)),*ptr=head;
	int cnt=1,pos=0;
	printf("enter positon where u want to add data\n");
	scanf("%d",&pos);
	while(ptr->link!=NULL)
	{
		cnt++;
		if(cnt==pos)
		{
			printf("enter your data\n");
			scanf("%d",&temp->data);
			temp->link=ptr->link;
			ptr->link=temp;
		}
		ptr=ptr->link;
	}

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
}
int delete()
{
	int item;
	P *ptr=head,*temp;
	printf("enter item which u want to delete\n");
	scanf("%d",&item);
	if(head->data==item)
	{
		head=head->link;
	}
	ptr=head;
	while(ptr->link!=NULL)
	{
		if(ptr->link->data==item)
		{
			temp=ptr->link;
			ptr->link=ptr->link->link;
			free(temp);
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
	add_end();
	add_middle();
	print();
	delete_middle();
	print();
	count();
	add_pos();
	print();
	reverse();
	print();
	delete();
	print();
}
