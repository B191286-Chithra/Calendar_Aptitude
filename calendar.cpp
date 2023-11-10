//program to find day of given date
//calendar topic in Aptitude
#include<bits/stdc++.h>
using namespace std;

int odd(int i)
{//function to find odd days of century years
	
	switch(i){
	case 100:
		return 5;
	case 200:
		return 3;
	case 300:
		return 1;
	case 400:
		return 0;
	case 500:
		return 5;
	case 600:
		return 3;
	case 700:
		return 1;
	case 800:
		return 0;
	case 900:
		return 5;
	default:
	i+=(i/4);
	return i%7;}//odd days of particular century years
}

int month_odd(int d,int m)
{//function to find odd days till previous month
	
	int arr[15]={0,0,3,3,6,8,11,13,16,19,21,24,26};
	return (arr[m]+d)%7;
}

string day(int i)
{// function to find day of week related to odd days
	switch(i)
	{
	case 0: return "sunday";
	case 1: return "monday";
	case 2: return "tuesday";
	case 3: return "wednesday";
	case 4: return "thursday";
	case 5: return "friday";
	case 6: return "saturday";
	default : return "nothing" ;
	}
}
int main()
{
	int d,m,y;
	//day month year
	cin>>d>>m>>y;

	//check if year is not leap year
	if(y%4!=0)

	{
		if(d==29&&m==2)
		{
			//leap years do not have 28 days in feb
			cout<<"invalid date";
			return 0;
		}
	}
	int dup_y=y;
	y--;
	int n=1,rem,sum=0;

	//check if any century year before the given year
	while(y/100!=0)
	{
		rem=y%10;
		sum=sum+rem*n;
		n*=10;
		y=y/10;
	}
	
	y*=100;
	while(y%400!=0)
	{
		y-=100;
		sum+=100;
	}
	
	int result=0,new_sum=0;
	n=1;
	if(sum>100)
	{
		while(sum/10!=0)
		{
		rem=sum%10;
		new_sum=new_sum+rem*n;
		n*=10;
		sum=sum/10;
		}
		//odd days of the week in remaining years
		result=odd(sum*100);
	}
	else new_sum=sum;
	result=result+odd(new_sum);//add odd days of given date
	result=result+month_odd(d,m);//add odd days of month

	if(dup_y%4==0)
	{
		if(m>2)
		result+=1;
	}
	string s=day(result%7);
	
	cout<<endl<<s<<endl;//day of the week
}


