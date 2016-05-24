/**
*@author:StormMaybin
*@Date:2016-05-06
*@Filename:HDOJ1249.c 
*/
# include <stdio.h>

int main (void)
{
	int N;
	scanf ("%d",&N);
	while (N--)
	{
		int n;
		scanf ("%d",&n);
		printf ("%d\n",3 * n * (n - 1) + 2);
	}
	return 0;
}
