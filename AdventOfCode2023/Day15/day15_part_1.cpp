#include<iostream>
#include <string>
#include <fstream>
#include<vector>

using namespace std;

uint64_t parse_word (const string& str)
{
    uint64_t val = 0;

    for (size_t i = 0; i < str.size(); i++)
    {
        val += (int)str[i];
        val *= 17;
        val %= 256;
    }
    return val;
}

void parse_input(const char* filename, uint64_t& sum)
{

    std::ifstream input_file;
    input_file.open(filename);

    if(!input_file.is_open())
        return;

    string current_word;
    char c;
    while(input_file.get(c))
    {

        if(c == ',')
        {
            sum += parse_word(current_word);
            current_word.clear();
        }
        else
        {
            current_word += c;
        }
    }

    if(!current_word.empty())
        sum += parse_word(current_word);

}


int main()
{
    uint64_t sum;

    parse_input("input.txt", sum);

    cout << sum << endl;
    return 0; 
}