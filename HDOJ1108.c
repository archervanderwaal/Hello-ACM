/**
*@author:StormMaybin
*@Date:2016-05-06
*@Filename:HDOJ1108.c 
*/
# include <stdio.h>

int gcd  (int a, int b)
{
	return b == 0 ? a : gcd (b, a%b);
}

int main (void)
{
	int a, b;
	while (scanf ("%d %d",&a, &b) == 2)
	{
		int temp = gcd (a, b);
		printf ("%d\n",a*b/temp);
	}
	return 0;
} 
