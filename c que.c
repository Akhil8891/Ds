#include<stdio.h>
#include<stdlib.h>
#define size 3
int queue[size];
int front=0,rear=0;
void main()
{
void insertq(int);
int deleteq();
int searchq(int);
int data,opt;
do
{
printf("\n 1.insert \n");
printf("2.delete\n");
printf("3.search\n");
printf("4.exit\n");
printf("your option:");
scanf(  "%d",&opt);
switch(opt)
{
case 1:printf("enter your data:");
scanf("  %d",&data);
insertq(data);
break;
case 2:data=deleteq(); 

if(data!=-1)
printf("delete item = :  %d \n",data);
break;
case 3:printf(" item to search:");
scanf("%d",&data);

if(searchq(data))
printf("founded the searched item");
else
printf("the searched item not found");

break;
case4:exit(0);
}
}
while(1);
}

void insertq(int item)
{
int trear=(rear+1)%size;
if(trear==front)
{
printf("queue is full");
}
else
{ 
rear=trear;
queue[rear]=item;
}
}

int deleteq()
{
if(front==rear)
{
printf("queue is empty");
return -1;
}
else
{
front=(front+1)%size;

}
return queue[front];
}

int searchq(int item)
{
if(front==rear)
return 0;

int tfront;
tfront=(front+1);
while(tfront!=rear && queue[tfront]!=item)
tfront=(tfront+1)%size;

if(queue[tfront]==item)
return 1;
return 0;
}

