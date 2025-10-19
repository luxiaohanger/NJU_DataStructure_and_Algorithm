#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;


void solve() {
    int A = 0,B = 0;
    string cmd;
    while(cin >> cmd) {
        if(cmd == "enqueue") {
            cout<<"push A\n";
            A++;
        }else {
            if(B == 0) {
                for(int i =0;i<A;++i) {
                    cout<<"move A B\n";
                    B++;
                }
                A = 0;
                cout<<"pop B\n";
                B--;
            }else {
                cout<<"pop B\n";
                B--;
            }
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
