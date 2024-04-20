

#include<stdio.h>
void main()
{
   int n , m , i , j , k , proc=-1, flag=1, rpn, grant=1, f=0;
   printf("Enter the no.of processes : ");
   scanf("%d",&n);
   printf("Enter the no.of resources : ");
   scanf("%d",&m);
   int allocation[n][m], max[n][m], available[m],need[n][m],finish[n],work[m],sequence[n], 
   request[m];
   
   printf("Enter the allocation matrix :");
   for(i=0; i<n; i++)
     for(j=0; j<m; j++)
     scanf("%d",&allocation[i][j]);
     
     printf("\n*** Allocation matrix ***\n");
     for(i=0; i<n; i++)
     {
         for(j=0; j<m ; j++)
         printf("\t%d",allocation[i][j]);
         printf("\n");   
     }
     
     printf("Enter the max matrix :");
   for(i=0; i<n; i++)
     for(j=0; j<m; j++)
     scanf("%d",&max[i][j]);
     
     printf("\n*** max matrix ***\n");
     for(i=0; i<n; i++)
     {
         for(j=0; j<m ; j++)
         printf("\t%d",max[i][j]);
         printf("\n");       
     }
     
     printf("Enter the available matrix : ");
     for(i=0; i<m; i++)
     {
         scanf("%d",&available[i]);
         work[i]=available[i];
     }
     printf("\n***Available matrix***\n");
     for(i=0; i<m; i++)
     printf("\t%d",available[i]);
     printf("\n\n");
     
     printf("\n IS there any request?[1/0] : ");
     scanf("%d",&f);
     if(f)
     {
       printf("\nEnter process no : ");
       scanf("%d",&rpn);
       printf("\nEnter request : ");
       for(i=0; i<m; i++)
       scanf("%d",&request[i]);
       
       printf("\n***Request matrix for process P %d ***\n",rpn);
       for(i=0; i<m; i++)
       printf("\t%d",request[i]);
       printf("\n");
     }
     
     //calculating need matrix
     for(i=0; i<n; i++)
       for(j=0; j<m; j++)
       need[i][j]=max[i][j]-allocation[i][j];
       
       //printing need matrix
       printf("\n*** Need matrix***\n");
       for(i=0; i<n; i++)
       {
           for(j=0; j<m; j++)
           printf("\t%d",need[i][j]);
           printf("\n");
       }
       
       for(i=0; i<n; i++)
       finish[i]=0;
     
     //Banker Algo
     outer:
     for(i=0; i<n; i++)
     {
       if(finish[i]==0)
       {
          for(j=0; j<m; j++)
          {
             if(need[i][j] > work[j])
            flag=0;
          }
          if(flag==0)
          printf("\n Process P %d must wait \n Resource not available ....",i);
          else
          {
               printf("\n process P%d added",i);
               finish[i]=1;
               sequence[++proc]=i;
               for(k=0; k<m; k++)
               work[k]=work[k]+allocation[i][k];
          }
          flag=1;
       }
     }  
     for(i=0; i<n; i++)
     if(finish[i]==0)
     goto outer;
     
     printf("\n * safe sequence * \n");
     for(i=0; i<n; i++)
     printf("\t P%d",sequence[i]);
     printf("\n\n");
     
     //checking request for grantable or not
     for(i=0; i<m; i++)
     if(request[i]>need[rpn][i]  | request[i]>available[i])
     {
          grant=0;
          break;
     }
     if(grant==1)
     {
         printf("Request P%d can be granted immediately\n",rpn);
         for(i=0; i<m; i++)
         {
            available[i]=available[i]-request[i];
            allocation[rpn][i]=allocation[rpn][i]+request[i];
            need[rpn][i]=need[rpn][i]-request[i];
            work[i]=available[i];
         }
         for(i=0; i<n; i++)
         finish[i]=0;
         flag=1;
         proc=-1;
         
         //banker's algo
          outer2:
     for(i=0; i<n; i++)
     {
       if(finish[i]==0)
       {
          for(j=0; j<m; j++)
          {
             if(need[i][j] > work[j])
            flag=0;
          }
          if(flag==0)
          printf("\n Process P %d must wait \n Resource not available ....\n",i);
          else
          {
               printf("\n process P%d added",i);
               finish[i]=1;
               sequence[++proc]=i;
               for(k=0; k<m; k++)
               work[k]=work[k]+allocation[i][k];
          }
          flag=1;
       }
     }  
     for(i=0; i<n; i++)
     if(finish[i]==0)
     goto outer2;
     
      printf("\n * new safe sequence * \n");
     for(i=0; i<n; i++)
     printf("\t P%d",sequence[i]);
     printf("\n\n");
         
     }
     else
     printf("\n request P%d cannot be granted immediately\n\n",rpn);
}
