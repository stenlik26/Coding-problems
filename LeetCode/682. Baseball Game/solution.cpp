#include <iostream>
#include <vector>
#include <string>
using namespace std;

int calPoints(vector<string>& operations) {

    vector<int> res;

    for (int i = 0; i < operations.size(); i++)
    {
        string cur = operations[i];
        
        if (cur == "+")
        {
            int last = res.size() - 1;
            res.push_back(res[last] + res[last - 1]);
        }
        else if (cur == "D")
        {
            res.push_back(res.back() * 2);
        }
        else if (cur == "C")
        {
            res.pop_back();
        }
        else
        {
            res.push_back(stoi(cur));
        }
    }

    uint32_t sum = 0;
    for (auto i = res.begin(); i < res.end(); ++i)
        sum += *i;

    return sum;
}

int main()
{
    vector<string> operations = { "5","2","C","D","+" };
    vector<string> operations2 = { "5","-2","4","C","D","9","+","+" };

    std::cout << "Test1: " << calPoints(operations) << std::endl;
    std::cout << "Test2: " << calPoints(operations2) << std::endl;
}
