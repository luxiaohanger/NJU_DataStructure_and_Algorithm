#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

struct kid {
    int a;
    int w;
};

struct cmp {
    bool operator()(const kid &a, const kid &b) {
        return a.a < b.a;
    }
};

void solve() {
    int N;
    cin >> N;
    vector<kid> kids(N);
    for (int i = 0; i < N; ++i) {
        cin >> kids[i].a;
        cin >> kids[i].w;
    }

    sort(kids.begin(), kids.end(), cmp());
    vector<ll> presum(N + 1);

    for (int i = 1; i <= N; ++i) {
        presum[i] = presum[i - 1] + kids[i - 1].w;
    }

    for (int i = 1; i < N; ++i) {
        if (presum[i] < (presum[N] / 2) && ((presum[N] - presum[i + 1]) <= (presum[N] + 1) / 2)) {
            cout << kids[i].a;
            return;
        }
    }
}

void find(vector<kid> &kids, ll &exsumL, ll &exsumR, int left, int right, ll T, ll C) {
    int th = (left + right) / 2;
    nth_element(kids.begin() + left, kids.begin() + th, kids.begin() + right + 1, cmp());
    ll insumL = 0;
    ll insumR = 0;

    for (int i = left; i < th; ++i) {
        insumL += kids[i].w;
    }

    for (int i = th + 1; i <= right; ++i) {
        insumR += kids[i].w;
    }

    if (exsumL + insumL < T && exsumR + insumR <= C) {
        cout << kids[th].a;
        return;
    }

    if (exsumL + insumL >= T) {
        exsumR = exsumR + insumR + kids[th].w;
        right = th - 1;
        find(kids, exsumL, exsumR, left, right, T, C);
    } else {
        exsumL = exsumL + insumL + kids[th].w;
        left = th + 1;
        find(kids, exsumL, exsumR, left, right, T, C);
    }
}

void solve_plus() {
    int N;
    cin >> N;
    vector<kid> kids(N);
    ll sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> kids[i].a;
        cin >> kids[i].w;
        sum += kids[i].w;
    }
    ll T = sum / 2; //L<T
    ll C = (sum + 1) / 2; //R<=C
    ll exsumL = 0;
    ll exsumR = 0;
    find(kids,exsumL,exsumR,0,N-1,T,C);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) {
        solve_plus();
    }
    return 0;
}
