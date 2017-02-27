#include<stdio.h>
#include<conio.h>
#include<math.h>
#define SIZE 20
struct stack
{
	int a[SIZE];
	int top;
}st1,st2,st3;
void push1(int item)
{
	st1.a[++st1.top]=item;
}
int pop1()
{
	int item;
	return(item=st1.a[st1.top--]);
}
void push2(int item)
{
	st1.a[++st2.top]=item;
}
int pop2()
{
	int item;
	return(item=st2.a[st2.top--]);
}
void push3(int item)
{
	st1.a[++st3.top]=item;
}
int pop3()
{
	int item;
	return(item=st3.a[st3.top--]);
}
int main()
{
	st1.top=-1;st2.top=-1;st3.top=-1;
	int n,i,moves;
	puts("Enter the number of discs: ");
	scanf("%d",&n);
	moves=(pow(2,n)-1);
	for(i=n;i>=1;i--)
	push1(i);//first stack is filled as n,n-1,n-2,......,3,2,1
	for(i=1;i<=moves;i++)//each oop iteration stands for one move
	{
		if((i%3)==1) //condtion for source to destination and vice-versa
		{
			if((st1.a[st1.top]<st3.a[st3.top])||(st3.top==-1))
			{
				push3(pop1());
				puts("Move from S to D.");
			}
			else
			{
				push1(pop3());
				puts("Move from D to S.");
			}
		}
		else if((i%3)==0)//condition for dest to aux and vice versa
		{
			if(st2.a[st2.top]<st3.a[st3.top] || st3.top==-1)
			{
				push3(pop2());
				puts("Move from A to D.");
			}
			else
			{
				push2(pop3());
				puts("Move from D to A.");
			}
		}
		else if((i%3)==2)
		{
			if(st2.a[st2.top]<st1.a[st1.top])
			{
				push1(pop2());
				puts("Move from S to A.");
			}
			else
			{
				push2(pop1());
				puts("Move from A to S.");
			}
		}
	}
	return 0;
}
