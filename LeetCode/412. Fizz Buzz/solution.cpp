#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> fizzBuzz(int n) {

    vector<string> ans(n);

	for (size_t i = 0; i < n; i++)
	{
		ans[i] = to_string(i + 1);
	}

	for (size_t i = 2; i < n; i+=3)
	{
		ans[i] = "Fizz";
	}

	for (size_t i = 4; i < n; i += 5)
	{
		ans[i] = "Buzz";
	}

	for (size_t i = 14; i < n; i += 15)
	{
		ans[i] = "FizzBuzz";
	}
	return ans;
}

int main()
{
	vector<string> res = fizzBuzz(15);

	for (size_t i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	cout << endl;
}
