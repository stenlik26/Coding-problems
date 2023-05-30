#include <iostream>
#include <string>
using namespace std;

int longestPalindrome(string s) {
    uint32_t chars[52] = {0};

	uint32_t total = 0;

	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			chars[s[i] - 'A']++;
		else
			chars[s[i] - 'a' + 26]++;
	}

	for (size_t i = 0; i < 52; i++)
	{
		total += chars[i] - chars[i] % 2;
		chars[i] -= chars[i] - chars[i] % 2;
	}

	for (size_t i = 0; i < 52; i++)
	{
		if (chars[i] == 1)
		{
			total++;
			break;
		}
	}
	return total;
}

int main()
{
	cout << longestPalindrome("abccccdd") << endl;
	cout << longestPalindrome("a") << endl;
	cout << longestPalindrome("aaaaaaaaabbbdd") << endl;
}
