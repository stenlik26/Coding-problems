#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

struct node_info{
    int r;
    int c;
    int path_len;
};

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

void find_start(const vector<vector<char>> &mat, int &start_r, int &start_c)
{
    for (size_t i = 0; i < mat.size(); i++)
    {
        for (size_t j = 0; j < mat[i].size(); j++)
        {
            if (mat[i][j] == 'S')
            {
                start_r = i;
                start_c = j;
                return;
            }
        }
    }
}

bool invalid_pos(int r, int c, int n, int M)
{
    return (r < 0 || c < 0 || r >= n || c >= M);
}

bool pos_visited(const vector<vector<char>> &mat, int r, int c)
{
    return mat[r][c] == '.' || mat[r][c] == 'X';
}

int find_max_dfs(vector<vector<char>>& mat, int s_r,int s_c)
{
    int max_path_len = 0;
    const int N = mat.size();
    const int M = mat[0].size();

    queue<node_info> pos;

    pos.push({s_r,s_c, 0});

    while(!pos.empty())
    {
        int r = pos.front().r;
        int c = pos.front().c;
        int current_path_len = pos.front().path_len;

        pos.pop();

        if(invalid_pos(r, c, N, M))
            continue;

        if(pos_visited(mat,r,c))
            continue;

            
        if (mat[r][c] == 'S')
        {
            mat[r][c] = 'X';

            if(max_path_len < current_path_len)
                max_path_len = current_path_len;

            if (!invalid_pos(r, c + 1, N, M) && (mat[r][c + 1] == '-' || mat[r][c + 1] == 'J' || mat[r][c + 1] == '7'))
                pos.push({r, c+1, current_path_len + 1});

            if (!invalid_pos(r, c - 1, N, M) && (mat[r][c - 1] == '-' || mat[r][c - 1] == 'L' || mat[r][c - 1] == 'F'))
                pos.push({ r, c - 1, current_path_len + 1});

            if (!invalid_pos(r + 1, c, N, M) && (mat[r + 1][c] == '|' || mat[r + 1][c] == 'L' || mat[r + 1][c] == 'J'))
                pos.push({r + 1, c, current_path_len + 1});

            if (!invalid_pos(r - 1, c, N, M) && (mat[r - 1][c] == '|' || mat[r - 1][c] == '7' || mat[r - 1][c] == 'F'))
                pos.push({r - 1, c, current_path_len + 1});
        }
        else if (mat[r][c] == '|')
        {
            mat[r][c] = 'X';

            if(max_path_len < current_path_len)
                max_path_len = current_path_len;

            if (!invalid_pos(r - 1, c, N, M) && !pos_visited(mat, r - 1, c))
                pos.push({r - 1, c, current_path_len + 1});

            else if (!invalid_pos(r + 1, c, N, M) && !pos_visited(mat, r + 1, c))
                pos.push({r + 1, c, current_path_len + 1});
        }
        else if (mat[r][c] == '-')
        {
            mat[r][c] = 'X';

            if(max_path_len < current_path_len)
                max_path_len = current_path_len;

            if (!invalid_pos(r, c - 1, N, M) && !pos_visited(mat, r, c - 1))
                pos.push({r , c - 1, current_path_len + 1});

            if (!invalid_pos(r, c + 1, N, M) && !pos_visited(mat, r, c + 1))
                pos.push({r , c + 1, current_path_len + 1});
        }
        else if (mat[r][c] == 'L')
        {
            mat[r][c] = 'X';

            if(max_path_len < current_path_len)
                max_path_len = current_path_len;

            if (!invalid_pos(r - 1, c, N, M) && !pos_visited(mat, r - 1, c))
                pos.push({r - 1 , c, current_path_len + 1});

            if (!invalid_pos(r, c + 1, N, M) && !pos_visited(mat, r, c + 1))
                pos.push({r , c + 1, current_path_len + 1});
        }
        else if (mat[r][c] == 'J')
        {
            mat[r][c] = 'X';

            if(max_path_len < current_path_len)
                max_path_len = current_path_len;

            if (!invalid_pos(r - 1, c, N, M) && !pos_visited(mat, r - 1, c))
                pos.push({r - 1 , c, current_path_len + 1});

            if (!invalid_pos(r, c - 1, N, M) && !pos_visited(mat, r, c - 1))
                pos.push({r , c - 1, current_path_len + 1});
        }
        else if (mat[r][c] == '7')
        {
            mat[r][c] = 'X';

            if(max_path_len < current_path_len)
                max_path_len = current_path_len;

            if (!invalid_pos(r + 1, c, N, M) && !pos_visited(mat, r + 1, c))
                pos.push({r + 1 , c, current_path_len + 1});

            if (!invalid_pos(r, c - 1, N, M) && !pos_visited(mat, r, c - 1))
                pos.push({r , c - 1, current_path_len + 1});
        }
        else if (mat[r][c] == 'F')
        {
            mat[r][c] = 'X';

            if(max_path_len < current_path_len)
                max_path_len = current_path_len;

            if (!invalid_pos(r + 1, c, N, M) && !pos_visited(mat, r + 1, c))
                pos.push({r + 1 , c, current_path_len + 1});

            if (!invalid_pos(r, c + 1, N, M) && !pos_visited(mat, r, c + 1))
                pos.push({r , c + 1, current_path_len + 1});
        }


    }
    return max_path_len;
}

int main()
{
    vector<vector<char>> mat;

    int start_r = 0, start_c = 0;

    parse_input("example_input2.txt", mat);

    find_start(mat, start_r, start_c);

    int max_path_len = find_max_dfs(mat, start_r, start_c);    



    cout << max_path_len<<endl;

    for (const vector<char> &x : mat)
    {
        for (const char c : x)
        {
            cout << c;
        }
        cout << endl;
    }

    return 0;
}