/**
*@author StormMaybin
*@Date 2016-07-17
*@description HDOJ1021 
*/
/*
通过找规律，发现
n           0   1   2   3   4   5   6   7   8   9   10
f(n)        7   11  18  29  47  76  123 199 322 521 843
余数        1   2   0   2   2   1   0   1   1   2   0
每8个数是一个循环，%8 == 2 和 &8 == 6的时候f(n)%3 == 0
*/
#include<iostream>
using namespace std;

const int Max = 9;
int d[Max] = {1, 2};

int main()
{
	int loop;
	
	for(int i=2; ; i++)
	{
		d[i] = (d[i-1] + d[i-2]) % 3;
		
		if(d[i] == d[1] && d[i-1] == d[0])
		{
			loop = i - 1;
			break;
		} 
	}
	
	int n;
	while(scanf("%d", &n) != EOF)
	{
		if(!d[n%loop]) printf("yes\n");
		else printf("no\n");
	}
	system("pause");
	return 0;
}
