#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;


void solve() {
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    vector<int> maxL(n + 1, 1);
    vector<int> maxR(n + 1, n );
    //
    stack<int> st;
    for (int i = 1; i <= n; ++i) {
        while (!st.empty() && arr[i] < arr[st.top()]) {
            maxR[st.top()] = i - 1;
            st.pop();
        }
        st.push(i);
    }
    //
    stack<int> st2;
    for (int i = n; i >= 1; --i) {
        while (!st2.empty() && arr[i] <= arr[st2.top()]) {
            maxL[st2.top()] = i + 1;
            st2.pop();
        }
        st2.push(i);
    }

    ll ans = 0;
    for(int i =1;i<=n;++i) {
        ll l = i;
        ll r = i;

        for(int k=i;k>=maxL[i];--k) {
            if(arr[k]%arr[i]!=0)break;
            l = k;
        }
        for(int k = i;k<=maxR[i];++k) {
            if(arr[k]%arr[i]!=0)break;
            r = k;
        }
        ans+=(i-l+1)*(r-i+1);
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
