#include <iostream>
#include <string>
using namespace std;


bool canConstruct(string ransomNote, string magazine) {

    uint32_t mag_count[26] = { 0 };

	for (size_t i = 0; i < magazine.size(); i++)
	{
		mag_count[magazine[i] - 'a']++;
	}

	for (size_t i = 0; i < ransomNote.size(); i++)
	{
		if (mag_count[ransomNote[i] - 'a'] <= 0)
			return false;

		mag_count[ransomNote[i] - 'a']--;
	}
	return true;

}

int main()
{
	cout << canConstruct("a", "b") << endl;
	cout << canConstruct("aa", "ab") << endl;
	cout << canConstruct("aa", "aab") << endl;
}
