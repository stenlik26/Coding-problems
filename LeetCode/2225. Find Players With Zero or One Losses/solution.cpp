#include<iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> findWinners(vector<vector<int>>& matches) {
    unordered_set<int> players;
    unordered_map<int,int> players_to_looses;

    vector<int> only_winners;
    vector<int> only_one_loss;

    for (size_t i = 0; i < matches.size(); i++)
    {
        players.insert(matches[i][0]);
        players.insert(matches[i][1]);

        players_to_looses[matches[i][1]]++;
    }
    
    unordered_set<int>::iterator itr = players.begin();

    for(; itr != players.end(); ++itr)
    {
        if(players_to_looses.find(*itr) == players_to_looses.end())
        {
            only_winners.push_back(*itr);
            continue;
        }
        else if(players_to_looses[*itr] == 1)
            only_one_loss.push_back(*itr);
    }

    sort(only_winners.begin(), only_winners.end());
    sort(only_one_loss.begin(), only_one_loss.end());

    return {only_winners, only_one_loss};
}

int main()
{

    cout << "Test" << endl; 
    return 0; 

}