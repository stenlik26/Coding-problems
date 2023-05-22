#include <iostream>
#include <string>
using namespace std;

string convertToTitle(int columnNumber) {
    
    if (columnNumber <= 26)
        return string(1, columnNumber - 1 + 'A');
    else if (columnNumber % 26 != 0)
        return convertToTitle(columnNumber / 26) + convertToTitle(columnNumber % 26);
    else
        return convertToTitle((columnNumber / 26) - 1) + "Z";
}


int main()
{
    for (size_t i = 1; i <= 200; i++)
    {
        cout << "i: " << i << " " << convertToTitle(i) << endl;
    }
}
