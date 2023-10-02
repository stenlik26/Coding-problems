#include <iostream>
#include <string>
using namespace std;

const string reverse_word(const string& word)
{
    string reversed = "";

	for (int i = word.size() - 1; i >= 0; i--)
	{
		reversed += word[i];
	}

	return reversed;
}

string reverseWords(string s) {

	int current_char = 0;

	string current_word = "";
	string result = "";

	while (current_char < s.size())
	{
		if (s[current_char] == ' ')
		{
			result += reverse_word(current_word);
			result += ' ';
			current_word = "";
		}
		else
			current_word += s[current_char];

		current_char++;
	}

	result += reverse_word(current_word);

	return result;
}

int main()
{
	cout << reverseWords("Let's take LeetCode contest") << endl;
	cout << reverseWords("God Ding") << endl;
}
