/**
*@author:StormMaybin
*@Date:2016-05-12
*@Filename:HDOJ1395.c 
*/ 
# include <stdio.h>
int main (void)
{
	int n;
	while (scanf ("%d",&n) == 1)
	{
		if (n == 1 || n % 2 == 0)
		{
			printf ("2^? mod %d = 1\n",n);
			continue;
		}
		int k = 1;
		int ans = 2;
		while (ans != 1)
		{
			ans = ans * 2 % n;
			k++;
		}
		printf ("2^%d mod %d = 1\n",k,n);
	}
	return 0;
}
