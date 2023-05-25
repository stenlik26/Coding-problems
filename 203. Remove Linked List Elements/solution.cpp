#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* removeElements(ListNode* head, int val) {

    while (head != nullptr && head->val == val)
    {
        head = head->next;
    }

    ListNode* copy = head;

    while (copy != nullptr)
    {
        if (copy->next == nullptr)
            break;

        if (copy->next->val == val)
            copy->next = copy->next->next;
        else
            copy = copy->next;
    }
    return head;
}

int main()
{
    //1,2,6,3,4,5,6
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);

    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(2);
    head2->next->next->next = new ListNode(1);

    ListNode* new_h = removeElements(head2, 2);


    while (new_h != nullptr)
    {
        cout << new_h->val << " ";
        new_h = new_h->next;
    }cout << endl;

}
