#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    int n;

    void build(vector<int>& usage, int node, int start, int end) {
        if (start == end) {
            tree[node] = usage[start];
        } else {
            int mid = (start + end) / 2;
            build(usage, 2*node, start, mid);
            build(usage, 2*node+1, mid+1, end);
            tree[node] = tree[2*node] + tree[2*node+1]; // sum of water usage
        }
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) update(2*node, start, mid, idx, val);
            else update(2*node+1, mid+1, end, idx, val);
            tree[node] = tree[2*node] + tree[2*node+1];
        }
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return query(2*node, start, mid, l, r) + query(2*node+1, mid+1, end, l, r);
    }

public:
    SegmentTree(vector<int>& usage) {
        n = usage.size();
        tree.resize(4*n);
        build(usage, 1, 0, n-1);
    }

    void updateUsage(int idx, int val) {
        update(1, 0, n-1, idx, val);
    }

    int queryUsage(int l, int r) {
        return query(1, 0, n-1, l, r);
    }
};

int main() {
    vector<int> waterUsage = {50, 30, 40, 20, 60}; // usage per household
    SegmentTree st(waterUsage);

    cout << "Total water usage from household 1 to 3: " << st.queryUsage(1,3) << endl;

    cout << "Updating household 2 usage to 70 units.\n";
    st.updateUsage(2, 70);
    cout << "Total water usage from household 1 to 3: " << st.queryUsage(1,3) << endl;

    return 0;
}
