#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

struct node {
    int idx;
    int val;
    int left;
    int right;
    int parent = 0;
};

void preOrder(const vector<node> &tree, int root) {
    stack<pair<int, int>> st;
    st.push({root, 0});
    while (!st.empty()) {
        auto &cur = st.top();
        int state = cur.second;
        if (state == 0) {
            cout << tree[cur.first].val << ' '; // 前序访问
            cur.second = 1;
            if (tree[cur.first].left) {
                st.push({tree[cur.first].left, 0});
            }
        } else if (state == 1) {
            cur.second = 2;
            if (tree[cur.first].right) {
                st.push({tree[cur.first].right, 0});
            }
        } else {
            //state == 2
            st.pop();
        }
    }
}

void inOrder(const vector<node> &tree, int root) {
    stack<pair<int, int>> st;
    st.push({root, 0});
    while (!st.empty()) {
        auto &cur = st.top();
        int state = cur.second;
        if (state == 0) {
            cur.second = 1;
            if (tree[cur.first].left) {
                st.push({tree[cur.first].left, 0});
            }
        } else if (state == 1) {
            cout << tree[cur.first].val << ' '; // 中序访问
            cur.second = 2;
            if (tree[cur.first].right) {
                st.push({tree[cur.first].right, 0});
            }
        } else {
            st.pop();
        }
    }
}

void postOrder(const vector<node> &tree, int root) {
    stack<pair<int, int>> st;
    st.push({root, 0});
    while (!st.empty()) {
        auto &cur = st.top();
        int state = cur.second;
        if (state == 0) {
            cur.second = 1;
            if (tree[cur.first].left) {
                st.push({tree[cur.first].left, 0});
            }
        } else if (state == 1) {
            cur.second = 2;
            if (tree[cur.first].right) {
                st.push({tree[cur.first].right, 0});
            }
        } else {
            cout << tree[cur.first].val << ' '; // 后序访问
            st.pop();
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<node> tree(n + 1);
    for (int i = 1; i <= n; ++i) {
        tree[i].idx = i;
        cin >> tree[i].val;
        cin >> tree[i].left;
        tree[tree[i].left].parent = i;
        cin >> tree[i].right;
        tree[tree[i].right].parent = i;
    }

    int root = 0;
    for (int i = 1; i <= n; ++i) {
        if (tree[i].parent == 0) {
            root = i;
            break;
        }
    }

    preOrder(tree,root);
    cout << '\n';
    inOrder(tree, root);
    cout << '\n';
    postOrder(tree,root);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
