#include <iostream>
#include <string>
using namespace std;

bool winnerOfGame(string colors) {

    const char* word = colors.c_str();

    word++;

    int count = 0;

    while(*word != '\0')
    {
        if(*word == *(word + 1) && *word == *(word - 1))
            count += (*word == 'A') ? 1 : -1;
        word++;
    }

    return count > 0;
}

int main()
{
    std::cout << winnerOfGame("AAABABB") << endl;
    std::cout << winnerOfGame("AA") << endl;
    std::cout << winnerOfGame("ABBBBBBBAAA") << endl;
    return 0;
}