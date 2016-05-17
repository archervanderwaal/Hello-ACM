/**
*@author:StormMaybin
*@Date:2016-05-13
*@Filename:HDOJ1018.c 
*@<description>17150006	2016-05-13 23:50:53	Accepted	1018	15MS	1692K	384 B	C	bin</description>
*/ 
/*
这个题用模拟很容易得到答案，但是10的7次方！！！！！！毫无疑问超时超内存。
这里用到一个stirling公式，斯特林公式（Stirling's approximation）是一条用来取n的阶乘的值近似值的数学公式。一般来说，当n很大的时候，n阶乘的计算量十分大，所以斯特林公式十分好用，而且，即使在n很小的时候，斯特林公式的取值已经十分准确。   stirling公式：   
但只用这个公式远远不够，因为n的阶乘算到十几就超int范围了，这题要算n!阶乘的位数，对于一个数a，若有10^(x-1)<a<10^x，则a为x位的整数，所以求n!的位数对公式两边取以10为底的对数，算出来是小数，转为int型后要加1.
x=int(lgn!)=int((lg2*PI+lgn)/2+n*(lgn-lge))+1。
注意n=1的情况。
*/
# include <stdio.h>
# include <math.h>

int main (void)
{
	int n,m;
	scanf ("%d",&n);
	double s;
	while (n--)
	{
		scanf ("%d",&m);
		if (m == 1)
			s = 0;
		else
			s = (log10(2*3.141592654)*0.5 + log10(m)*0.5+m*(log10(m)-log10(2.718281828459)));
		printf ("%d\n",(int)s+1);
	}
	return 0;
}
