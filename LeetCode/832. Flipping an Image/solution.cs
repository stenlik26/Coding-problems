using System;
					
public class Program
{
	public static int[][] FlipAndInvertImage(int[][] image) {
        int n = image[0].Length;
		for(int i = 0; i< n; i++)
		{
			Array.Reverse(image[i]);
			for(int j = 0; j < n; j++)
			{
				if(image[i][j] == 1)
					image[i][j] = 0;
				else
					image[i][j] = 1;
			}
		}
		
		for(int i = 0; i< n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				Console.Write(image[i][j] + " ");
			}
			Console.WriteLine();
		}
		
		
		return image;
    }
	public static void Main()
	{
		int[][] test = new int[3][];
		test[0] = new int[] {1,1,0};
		test[1] = new int[] {1,0,1};
		test[2] = new int[] {0,0,0};				 
		FlipAndInvertImage(test);
		Console.WriteLine("Hello World");
	}
}