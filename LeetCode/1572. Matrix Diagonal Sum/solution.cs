int DiagonalSum(int[][] mat)
{
    int n = mat[0].Length;
    int current_sum = 0;
    
    for(int i = 0; i < n; i++)
    {
        current_sum += mat[i][i];
        Console.Write(mat[i][i] + " ");
    }
    Console.WriteLine();
    
    for (int i = n - 1; i >= 0; i--)
    {
        current_sum += mat[n - i - 1][i];
        Console.Write(mat[n - i - 1][i] + " ");
    }
    if(n % 2 != 0)
    {
        current_sum -= mat[n / 2][n / 2];
    }
    Console.WriteLine();
    return current_sum;
}

void main()
{
    int[][] test = new int[4][];
    test[0] = new int[] { 1, 1, 1, 1 };
    test[1] = new int[] { 1, 1, 1, 1 };
    test[2] = new int[] { 1, 1, 1, 1 };
    test[3] = new int[] { 1, 1, 1, 1 };
    Console.WriteLine(DiagonalSum(test));
}

main();