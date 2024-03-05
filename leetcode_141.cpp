#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head)
{
    ListNode *fast = head, *slow = head;
    while (fast != nullptr)
    {
        fast = fast->next;
        if (fast != nullptr)
            fast = fast->next;
        if (fast == slow)
            return true;
        slow = slow->next;
    }
    return false;
}
int main()
{

    return 0;
}