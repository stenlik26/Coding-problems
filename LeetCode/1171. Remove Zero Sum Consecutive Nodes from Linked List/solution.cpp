#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print_list(ListNode *head)
{
    if (head == nullptr)
    {
        std::cout << "\n";
        return;
    }

    std::cout << head->val << " ";

    print_list(head->next);
}

ListNode *removeZeroSumSublists(ListNode *head)
{
    unordered_map<int, ListNode *> prefix_sum;

    ListNode *ptr = head;

    int sum = 0;
    while (ptr != nullptr)
    {
        sum += ptr->val;

        if (prefix_sum.find(sum) != prefix_sum.end())
        {
            int temp_sum = sum;

            ListNode *temp = prefix_sum[sum]->next;
            temp_sum += temp->val;

            while (temp_sum != sum)
            {
                prefix_sum.erase(temp_sum);
                temp = temp->next;
                temp_sum += temp->val;
            }

            prefix_sum[sum]->next = ptr->next;
        }
        else if (sum == 0)
        {
            int t_sum = 0;
            ListNode* t_ptr = head;

            while(t_ptr != ptr->next)
            {
                t_sum += t_ptr->val;
                prefix_sum.erase(t_sum);
                t_ptr = t_ptr->next;
            }

            head = ptr->next;
        }
        else
            prefix_sum[sum] = ptr;

        ptr = ptr->next;
    }
    return head;
}

int main()
{
    return 0;
}