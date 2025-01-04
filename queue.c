#include<stdio.h>
#include<stdlib.h>
#define size 10
int queue[size];
int front=-1,rear=-1;
void main()
{
void insertq(int);
int deleteq();
int searchq(int);
int data,opt,tfront,ans;
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
case 1:printf("data:");
scanf("  %d",&data);
insertq(data);
break;
case 2:data=deleteq();
if(data!=-1)
printf("delete item is :  %d",data);
break;
case 3:
printf("\n item  serached:");
scanf("%d",&data);
ans=searchq(data);
if(ans==1)
printf("found the searched item");
else
printf("not found the searched item");
break;
case4:exit(0);
}
}
while(1);
}
void insertq(int item)
{
if(rear==size-1)
printf("queue is found \n");
else 
queue[++rear]=item;
}
int deleteq()
{
if(front==rear)
{
printf("queue in empty \n");
return -1;
}
else
return queue[++front];
}

int searchq(int item)
{
if(front==rear)
return 0;
int tfront=front+1;
while(tfront!=rear&& queue[tfront]!=item)
++tfront;
if(queue[tfront]==item)
return 1;
return 0;
}


