#include<iostream>
#include <string>
#include<vector>
#include<unordered_map>

using namespace std;

bool uniqueOccurrences(vector<int>& arr) {

    unordered_map<int,int> arr_count;

    bool seen_freq[1001] = {false};

    for (size_t i = 0; i < arr.size(); i++)
    {
        arr_count[arr[i]]++;
    }
    
    unordered_map<int,int>::iterator kvp = arr_count.begin();

    for(; kvp != arr_count.end(); ++kvp)
    {
        if(seen_freq[kvp->second])
            return false;

        seen_freq[kvp->second] = true;
    }
    return true;
}

int main()
{

    cout << "Test" << endl; 
    return 0; 

}