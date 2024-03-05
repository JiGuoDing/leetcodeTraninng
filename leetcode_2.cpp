#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    int sum, carry = 0;
    ListNode *res = new ListNode();
    ListNode *result = res;
    while (l1 != nullptr && l2 != nullptr)
    {
        sum = l1->val + l2->val + carry;
        if (sum >= 10)
        {
            carry = 1;
            sum -= 10;
        }
        else
            carry = 0;
        ListNode *node = new ListNode();
        node->val = sum;
        res->next = node;
        res = res->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1 != nullptr)
    {
        sum = l1->val + carry;
        if (sum >= 10)
        {
            carry = 1;
            sum -= 10;
        }
        else
            carry = 0;
        ListNode *node = new ListNode();
        node->val = sum;
        res->next = node;
        res = res->next;
        l1 = l1->next;
    }
    while (l2 != nullptr)
    {
        sum = l2->val + carry;
        if (sum >= 10)
        {
            carry = 1;
            sum -= 10;
        }
        else
            carry = 0;
        ListNode *node = new ListNode();
        node->val = sum;
        res->next = node;
        res = res->next;
        l2 = l2->next;
    }
    if (carry == 1)
    {
        ListNode *node = new ListNode();
        node->val = carry;
        res->next = node;
        res = res->next;
    }
    res = result->next;
    delete (result);
    return res;
}

int main()
{

    return 0;
}