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

ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    
    ListNode* list1_iter = list1;

    for (size_t i = 0; i < a - 1; i++)
    {
        list1_iter = list1_iter->next;
    }
    
    ListNode* insert_tail = list1_iter;

    for (size_t i = 0; i <= b - a; i++)
    {
        insert_tail = insert_tail->next;
    }

    list1_iter->next = list2;
    
    while(list1_iter->next != nullptr)
        list1_iter = list1_iter->next;

    list1_iter->next = insert_tail;
    
    return list1;
}

int main()
{

    cout << "Test" << endl; 
    return 0; 

}