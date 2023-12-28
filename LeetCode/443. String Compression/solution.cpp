#include<iostream>
#include <string>
#include<vector>

using namespace std;

void insert_number_vec(vector<char>& chars, int pos, string num)
{
    for (size_t i = 0; i < num.size(); i++)
    {
        chars.insert(chars.begin() + pos + i, num[i]);
    }

}

int compress(vector<char>& chars) {
    
    int current_count = 1;

    for (int i = 0; i < chars.size() - 1; i++)
    {
        if(chars[i] != chars[i+1])
        {
            if(current_count == 1)
                continue;
            
            string count_str = to_string(current_count);
            insert_number_vec(chars, i+1, count_str);

            i += count_str.size();
            current_count = 1;
        }
        else
        {

            chars.erase(chars.begin() + i);
            i--;
            current_count++;

        }
    }

    if(current_count != 1)
        insert_number_vec(chars, chars.size(), to_string(current_count));

    return chars.size();
}

int main()
{
    vector<char> test1 = {'a','a','b','b','c','c','c'};
    vector<char> test2 = {'a'};
    vector<char> test3 = {'a','b','b','b','b','b','b','b','b','b','b','b','b'};
    vector<char> test4 = {'p','p','p','p','m','m','b','b','b','b','b','u','u','r','r','u','n','n','n','n','n','n','n','n','n','n','n','u','u','u','u','a','a','u','u','r','r','r','s','s','a','a','y','y','y','g','g','g','g','g'};

    cout << compress(test1) << endl; 
    cout << compress(test2) << endl; 
    cout << compress(test3) << endl; 
    cout << compress(test4) << endl; 
    return 0; 

}