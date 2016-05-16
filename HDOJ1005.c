/**
*@author:StormMaybin
*@Date:20160426
*@Filename:HDOJ1005.c
*@<description></desciption>
*/
/*
首先我们来分析一下题目，这道题乍一看就是用递归解决的问题，但是看了数据的范围，立马打消了递归解决的想法，实在
太荒唐，那么怎么办呢，这个题是对小数取余，那么取余肯定会循环，这样问题就很清晰化了，我们牺牲时间和空间复杂度
更快的解决这个问题，怎么循环呢，当存在一个i使得f[i] = 1;并且f[i-1] = 1;这时候就循环了，但是怎么确定循环的基数
呢？循环基数很快能知道就是i-2，然后让n值对i-2进行取余，然后判断余数进行处理，这道题就很轻松地解决了！ 
*/
# include <stdio.h>
int main (void)
{
	int f[200];
	int A, B, n;
	int i;
	while (scanf ("%d %d %d",&A, &B, &n) == 3 && A || B || n)
	{
		if (n > 2)
		{
			f[1] = 1;
			f[2] = 1;
			for (i = 3; i < 200; i++)
			{
				f[i] = (A*f[i-1] + B*f[i-2]) % 7;
				if (f[i] == 1 && f[i-1] == 1)
				{
					break;
				}
			}
			i -= 2;
			n = n%i;
			if (n == 0)
			{
				printf ("%d\n",f[i]);
			}
			else
			{
				printf ("%d\n",f[n]);
			}
		}
		else
		{
			printf ("1\n");
		}
	}
	return 0;
}
