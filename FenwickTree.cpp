#include <iostream>
#include <vector>
using namespace std;

class FenwickTree {
    vector<int> tree;
public:
    FenwickTree(int n) { tree.resize(n + 1, 0); }

    void update(int i, int val) {
        while (i < tree.size()) {
            tree[i] += val;
            i += i & -i;
        }
    }

    int query(int i) {
        int sum = 0;
        while (i > 0) {
            sum += tree[i];
            i -= i & -i;
        }
        return sum;
    }
};

int main() {
    FenwickTree ft(5);

    ft.update(1, 3000);
    ft.update(2, 4000);
    ft.update(3, 5000);

    cout << "Total steps (Day 1–3): " << ft.query(3);
    return 0;
}
