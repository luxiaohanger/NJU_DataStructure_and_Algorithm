#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;


void solve() {
    stack<int> st;
    vector<int> goal;
    int num;

    while(cin >> num) {
        goal.push_back(num);
    }

    //
    int k = 0;
    for(int i = 1;i <= goal.size();++i) {
        st.push(i);
        while(!st.empty() && st.top() == goal[k]) {
            st.pop();
            k++;
        }
    }

    if(st.empty())cout << "YES";
    else cout << "NO";
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
