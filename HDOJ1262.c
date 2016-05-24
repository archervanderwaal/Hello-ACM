/**
*@author:StormMaybin
*@Date:2016-05-12
*@Filename:HDOJ1262.c 
*/ 
# include <stdio.h>
# include <string.h>
# define MAX 10001
int Isprime [10001];
void function ()
{
	int i, j;
	memset (Isprime, 0, sizeof (Isprime));
	Isprime[0] = 1;
	Isprime[1] = 1;
	for (int i = 2; i < 100; i++)
	{
		if (!Isprime[i])
		{
			for (j = 2 * i; j < MAX; j += i)
			{
				Isprime[j] = 1;
			}
		}
	}
}
int main (void)
{
	int m, i, j;
	function();//开始打表
	while (scanf ("%d",&m) == 1)
	{
		for (i = m / 2; i <= m; i++)
		{
			j = m - i;
			//中间向两边遍历 
			if (!Isprime[i] && !Isprime[j])
			{
				printf ("%d %d\n",j,i);
				break;
			}
		}
	} 
	return 0;
}
