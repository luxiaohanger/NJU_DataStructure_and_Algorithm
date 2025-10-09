#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int N = 5000005; //

int ans[N] = {0};
int temp[N] = {0};

inline int coutidx(const int k, const int i, const int j) {
    return i * (k + 1) + j;
}

void mysort(int n, int k, const string &arr) {
    for (int pos = k - 1; pos >= 0; --pos) {
        int cnt[16] = {0};
        for (int i = 0; i < n; ++i) {
            char c = arr[coutidx(k, i, pos)];
            int way = (c >= '0' && c <= '9') ? c - '0' : c - 'A' + 10;
            cnt[way]++;
        }

        for (int i = 1; i < 16; i++) {
            cnt[i] += cnt[i - 1];
        }

        for (int i = n - 1; i >= 0; --i) {
            char c = arr[coutidx(k, ans[i], pos)];
            int way = (c >= '0' && c <= '9') ? c - '0' : c - 'A' + 10;
            temp[--cnt[way]] = ans[i];
        }

        for (int i = 0; i < n; ++i) {
            ans[i] = temp[i];
        }
    }
}


void solve() {
    int n, k;
    cin >> n >> k;
    string arr;
    cin.ignore(1,'\n');
    getline(cin, arr);

    for (int i = 0; i < n; ++i) {
        ans[i] = i;
    }

    mysort(n, k, arr);
    vector<int> sum(n + 1);
    for (int i = 0; i < n; ++i) {
        int num = 0;
        for (int j = 0; j < k; ++j) {
            if (arr[coutidx(k, ans[i], j)] == 'F')num++;
        }
        sum[i + 1] = sum[i] + num;
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << sum[r] - sum[l - 1] << '\n';
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
