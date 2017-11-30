#include<stdio.h>
#include<string.h>
#define N 100
struct call
{
	char name[20];
	char telephone[11];
	char type[20];
}cl[N];
int n;
void input ()
{
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("please input NO.%d information:\n",i+1);
		scanf("%s %s %s",cl[i].name,cl[i].telephone,cl[i].type);
	}
}
void show ()
{
	int i;
	printf("**********information**********\n");
	for(i=0;i<n;i++)
	{
		printf("%s-----%s-----%s",cl[i].name,cl[i].telephone,cl[i].type);
		printf("\n");
	}
}
void query ()
{
	int i;
	char a[20];
	printf("please input a search item:");
	scanf("%s",a);
	for(i=0;i<n;i++)
	{
		if(strcmp(a,cl[i].name)==0)
		{
			printf("%s-----%s",cl[i].telephone,cl[i].type);	
			printf("\n");
		}
		if(i==n-1&&strcmp(a,cl[i].name)!=0)	
			printf("error!");	
	} 	
}
void das ()
{
	int i,j;
	char a[20];
	printf("please input a delete item:");
	scanf("%s",a);
	for(i=0;i<n;i++)
	{
		if(strcmp(a,cl[i].name)==0)
			for(j=0;j<n;j++)
			{
				cl[i]=cl[i+1];
			}	
	}
	for(i=0;i<n-1;i++)
	{
		printf("%s-----%s-----%s",cl[i].name,cl[i].telephone,cl[i].type);
		printf("\n");
	}
}
void atas ()
{
	int i;
	printf("please input a add to item:");
	scanf("%s %s %s",cl[n].name,cl[n].telephone,cl[n].type);
	for(i=0;i<n+1;i++)
	{
		printf("%s-----%s-----%s",cl[i].name,cl[i].telephone,cl[i].type);
		printf("\n");
	}
}
void group ()
{
	int i;
	char a[20];
	printf("please input a group:");
	scanf("%s",a);
	for(i=0;i<n;i++)
	{
		if(strcmp(a,cl[i].type)==0)
		{
			printf("%s-----%s",cl[i].name,cl[i].telephone);	
			printf("\n");
		}	
	} 
}
int main ()
{
	int choice;
	printf("please input the number of people:");
	input();
	show();
	for(;;)
	{
		printf("\t\t\t\tplease select function:\n");
		printf("1.Query \t2.Delete and Show \t3.Add to and Show \t4.group \t5.break\n");
		printf("Your choice is:(number)");
		scanf("%d",&choice);
		if(choice==1) query();
		else if(choice==2)
		{
			das();
			n--;
		} 
		else if(choice==3)
		{
			atas();
			n++;
		}
		else if(choice==4) group();
		else
		{
			printf("break!");
			break;
		}
	}
}
