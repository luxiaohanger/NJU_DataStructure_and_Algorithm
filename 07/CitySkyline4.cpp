#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int,int>;

int n,m;
int h[505][505] = {};

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

struct edge {
    int ax;
    int ay;
    int bx;
    int by;
    int w;
};

struct cmp {
    bool operator()(const edge& a,const edge& b) {
        return a.w < b.w;
    }
};

void solve() {

    cin >> n >> m;
    vector<pii> vv;
    for(int i = 0;i<n;++i) {
        for(int j=0;j<m;++j) {
            cin >> h[i][j];
        }
    }

    for(int i = 0;i<n;++i) {
        for(int j=0;j<m;++j) {
            int num;
            cin >> num;
            if(num == 1) {
                vv.push_back({i,j});
            }
        }
    }

    vector<edge> edges;
    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            if(i < n - 1)edges.push_back({i,j,i+1,j,abs(h[i][j] - h[i+1][j])});
            if(j < m - 1)edges.push_back({i,j,i,j+1,abs(h[i][j] - h[i][j+1])});
        }
    }

    sort(edges.begin(), edges.end(),cmp());
    DSU dsu(n * m);
    edge last ;

    int root = vv[0].first * m + vv[0].second;
    for(auto e:edges) {
        int u = e.ax * m + e.ay;
        int v = e.bx * m + e.by;
        if(dsu.find(u) == dsu.find(v))continue;
        dsu.unite(u,v);
        last = e;
        bool flag = true;
        for(auto v: vv) {
            if(dsu.find(root) != dsu.find(v.first * m + v.second)) {
                flag = false;
                break;
            }
        }
        if(flag)break;
    }

    cout << last.w;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
