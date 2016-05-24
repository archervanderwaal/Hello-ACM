/**
*@author:StormMaybin
*@Date:2016-05-04
*@Filename:HDOJ1097.c
*@<description> 找规律问题 </description>
*/ 
# include <stdio.h>

int main (void)
{
	int a, b;
	while (scanf ("%d %d",&a, &b) == 2)
	{
		a %= 10;
		if (a == 0 || a == 1 || a == 5 || a == 6)
		{
			printf ("%d\n",a);
		}
		else if (a == 4 || a == 9)
		{
			int t = b % 2;
			printf ("%d\n",t == 0 ? a * a % 10 : a);
		}
		else
		{
			int t = b % 4;
			if(t == 1) printf("%d\n",a);
            else if(t == 2) printf("%d\n",a * a % 10);
            else if(t == 3) printf("%d\n",a * a * a % 10);
            else printf("%d\n",a * a * a * a % 10);    
		}
	}
	return 0;
} 
