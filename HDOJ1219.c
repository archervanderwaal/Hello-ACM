/**
*@author:StormMaybin
*@Date:2016-05-11
*Filename:HDOJ1219.c
*/
# include <stdio.h>
# include <string.h>

int main (void)
{
	char str [100001];
	int storm [26];
	char bin [27] = "abcdefghijklmnopqrstuvwxyz";
	while (gets(str))
	{
		memset (storm, 0, sizeof (storm));
		int length = strlen(str);
		for (int i = 0; i < length; i++)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
			//说明是字母
			{
				int t = str[i] - 'a';
				storm[t] ++;
			} 
		}
		for (int i = 0; i < 26; i++)
		{
			printf ("%c:%d\n",bin[i],storm[i]);
		}
		printf ("\n");
	}
	return 0;
}
