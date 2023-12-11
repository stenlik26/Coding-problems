#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

uint32_t get_winning_count(const std::string &line)
{
    std::istringstream str(line);

    string word;
    str >> word; // Skip game3
    str >> word; // Skip game num

    std::unordered_set<int> my_nums;
    int valid_count = 0;
    bool my_nums_end = false;

    while (!str.eof())
    {
        str >> word;

        if (word == "|")
        {
            my_nums_end = true;
            continue;
        }

        if (!my_nums_end)
        {
            my_nums.insert(stoi(word));
            continue;
        }

        if (my_nums.find(stoi(word)) != my_nums.end())
        {
            valid_count++;
        }
    }

    return valid_count;
}

void parse_line(int line_num, const std::string &line, unordered_map<int, uint32_t> &line_count)
{
    uint32_t wining_count = get_winning_count(line);


    for (size_t i = 0; i < wining_count; i++)
    {
        const int key = line_num + 1 + i;

        line_count[key]+=line_count[line_num];
    }
}

void parse_input(const char *filename, unordered_map<int, uint32_t> &line_to_count)
{

    std::ifstream input_file;
    input_file.open(filename);

    if (!input_file.is_open())
        return;

    int line = 1;
    string input_line;
    while (input_file.good())
    {

        getline(input_file, input_line);
        // cout <<"Line: "<< get_winning_line(input_line)<<endl;
        if(input_file.eof())
            break;
        line_to_count[line]++;

        parse_line(line, input_line, line_to_count);
        line++;
    }
}
int main()
{
    unordered_map<int, uint32_t> line_to_count;

    parse_input("input.txt", line_to_count);

    uint32_t result = 0;
    for (auto i = line_to_count.begin(); i != line_to_count.end(); ++i)
    {
        cout << i->first << " " << i->second << endl;
        result += i->second;
    }
    cout << "Result: " << result << endl;

    return 0;
}