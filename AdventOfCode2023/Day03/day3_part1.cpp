#include <iostream>
#include <string>
#include <fstream>
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

bool is_symbol(const char c)
{
    return !is_number(c) && c != '.';
}

bool valid_symbol_pos(int r, int c, int n, const vector<vector<char>> &board)
{
    if (r < 0 || r >= n || c < 0 || c >= n)
        return false;
    return is_symbol(board[r][c]);
}

bool has_adj_symbol(int r, int c, int n, const vector<vector<char>> &board)
{
    return valid_symbol_pos(r - 1, c, n, board) ||
           valid_symbol_pos(r + 1, c, n, board) ||
           valid_symbol_pos(r, c - 1, n, board) ||
           valid_symbol_pos(r, c + 1, n, board) ||
           valid_symbol_pos(r - 1, c - 1, n, board) ||
           valid_symbol_pos(r - 1, c + 1, n, board) ||
           valid_symbol_pos(r + 1, c - 1, n, board) ||
           valid_symbol_pos(r + 1, c + 1, n, board);
}

int compute_matrix(const vector<vector<char>> &board)
{
    const int n = board.size();

    uint32_t total = 0;

    for (size_t r = 0; r < n; r++)
    {
        cout << endl;
        bool has_adj = false;
        int current_num = 0;
        for (size_t c = 0; c <= n; c++)
        {
            if (c != n && is_number(board[r][c]))
            {
                (current_num *= 10) += board[r][c] - '0';

                if (!has_adj)
                    has_adj = has_adj_symbol(r, c, n, board);
            }
            else if ((c == n && current_num != 0) || (current_num != 0))
            {
                cout << current_num << " " << has_adj << endl;
                if (has_adj)
                    total += current_num;

                current_num = 0;
                has_adj = false;
            }
        }
    }
    return total;
}

int main()
{
    vector<vector<char>> board;

    // parse_input("example_input.txt", board);
    parse_input("input.txt", board);

    cout << compute_matrix(board) << endl;

    return 0;
}