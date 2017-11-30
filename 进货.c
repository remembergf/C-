#include<stdio.h>
#include<stdlib.h>
#define N 10
struct date						
	{
		int year;
		int month;
		int day;
	};
struct appliance				
{
	char unitname[20];
	char telephone[11];
};
struct food							
{
	struct date a;
};
struct goods						
{
	char num[20];
	char name[20];
	struct date b; 
	int money;
	int quantity;
	char kind;						
	union 
	{
		struct appliance app;
		struct food fo;
	}type;
};
int main (void)
{	
	int i,j,n;
	struct goods go[N];
	printf("please input the number of good:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("please input number and name:\n");
		scanf("%s %s",go[i].num,go[i].name);
		printf("plesse input indate:\n");
		scanf(" %d %d %d",&go[i].b.year,&go[i].b.month,&go[i].b.day);
		printf("please input money and quantity:\n");
		scanf(" %d %d",&go[i].money,&go[i].quantity);
		printf("please input the kind of goods:\n");
		scanf(" %c",&go[i].kind);
		if(go[i].kind=='a'||go[i].kind=='A')
		{
			printf("please input unitname and telephone:\n");
			scanf(" %s %s",go[i].type.app.unitname,go[i].type.app.telephone);
		}
		else if(go[i].kind=='f'||go[i].kind=='F')
		{
			printf("please input date guarantee:\n");
			scanf(" %d %d %d",&go[i].type.fo.a.year,&go[i].type.fo.a.month,&go[i].type.fo.a.day);
		}
		else
		printf("input error!\n");
	}	
	printf("*****************************information******************************\n");
	for(i=0;i<n;i++)
	{
		printf("NO.%s\t%s",go[i].num,go[i].name);
		printf("\t%d-%d-%d",go[i].b.year,go[i].b.month,go[i].b.day);
		printf("\t%d\t%d",go[i].money,go[i].quantity);
		if(go[i].kind=='a'||go[i].kind=='A')
			printf("\t%s\t%s",go[i].type.app.unitname,go[i].type.app.telephone);
		else if(go[i].kind=='f'||go[i].kind=='F')
			printf("\t%d-%d-%d",go[i].type.fo.a.year,go[i].type.fo.a.month,go[i].type.fo.a.day);
		printf("\n");
	}
}