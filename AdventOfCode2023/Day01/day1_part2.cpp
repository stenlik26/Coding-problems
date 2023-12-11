#include<iostream>
#include <string>
#include <fstream>
#include<vector>

using namespace std;

//Part TWO
const string numbers[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
 "1", "2", "3", "4", "5", "6", "7", "8", "9"}; 
int parse_string_p2(const string& s)
{
    int number = 0;
    int min_pos = INT32_MAX;
    int max_pos = INT32_MIN;
    int low = 0; 
    int high = 0; 

    for(int i = 0; i < 18; i++)
    {
        int found_l = s.find(numbers[i]);
        int found_h = s.rfind(numbers[i]);
        if(found_l < min_pos && found_l != -1)
        {
            min_pos = found_l;
            low = i;
        }
        if(found_h > max_pos && found_h != -1)
        {
            max_pos = found_h;
            high = i;
        }
    }
    return ((low % 9) + 1)*10 + (high % 9) + 1;
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

        //Part two
        numbers.push_back(parse_string_p2(input_line));
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

    parse_input("input.txt", nums);
    cout << sum_vector(nums)<<endl;
    return 0; 
}