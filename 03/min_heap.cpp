#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int left(int idx) {
    return idx * 2 + 1;
}

int right(int idx) {
    return idx * 2 + 2;
}

int parent(int idx) {
    return (idx - 1) / 2;
}

struct minheap {
    vector<int> heap; //begin with 0;
    vector<int> map1; //idx-->num
    vector<int> map2; //num-->idx

    minheap(int n=1e6):heap(n),map1(n),map2(n) {
    }

    int nums = 1;
    int mysize = 0;

    void myswap(int idx1, int idx2) {
        int num1 = map1[idx1];
        int num2 = map1[idx2];
        map1[idx1] = num2;
        map1[idx2] = num1;
        map2[num1] = idx2;
        map2[num2] = idx1;
        int temp = heap[idx1];
        heap[idx1] = heap[idx2];
        heap[idx2] = temp;
    }

    void push(int x) {
        heap[mysize] = x;
        map1[mysize] = nums;
        map2[nums] = mysize;
        nums++;
        mysize++;

        int idx = mysize - 1;
        while (idx > 0 && heap[parent(idx)] > heap[idx]) {
            myswap(parent(idx), idx);
            idx = parent(idx);
        }
    }

    void pop() {
        myswap(0, mysize - 1);
        mysize--;
        minify(0);
    }

    void top() {
        cout << heap[0] << "\n";
    }

    void size() {
        cout << mysize << "\n";
    }

    void decrease(int i, int k) {
        int idx = map2[i];
        heap[idx] = k;
        while (idx > 0 && heap[parent(idx)] > heap[idx]) {
            myswap(parent(idx), idx);
            idx = parent(idx);
        }
    }

    void minify(int idx) {
        int left = idx * 2 + 1;
        int right = idx * 2 + 2;
        if (left < mysize && heap[left] < heap[idx]) {
            myswap(idx, left);
            minify(left);
        }
        if (right < mysize && heap[right] < heap[idx]) {
            myswap(idx, right);
            minify(right);
        }
        return;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string cmd;
    minheap hp;
    while (cin >> cmd) {
        if (cmd == "push") {
            int x;
            cin >> x;
            hp.push(x);
        } else if (cmd == "pop") {
            hp.pop();
        } else if (cmd == "top") {
            hp.top();
        } else if (cmd == "size") {
            hp.size();
        } else {
            int i, k;
            cin >> i >> k;
            hp.decrease(i, k);
        }
    }
    return 0;
}
