#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
    int num;
    int k;
    cin >> k;
    vector<int> arr;
    while(cin >> num) {
        arr.push_back(num);
    }
    int n = arr.size();
    int th = n - k + 1;
    nth_element(arr.begin(),arr.begin()+th-1,arr.end());
    cout << arr[th - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
