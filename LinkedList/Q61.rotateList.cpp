#include<bits/stdc++.h>
using namespace std;

// 61. Rotate List
// https://leetcode.com/problems/rotate-list/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // Edge Cases
        if (!head || !head->next || k == 0) return head;

        // Step 1: Find length and last node
        int n = 1;
        ListNode *tail = head;
        while(tail->next != NULL){
            tail = tail->next;
            n++;
        }
        // Step 2: Normalize k
        k = k % n;
        if(k == 0) return head;

        // Step 3: Make it circular
        tail->next = head;

        // Step 4: Find new tail (n - k steps)
        int stepsToNewTail = n - k;
        ListNode* newTail = head;
        
        for (int i = 1; i < stepsToNewTail; i++) {
            newTail = newTail->next;
        }

        // Step 5: Set new head and break circle
        ListNode* newHead = newTail->next;
        newTail->next = NULL;

        return newHead;
    }
};


int main() {
    // create linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;
    Solution sol;
    head = sol.rotateRight(head, k);

    // print rotated list
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;

    return 0;
}   