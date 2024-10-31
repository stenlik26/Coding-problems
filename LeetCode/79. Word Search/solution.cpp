#include <bits/stdc++.h>
using namespace std;
bool trace(vector<vector<char>> &board, vector<vector<bool>>& visited, const char *word, int r, int c)
{
    if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size())
        return false;

    if (visited[r][c])
        return false;

    visited[r][c] = true;

    if (*word != board[r][c])
        return false;

    if (strlen(word) == 1)
        return true;

    bool res =  trace(board, visited, word + 1, r + 1, c) ||
           trace(board, visited, word + 1, r - 1, c) ||
           trace(board, visited, word + 1, r, c + 1) ||
           trace(board, visited, word + 1, r, c - 1);

    visited[r][c] = false;
    return res;
}

void clear_vector(vector<vector<bool>>& visited, int r,int c)
{
    for (size_t i = 0; i < r; i++)
        for (size_t j = 0; j < c; j++)
            visited[i][j] = false;
}

bool exist(vector<vector<char>> &board, string word)
{
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
    clear_vector(visited, board.size(), board[0].size());
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (trace(board, visited, word.c_str(), i, j))
                return true;

            clear_vector(visited, board.size(), board[0].size());
        }
    }
    return false;
}

int main()
{
    // vector<vector<char>> board = {{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'}};
    vector<vector<char>> board = {{'a','b'},{'c','d'}};
    cout << exist(board, "cdba") << endl;

    return 0;
}