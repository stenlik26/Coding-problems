#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

bool is_vowel(char& c)
{
	return c == 'a' || c == 'A' ||
		c == 'e' || c == 'E' ||
		c == 'o' || c == 'O' ||
		c == 'i' || c == 'I' ||
		c == 'u' || c == 'U';
}

string reverseVowels(string s) {

	string res = "";
	stack<char> vowels;
	queue<char> cons;

	for (size_t i = 0; i < s.length(); i++)
	{
		if (is_vowel(s[i]))
			vowels.push(s[i]);	
		else
			cons.push(s[i]);
	}

	for (size_t i = 0; i < s.length(); i++)
	{
		if (is_vowel(s[i]))
		{
			res += vowels.top();
			vowels.pop();
		}
		else
		{
			res += cons.front();
			cons.pop();
		}
	}
	return res;
}
int main()
{
	cout << reverseVowels("leetcode") << endl;
	cout << reverseVowels("hello") << endl;
}
