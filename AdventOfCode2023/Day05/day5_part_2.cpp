#include<iostream>
#include <string>
#include <fstream>
#include <sstream>
#include<vector>

using namespace std;

struct map_info
{
    long dest_start, dest_end,source_start,source_end;
    int step;
};

void parse_input_seeds(const std::string& line, vector<std::pair<long, long>>& seeds)
{
    std::istringstream str(line);

    string word;
    str>>word; //Skip seeds

    while(str.good())
    {
        long seed1, seedc;
        str>>seed1 >> seedc;

        seeds.push_back({seed1, seed1 + seedc});

    }
}

void apply_map(vector<map_info> map, vector<std::pair<long, long>>& seeds)
{
    vector<std::pair<long, long>> seeds_new;
    for(int i = 0; i < seeds.size();  i++)
    {
        std::pair<long, long>& s = seeds[i];
        for (size_t i = 0; i < map.size(); i++)
        {
            const long long diff = map[i].dest_start - map[i].source_start;


            if(map[i].source_start <= s.first && map[i].source_end >= s.second)
            {
                seeds_new.push_back(
                    {s.first + diff,
                     s.second + diff});
                break;
            }
            else if(map[i].source_start > s.first && map[i].source_end < s.second )
            {
                seeds_new.push_back({map[i].dest_start, map[i].dest_end});
                seeds.push_back({s.first, map[i].source_start - 1});
                seeds.push_back({map[i].source_end + 1, s.second});
                break;
            }
            else if ((map[i].source_end < s.first) || (map[i].source_start > s.second))
            {
                if(i != map.size() - 1)
                    continue;
                else
                    seeds_new.push_back(s);
            }
            else if(map[i].source_start <= s.first && map[i].source_end <= s.second)
            {
                seeds_new.push_back({s.first + diff, map[i].source_end + diff});
                if(map[i].source_end < s.second)
                    seeds.push_back({map[i].source_end + 1, s.second});
                break;
            }
            else if(map[i].source_start >= s.first && map[i].source_end >= s.second)
            {
                seeds_new.push_back({map[i].source_start + diff, s.second + diff});
                if(map[i].source_start > s.first);
                    seeds.push_back({s.first, map[i].source_start - 1});
                break;
            }
            

        }
        
    }
    seeds = seeds_new;
    return;
}

long lowest_temp(const vector<std::pair<long, long>>& temps)
{
    long min = temps[0].first;
    for (size_t i = 1; i < temps.size(); i++)
    {
        if(temps[i].first < min)
            min = temps[i].first;
    }
    return min;
}

void parse_input(const char* filename, vector<std::pair<long, long>>& seeds)
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
            str >> mi.dest_start >> mi.source_start >> mi.step;
            mi.dest_end = mi.dest_start + mi.step - 1;
            mi.source_end = mi.source_start + mi.step - 1;
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
    vector<std::pair<long, long>> nums;

    parse_input("input.txt", nums);

    cout << lowest_temp(nums)<<endl;
    return 0; 
}