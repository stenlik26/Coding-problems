#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> left_numbers;
vector<int> right_numbers;

void parse_input(const char *filename)
{
    std::ifstream input_file;
    input_file.open(filename);

    if (!input_file.is_open())
        return;

    string num;
    while (input_file.good())
    {
        input_file >> num;

        if (input_file.eof())
            break;

        left_numbers.push_back(stoi(num));
        input_file >> num;
        right_numbers.push_back(stoi(num));
    }
}

int main()
{
    // parse_input("test_input.txt");
    parse_input("input.txt");
    uint32_t sum = 0;
    uint32_t cur_num_count = 0;
    const int n = left_numbers.size();

    map<int, int> mp;
    for(int i = 0; i < n; i++) 
    {
        mp[right_numbers[i]]++;
    }

    for(int i = 0; i < n; i++) 
    {
        sum += mp[left_numbers[i]] * left_numbers[i];
    }

    cout << sum << endl;
    return 0;
}