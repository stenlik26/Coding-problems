#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool first_row_char(char c)
{
    return c == 'a' || c == 'A' ||
        c == 's' || c == 'S' ||
        c == 'd' || c == 'D' ||
        c == 'f' || c == 'F' ||
        c == 'g' || c == 'G' ||
        c == 'h' || c == 'H' ||
        c == 'j' || c == 'J' ||
        c == 'k' || c == 'K' ||
        c == 'l' || c == 'L';
}

bool second_row_char(char c)
{
    return c == 'q' || c == 'Q' ||
        c == 'w' || c == 'W' ||
        c == 'e' || c == 'E' ||
        c == 'r' || c == 'R' ||
        c == 't' || c == 'T' ||
        c == 'y' || c == 'Y' ||
        c == 'u' || c == 'U' ||
        c == 'i' || c == 'I' ||
        c == 'o' || c == 'O' ||
        c == 'p' || c == 'P';
}

bool third_row_char(char c)
{
    return c == 'Z' || c == 'z' ||
        c == 'X' || c == 'x' ||
        c == 'C' || c == 'c' ||
        c == 'V' || c == 'v' ||
        c == 'B' || c == 'b' ||
        c == 'N' || c == 'n' ||
        c == 'M' || c == 'm';
}

bool is_word_x_row(const char* c, bool (*row_check)(char))
{
    if (*c == '\0')
        return true;

    if (row_check(*c))
        return is_word_x_row(c + 1, row_check);
    else
        return false;
}

vector<string> findWords(vector<string>& words) {
    vector<string> res;

    for (size_t i = 0; i < words.size(); i++)
    {
        const char* word = words[i].c_str();
        if (is_word_x_row(word, &first_row_char) ||
            is_word_x_row(word, &second_row_char) ||
            is_word_x_row(word, &third_row_char))
            res.push_back(word);
    }
    return res;
}

int main()
{
    vector<string> t1 = { "Hello","Alaska","Dad","Peace" };
    vector<string> t2 = { "omk"};
    vector<string> t3 = { "adsdf","sfd" };

    vector<string> res = findWords(t3);

    for (size_t i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }cout << endl;
}
