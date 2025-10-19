#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

struct node {
    int idx;
    ll w;
    int idxl;
    int idxr;
    int idxp;
};

void removeleave(vector<node> &tree, vector<bool> &isleave, int idx) {
    if(idx==0) return;
    int l = tree[idx].idxl;
    int r = tree[idx].idxr;
    removeleave(tree, isleave, l);
    removeleave(tree, isleave, r);
    isleave[idx] = false;
}

void cut(vector<node> &tree, vector<bool> &isleave,
         vector<ll>& sumtree, int idx) {
    int i = tree[idx].idxp;
    while (i > 0) {
        sumtree[i] -= sumtree[idx];
        i = tree[i].idxp;
    }
    removeleave(tree,isleave,idx);
    int p = tree[idx].idxp;
    if (tree[p].idxl == idx)tree[p].idxl = 0;
    else tree[p].idxr = 0;
    if (tree[p].idxl == 0 && tree[p].idxr == 0) isleave[p] = true;
}

void solve() {
    int n, k;
    cin >> n >> k;
    ll sum = 0;
    vector<node> tree(n + 1);
    vector<bool> isleave(n + 1, false);
    for (int i = 1; i <= n; ++i) {
        tree[i].idx = i;
        cin >> tree[i].idxl;
        cin >> tree[i].idxr;
        tree[tree[i].idxl].idxp = i;
        tree[tree[i].idxr].idxp = i;
        if (tree[i].idxl == 0 && tree[i].idxr == 0)isleave[i] = true;
    }

    for (int i = 1; i <= n; ++i) {
        cin >> tree[i].w;
        sum += tree[i].w;
    }

    if (sum % k != 0) {
        cout << "NO\n";
        return;
    }

    int num = sum / k;
    //root = 1
    vector<ll> sumtree(n + 1);
    //xianhoushunxupai
    for (int i = n; i > 0; --i) {
        sumtree[i] = sumtree[tree[i].idxl] + sumtree[tree[i].idxr] + tree[i].w;
    }

    while (num != 0) {
        bool c = false;
        for (int i = 1; i <= n; ++i) {
            if (isleave[i]) {
                int idx = i;
                while (sumtree[idx] <= k) {
                    if (sumtree[idx] == k) {
                        cut(tree, isleave, sumtree, idx);
                        num--;
                        c = true;
                        break;
                    }
                    idx = tree[idx].idxp;
                }
            }
        }
        if(c == false) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

ll count(int &cnt,const vector<node>& tree,int idx,int k) {
    if(idx == 0)return 0;
    int l = tree[idx].idxl;
    int r = tree[idx].idxr;
    ll sumleft = count(cnt,tree,l,k);
    ll sumright = count(cnt,tree,r,k);
    ll sum = sumleft + sumright + tree[idx].w;
    if(sum == k) {
        cnt++;
        return 0;
    }
    return sum;
}

void solve_plus() {
    int n, k;
    cin >> n >> k;
    ll sum = 0;
    vector<node> tree(n + 1);
    int root = 0;
    for (int i = 1; i <= n; ++i) {
        tree[i].idx = i;
        cin >> tree[i].idxl;
        cin >> tree[i].idxr;
        tree[tree[i].idxl].idxp = i;
        tree[tree[i].idxr].idxp = i;
    }

    for (int i = 1; i <= n; ++i) {
        cin >> tree[i].w;
        sum += tree[i].w;
    }

    for (int i = 1; i <= n; ++i) {
        if(tree[i].idxp==0) {
            root = i;
            break;
        }
    }

    if (sum % k != 0) {
        cout << "NO\n";
        return;
    }

    int num = sum / k;
    int cnt = 0;
    ll ans = count(cnt,tree,root,k);
    if(cnt == num && ans == 0) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
    return;

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve_plus();
    }
    return 0;
}
