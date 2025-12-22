#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
private:
    vector<int> heap;

    void heapify(int k) {
        int n = heap.size();
        while (2 * k + 1 < n) {
            int j = 2 * k + 1;
            if (j + 1 < n && heap[j] < heap[j + 1]) j++;
            if (heap[k] >= heap[j]) break;
            swap(heap[k], heap[j]);
            k = j;
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        int k = heap.size() - 1;
        while (k > 0 && heap[k] > heap[(k - 1) / 2]) {
            swap(heap[k], heap[(k - 1) / 2]);
            k = (k - 1) / 2;
        }
    }

    int removeTop() {
        if (heap.empty()) return -1;
        int top = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);
        return top;
    }

    bool isEmpty() {
        return heap.empty();
    }

    void printQueue() {
        for (int val : heap) cout << val << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    pq.insert(50);  // Example hazardous waste quantities
    pq.insert(20);
    pq.insert(80);
    pq.insert(10);

    cout << "Priority Queue (Max Heap) for hazardous waste: ";
    pq.printQueue();

    cout << "Removing top element: " << pq.removeTop() << endl;
    cout << "Queue after removal: ";
    pq.printQueue();

    return 0;
}
