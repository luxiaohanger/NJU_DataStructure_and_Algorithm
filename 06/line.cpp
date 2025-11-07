#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

struct line {
    double l;
    double r;
};

struct cmp {
    bool operator()(const line &a, const line &b) const{
        return a.r < b.r;
    }
};


void solve() {
    int n;
    cin >> n;
    set<line, cmp> mys;
    while (n--) {
        char cmd;
        cin >> cmd;
        if (cmd == 'A') {
            double l, r;
            cin >> l >> r;
            auto it = mys.lower_bound({0,r});
            vector<set<line, cmp>::iterator> to_erase;
            if(it != mys.end()) {
                while(  it->r >= l ) {
                    if(!(it->r < l || it ->l > r))to_erase.push_back(it);
                    if(it != mys.begin())--it;
                    else break;
                }
            }
            else if(!mys.empty()) {
                it = mys.end();
                it--;
                while(  it->r >= l ) {
                    if(!(it->r < l || it ->l > r))to_erase.push_back(it);
                    if(it != mys.begin())--it;
                    else break;
                }
            }

                //delete
                for(auto& it:to_erase) {
                    mys.erase(it);
                }
                cout << to_erase.size() << '\n';
                mys.insert({l,r});
            }else cout << mys.size() << '\n';
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
