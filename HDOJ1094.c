/**
*@author:StormMaybin
*@Date:2016-05-04
*@Filename:HDOJ1094.c
*@<description> easy </description>
*/ 
# include <stdio.h>
# define N 40
int main (void)
{
	int M, A[N];
	int sum;
	while (scanf ("%d",&M) == 1 && M) 
	{
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
