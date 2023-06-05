#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

vector<string> findRelativeRanks(vector<int>& score) {

    vector<pair<int,int>> score_sorted;
    
    for (size_t i = 0; i < score.size(); i++)
    {
        score_sorted.push_back({ score[i], i });
    }

    sort(score_sorted.begin(), score_sorted.end(), 
        [](pair<int, int> a, pair<int, int> b) {return a.first > b.first; });

    vector<string> res(score.size());

    if(score_sorted.size() > 0)
        res[score_sorted[0].second] = "Gold Medal";

    if (score_sorted.size() > 1)
        res[score_sorted[1].second] = "Silver Medal";

    if (score_sorted.size() > 2)
        res[score_sorted[2].second] = "Bronze Medal";


    for (size_t i = 3; i < score.size(); i++)
    {
        res[score_sorted[i].second] = to_string(i + 1);
    }

    return res;
    
}

int main()
{
    vector<int> t1 = { 1 };

    vector<string> res = findRelativeRanks(t1);

    for (size_t i = 0; i < t1.size(); i++)
    {
        cout << res[i] << " ";
    }cout << endl;
}
