#include<iostream>
#include <string>
#include<vector>
#include <unordered_map>

using namespace std;

const int numDecodingsWrap(const char* s, unordered_map<string, int>& cache)
{
    if(*s == '\0')
        return 1;

    if(*s == '0')
        return 0;

    if(*(s+1) == '\0')
        return 1;

    if((*s == '1') || (*s == '2' && *(s+1) >= '0' && *(s+1) <= '6'))
    {
        if(*(s+1) == '0')
        {
            if(cache.find(s+2) == cache.end())
                cache[s+2] = numDecodingsWrap(s + 2, cache);

            return cache[s+2];
        }
        else
        {
            if(cache.find(s+1) == cache.end())
                cache[s+1] = numDecodingsWrap(s + 1, cache);

            if(cache.find(s+2) == cache.end())
                cache[s+2] = numDecodingsWrap(s + 2, cache);

            return cache[s+1] + cache[s+2];
        }
    }

    if(cache.find(s+1) == cache.end())
        cache[s+1] = numDecodingsWrap(s + 1, cache);

    return cache[s+1];
    
}

int numDecodings(string s) {

    unordered_map<string, int> cache;

    if(s.find("00") != string::npos)
        return 0;

    return numDecodingsWrap(s.c_str(), cache);
}

void run_test_case(string test)
{
    cout <<test << ": "<< numDecodings(test)<<endl;
}

int main()
{
    run_test_case("306");
    run_test_case("06");
    run_test_case("226");
    run_test_case("12");
    run_test_case("1221");
    run_test_case("999");
    run_test_case("10");
    run_test_case("1010");
    run_test_case("1000");
    run_test_case("2101");
    run_test_case("111111111111111111111111111111111111111111111");


    return 0; 

}