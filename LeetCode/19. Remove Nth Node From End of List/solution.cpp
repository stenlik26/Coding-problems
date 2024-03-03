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

ListNode* removeNthFromEnd(ListNode* head, int n) {
    stack<ListNode*> nodes;

    ListNode* curr = head;

    while(curr != nullptr)
    {
        nodes.push(curr);
        curr = curr->next;
    }

    while(n > 0)
    {
        nodes.pop();
        n--;
    }
    
    if(nodes.empty())
        return head->next;

    nodes.top()->next = nodes.top()->next->next;

    return head;
}

int main()
{
    ListNode* t = new ListNode(1);
    //ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    
    print_list(t);
    t = removeNthFromEnd(t, 2);
    print_list(t);
    
    return 0; 

}