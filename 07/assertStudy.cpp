#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;


struct DSU {
    vector<int> pa, size;

    explicit DSU(size_t n): pa(n), size(n, 1) {
        iota(pa.begin(), pa.end(), 0);
    }

    size_t find(size_t x) {
        return pa[x] == x ? x : pa[x] = find(pa[x]);
    }

    void unite(size_t x, size_t y) {
        x = find(x);
        y = find(y);
        if (x == y)return;
        if (size[x] < size[y])swap(x, y);
        pa[y] = x;
        size[x] += size[y];
    }
};

struct expr {
    int i;
    int j;
    int e;
};

void solve() {
    int n;
    cin >> n;
    vector<expr> arr(n);
    unordered_map<int,int> mp;
    int idx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].i >> arr[i].j >> arr[i].e;
        if(mp.find(arr[i].i) == mp.end())mp[arr[i].i] = idx++;
        if(mp.find(arr[i].j) == mp.end())mp[arr[i].j] = idx++;
    }
    DSU dsu(2*n+5);

    for (auto ex: arr) {
        if (ex.e == 1) {
            dsu.unite(mp[ex.i], mp[ex.j]);
        }
    }

    for (auto ex: arr) {
        if (ex.e == 0) {
            if (dsu.find(mp[ex.i]) == dsu.find(mp[ex.j])) {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
