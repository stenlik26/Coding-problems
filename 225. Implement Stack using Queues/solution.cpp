#include <iostream>
#include <queue>
using namespace std;

void print_queue(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

class MyStack {

private:
    queue<int> q1;
    queue<int> q2;
    bool q1_active;

public:
    MyStack() {
        q1_active = true;
    }

    void push(int x) {

        queue<int>* active = nullptr;
        queue<int>* bak = nullptr;

        if (q1_active)
        {
            active = &q1;
            bak = &q2;
        }
        else
        {
            active = &q2;
            bak = &q1;
        }

        bak->push(x);

        while(!active->empty())
        {
            bak->push(active->front());
            active->pop();
        }
        q1_active = !q1_active;
    }

    int pop() {

        queue<int>* active = nullptr;

        if (q1_active)
            active = &q1;
        else
            active = &q2;

        int x = active->front();
        active->pop();
        return x;
    }

    int top() {
        return q1_active ? q1.front() : q2.front();
    }

    bool empty() {
        return q1_active ? q1.empty() : q2.empty();
    }
};

int main()
{
    MyStack* myStack = new MyStack();
    myStack->push(1);
    myStack->push(2);
    myStack->push(3);
    cout << myStack->pop() << "\n"; // return 2
    cout << myStack->pop() << "\n"; // return 2
    cout << myStack->pop() << "\n"; // return 2
    cout << myStack->empty() << "\n"; // return False
}
