#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

vector<vector<int>> matrix;

vector<int> parse_line(string line)
{
    stringstream string_stream(line);
    vector<int> out;
    while (string_stream.good())
    {
        int num;
        string_stream >> num;

        out.push_back(num);

        if (string_stream.eof())
            break;
    }
    return out;
}

void parse_input(const char *filename)
{
    std::ifstream input_file;
    input_file.open(filename);

    if (!input_file.is_open())
        return;

    string line;
    while (input_file.good())
    {
        getline(input_file, line);

        matrix.push_back(parse_line(line));

        if (input_file.eof())
            break;
    }
}

bool is_line_safe(vector<int> &line)
{
    bool asc = line[0] < line[1];

    for (size_t i = 0; i < line.size() - 1; i++)
    {
        int diff = line[i] - line[i + 1];
        if (abs(diff) < 1 || abs(diff) > 3)
                return false;

        if ((diff > 0 && asc) || (diff < 0 && !asc))
            return false;
    }
    return true;
}

int main()
{
    // parse_input("test_input.txt");
    parse_input("input.txt");

    int safe_cnt = 0;
    for (int i = 0; i < matrix.size(); i++)
    {
        if (is_line_safe(matrix[i]))
            safe_cnt++;
    }
    cout << safe_cnt << endl;
    return 0;
}