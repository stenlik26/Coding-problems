#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:

    stack<int> main;
    stack<int> cache;

    MyQueue() {

    }

    void push(int x) {
        while (!main.empty())
        {
            cache.push(main.top());
            main.pop();
        }

        main.push(x);

        while (!cache.empty())
        {
            main.push(cache.top());
            cache.pop();
        }

    }

    int pop() {
        int x = main.top();
        main.pop();
        return x;
    }

    int peek() {
        return main.top();
    }

    bool empty() {
        return main.empty();
    }
};


int main()
{
    std::cout << "Hello World!\n";
}
