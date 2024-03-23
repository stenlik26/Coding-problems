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

void reorderList(ListNode* head) {
    stack<ListNode*> nodes;

    for (ListNode* itr = head; itr != nullptr; itr = itr->next)
    {
        nodes.push(itr);
    }

    ListNode* itr = head;

    const int changes = nodes.size();
    
    for (size_t i = 0; i < changes / 2; i++)
    {
        ListNode* next_backup = itr->next;

        itr->next = nodes.top();

        nodes.pop();

        itr->next->next = next_backup;

        itr = next_backup;
    }
    if(changes <= 1)
        return;

    if(changes % 2 != 0)
        itr->next->next->next = nullptr;
    else
        itr->next->next = nullptr;
}

int main()
{   
    ListNode* t1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
    reorderList(t1);
    print_list(t1);

    ListNode* t2 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    reorderList(t2);
    print_list(t2);

    ListNode* t3 = new ListNode(1);
    reorderList(t3);
    print_list(t3);
    return 0; 

}