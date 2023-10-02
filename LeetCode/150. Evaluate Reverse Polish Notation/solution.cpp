#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const bool is_sign(const string c)
{
	return c == "+" || c == "-" || c == "/" || c == "*";
}

int evalRPN(const vector<string>& tokens) {
	stack<int> queued;
	for (auto i = tokens.begin(); i < tokens.end(); ++i)
	{
		if (!is_sign((*i)))
		{
			queued.push(atoi((*i).c_str()));
		}
		else
		{
			int current = queued.top();
			queued.pop();

			if ((*i)[0] == '+')
				current = queued.top() + current;
			else if ((*i)[0] == '-')
				current = queued.top() - current;
			else if ((*i)[0] == '/')
				current = queued.top() / current;
			else if ((*i)[0] == '*')
				current = queued.top() * current;

			queued.pop();
			queued.push(current);
		}
	}
	return queued.top();
}

int main()
{
	cout << evalRPN({ "2", "1", "+", "3", "*" }) << endl;
	cout << evalRPN({ "4","13","5","/","+" }) << endl;
	cout << evalRPN({ "10","6","9","3","+","-11","*","/","*","17","+","5","+" }) << endl;
}
