#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print_list(ListNode* head)
{
    if(head == nullptr)
    {
        std::cout<<"\n";
        return;
    }

    std::cout<<head->val<<" ";

    print_list(head->next);
}

ListNode* middleNode(ListNode* head) {
    stack<ListNode*> nodes;

    ListNode* cur = head;

    while(cur != nullptr)
    {
        nodes.push(cur);
        cur = cur->next;
    }

    int to_pop = nodes.size() / 2;
    if(nodes.size() % 2 == 0)
        to_pop--;

    for (size_t i = 0; i < to_pop; i++)
    {
        nodes.pop();
    }
    
    return nodes.top();
}

int main()
{

    cout << "Test" << endl; 
    return 0; 

}