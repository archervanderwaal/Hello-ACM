/**
*@author:StormMaybin
*@date:2016-05-14
*@Filename:HDOJ
*@<description>这是一道数学题，意思就是一个三维平面可以被n条直线分割成多少个平面问题，公式就是
(n^3+5n+6)/6个平面，知道公式就很简单了</description>
*/
# include <stdio.h>

int main (void)
{
	int n;
	while (scanf ("%d",&n) == 1)
	{
		int ans = (n * n *n + 5 * n + 6)/6;
		printf ("%d\n",ans);
	}
	return 0;
}
