/* What is a Heap?

A Heap is a special tree-based data structure that follows a particular ordering rule called the Heap Property.

It is mainly used when we repeatedly need to get the:

Largest element → Max Heap
Smallest element → Min Heap

In coding interviews, you will usually use a heap through Priority Queue.

important Funtion 
1.pq.push(x);
2.pq.pop();
3.pq.top();
4.pq.empty();
5.pq.size();

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Max Heap
    void maxHeap() {

        priority_queue<int> pq;

        // Insert elements
        pq.push(10);
        pq.push(20);
        pq.push(15);
        pq.push(30);
        pq.push(40);

        cout << pq.top() << endl;  // 40

        pq.pop();                  // removes 40

        // cout << pq.top() << endl;  // 30
    }

    // Min Heap
    void minHeap() {

        priority_queue<int, vector<int>, greater<int>> pq;

        pq.push(10);
        pq.push(20);
        pq.push(15);
        pq.push(30);
        pq.push(40);

        cout << pq.top() << endl;  // 10

        pq.pop();                  // removes 10

        // cout << pq.top() << endl;  // 15
    }
};

int main() {

    Solution sol;

    sol.maxHeap();

    sol.minHeap();

    return 0;
}