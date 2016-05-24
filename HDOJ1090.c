/**
*@author:StormMaybin
*@Date:2016-05-04
*@Filename:HDOJ1090.c
*@<description> easy </description>
*/ 
# include <stdio.h>
int main (void)
{
	int a, b;
	int N;
	scanf ("%d",&N);
	while (N--)
	{
		scanf ("%d %d",&a, &b);
		printf ("%d\n",a+b);
	}
	return 0;
}
