#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int lengthOfLongestSubstring(string s) {

	int max_size = 0;

	for (size_t i = 0; i < s.size(); i++)
	{
		unordered_set<char> chars;
		int current = 0;

		for (size_t j = i; j < s.size(); j++)
		{
			if (chars.find(s[j]) != chars.end())
				break;

			current++;
			chars.insert(s[j]);
		}
		if (max_size < current)
			max_size = current;
	}
	return max_size;
}

int main()
{
	cout << lengthOfLongestSubstring("abcabcbb") << endl;
	cout << lengthOfLongestSubstring("bbbbbb") << endl;
	cout << lengthOfLongestSubstring("pwwkew") << endl;
	cout << lengthOfLongestSubstring("c") << endl;
	cout << lengthOfLongestSubstring(" ") << endl;
	cout << lengthOfLongestSubstring("") << endl;
}

