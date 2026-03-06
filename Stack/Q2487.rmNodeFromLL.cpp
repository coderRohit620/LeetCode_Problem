#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {

        stack<ListNode*> st;
        ListNode* curr = head;

        while(curr != nullptr){
            while(!st.empty() && st.top()->val < curr->val){
                st.pop();
            }
            st.push(curr);
            curr = curr->next;
        }

        ListNode* newHead = nullptr;
        ListNode* tail = nullptr;

        while(!st.empty()){
            ListNode* node = st.top();
            st.pop();

            if(newHead == nullptr){
                newHead = node;
                tail = node;
            }
            else{
                tail->next = node;
                tail = node;
            }
        }

        if(tail != nullptr){
            tail->next = nullptr;
        }

        return newHead;
    }
};


int main(){
    Solution sol;
    ListNode* head = new ListNode(5);
    head->next = new ListNode(2);
    head->next->next = new ListNode(13);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(8);

    ListNode* res = sol.removeNodes(head);

    while(res != nullptr){
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}   