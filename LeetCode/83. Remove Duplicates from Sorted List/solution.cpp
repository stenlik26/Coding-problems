
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}

};


void print_list(ListNode* list)
{
    cout << list->val << " ";

    if (list->next == nullptr)
    {
        cout << endl;
        return;
    }

    print_list(list->next);
}

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* head_copy = head;
    while (head_copy != nullptr)
    {
        while (head_copy->next->val == head_copy->val)
        {
            head_copy->next = head_copy->next->next;
        }
        head_copy = head_copy->next;
    }
    return head;
}

int main()
{
    ListNode a(2);
    ListNode x(1, &a);


    ListNode* list1 = new ListNode(1, &x);
    print_list(list1);
    ListNode* newlist = deleteDuplicates(list1);

    print_list(newlist);

    delete list1;
}

