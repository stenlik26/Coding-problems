#include<iostream>
#include <string.h>
#include<vector>

using namespace std;

const bool is_good(const string& num)
{
    return num[0] == num[1] && num[0] == num[2];
}


string largestGoodInteger(string num) {

    string res = "";

    for (size_t i = 0; i < num.size() - 2; i++)
    {
        string sub = num.substr(i, 3);
        if(is_good(sub) && strcmp(res.c_str(), sub.c_str()) < 0)
            res = sub;
    }
    
    return res;
}

int main()
{

 cout << largestGoodInteger("6777133339") << endl; 
 cout << largestGoodInteger("2300019") << endl; 
 cout << largestGoodInteger("42352338") << endl; 
 cout << largestGoodInteger("333") << endl; 
 return 0; 

}