#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{

    vector<vector<int>> res;
    int insert_idx = 0;

    if (intervals.empty())
    {
        res.push_back(newInterval);
        return res;
    }

    while (insert_idx < intervals.size())
    {
        if (intervals[insert_idx][0] >= newInterval[0])
            break;

        insert_idx++;
    }
    insert_idx--;

    for (int i = 0; i < insert_idx; i++)
    {
        res.push_back(intervals[i]);
    }

    if (insert_idx == -1)
    {
        insert_idx++;
    }

    if (intervals[insert_idx][0] >= newInterval[0] && intervals[insert_idx][0] <= newInterval[1])
    {
        vector<int> t = {newInterval[0], max(intervals[insert_idx][1], newInterval[1])};
        res.push_back(t);
    }
    else if (intervals[insert_idx][0] >= newInterval[0] && intervals[insert_idx][0] > newInterval[1])
    {
        res.push_back(newInterval);
        res.push_back(intervals[insert_idx]);
    }
    else if (intervals[insert_idx][1] < newInterval[0])
    {
        res.push_back(intervals[insert_idx]);
        res.push_back(newInterval);
    }
    else if (intervals[insert_idx][1] >= newInterval[0] && intervals[insert_idx][1] <= newInterval[1])
    {
        vector<int> t = {intervals[insert_idx][0], newInterval[1]};
        res.push_back(t);
    }
    else if (intervals[insert_idx][1] > newInterval[0] && intervals[insert_idx][1] >= newInterval[1])
    {
        res.push_back(intervals[insert_idx]);
    }
    insert_idx++;

    for (size_t i = insert_idx; i < intervals.size(); i++)
    {
        if (res[res.size() - 1][1] > intervals[i][1])
            continue;

        if (res[res.size() - 1][1] < intervals[i][0])
        {
            res.push_back(intervals[i]);
            continue;
        }

        if (res[res.size() - 1][1] >= intervals[i][0] && res[res.size() - 1][1] < intervals[i][1])
        {
            res[res.size() - 1][1] = intervals[i][1];
        }
    }

    return res;
}

int main()
{
    // vector<vector<int>> t = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<vector<int>> t = {{0, 2}, {4, 5}, {6, 9}, {11, 15}, {18, 19}};
    vector<int> new_int = {2, 2};
    vector<vector<int>> result = insert(t, new_int);
    return 0;
}