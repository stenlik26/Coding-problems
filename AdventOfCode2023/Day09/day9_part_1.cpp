#include<iostream>
#include <string>
#include <fstream>
#include <sstream>
#include<vector>

using namespace std;

bool check_diffs(const vector<int>& diffs)
{
    for (size_t i = 0; i < diffs.size(); i++)
    {
        if(diffs[i] != 0)
            return false;
    }
    return true;
}

long parse_line(const string& line)
{
    std::istringstream str(line);
    vector<int> nums;
    vector<vector<int>> diffs;
    long result = 0;

    while(!str.eof())
    {
        int x;
        str >> x;
        nums.push_back(x);
    }

    diffs.push_back(nums);

    while(!check_diffs(nums))
    {
        vector<int> new_nums;

        for (size_t i = 0; i < nums.size() - 1; i++)
        {
            new_nums.push_back(nums[i+1] - nums[i]);
        }

        diffs.push_back(new_nums);
        nums = new_nums;
    }
    int last_num = 0;
    for (int i = diffs.size() - 2; i >= 0; i--)
    {
        last_num = diffs[i][diffs[i].size() - 1] + last_num;
    }
    return last_num;
}

void parse_input(const char* filename, long& result)
{

    std::ifstream input_file;
    input_file.open(filename);

    if(!input_file.is_open())
        return;

    string input_line;
    while(input_file.good())
    {
        getline(input_file, input_line);
        result += parse_line(input_line);
    }

}
int main()
{
    long result = 0;
    //parse_input("example_input.txt", result);
    parse_input("input.txt", result);
    cout << result << endl;
    return 0; 
}