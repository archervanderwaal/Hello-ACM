/**
*@author:StormMaybin
*@Date:2016-05-04
*@Filename:HDOJ1091.c
*@<description> easy </description>
*/ 
# include <stdio.h>
int main (void)
{
	int a, b;
	while (scanf ("%d %d",&a, &b) != EOF) 
	{
		if (a == 0 && b == 0)
		{
			return 0;
		}
		else
		{
			printf ("%d\n",a+b);
		}
	}
	return 0;
}
