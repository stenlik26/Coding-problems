#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void construct(ListNode* top, ListNode* current, ListNode*& t)
{
    if (current == nullptr)
    {
        return;
    }

    construct(top, current->next, t);

    t->val = current->val;

    if(current != top)
        t->next = new ListNode();

    t = t->next;
    
}

ListNode* reverseList(ListNode* head) {

    if (head == nullptr)
        return nullptr;

    ListNode* t = new ListNode();
    ListNode* copy_t = t;
    construct(head, head, t);
    return copy_t;
}

int main()
{
    //1,2,6,3,4,5,6
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    ListNode* rev = reverseList(head);


    while (rev != nullptr)
    {
        cout << rev->val << " ";
        rev = rev->next;
    }cout << endl;

}
