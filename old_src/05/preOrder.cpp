#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

vector<int> work(const vector<int> &inOrder, const vector<int> &postOrder) {
    vector<int> preOrder;
    if (inOrder.empty())return preOrder;
    if (inOrder.size() == 1) {
        return inOrder;
    }
    int root = postOrder.back();
    int idx_root = 0;
    for (int i = 0; i < inOrder.size(); ++i) {
        if (inOrder[i] == root) {
            idx_root = i;
            break;
        }
    }
    vector<int> inleft;
    vector<int> inright;
    vector<int> postleft;
    vector<int> postright;
    for (int i = 0; i < idx_root; ++i) {
        inleft.push_back(inOrder[i]);
        postleft.push_back(postOrder[i]);
    }
    for (int i = idx_root + 1; i < inOrder.size(); ++i) {
        inright.push_back(inOrder[i]);
    }
    for (int i = idx_root; i < inOrder.size() - 1; ++i) {
        postright.push_back(postOrder[i]);
    }
    vector<int> preleft = work(inleft, postleft);
    vector<int> preright = work(inright, postright);
    preOrder.push_back(root);
    for (int i = 0; i < preleft.size(); i++) {
        preOrder.push_back(preleft[i]);
    }
    for (int i = 0; i < preright.size(); i++) {
        preOrder.push_back(preright[i]);
    }
    return preOrder;
}

void solve() {
    int num;
    vector<int> input;
    while (cin >> num) {
        input.push_back(num);
    }
    int n = input.size();
    vector<int> inOrder(input.begin(), input.begin() + n / 2);
    vector<int> postOrder(input.begin() + n / 2, input.end());
    vector<int> preOrder = work(inOrder,postOrder);
    for(int x:preOrder) {
        cout << x << ' ';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
