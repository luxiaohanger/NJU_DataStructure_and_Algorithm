#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

bool query(int a, int b) {
    cout << "? " << a << " " << b << endl;
    int ans;
    cin >> ans;
    return ans == 1;
}

void islink() {
    cout << "! 1" << endl;
}

void isflower() {
    cout << "! 2" << endl;
}

void solve() {
    int n;
    cin >> n;
    int firstlink = 0;

    for (int i = 1; i < n; i += 2) {
        if (query(i, i + 1)) {
            firstlink = i;
            break;
        }
    }

    if (n % 2 == 0 && firstlink == 0) {
        islink();
        return;
    }

    if (n % 2 != 0 && firstlink == 0) {
        // n is center or link
        if (!(query(1, n) && query(2, n) && query(3, n))) {
            islink();
            return;
        }
        isflower();
        return;
    }

    //firstlink != 0
    int help1, help2;
    if (firstlink == 1) {
        help1 = 3;
        help2 = 4;
    } else {
        help1 = 1;
        help2 = 2;
    }


    if (query(help1, firstlink)) {
        if (query(help2, firstlink)) {
            isflower();
            return;
        }
        //lf to 1 but not to 2 --> lf + 1 not to 1
        islink();
        return;
    } else {
        //lf not to 1
        if (query(help1, firstlink + 1) && query(help2, firstlink + 1)) {
            isflower();
            return;
        }
    }
    islink();
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
