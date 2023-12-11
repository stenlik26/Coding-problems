#include<iostream>
#include <string.h>
#include <fstream>
#include<vector>
#include<algorithm>

using namespace std;

const int map_card_to_val(char c)
{
    switch(c)
    {
        case 'J':
            return 2;
        case '2':
            return 3;
        case '3':
            return 4;
        case '4':
            return 5;
        case '5':
            return 6;
        case '6':
            return 7;
        case '7':
            return 8;
        case '8':
            return 9;
        case '9':
            return 10;
        case 'T':
            return 11;
        case 'Q':
            return 12;
        case 'K':
            return 13;
        case 'A':
            return 14;
    }
}

enum strength {
    high_card = 0,
    one_pair = 1,
    two_pair = 2,
    three_of_kind = 3,
    full_house = 4,
    four_kind = 5,
    five_kind = 6
};

struct hand
{
    string cards;
    int bid;
    strength type;
    int rank;

    bool operator < (const hand& other) const
    {
        if(type != other.type)
            return type < other.type;

        for (size_t i = 0; i < 5; i++)
        {
            if(cards[i] != other.cards[i])
                return map_card_to_val(cards[i]) < map_card_to_val (other.cards[i]);
        }
        return false; 
    }
};

void parse_input(const char* filename, vector<hand>& hands)
{

    std::ifstream input_file;
    input_file.open(filename);

    if(!input_file.is_open())
        return;

    string input_line;
    while(input_file.good())
    {
        hand current;
        input_file >> current.cards;
        input_file >> current.bid;
        current.type = high_card;
        hands.push_back(current);
    }
}

void map_types(vector<hand>& hands)
{
    for (size_t i = 0; i < hands.size(); i++)
    {
        const string& cards = hands[i].cards;

        int card_count[13] = {0};

        for (size_t j = 0; j < cards.size(); j++)
        {
            card_count[map_card_to_val(cards[j]) - 2]++;
        }

        int pairs = 0;
        int triplets = 0;

        if(card_count[0] != 0)
        {
            int max_idx = 1;
            int max = card_count[1];
            for (size_t i = 2; i < 13; i++)
            {
                if(max < card_count[i])
                {
                    max = card_count[i];
                    max_idx = i;
                }
            }
            card_count[max_idx] += card_count[0];
        }
        
        for (size_t j = 1; j < 13; j++)
        {
            if(card_count[j] == 5)
            {
                hands[i].type = five_kind;
                break;
            }
            if(card_count[j] == 4)
            {
                hands[i].type = four_kind;
                break;
            }
            if(card_count[j] == 3)
            {
                triplets++;
            }
            if(card_count[j]== 2)
            {
                pairs++;
            }
        }
        if(hands[i].type != high_card)
            continue;

        if(pairs == 1 && triplets == 1)
            hands[i].type = full_house;
        else if(triplets == 1)
            hands[i].type = three_of_kind;
        else if (pairs == 2)
            hands[i].type = two_pair;
        else if (pairs == 1)
            hands[i].type = one_pair;       
    }
    
}

void map_ranks(vector<hand>& hands)
{
    for (size_t i = 0; i < hands.size(); i++)
    {
       hands[i].rank = i + 1;
    }
    
}

uint32_t get_score(const vector<hand>& hands)
{
    uint32_t res = 0;
    for (size_t i = 0; i < hands.size(); i++)
    {
        res += hands[i].bid * hands[i].rank;
    }
    return res;
}

int main()
{
    vector<hand> hands;

    parse_input("input.txt", hands);
    map_types(hands);

    std::sort(hands.begin(), hands.end());

    map_ranks(hands);

    cout << get_score(hands)<<endl;
    return 0; 
}