/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int l1 = 0, l2 = 0;
        ListNode *a = headA;
        ListNode *b = headB;
        while (a != NULL)
        {
            l1 += 1;
            a = a->next;
        }
        while (b != NULL)
        {
            l2 += 1;
            b = b->next;
        }
        if (l1 > l2)
        {
            a = headA;
            int i = 0;
            while (i < (l1 - l2))
            {
                a = a->next;
                i++;
            }
            b = headB;
        }
        else
        {
            b = headB;
            int i = 0;
            while (i < (l2 - l1))
            {
                b = b->next;
                i++;
            }
            a = headA;
        }
        while (a != NULL && b != NULL)
        {
            if (a == b)
            {
                break;
            }
            else
            {
                a = a->next;
                b = b->next;
            }
        }
        return a;
    }
};