#include<iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_set>
#include<vector>

using namespace std;

uint32_t pow_2(int x)
{
    return 1 << x;
}


uint32_t get_winning_line(const std::string& line)
{
    std::istringstream str(line);

    string word;
    str>>word; //Skip game
    str>>word; //Skip game num

    std::unordered_set<int> my_nums;
    int valid_count = 0;
    bool my_nums_end = false;

    while(!str.eof())
    {
        str>>word;

        if(word == "|")
        {
            my_nums_end = true;
            continue;
        }

        if(!my_nums_end)
        {
            my_nums.insert(stoi(word));
            continue;
        }

        if(my_nums.find(stoi(word)) != my_nums.end())
        {
            valid_count++;
        }
    }

    return (valid_count != 0) ? pow_2(valid_count - 1) : 0;
}

void parse_input(const char* filename, uint32_t& result)
{

    std::ifstream input_file;
    input_file.open(filename);

    if(!input_file.is_open())
        return;

    string input_line;
    while(input_file.good())
    {

        getline(input_file, input_line);
        //cout <<"Line: "<< get_winning_line(input_line)<<endl;
        result += get_winning_line(input_line);
    }

}
int main()
{
    uint32_t result = 0;

    //parse_input("example_input.txt", result);
    parse_input("input.txt", result);

    cout << "Result: " << result <<endl;
    return 0; 
}