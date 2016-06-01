/**
*@author StormMaybin
*@Date 2016-05-31
*@Filename nisuclass.java
*/
import java.util.Scanner;
class Main
{
	public static void main(String[] args) 
	{
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int [] arr = new int [n];
		for (int i = 0; i < n; i++)
		{
			arr[i] = scan.nextInt();
		}
		int element = scan.nextInt();
		System.out.println(removeElement(arr,element));
	}
	public static int removeElement(int [] arr, int element)
	{
		int count = arr.length;
		for (int i = 0; i < arr.length ; i++)
		{
			if (arr[i] == element)
			{
				count--;
			}
		}
		return count;
	}
}
