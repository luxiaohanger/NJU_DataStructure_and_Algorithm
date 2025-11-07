#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;


struct cmp {
    bool operator()(const int a, const int b) {
        return a > b;
    }
};

void solve() {
    int num;
    vector<int> arr;
    arr.push_back(0);
    while (cin >> num) {
        arr.push_back(num);
    }

    priority_queue<int, vector<int> > maxheap;
    priority_queue<int, vector<int>, cmp> minheap;
    for (int k = 1; k <= arr.size() - 1; ++k) {
        minheap.push(arr[k]);
        int t1 = minheap.top();
        minheap.pop();
        maxheap.push(t1);
        int t2 = maxheap.top();
        maxheap.pop();
        minheap.push(t2);
        if(k%2==1) {
            int t3 = minheap.top();
            minheap.pop();
            maxheap.push(t3);
        }
        cout << maxheap.top() << '\n';
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    solve();
    return 0;
}
