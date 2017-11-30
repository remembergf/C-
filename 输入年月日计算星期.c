#include<stdio.h>
enum weekday
	{Sunday,Monday,Tuesday,Wednesday,Thursday,Friday,Saturday};
struct date
{
	int year;
	int month;
	int day;
};
int main ()
{
	printf("please input a date:");
	enum weekday m;
	struct date da;
	int i=0,x,y,z;
	scanf("%d %d %d",&da.year,&da.month,&da.day);
	z=da.day;												
	if(da.year%4==0&&da.year%100==0||da.year%400==0)	
	{
		switch(da.month)
		{
			case 5:y=5;break;
			case 2:
			case 8:y=1;break;
			case 3:
			case 11:y=2;break;
			case 6:y=3;break;
			case 9:
			case 12:y=4;break;
			case 1:
			case 4:
			case 7:y=5;break;
			default:y=6;break;
		}
	}
	else
	{
			switch(da.month)
		{
			case 5:y=5;break;
			case 8:y=1;break;
			case 2:
			case 3:
			case 11:y=2;break;
			case 6:y=3;break;
			case 9:
			case 12:y=4;break;
			case 4:
			case 7:y=5;break;
			default:y=6;break;
		}
	}
	x=da.year%100/4+10%7;					
	m=(enum weekday)((x+y+z)%7);
	printf("That day is ");
	switch(m)
	{
		case 1:printf("Monday");break;
		case 2:printf("Tuesday");break;
		case 3:printf("Wednesday");break;
		case 4:printf("Thursday");break;
		case 5:printf("Friday");break;
		case 6:printf("Saturday");break;
		default:printf("Sunday");break;
	}
}