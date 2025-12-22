#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& a, int l, int m, int r) {
    vector<int> left(a.begin()+l, a.begin()+m+1);
    vector<int> right(a.begin()+m+1, a.begin()+r+1);

    int i=0, j=0, k=l;
    while (i < left.size() && j < right.size())
        a[k++] = (left[i] <= right[j]) ? left[i++] : right[j++];

    while (i < left.size()) a[k++] = left[i++];
    while (j < right.size()) a[k++] = right[j++];
}

void mergeSort(vector<int>& a, int l, int r) {
    if (l >= r) return;
    int m = (l+r)/2;
    mergeSort(a, l, m);
    mergeSort(a, m+1, r);
    merge(a, l, m, r);
}

int main() {
    vector<int> shelfLife = {7, 3, 12, 1, 5};

    mergeSort(shelfLife, 0, shelfLife.size()-1);

    cout << "Produce sorted by shelf-life: ";
    for (int x : shelfLife) cout << x << " ";

    return 0;
}
