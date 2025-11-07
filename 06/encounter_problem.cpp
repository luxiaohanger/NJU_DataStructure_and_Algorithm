#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;


struct px {
    ll x;
    ll v;
};

struct py {
    ll y;
    ll v;
};

void solve() {
    int n,m;
    cin >> n >> m;
    vector<px> arrx(n);
    vector<py> arry(m);

    for(int i=0;i<n;++i) {
        cin >> arrx[i].x >> arrx[i].v;
    }

    for(int i=0;i<m;++i) {
        cin >> arry[i].y >> arry[i].v;
    }

    unordered_map<ll,int> P;
    unordered_map<ll,int> Q;
    for(auto it:arrx) {
        ll key = it.v * it.x;
        if(key) {
            P[key]++;
        }
    }

    for(auto it:arry) {
        ll key = it.y * it.v;
        if(key) {
            Q[key]++;
        }
    }
    ll ans = 0;
    for(auto it = P.begin();it != P.end();++it) {
        if(Q.find(it->first) != Q.end())ans += it->second * Q[it->first];
    }
    cout << ans;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
