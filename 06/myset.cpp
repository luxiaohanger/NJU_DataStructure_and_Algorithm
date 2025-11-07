#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int SIZE = 1000000;
int MOD = 999997;

struct node {
    ll val = 0;
    node* next = nullptr;
};

struct myset {
    vector<node*> table;
    ll mysize;
    myset ():table(SIZE,nullptr),mysize(0){

    }

    int hashf(ll x) {
        return (x % MOD + MOD) % MOD;
    }

    void myinsert(ll x) {
        int idx = hashf(x);
        if(table[idx] == nullptr) {
            node* newnode = new node{x,nullptr};
            table[idx] = newnode;
            mysize++;
        }else {
            node* cur = table[idx];
            bool has = false;
            while(cur && cur->next) {
                if(cur->val == x) {
                    has = true;
                    break;
                }
                cur = cur->next;
            }

            if(cur->val == x) {
                has = true;
            }

            if(!has) {
                node* newnode = new node{x,nullptr};
                cur -> next = newnode;
                mysize++;
            }
        }
    }

    bool myfind(ll x) {
        int idx = hashf(x);
        if(table[idx] == nullptr)return false;
        node* cur = table[idx];
        while(cur && cur->next) {
            if(cur->val == x)return true;
            cur = cur->next;
        }
        if(cur->val == x)return true;
        return false;
    }
};

void solve() {
    int n;
    cin >> n;
    int cnt = 0;
    myset ms;
    while(n--) {
        string cmd;
        cin >> cmd;
        if(cmd == "insert") {
            ll x;
            cin >> x;
            for(int i = 1;i <= 1000;++i) {
                ms.myinsert(i * x);
            }
        }else {
            ll x;
             cin >> x;
             if(ms.myfind(x))cnt++;
        }
    }
    cout << ms.mysize << ' ' << cnt << '\n';
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
