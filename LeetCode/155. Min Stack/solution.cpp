#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> current_stack;

    stack<int> min_elements;

    int min_element = INT_MAX;

public:
    MinStack() {

    }

    void push(int val) {
        current_stack.push(val);

        if (val <= min_element)
        {
            min_elements.push(min_element);
            min_element = val;
        }
    }

    void pop() {

        if (current_stack.top() == min_element)
        {
            min_element = min_elements.top();
            min_elements.pop();
        }

        current_stack.pop();
    }

    int top() {
        return current_stack.top();
    }

    int getMin() {
        return min_element;
    }
};

int main()
{
    MinStack mins = MinStack();

    mins.push(-2);
    mins.push(0);
    mins.push(-3);

    cout << mins.getMin() << endl;

    mins.pop();

    std::cout << mins.top() << endl;
    cout << mins.getMin() << endl;
}
