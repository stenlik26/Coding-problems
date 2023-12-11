#include<iostream>
#include <string>
#include <fstream>
#include<vector>

using namespace std;

int parse_string_p1(const string& s)
{
    int number = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(isdigit(s[i]))
        {
            (number *= 10) += s[i] - '0';
            break;
        }
    }

    for(int i = s.size() - 1; i >= 0; i--)
    {
        if(isdigit(s[i]))
        {
            (number *= 10) += s[i] - '0';
            break;
        }
    }
    return number;
}
void parse_input(const char* filename, vector<int>& numbers)
{
    std::ifstream input_file;
    input_file.open(filename);

    if(!input_file.is_open())
        return;

    string input_line;
    while(input_file.good())
    {
        input_file >> input_line;

        if(input_file.eof())
            break;
        
        numbers.push_back(parse_string_p1(input_line));
    }

}

uint32_t sum_vector(const std::vector<int>& vec)
{
    uint32_t sum = 0;

    for(auto itr = vec.begin(); itr != vec.end(); ++itr)
    {
        sum += *itr;
    }

    return sum;
}

int main()
{
    vector<int> nums;

    //parse_input("example_input.txt", nums);
    parse_input("input.txt", nums);
    cout << sum_vector(nums)<<endl;
    return 0; 
}