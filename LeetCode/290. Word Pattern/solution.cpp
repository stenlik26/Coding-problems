#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool wordPattern(string pattern, string s) {
    unordered_map<char, string> dict;

	unordered_set<string> mapped;

	stringstream ss(s);

	string word;

	for (size_t i = 0; i < pattern.size(); i++)
	{
		ss >> word;
		cout << word << endl;

		if (dict.find(pattern[i]) == dict.end())
		{
			if (mapped.find(word) != mapped.end())
				return false;

			dict.insert({ pattern[i], word });
			mapped.insert(word);
		}
		else if (dict[pattern[i]] != word)
		{
			return false;
		}
	}
	return ss.eof();
}

int main()
{
	std::cout << wordPattern("aaa", "aa aa aa aa") << std::endl;
}
