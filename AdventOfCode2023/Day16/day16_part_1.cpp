#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <vector>
#include <limits.h>
#include <stack>

using namespace std;

enum DIR
{
    UP = 1,
    DOWN = 2,
    LEFT = 4,
    RIGHT = 8
};

pair<int, int> get_next_dir(pair<int, int> current, DIR direction)
{
    if (direction == UP)
        return {current.first - 1, current.second};
    if (direction == DOWN)
        return {current.first + 1, current.second};
    if (direction == LEFT)
        return {current.first, current.second - 1};
    if (direction == RIGHT)
        return {current.first, current.second + 1};
}

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

void apply_beam(std::pair<int, int> pos, vector<vector<char>> &mat, DIR direction, vector<vector<int>> &energised)
{
    int r = pos.first;
    int c = pos.second;

    if (r < 0 || c < 0 || r >= mat.size() || c >= mat[0].size())
        return;

    if((energised[r][c] & direction) > 0 )
        return;

    energised[r][c] |= direction;

    if (mat[r][c] == '.')
        return apply_beam(get_next_dir(pos, direction), mat, direction, energised);

    if (mat[r][c] == '\\')
    {
        if (direction == UP)
            return apply_beam({r, c - 1}, mat, LEFT, energised);
        if (direction == DOWN)
            return apply_beam({r, c + 1}, mat, RIGHT, energised);
        if (direction == LEFT)
            return apply_beam({r - 1, c}, mat, UP, energised);
        if (direction == RIGHT)
            return apply_beam({r + 1, c}, mat, DOWN, energised);
    }
    if (mat[r][c] == '/')
    {
        if (direction == UP)
            return apply_beam({r, c + 1}, mat, RIGHT, energised);
        if (direction == DOWN)
            return apply_beam({r, c - 1}, mat, LEFT, energised);
        if (direction == LEFT)
            return apply_beam({r + 1, c}, mat, DOWN, energised);
        if (direction == RIGHT)
            return apply_beam({r - 1, c}, mat, UP, energised);
    }
    if (mat[r][c] == '|')
    {
        if (direction == UP || direction == DOWN)
            return apply_beam(get_next_dir(pos, direction), mat, direction, energised);

        if (direction == LEFT || direction == RIGHT)
        {
            apply_beam({r - 1, c}, mat, UP, energised);
            apply_beam({r + 1, c}, mat, DOWN, energised);
            return;
        }
    }
    if (mat[r][c] == '-')
    {
        if (direction == LEFT || direction == RIGHT)
            return apply_beam(get_next_dir(pos, direction), mat, direction, energised);

        if (direction == UP || direction == DOWN)
        {
            apply_beam({r, c - 1}, mat, LEFT, energised);
            apply_beam({r, c + 1}, mat, RIGHT, energised);
            return;
        }
    }
}

int main()
{
    vector<vector<char>> mat;

    uint32_t res = 0;
    parse_input("input.txt", mat);

    vector<vector<int>> energised(mat.size(), vector<int>(mat[0].size(), 0));

    apply_beam({0,0}, mat, RIGHT, energised);
    //apply_beam_iter(mat, energised);

    for (size_t i = 0; i < energised.size(); i++)
    {
        for (size_t j = 0; j < energised[0].size(); j++)
        {
            if(energised[i][j] != 0)
            {
                res++;
                cout << '#';
            }
            else
                cout << '.';
        }
        cout << endl;
    }
    cout << res<<endl;
    return 0;
}