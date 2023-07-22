#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};

void print_list(ListNode* l)
{
    if (l == nullptr)
    {
        cout << endl;
        return;
    }
    cout << l->val << " ";
    print_list(l->next);
}

void reverse_list(ListNode*& l)
{
    ListNode *curr = nullptr, *prev = nullptr, *next = nullptr;

    curr = l;
    while (curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    l = prev;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    reverse_list(l1);
    reverse_list(l2);

    ListNode* output = new ListNode();
    ListNode* out_copy = output;

    bool carry = false;

    while (l1 != nullptr || l2 != nullptr)
    {
        output->val =
            (l1 != nullptr ? l1->val : 0) +
            (l2 != nullptr ? l2->val : 0);

        if (carry)
        {
            output->val++;
            carry = false;
        }

        if (output->val > 9)
        {
            output->val %= 10;
            carry = true;
        }

        if (l1 != nullptr)
            l1 = l1->next;

        if (l2 != nullptr)
            l2 = l2->next;

        if (l1 != nullptr || l2 != nullptr)
        {
            output->next = new ListNode();
            output = output->next;
        }
    }

    if (carry)
    {
        output->next = new ListNode(1);
    }

    reverse_list(out_copy);

    return out_copy;
}

int main()
{
    ListNode* l1 = new ListNode(7);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    l1->next->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode* res = addTwoNumbers(l1, l2);

}
