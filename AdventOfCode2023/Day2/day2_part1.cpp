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

bool check_line(int game_num, const string& line)
{
    std::istringstream str(line);

    int color_count[3] = {0};

    int count = 0;
    string word;
    str>>word; //Skip game
    str>>word; //Skip game num

    while(!str.eof())
    {
        str>>count;
        str>>word;

        color_count[col_to_arr(word[0])] += count;

        if(word[word.size() - 1] == ';' || str.eof())
        {
            //cout << "Red: " << color_count[0]<< " Green: " << color_count[1] << " Blue: " << color_count[2] << endl;
            if(color_count[0] > 12 || color_count[1] > 13 || color_count[2] > 14)
                return false;

            color_count[0] = color_count[1] = color_count[2] = 0;
        }
    }
    return true;
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

        if(check_line(game, input_line))
        {
            valid_games += game;
        }
        game++;
    }

}
int main()
{
    uint32_t games_sum = 0;

    //xarse_input("example_input.txt", games_sum);
    parse_input("input.txt", games_sum);

    cout << "Games sum: "<< games_sum << endl;
    return 0; 
}