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

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

    unordered_set<ListNode*> points;
    while (headA != nullptr)
    {
        points.insert(headA);
        headA = headA->next;
    }

    while (headB != nullptr)
    {
        if (points.find(headB) != points.end())
            return headB;
        headB = headB->next;
    }
    return nullptr;
}
int main()
{
    std::cout << "Hello World!\n";
}
