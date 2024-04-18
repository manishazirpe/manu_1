#include<stdio.h>
#include<stdlib.h>
int main()
{
int R[100],i,n,TotalHeadMoment=0,initial;
printf("Enter the total number of requests:\n");
scanf("%d",&n);
printf("Enter the request numbers:\n");
for(i=0;i<n;i++)
scanf("%d",&R[i]);
printf("Enter initial head position:\n");
scanf("%d",&initial);
for(i=0;i<n;i++)
{
TotalHeadMoment=TotalHeadMoment+abs(R[i]-initial);
initial=R[i];
}
printf("Total Head Moment is:%d\n",TotalHeadMoment);
return 0;
}

