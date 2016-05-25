/**
*@author StormMaybin
*@Date 2016-05-25
*@Filename HDOJ1076.java
*/
import java.util.Scanner;
public class  HDOJ1076
{
	public static void main(String[] args) 
	{
		Scanner scan = new Scanner(System.in);
		int T = scan.nextInt();
		for(int i = 1; i <= T; i++)
		{
			int count = 0;
			int year = scan.nextInt();
			int n = scan.nextInt();
			while(count < n)
			{
				if (leapYear(year) == 1)
				{
					count++;
					year++;
				}
				else
					year++;
			}
			System.out.println(year-1);
		}
		
	}

	public static int leapYear(int year)
	{
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400) == 0)
		{
			return 1;
		}
		return 0;
	}
}
