#include<iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include<vector>

using namespace std;

void parse_input(const char* filename, unordered_map<string, std::pair<string, string>>& map, string& instructions)
{

    std::ifstream input_file;
    input_file.open(filename);

    if(!input_file.is_open())
        return;

    string key, pair_l, pair_r, buffer;

    input_file >> instructions;
    
    while(input_file.good() && !input_file.eof())
    {
        input_file >> key >> buffer >> pair_l >> pair_r;

        map[key] = {pair_l.substr(1,3), pair_r.substr(0,3)};

    }

}

uint32_t run_instructions(const string& instructions, unordered_map<string, std::pair<string, string>>& map)
{
    uint32_t inst_count = 0;
    string current_key = "AAA";

    while(current_key != "ZZZ")
    {
        for (size_t i = 0; i < instructions.size(); i++)
        {
            if(current_key == "ZZZ")
                break;

            if(instructions[i] == 'L')
                current_key = map[current_key].first;
            else
                current_key = map[current_key].second;
            inst_count++;
        }
        
    }
    return inst_count++;
}

int main()
{
    unordered_map<string, std::pair<string, string>> map;
    string instructions = "";
    parse_input("input.txt", map, instructions);

    cout << run_instructions(instructions, map)<<endl;
    return 0; 
}