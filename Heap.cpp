#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
    vector<int> heap;

    void heapify(int i) {
        int n = heap.size();
        int smallest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;

        if (l < n && heap[l] < heap[smallest]) smallest = l;
        if (r < n && heap[r] < heap[smallest]) smallest = r;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapify(smallest);
        }
    }

public:
    void insert(int shelfLife) {
        heap.push_back(shelfLife);
        int i = heap.size() - 1;

        while (i > 0 && heap[(i-1)/2] > heap[i]) {
            swap(heap[i], heap[(i-1)/2]);
            i = (i-1)/2;
        }
    }

    int extractMin() {
        if (heap.empty()) return -1;
        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);
        return root;
    }

    void display() {
        for (int x : heap) cout << x << " ";
        cout << endl;
    }
};

int main() {
    MinHeap mh;
    mh.insert(5);   // days left
    mh.insert(2);
    mh.insert(10);
    mh.insert(1);

    cout << "Perishable produce (by shelf-life): ";
    mh.display();

    cout << "Next item to distribute (days left): "
         << mh.extractMin();

    return 0;
}
