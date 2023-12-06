#include<iostream>
#include <string>
#include <fstream>
#include <sstream>
#include<vector>

using namespace std;

struct map_info
{
    long dest,source,step;
};

void parse_input_seeds(const std::string& line, vector<long>& seeds)
{
    std::istringstream str(line);

    string word;
    str>>word; //Skip seeds

    while(str.good())
    {
        long seed;
        str>>seed;

        seeds.push_back(seed);
    }
}

void apply_map(vector<map_info> map, vector<long>& seeds)
{
    for(long& s : seeds)
    {
        for (size_t i = 0; i < map.size(); i++)
        {
            if(map[i].source <= s && map[i].source + map[i].step >= s)
            {
                s += map[i].dest - map[i].source;
                break;
            }
        }
        
    }
    return;
}

long lowest_temp(const vector<long>& temps)
{
    long min = temps[0];
    for (size_t i = 1; i < temps.size(); i++)
    {
        if(temps[i] < min)
            min = temps[i];
    }
    return min;
}

void parse_input(const char* filename, vector<long>& seeds)
{

    std::ifstream input_file;
    input_file.open(filename);

    if(!input_file.is_open())
        return;

    string input_line;
    vector<map_info> map;


    getline(input_file, input_line);
    parse_input_seeds(input_line, seeds);
    getline(input_file, input_line);

    while(!input_file.eof())
    {
        getline(input_file, input_line);

        if(input_line[input_line.size() - 1] == ':')
            continue;

        if(input_line == "")
        {
            apply_map(map, seeds);
            map.clear();
        }
        else
        {
            std::istringstream str(input_line);
            map_info mi;
            str >> mi.dest >> mi.source >> mi.step;
            map.push_back(mi);
        }
    }

    if(!map.empty())
    {
        apply_map(map, seeds);
        map.clear();
    }

}
int main()
{
    vector<long> nums;

    parse_input("example_input.txt", nums);

    cout << lowest_temp(nums)<<endl;
    return 0; 
}