#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

struct node {
    int idx = 0;
    int left = 0;
    int right = 0;
    int parent = 0;
};

int query(const int a, const int b) {
    cout << "? " << a << " " << b << endl;
    int ans;
    cin >> ans;
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<node> tree(n + 1);
    for (int i = 1; i <= n; ++i) {
        tree[i].idx = i;
        cin >> tree[i].left;
        cin >> tree[i].right;
        tree[tree[i].left].parent = i;
        tree[tree[i].right].parent = i;
    }
    //find root
    int root = 0;
    for (int i = 1; i <= n; ++i) {
        if (tree[i].parent == 0) {
            root = i;
            break;
        }
    }

    //find
    int prev = root;
    int left = tree[root].left;
    int right = tree[root].right;
    while (true) {
        if (left != 0 && right != 0) {
            int ans = query(left, right);
            if (ans == 1) {
                cout << "! " << prev << endl;
                return;
            }
            if (ans == 0) {
                //near to left
                prev = left;
                left = tree[prev].left;
                right = tree[prev].right;
            } else {
                prev = right;
                left = tree[prev].left;
                right = tree[prev].right;
            }
            continue;
        }

        if (left == 0 && right == 0) {
            cout << "! " << prev << endl;
            return;
        }

        //one of left and right is 0
        int kid = (left == 0) ? right : left;
        int q = query(kid, prev);
        if (q == 2) {
            cout << "! " << prev << endl;
            return;
        }
        prev = kid;
        left = tree[prev].left;
        right = tree[prev].right;
    }
}

void findans(int ans) {
    cout << "! " << ans << endl;
}

int countNode(const vector<node> &tree, vector<int> &nNode, int root) {
    if (root == 0)return 0;
    int nleft = countNode(tree, nNode, tree[root].left);
    int nright = countNode(tree, nNode, tree[root].right);
    int ans = nleft + nright + 1;
    nNode[root] = ans;
    return ans;
}

int findG(const vector<node> &tree, const vector<int> &nNode, int root, int size) {
    int nleft = nNode[tree[root].left];
    int nright = nNode[tree[root].right];
    int nparent = size - nNode[root];
    if (nleft <= size / 2 && nright <= size / 2 && nparent <= size / 2) {
        return root;
    }
    if (nleft > size / 2)return findG(tree, nNode, tree[root].left, size);
    return findG(tree, nNode, tree[root].right, size);
}

void reducetoP(vector<node> &tree, vector<int> &nNode, int &prevroot, int &G, int &size) {
    int p = tree[G].parent;
    tree[G].parent = 0;
    if (tree[p].left == G) {
        tree[p].left = 0;
    } else {
        tree[p].right = 0;
    }
    //new the nNode
    int re = p;
    while (re) {
        nNode[re] -= nNode[G];
        re = tree[re].parent;
    }
    //reduce to p
    size = nNode[prevroot];
    G = findG(tree, nNode, prevroot, size);
}

void reducetoG(vector<node> &tree, vector<int> &nNode, int &prevroot, int &G, int &size) {
    tree[G].parent = 0;
    prevroot = G;
    size = nNode[G];
    G = findG(tree,nNode,prevroot,size);
}

void reducetoPandG(vector<node> &tree, vector<int> &nNode, int &prevroot, int &G, int &size) {
    int l = tree[G].left;
    int r = tree[G].right;
    int p = tree[G].parent;
    tree[G].left = 0;
    tree[G].right = 0;
    tree[l].parent = 0;
    tree[r].parent = 0;
    int re = G;
    while (re) {
        nNode[re] -= (nNode[l] + nNode[r]);
        re = tree[re].parent;
    }
    size = nNode[prevroot];
    G = findG(tree, nNode, prevroot, size);
}

void reducetoL(vector<node> &tree, vector<int> &nNode, int &prevroot, int &G, int &size) {
    int l = tree[G].left;
    tree[G].left = 0;
    tree[l].parent = 0;
    size = nNode[l];
    prevroot = l;
    G = findG(tree, nNode, prevroot, size);
}

void reducetoR(vector<node> &tree, vector<int> &nNode, int &prevroot, int &G, int &size) {
    int r = tree[G].right;
    tree[G].right = 0;
    tree[r].parent = 0;
    size = nNode[r];
    prevroot = r;
    G = findG(tree, nNode, prevroot, size);
}

void solve_plus() {
    int n;
    cin >> n;
    vector<node> tree(n + 1);
    for (int i = 1; i <= n; ++i) {
        tree[i].idx = i;
        cin >> tree[i].left;
        cin >> tree[i].right;
        tree[tree[i].left].parent = i;
        tree[tree[i].right].parent = i;
    }
    //find root
    int root = 0;
    for (int i = 1; i <= n; ++i) {
        if (tree[i].parent == 0) {
            root = i;
            break;
        }
    }
    vector<int> nNode(n + 1); //store the num of nodes in behalf of root
    int useless = countNode(tree, nNode, root);
    int size = n;
    int prevroot = root;
    int G = findG(tree, nNode, prevroot, size);
    while (true) {
        int l = tree[G].left;
        int r = tree[G].right;
        int p = tree[G].parent;

        //3
        if (!l && !r && !p) {
            findans(G);
            return;
        }

        if (l && r && p) {
            int ans1 = query(l, r);
            if (ans1 == 1) {
                // p and g
                reducetoPandG(tree, nNode, prevroot, G, size);
                continue;
            }else if(ans1 == 0){
                reducetoL(tree, nNode, prevroot, G, size);
                continue;
            }else {
                reducetoR(tree, nNode, prevroot, G, size);
                continue;
            }
        }

        //2
        if (p == 0 && l && r) {
            int ans1 = query(l, r);
            if (ans1 == 1) {
                findans(G);
                return;
            }
            if (ans1 == 0) {
                reducetoL(tree, nNode, prevroot, G, size);
                continue;
            } else {
                reducetoR(tree, nNode, prevroot, G, size);
                continue;
            }
        }

        if (!l && r && p) {
            int ans1 = query(r, p);
            if (ans1 == 1) {
                findans(G);
                return;
            }
            if (ans1 == 0) {
                reducetoR(tree, nNode, prevroot, G, size);
                continue;
            } else {
                reducetoP(tree, nNode, prevroot, G, size);
                continue;
            }
        }

        if (l && p && !r) {
            int ans1 = query(l, p);
            if (ans1 == 1) {
                findans(G);
                return;
            }
            if (ans1 == 0) {
                reducetoL(tree, nNode, prevroot, G, size);
                continue;
            } else {
                reducetoP(tree, nNode, prevroot, G, size);
                continue;
            }
        }

        if (!l && !r && p) {
            int ans1 = query(G, p);
            if (ans1 == 0) {
                findans(G);
                return;
            }
            reducetoP(tree, nNode, prevroot, G, size);
            continue;
        }

        if (l && !r && !p) {
            int ans1 = query(G, l);
            if (ans1 == 0) {
                findans(G);
                return;
            }
            reducetoL(tree, nNode, prevroot, G, size);
            continue;
        }

        if (!l && r && !p) {
            int ans1 = query(G, r);
            if (ans1 == 0) {
                findans(G);
                return;
            }
            reducetoR(tree, nNode, prevroot, G, size);
            continue;
        }
    }
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
