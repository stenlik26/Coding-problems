#include<iostream>
#include <string>
#include<vector>

using namespace std;

int minOperations(string s) {

    bool current_one = true, current_zero = false; // 101; 010 - are valid

    int changes_one = 0, changes_two = 0;

    for(string::iterator itr = s.begin(); itr != s.end(); itr++)
    {
        if(*itr == '0' && current_one)
            changes_one++;

        if(*itr == '1' && !current_one)
            changes_one++;

        if(*itr == '0' && current_zero)
            changes_two++;

        if(*itr == '1' && !current_zero)
            changes_two++;

        current_one = !current_one;
        current_zero = !current_zero;
    }

    return std::min(changes_two, changes_one);
}

int main()
{

    cout << minOperations("0100")<< endl; 
    cout << minOperations("10")<< endl; 
    cout << minOperations("1111")<< endl; 
    return 0; 

}