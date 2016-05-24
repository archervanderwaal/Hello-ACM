/**
*@author:StromMaybin
*@time:2016年4月12日12:49:26
*@filename:HDOJ1212.c
*@describe:大数取模和我们平常算余数的方法一致
*@原理:(a+b)%m = (a%m + b%m)%m 
*/ 
# include <stdio.h>
# include <string.h>

int bigNumMod (char Str[] , int m)
{
	int i;
	int ans = 0;
	int len_str = strlen (Str); 
	for (i = 0; i < len_str; i++)
	{
		ans = (int)(((long long)ans * 10 + (Str[i] - '0')) % m);
	}
	return ans;
}

int main (void)
{
	char Str[1000];
	int m;
	while (scanf ("%s",Str),scanf ("%d",&m)!=EOF)
	{
		printf ("%d\n",bigNumMod(Str, m));
	}
	return 0;
}
