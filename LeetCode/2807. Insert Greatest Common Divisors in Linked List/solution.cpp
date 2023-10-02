#include<iostream>
#include <string>
#include<vector>

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

const int gcd(int a,int b)
{
    while(b != 0)
    {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

ListNode* insertGreatestCommonDivisors(ListNode* head) {
    
    ListNode* current = head;

    while(current->next != nullptr)
    {
        current->next = new ListNode(gcd(current->val, current->next->val), current->next);
        current = current->next->next;
    }
    return head;
}


int main()
{
    ListNode* head = new ListNode(18);
    head->next = new ListNode(6);
    head->next->next = new ListNode(10);
    head->next->next->next = new ListNode(3);


    print_list(head);

    head = insertGreatestCommonDivisors(head);

    print_list(head);

    return 0; 
}