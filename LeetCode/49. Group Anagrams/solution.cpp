#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string sort_word(const string& word)
{
	string n = word;
	sort(n.begin(), n.end());
	return n;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {

	unordered_map<string, vector<string>> map;
	vector<vector<string>> res;

	for (size_t i = 0; i < strs.size(); i++)
	{
		map[sort_word(strs[i])].push_back(strs[i]);
	}

	for (auto i = map.begin(); i != map.end(); ++i)
	{
		res.push_back(i->second);
	}
	return res;
}

int main()
{
	vector<string> t1 = { "eat","tea","tan","ate","nat","bat" };

	vector<vector<string>> res = groupAnagrams(t1);

	for (size_t i = 0; i < res.size(); i++)
	{
		for (size_t j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
}
