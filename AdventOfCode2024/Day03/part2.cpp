#include <bits/stdc++.h>
#include <regex>
using namespace std;

string parse_input(const char *filename)
{
    std::ifstream input_file;
    input_file.open(filename);

    if (!input_file.is_open())
        return "";

    string line;
    while (input_file.good())
    {
        getline(input_file, line);

        if (input_file.eof())
            break;
    }
    return line;
}

int get_mul_result(string clause)
{
    int comma = clause.find(',');
    string val1 = clause.substr(4, comma - 4);
    string val2 = clause.substr(comma + 1, clause.size() - 2 - comma);

    int x = stoi(val1);
    int y = stoi(val2);

    return x * y;
}

int main()
{
    // string line = parse_input("test.txt");
    string line = parse_input("input.txt");
    uint64_t result = 0;

    regex r("mul\\([0-9]+,[0-9]+\\)|do\\(\\)|don't\\(\\)");

    sregex_iterator it(line.begin(), line.end(), r);
    sregex_iterator ends = sregex_iterator();

    int matchCount = 0;
    bool enabled = true;
    while (it != ends)
    {
        string match = it->str();

        if(match[2] == 'n')
            enabled = false;
        else if(match[2] == '(')
            enabled = true;
        else if(enabled)
            result += get_mul_result(it->str());
        ++it;
    }
    cout << result << endl;

    return 0;
}