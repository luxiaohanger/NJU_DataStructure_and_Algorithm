#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

bool checkR(const vector<ld> x, const vector<ld> d, ld R) {
    int n = x.size();
    vector<ld> min(n);
    vector<ld> max(n);
    for (int i = 0; i < n; ++i) {
        if (2 * R < d[i])return false;
        min[i] = x[i] - sqrt(2 * R * d[i] - d[i] * d[i]);
        max[i] = x[i] + sqrt(2 * R * d[i] - d[i] * d[i]);
    }
    ld maxmin = min[0];
    ld minmax = max[0];
    for (int i = 0; i < n; ++i) {
        if (maxmin < min[i])maxmin = min[i];
        if (minmax > max[i])minmax = max[i];
    }
    return maxmin <= minmax;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ld> x(n);
    vector<ld> y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    //exclude the condition of invalid
    bool check = y[0] > 0;
    for (int i = 0; i < n; i++) {
        if (check != (y[i] > 0)) {
            cout << "-1";
            return 0;
        }
    }
    //
    vector<ld> d(n);
    for (int i = 0; i < n; ++i) {
        d[i] = abs(y[i]);
    }

    int nums = 80;
    ld left = 0, right = 1e14;
    ld mid = (left + right) / 2;
    while (nums--) {
        if (!checkR(x, d, mid)) {
            left = mid;
        } else {
            right = mid;
        }
        mid = (left + right) / 2;
    }
    cout << fixed << setprecision(10) << mid;
    return 0;
}
