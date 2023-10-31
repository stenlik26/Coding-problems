#include <iostream>
#include <stack>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};

const int fast_pow(int x)
{
    return (1 << x);
}

int getDecimalValue(ListNode* head) {
    std::stack<bool> els;

    int res = 0;

    while (head != nullptr) 
    {
        els.push((bool)head->val);
        head = head->next;
    }
    int x = els.size();
    for (size_t i = 0; i < x; i++)
    {
        if (els.top())
            res += fast_pow(i);
        els.pop();
    }
    return res;
}

int main()
{
    ListNode* num = new ListNode{ 1, new ListNode{0, new ListNode{1, nullptr}}};
    std::cout << getDecimalValue(num) << std::endl;
}
