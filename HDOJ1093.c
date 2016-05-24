/**
*@author:StormMaybin
*@Date:2016-05-04
*@Filename:HDOJ1093.c
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
		printf ("%d\n",sum);
	}
	return 0;
}
