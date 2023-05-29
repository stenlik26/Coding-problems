#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

char findTheDifference(string s, string t) {

	int map_s[26] = { 0 };
	int map_t[26] = { 0 };

	for (size_t i = 0; i < s.size(); i++)
	{
		map_s[s[i] - 'a']++;
		map_t[t[i] - 'a']++;
	}
	map_t[t[t.size() - 1] - 'a']++;

	for (size_t i = 0; i < 26; i++)
	{
		if (map_s[i] != map_t[i])
			return i + 'a';
	}
	return 'a';
}
int main()
{
	cout << findTheDifference("abcd", "abcde") << endl;
	cout << findTheDifference("", "y") << endl;
}
