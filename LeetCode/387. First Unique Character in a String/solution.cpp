#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int firstUniqChar(string s) {
    unordered_map<char, int> map;

	for (size_t i = 0; i < s.size(); i++)
	{
		map[s[i]]++;
	}

	for (size_t i = 0; i < s.size(); i++)
	{
		if (map[s[i]] == 1)
			return i;
	}
	return -1;
}

int main()
{
	cout << firstUniqChar("leetcode") << endl;
	cout << firstUniqChar("loveleetcode") << endl;
	cout << firstUniqChar("aabb") << endl;
}
