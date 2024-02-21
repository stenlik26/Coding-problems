#include<iostream>
#include <string>
#include<vector>

using namespace std;

bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n-1)) == 0;
}

int main()
{

    cout << "Test" << endl; 
    return 0; 

}