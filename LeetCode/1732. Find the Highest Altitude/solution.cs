int LargestAltitude(int[] gain)
{
    int current = 0;
    int max_current = 0;
    foreach(int x in gain)
    {
        current += x;
        if(max_current < current)
            max_current = current;
    }
    return max_current;
}

void main()
{
    Console.WriteLine(LargestAltitude(new int[] { -4, -3, -2, -1, 4, 3, 2 }));
    Console.WriteLine("Test");
}

main();