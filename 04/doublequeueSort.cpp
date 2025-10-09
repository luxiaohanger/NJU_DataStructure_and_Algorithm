#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

queue<ll> A;
queue<ll> B;
string ans;
int M = 0;

void Trans(queue<ll> &From, queue<ll> &To) {
    ll temp = From.front();
    From.pop();
    To.push(temp);
    char f = (&From == &A) ? 'A' : 'B';
    char t = (&To == &A) ? 'A' : 'B';
    ans += f;
    ans += ' ';
    ans += t;
    ans += '\n';
    M++;
}

void mysort(queue<ll> &Target, queue<ll> &Help, int len) {
    //排序 Target 的前 len 个元素并且排序后仍然在原位置，也就是队列前端
    int l1 = Target.size();
    int l2 = Help.size();
    if (len == 0 || len == 1)return;
    int mid = len / 2; //给 Help
    int det = len - mid; //给 Target

    for (int i = 0; i < mid; ++i) {
        Trans(Target, Help);
    }

    //把 mid 个元素移动到 HELP 前端
    for (int i = 0; i < l2; ++i) {
        Trans(Help, Help);
    }

    mysort(Target, Help, det);
    mysort(Help, Target, mid);

    //merge 到 Target后端
    int i = det;
    int j = mid;

    while (i && j) {
        if (Target.front() <= Help.front()) {
            Trans(Target, Target);
            i--;
        } else {
            Trans(Help, Target);
            j--;
        }
    }
    if (i) {
        while (i--) Trans(Target, Target);
    } else {
        while (j--) Trans(Help, Target);
    }

    // 把 len 个元素移动到 Target 前端
    int det1 = l1 - len;
    while (det1--) Trans(Target, Target);

    return;
}

void mysort_plus(int N) {
    for (int i = 1; i < N; i *= 2) {
        int groupnums = N / (2 * i) ;
        int remain = N % (2 * i);
        if(remain!=0)groupnums++;
        while (groupnums--) {
            //the scale of each merged group is i*2
            int j = 0, k = 0, t1 = 0, t2 = 0;
            if (groupnums != 0|| remain==0) {
                t1 = i;
                t2 = i;
            } else {
                if (remain > i) {
                    t1 = remain -i;
                    t2 = i;
                } else {
                    t2 = remain;
                }
            }

            for (int p = 0; p < t2; ++p) {
                Trans(A, B);
            }

            while (j != t1 && k != t2) {
                if (A.front() <= B.front()) {
                    Trans(A, A);
                    j++;
                } else {
                    Trans(B, A);
                    k++;
                }
            }

            if (j == t1) {
                while (k != t2) {
                    Trans(B, A);
                    k++;
                }
            } else {
                while (j != t1) {
                    Trans(A, A);
                    j++;
                }
            }
        }
    }
}

void solve() {
    int N;
    cin >> N;
    ll num;
    for (int i = 0; i < N; ++i) {
        cin >> num;
        A.push(num);
    }
    //mysort(A, B, N);
    mysort_plus(N);
    // if (M > 4 * N * ceil(log(N) / log(2))) {
    //     cout << "over" << '\n';
    // }

    cout << M << '\n';

    // for (int i = 0; i < N; ++i) {
    //     int x = A.front();
    //     cout << x << ' ';
    //     A.pop();
    // }
    // cout << '\n';
    cout << ans;
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
