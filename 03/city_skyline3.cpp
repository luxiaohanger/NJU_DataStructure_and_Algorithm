#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

ll cntday_plus(ll sumwater, ll sumconsume, ll minconsume, int n) {
    ll ans = 0;
    //每个m[i]都为1，则天数无穷
    if (sumconsume == n)return -1;
    //无法支撑第0天
    if (sumwater < sumconsume)return 0;
    if (minconsume == 1) {
        long long dec = sumconsume - n;  // 每天固定减少的水量
        return (sumwater - sumconsume) / dec + 1;
    }
    while (sumwater >= sumconsume) {
        ll temp = sumwater - (sumconsume - minconsume); //分配给最小消耗水塔的水
        //最小水塔剩余水，其他水塔剩余1
        temp /= minconsume;
        //更新总水量
        sumwater = temp + n - 1;
        ans++;
    }
   return ans;
}

struct mydata {
    ll val;
    int idx;
    int version;
};

struct cmp {
    bool operator()(const mydata a, const mydata b) {
        return a.val > b.val;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n + 1);
    vector<mydata> m(n + 1);
    ll sumwater = 0, sumconsume = 0;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sumwater += a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> m[i].val;
        m[i].idx = i;
        m[i].version = 0;
        sumconsume += m[i].val;
    }

    priority_queue<mydata, vector<mydata>, cmp> queue;
    for (int i = 1; i <= n; ++i) {
        queue.push(m[i]);
    }

    int cmd;
    int id;
    ll x;
    while (q--) {
        cin >> cmd;
        if (cmd == 1) {
            cin >> id >> x;
            sumwater -= a[id];
            a[id] = x;
            sumwater += a[id];
        } else if (cmd == 2) {
            cin >> id >> x;
            sumconsume -= m[id].val;
            m[id].val = x;
            sumconsume += m[id].val;
            m[id].version++;
            queue.push(m[id]);
        } else {
            //多次查询，每次都遍历计算消耗过大
            while (queue.top().version != m[queue.top().idx].version)queue.pop();
            ll ans = cntday_plus(sumwater, sumconsume, queue.top().val, n);
            cout << ans << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
