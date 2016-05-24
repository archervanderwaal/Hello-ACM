/**
*@author:StormMaybin
*@Date:2016-05-04
*@Filename:HDOJ1096.c
*@<description> easy </description>
*/ 
# include <stdio.h>
# define N 40
int main (void)
{
	int M, A[N];
	int sum;
	int X;
	scanf ("%d",&X);
	while (X--) 
	{
		scanf ("%d",&M);
		if (M == 0)
		{
			
			return 0;
		}
		sum = 0;
		for (int i = 0; i < M; i++)
		{
			scanf ("%d",&A[i]);
			sum += A[i];
		}
		if (X != 0)
		{
			printf ("%d\n\n",sum);
		}
		else
		{
			printf ("%d\n",sum);
		}
	}
	return 0;
}
