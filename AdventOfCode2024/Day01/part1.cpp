#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

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

    sort(left_numbers.begin(), left_numbers.end());
    sort(right_numbers.begin(), right_numbers.end());

    for (int i = 0; i < left_numbers.size(); i++)
    {   
        sum += abs(left_numbers[i] - right_numbers[i]);
    }

    cout << sum << endl;
    return 0;
}