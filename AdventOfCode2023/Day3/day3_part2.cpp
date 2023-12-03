#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>

using namespace std;

void parse_line(const std::string &line, vector<vector<char>> &board)
{
    vector<char> char_line;
    for (size_t i = 0; i < line.size(); i++)
    {
        char_line.push_back(line[i]);
    }
    board.push_back(char_line);
}

void parse_input(const char *filename, vector<vector<char>> &board)
{

    std::ifstream input_file;
    input_file.open(filename);

    if (!input_file.is_open())
        return;

    string input_line;
    while (input_file.good())
    {

        input_file >> input_line;
        parse_line(input_line, board);
    }
}

bool is_number(const char c)
{
    return c >= '0' && c <= '9';
}

bool is_gear(const char c)
{
    return c == '*';
}

bool valid_symbol_pos(int r, int c, int n, const vector<vector<char>> &board, std::pair<int,int>& pos)
{
    if (r < 0 || r >= n || c < 0 || c >= n)
        return false;
    
    if(is_gear(board[r][c]))
    {
        pos = {r,c};
        return true;
    }
    else
    {
        pos = {-1,-1};
        return false;
    }
}

bool has_adj_symbol(int r, int c, int n, const vector<vector<char>> &board, std::pair<int,int>& pos)
{
    return valid_symbol_pos(r - 1, c, n, board, pos) ||
           valid_symbol_pos(r + 1, c, n, board, pos) ||
           valid_symbol_pos(r, c - 1, n, board, pos) ||
           valid_symbol_pos(r, c + 1, n, board, pos) ||
           valid_symbol_pos(r - 1, c - 1, n, board, pos) ||
           valid_symbol_pos(r - 1, c + 1, n, board, pos) ||
           valid_symbol_pos(r + 1, c - 1, n, board, pos) ||
           valid_symbol_pos(r + 1, c + 1, n, board, pos);
}

int compute_map(const unordered_map<std::string, vector<int>> gears)
{
    uint32_t total = 0;

    for (auto i = gears.begin(); i != gears.end(); ++i)
    {
        if(i->second.size() == 2)
        {
            total += i->second[0] * i->second[1];
        }
    }
    return total;
}

int compute_matrix(const vector<vector<char>> &board)
{
    const int n = board.size();
    
    std::unordered_map<std::string, vector<int>> gears_to_numbers;


    for (size_t r = 0; r < n; r++)
    {
        std::pair<int,int> gear_pos = {-1,-1};

        int current_num = 0;
        for (size_t c = 0; c <= n; c++)
        {
            if (c != n && is_number(board[r][c]))
            {
                (current_num *= 10) += board[r][c] - '0';

                if (gear_pos.first == -1)
                    has_adj_symbol(r,c,n,board, gear_pos);
            }
            else if ((c == n && current_num != 0) || (current_num != 0))
            {
                if (gear_pos.first != -1)
                {
                    std::string gear = to_string(gear_pos.first) + ":" + to_string(gear_pos.second);
                    gears_to_numbers[gear].push_back(current_num);
                    cout << current_num << " " << gear << endl;
                }

                current_num = 0;
                gear_pos = {-1,-1};
            }
        }
    }
    return compute_map(gears_to_numbers);
}

int main()
{
    vector<vector<char>> board;

    //parse_input("example_input.txt", board);
    parse_input("input.txt", board);

    cout << compute_matrix(board) << endl;

    return 0;
}