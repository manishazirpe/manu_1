# include<stdio.h>
#include<stdlib.h>
int main()
{
    int Request[100],i,n,TotalHeadMoment=0,initial,count=0;
    printf("Enter the request:");
    scanf("%d",&n);
    printf("Enter Actual Request");
    for(i=0;i<n;i++)    
    scanf("%d",&Request[i]);
    printf("Enter the initial head ");
    scanf("%d",&initial);
    while(count!=n)
    {
        int min=1000,diff,index;
        for(i=0;i<n;i++)
        {
           diff=abs(Request[i]-initial);
           if(min>diff)
           {
               min=diff;
               index=i;
           }
        }
        TotalHeadMoment=TotalHeadMoment+min;
        initial=Reqest[index];
        Request[index]=1000;
        count++;
    }
    printf("Total head movement is %d",TotalHeadMoment);
}

