#include <bits/stdc++.h>
using namespace std;
// 25. Reverse Nodes in k-Group
// https://leetcode.com/problems/reverse-nodes-in-k-group/



// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    void reverse(ListNode *head, int times)
    {
        ListNode *curr = head;
        ListNode *prev = NULL;
        while (times-- && curr)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == NULL)
            return head;

        ListNode *left = head;
        ListNode *prevleft = NULL;
        ListNode *res = NULL;
        ListNode *right;
        int size = k;

        while (right)
        {
            right = left;
            for (int i = 1; i < size && right; i++)
            {
                right = right->next;
            }

            if (right)
            {
                ListNode *nextleft = right->next;
                reverse(left, size);

                if (prevleft)
                {
                    prevleft->next = right;
                }
                else
                {
                    res = right;
                }
                prevleft = left;
                left = nextleft;
            }
            else
            {
                if (prevleft)
                    prevleft->next = left;

                if (res == NULL)
                    res = left;

                break;
            }
        }
        return res;
    }
};


int main()
{
    // create linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;

    Solution sol;
    head = sol.reverseKGroup(head, k);

    // print the modified list
    while (head != NULL)
    {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;

    return 0;
}