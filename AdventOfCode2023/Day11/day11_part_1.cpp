#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;

void parse_input(const char *filename, vector<vector<char>> &mat)
{

    std::ifstream input_file;
    input_file.open(filename);

    if (!input_file.is_open())
        return;

    string input_line;

    while (input_file.good())
    {
        vector<char> line;
        input_file >> input_line;

        for (size_t i = 0; i < input_line.size(); i++)
        {
            line.push_back(input_line[i]);
        }

        mat.push_back(line);
    }
}

void expand_mat(vector<vector<char>>& mat)
{
    vector<int> rows_to_expand;
    vector<int> cols_to_expand;

    for (size_t i = 0; i < mat.size(); i++)
    {
        int candidate = i;
        for (size_t j = 0; j < mat[i].size(); j++)
        {
            if(mat[i][j] == '#')
                candidate = -1;
        }
        if(candidate != -1)
            rows_to_expand.push_back(candidate);
    }

    for (size_t i = 0; i < mat[0].size(); i++)
    {
        int candidate = i;
        for (size_t j = 0; j < mat.size(); j++)
        {
            if(mat[j][i] == '#')
                candidate = -1;
        }
        if(candidate != -1)
            cols_to_expand.push_back(candidate);
    }

    for (size_t i = 0; i < rows_to_expand.size(); i++)
    {
            mat.insert(mat.begin() + rows_to_expand[i], mat[rows_to_expand[i]]);
    }
    
    for (size_t ce = 0; ce < cols_to_expand.size(); ce++)
    {
        for (size_t j = 0; j < mat.size(); j++)
        {
            mat[j].insert(mat[j].begin() + cols_to_expand[ce] + ce, '.');
        }
    }
    

    return;
}

void find_galaxies(vector<vector<char>>& mat, vector<std::pair<int, int>>& galaxies)
{
    for (size_t r = 0; r < mat.size(); r++)
    {
        for (size_t c = 0; c < mat[r].size(); c++)
        {
            if(mat[r][c] == '#')
                galaxies.push_back({r,c});
        }
        
    }
    
}

int main()
{
    vector<vector<char>> mat;
    vector<pair<int,int>> galaxies;

    parse_input("example_input.txt", mat);
    expand_mat(mat);
    find_galaxies(mat, galaxies);

    uint32_t total_dist = 0;
    for (size_t i = 0; i < galaxies.size(); i++)
    {
        for (size_t j = i + 1; j < galaxies.size(); j++)
        {
            total_dist += abs(galaxies[i].second - galaxies[j].second) + abs(galaxies[i].first - galaxies[j].first);
        }
        
    }
    
    cout << total_dist<<endl;
    return 0;
}