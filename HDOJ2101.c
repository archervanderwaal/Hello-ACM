/**
*@author:StormMaybin
*@Date:2016-05-16
*@Filename:HDOJ2101.c
*@<description>签到题</description>
*/
# include <stdio.h>

int main (void)
{
	int a, b, n;
	while (scanf ("%d %d",&a, &b) == 2)
	{
		n = a + b;
		if (n % 86 == 0)
		{
			printf ("yes\n");
		}
		else
			printf ("no\n");
	}
	return 0;
}
