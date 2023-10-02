#include <string>
#include <iostream>
using namespace std;

string defangIPaddr(string address) {

    string new_address = "";

    for (int i = 0; i < address.size(); ++i)
    {
        if(address[i] == '.')
            new_address += "[.]";
        else
            new_address += address[i];
    }

    return new_address;
}
int main()
{
    cout << defangIPaddr("192.168.0.1")<<endl;
    return 0;
}
