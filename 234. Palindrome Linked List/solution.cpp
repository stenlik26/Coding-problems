#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};

bool check_pal(ListNode* back, ListNode*& other)
{
    if (back->val != other->val)
        return false;

    other = other->next;
    return true;
}

void palindrome_util(ListNode* head, ListNode*& s, bool& res)
{
    if (head == nullptr)
        return;

    palindrome_util(head->next, s, res);

    res &= check_pal(head, s);
}

bool isPalindrome(ListNode* head) {

    bool res = true;
    palindrome_util(head, head, res);
    return res;
}

int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    //head->next->next->next = new ListNode(1);

    cout << isPalindrome(head) << endl;
}
