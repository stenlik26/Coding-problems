#include<iostream>
#include <string>
#include <fstream>
#include <sstream>
#include<vector>

using namespace std;

int col_to_arr(char c)
{
    switch(c)
    {
        case 'r':
            return 0;
        case 'g':
            return 1;
        case 'b':
            return 2;
        default:
            return -1;
    }
}

uint32_t check_line(int game_num, const string& line)
{
    std::istringstream str(line);

    uint32_t max_color_count[3] = {0};

    int count = 0;
    string word;
    str>>word; //Skip game
    str>>word; //Skip game num

    while(!str.eof())
    {
        str>>count;
        str>>word;

        const int col_idx = col_to_arr(word[0]);

        if(max_color_count[col_idx] < count)
            max_color_count[col_idx] = count;

    }
    return max_color_count[0] * max_color_count[1] * max_color_count[2];
}

void parse_input(const char* filename, uint32_t& valid_games)
{

    std::ifstream input_file;
    input_file.open(filename);

    if(!input_file.is_open())
        return;

    string input_line;
    int game = 1;

    while(input_file.good())
    {
        getline(input_file, input_line);

        if(input_file.eof())
            break; 

        valid_games += check_line(game, input_line);
        game++;
    }

}
int main()
{
    uint32_t games_sum = 0;

    //parse_input("example_input.txt", games_sum);
    parse_input("input.txt", games_sum);

    cout << "Games sum: "<< games_sum << endl;
    return 0; 
}