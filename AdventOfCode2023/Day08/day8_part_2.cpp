#include<iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include<vector>
#include<numeric>

using namespace std;

void parse_input(
    const char* filename, 
    unordered_map<string, std::pair<string, string>>& map, 
    string& instructions,
    vector<string>& a_keys)
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

        if(key[2] == 'A')
            a_keys.push_back(key);

        map[key] = {pair_l.substr(1,3), pair_r.substr(0,3)};

    }

}

void run_instructions(
    const string& instructions, 
    unordered_map<string, std::pair<string, string>>& map,
    vector<string>& a_keys,
    vector<int>& path_len)
{
    bool set = true;
    while(set)
    {
        for (size_t i = 0; i < instructions.size(); i++)
        {
            set = false;

            bool left_inst = instructions[i] == 'L';
            
            for (size_t j = 0; j < a_keys.size(); j++)
            {
                if(a_keys[j][2] == 'Z')
                {
                    continue;
                }

                if(left_inst)
                    a_keys[j] = map[a_keys[j]].first;
                else
                    a_keys[j] = map[a_keys[j]].second;
                
                path_len[j]++;
                set = true;
            }         
        }
        
    }
}

uint64_t lcm_vec(const vector<int>& path_len)
{
    uint64_t result = std::lcm(path_len[0], path_len[1]);
    
    for (size_t i = 2; i < path_len.size(); i++)
    {
        result = std::lcm(result, path_len[i]);
    }
    return result;
}

int main()
{
    unordered_map<string, std::pair<string, string>> map;

    vector<string> a_keys;


    string instructions = "";
    parse_input("input.txt", map, instructions, a_keys);

    vector<int> path_len(a_keys.size(), 0);

    run_instructions(instructions, map, a_keys, path_len);

    cout << lcm_vec(path_len)<<endl;
    return 0; 
}