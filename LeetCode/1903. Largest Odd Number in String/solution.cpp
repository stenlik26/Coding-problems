#include<iostream>
#include <string>
#include<vector>

using namespace std;

string largestOddNumber(string num) {

    int last_odd_num = num.size() - 1;

    for (; last_odd_num >= 0; last_odd_num--)
    {
        if((num[last_odd_num] - '0') % 2 != 0)
            break;
    }

    if(last_odd_num < 0)
        return "";
        
    return num.substr(0, last_odd_num + 1);
}

int main()
{

 cout << largestOddNumber("52") << endl; 
 cout << largestOddNumber("4206") << endl; 
 cout << largestOddNumber("35427") << endl; 
 return 0; 

}