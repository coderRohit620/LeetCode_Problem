import java.util.*;

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
public class Intro {

    void minHeap(){
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        // insert
        pq.add(10);
        pq.add(20);
        pq.add(50);
        pq.add(90);
        pq.add(22);

        System.out.println("MinHeap Top Element :"+pq.peek());
        pq.poll();

        System.out.println("MinHeap Top Element after poll :"+pq.peek());


    }
    void maxHeap(){
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
         pq.add(10);
        pq.add(20);
        pq.add(50);
        pq.add(90);
        pq.add(22);

        System.out.println("MaxHeap Top Element :"+pq.peek());
        pq.poll();

        System.out.println("MaxHeap Top Element After poll :"+pq.peek());
    }

    public static void main(String[] args) {
        Intro sol = new Intro();
        sol.minHeap();
        sol.maxHeap();
    }
}