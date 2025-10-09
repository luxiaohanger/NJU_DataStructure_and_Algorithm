#include<bits/stdc++.h>

using namespace std;
using ll = long long;

struct mydata {
    ll val;
    int idx;
    int version;
};

struct node {
    ll val;
    int idx;
    int left;
    int right;
    int version;
};


struct cmp {
    bool operator()(const mydata &a, const mydata &b) {
        if (a.val > b.val)return true;
        if (a.val == b.val)return a.idx > b.idx;
        return false;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    priority_queue<mydata, vector<mydata>, cmp> queue;
    vector<node> nodes(n);
    for (int i = 0; i < n; ++i) {
        nodes[i] = {a[i], i, i - 1, i + 1, 0};
    }
    for (int i = 0; i < n; ++i) {
        queue.push({a[i], i, 0});
    }

    while (k--) {
        mydata cur = queue.top();
        while (cur.version != nodes[cur.idx].version) {
            queue.pop();
            cur = queue.top();
        }
        int id = cur.idx;
        if (nodes[id].left >= 0) {
            int left = nodes[id].left;
            nodes[left].val += nodes[id].val;
            nodes[left].right = nodes[id].right;
            nodes[left].version++;
            queue.push({nodes[left].val, left, nodes[left].version});
        }
        if (nodes[id].right < n) {
            int right = nodes[id].right;
            nodes[right].val += nodes[id].val;
            nodes[right].left = nodes[id].left;
            nodes[right].version++;
            queue.push({nodes[right].val, right, nodes[right].version});
        }
        nodes[id].val = -1;
        queue.pop();
    }

    for (int i = 0; i < n; i++) {
        if (nodes[i].val != -1)cout << nodes[i].val << ' ';
    }

    return 0;
}
