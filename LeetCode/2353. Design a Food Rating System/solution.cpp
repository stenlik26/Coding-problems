#include<iostream>
#include <string.h>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<set>

using namespace std;
struct cmp {
    bool operator() (const pair<string, int*>& x, const pair<string, int*>& y) const
    {
        if (*(x.second) != *(y.second))
            return *(x.second) > *(y.second);
        else
            return x.first.compare(y.first) < 0;
    }
};

class FoodRatings {
private:
    unordered_map<string, int> food_to_idx;
    vector<int> ratings;
    vector<string> cuis;

    unordered_map<string, std::set<pair<string, int*>, cmp>> map;

private:


public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        this->ratings = ratings;
        this->cuis = cuisines;

        for (size_t i = 0; i < foods.size(); i++)
        {
            food_to_idx[foods[i]] = i;
            map[cuisines[i]].insert({ foods[i], &(this->ratings[i]) });
        }

    }

    void changeRating(string food, int newRating) {

        pair<string, int*> current = { food, &ratings[food_to_idx[food]] };

        map[this->cuis[food_to_idx[food]]].erase(current);

        this->ratings[food_to_idx[food]] = newRating;

        map[this->cuis[food_to_idx[food]]].insert(current);

    }

    string highestRated(string cuisine) {
        auto x = map[cuisine].begin();
        return x->first;
    }
};

int main()
{
    vector<string> foods_test = { "kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi" };
    vector<string> cuis_test = { "korean", "japanese", "japanese", "greek", "japanese", "korean" };
    vector<int> ratings = { 9, 12, 8, 15, 14, 7 };
    FoodRatings* foodRatings = new FoodRatings(foods_test, cuis_test, ratings);

    cout << foodRatings->highestRated("korean") << endl; // return "kimchi"
        
    cout << foodRatings->highestRated("japanese") << endl; // return "ramen"
   
    foodRatings->changeRating("sushi", 16); // "sushi" now has a rating of 16.
    
    cout << foodRatings->highestRated("japanese") << endl; // return "sushi"

    foodRatings->changeRating("ramen", 16); // "ramen" now has a rating of 16.
    cout << foodRatings->highestRated("japanese") << endl; // return "ramen"

    return 0;

}