#include <iostream>
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

bool hasCycle(ListNode* head) {
    if (head == nullptr)
        return false;

    ListNode* next = head;
    ListNode* next_next = head;

    while (next_next != nullptr && next_next->next != nullptr)
    {
        next_next = next_next->next->next;
        next = next->next;


        if (next == next_next)
            return true;
    }

    return false;
}

int main()
{
    std::cout << "Hello World!\n";
}
