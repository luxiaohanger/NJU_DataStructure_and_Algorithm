#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;



struct DSU {
    vector<int> pa, size;

    explicit DSU(size_t n):pa(n),size(n,1) {
        iota(pa.begin(), pa.end(),0);
    }

    size_t find(size_t x) {
        return pa[x] == x ? x : pa[x] = find(pa[x]);
    }

    void unite(size_t x, size_t y) {
        x = find(x);
        y = find(y);
        if(x == y)return;
        if(size[x] < size[y])swap(x,y);
        pa[y] = x;
        size[x] += size[y];
    }
};

void solve() {
    string s1,s2,s3;
    cin >> s1 >> s2 >> s3;
    DSU dsu(26);
    for(int i =0;i<s1.size();++i) {
        dsu.unite(s1[i] - 'a',s2[i] - 'a');
    }
    for(int i =0;i<s1.size();++i) {
        if(dsu.find(s1[i] - 'a') != dsu.find(s3[i] - 'a')) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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
