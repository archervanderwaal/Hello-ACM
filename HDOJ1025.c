/**
*@author:StromMaybin
*@time:20160413
*@filename:HDOJ1025.c
*/

# include <stdio.h>
# define M 1000000
# define max(a,b) a>b?a:b
int main (void)
{
	int T, n, a[M];
	int i;
	int Max;
	scanf ("%d",&T);
	while (T--)
	{
		long long sum = 0;
		scanf ("%d",&n);
		Max = 0;
		//这个地方完全没必要来两个for一个录入数据一个进行求和和找到Max的值
		//其实一个for完全可以搞定 
		for (i = 0; i < n; i++)
		{
			scanf ("%d",&a[i]);
			sum += a[i];
			Max = max(Max,a[i]);
		}
		sum = sum - Max + 1;
		if (sum >= Max)
		{
			printf ("Yes\n");
		} 
		else
		{
			printf ("No\n");
		}
	}
	return 0;
}
