/**
*@author:StormMaybin
*@Date:2016-05-11
*@Filename:HDOJ1201.c 
*/ 
# include <stdio.h>

int leap (int year)
{
	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
	{
		return 1;
	}
	return 0;
}

int main (void)
{
	int T;
	scanf ("%d",&T);
	int year, month, day;
	while (T--)
	{
		scanf ("%d-%d-%d",&year, &month, &day);
		int sum = 365 * 18;//先计算出以365天为一年的18年的天数
		for (int i = 1; i < 18; i++)
		{
			sum += leap (i + year);
		} 
		//如果生日的月份在2月以前，那么必须处理这一年是平闰年的情况； 
		if (month <= 2)
		{
			sum += leap (year);
		}
		else
		{
			sum += leap (year + 18);
		} 
		if (month == 2 && day == 29)
		{
			printf ("-1\n");
		}
		else
		{
			printf ("%d\n",sum);
		}
	}
	return 0;
}
