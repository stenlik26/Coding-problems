    int minPartitions(string n) {
        char max_digit = '0';
        for(int i = 0; i < n.size(); i++)
        {
            if(max_digit < n[i])
                max_digit = n[i];
        }
        return max_digit - '0';
    }