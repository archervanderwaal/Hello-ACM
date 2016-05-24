/**
*@author:StormMaybin
*@Date:2016-05-03
*@Filename:HDOJ1042.c 
*/ 
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# define MAX 8000
int main (void)
{
	int i, j, k, t, N;
	int f[MAX];
	while (scanf ("%d",&N) == 1)
	{
		//每次使用前要清零
		memset (f, 0, sizeof (f));
		f[0] = 1;
		for (i = 2; i <= N; i++)
		{
			for (t = 0, j = 0; j < MAX; j++)
			{
				k = f[j] * i + t;
				f[j] = k % 100000;
				t = k / 100000;
			}
		}
		//除去前导零
		for (i = MAX - 1; ! f[i]; i--);
		//第一个元素不要求输出多余零
		printf ("%d",f[i]);
		while (i)
		{
			printf ("%05d",f[--i]);
			//这些需要输出前面多余的零,这个你懂的，否则一直WA！
		}
		printf ("\n");
	}
	return 0;
} 
