#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct file
{
	char name[10];
	int start;
	int size;
	int status;
}f[10];
struct node
{
	int info;
	char a[1];
	struct node *next;
	struct node *prev;
}*start,*temp,*new,*t,*s;

int fno=-1,sz,st,fb=0;
char fn[10];

char name[10];
int size,d;
int i,ch;

void createBlock()
{
	printf("Enter The Total Block Of Disk:  ");
	scanf("%d",&d);

	start=temp=NULL;
	for(i=0;i<d;i++)
	{
		new=(struct node *)malloc(sizeof(struct node));
		new->next=NULL;
		new->prev=NULL;
		strcpy(new->a,"F");
		new->info=i;

		if(start==NULL)
		{
			start=temp=new;
		}
		else
		{
			new->prev=temp;
			temp->next=new;
			temp=new;
		}
	}
}

void contain()
{
	temp=start;
	while(temp!=NULL)
	{
		printf("%d\t",temp->info);
		temp=temp->next;
	}
	temp=start;
	printf("\n");
	while(temp!=NULL)
	{
		printf("%s\t",temp->a);
		temp=temp->next;
	}
}

void add()
{
	printf("\nEnter File Name & Size : ");
	scanf("%s%d",&fn,&sz);

	fb=0;
	temp=start;
	while(temp!=NULL)
	{
		if(strcmp(temp->a,"A")==0)
		{
			fb=0;
		}
		if(strcmp(temp->a,"A")!=0)
		{
			if(fb==0)
			{
				s=temp;
				fb++;
			}
			else
				fb++;
		}
		if(fb==sz)
		{
			break;
		}
		temp=temp->next;
	}
	if(fb<sz)
	{
		printf("\nInefficiant Memory For File %s\n",fn);
		fb=0;
	}
	else
	{
		fno++;
		strcpy(f[fno].name,fn);
		f[fno].size=sz;
		f[fno].start=s->info;
		f[fno].status=1;
	}
	while(fb>0)
	{
		strcpy(s->a,"A");
		s=s->next;
		fb--;
	}
}

void delete()
{
	printf("Enter File name to delete: ");
	scanf("%s",&fn);
	for(i=0;i<=fno;i++)
	{
		if(strcmp(f[i].name,fn)==0)
		{
			sz=f[i].size;
			st=f[i].start;
			f[i].status=0;
			f[i].start=-1;
			break;
		}
	}
	temp=start;
	while(temp->next!=NULL)
	{
		if(temp->info==st)
		{
			break;
		}
		else
		{
			temp=temp->next;
		}
	}
	while(sz>0)
	{
		strcpy(temp->a,"F");
		temp=temp->next;
		sz--;
	}
}

void files()
{
	printf("\n____________________________________________________________\n");
	printf("FName\tSize\tStart\tStatus\n");
	printf("____________________________________________________________\n");
	{
		for(i=0;i<=fno;i++)
		{
			if(f[i].status!=0)
				printf("%s\t%d\t%d\t%d\n",f[i].name,f[i].size,f[i].start,f[i].status);
		}
	}
	printf("____________________________________________________________\n");

}

void main()
{
	do
	{
		printf("\n1: Create Bocks\n2: Add\n3: Delete\n4: Files\n"
						                     "5: Contains\n6: Exit");
		printf("\nEnter Your Choice: ");
		scanf("%d",&ch);

		switch(ch)
		{
		case 1:
			createBlock();	break;
		case 2:
			add();	break;
		case 3:
			delete();	break;
		case 4:
			files();	break;
		case 5:
			contain();	break;
		}
	}while(ch!=6);
}
