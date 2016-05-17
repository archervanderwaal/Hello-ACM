/**
*@author:StormMaybin
*@Date:2016-05-12
*@Filename:HDOJ1012.c 
*/ 
# include <stdio.h>
double fac (int n)
{
	if (n == 1 || n == 0)
	{
		return 1;
	}
	else
	{
		return n * fac (n-1);
	}
}
double sum (int n)
{
	double sumk = 0;
	for (int i = 0; i <= n; i++)
	{
		sumk += 1/fac(i);
	}
	return sumk; 
}
int main (void)
{
	printf ("n e\n");
	printf ("- -----------\n");
	int a = 0;
	printf ("0 1\n1 2\n2 2.5\n");
	for (int i = 3; i <= 9; i++)
	{
		printf ("%d %.9f\n",a+i,sum(a+i));
	}
	return 0;
}

