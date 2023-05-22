#include <iostream>
#include <unordered_set>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}

};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    int carry = 0;

    int val = l1->val + l2->val + carry;

    ListNode* n = new ListNode(val % 10);
    ListNode* n_c = n;
    carry = val / 10;
    l1 = l1->next;
    l2 = l2->next;

    while (l1 != nullptr && l2 != nullptr)
    {
        val = l1->val + l2->val + carry;
        n->next = new ListNode(val % 10);
        carry = val / 10;
        n = n->next;

        l1 = l1->next;
        l2 = l2->next;
    }

    while (l1 != nullptr)
    {
        val = l1->val + carry;
        n->next = new ListNode(val % 10);
        carry = val / 10;
        n = n->next;

        l1 = l1->next;
    }

    while (l2 != nullptr)
    {
        val = l2->val + carry;
        n->next = new ListNode(val % 10);
        carry = val / 10;
        n = n->next;

        l2 = l2->next;
    }

    if (carry != 0)
    {
        n->next = new ListNode(carry);
    }

    return n_c;
}

int main()
{
    ListNode* n = new ListNode(2);
    n->next = new ListNode(4);
    n->next->next = new ListNode(3);

    ListNode* m = new ListNode(5);
    m->next = new ListNode(6);
    m->next->next = new ListNode(4);

    ListNode* n_m = addTwoNumbers(n, m);

    for (ListNode* i = n_m; i != nullptr; i = i->next)
    {
        cout << i->val << " ";
    }cout << endl;
}
