#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;


ld extendpre = 1e6;
ld myprecision = 1e-7;
int A, B, C;

struct point {
    ld x = 0;
    ld y = 0;
};

ld dist(const point &a, const point &b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

ld getY(ld x) {
    return -(A * x + C) / B;
}


ld maxdist(const vector<point> &points, point p) {
    ld maxd = dist(points[0], p);
    for (int i = 1; i < points.size(); ++i) {
        maxd = max(maxd, dist(points[i], p));
    }
    return maxd;
}

void solve() {
    int n;
    cin >> n;
    vector<point> points(n);
    ld l1, l2, l3, l4;
    ld up, down;
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    l1 = -extendpre;
    l4 = extendpre;
    down = -extendpre;
    up = extendpre;
    ld det;


    point p2, p3;
    cin >> A >> B >> C;
    ld ans;
    if (B != 0) {
        //x = -(ax + c)/b
        det = (l4 - l1) / 3;
        l2 = l1 + det;
        l3 = l2 + det;
        p2.x = l2;
        p2.y = getY(p2.x);
        p3.x = l3;
        p3.y = getY(p3.x);

        ld maxl,maxr;
        int times = 200;
        while (times--) {
             maxl = maxdist(points, p2);
             maxr = maxdist(points, p3);
            if (maxl == maxr) {
                l1 = l2;
                l4 = l3;

                det = (l4 - l1) / 3;
                l2 = l1 + det;
                l3 = l2 + det;
                p2.x = l2;
                p2.y = getY(p2.x);
                p3.x = l3;
                p3.y = getY(p3.x);
            } else if (maxl > maxr) {
                l1 = l2;

                det = (l4 - l1) / 3;
                l2 = l1 + det;
                l3 = l2 + det;
                p2.x = l2;
                p2.y = getY(p2.x);
                p3.x = l3;
                p3.y = getY(p3.x);
            } else {
                l4 = l3;

                det = (l4 - l1) / 3;
                l2 = l1 + det;
                l3 = l2 + det;
                p2.x = l2;
                p2.y = getY(p2.x);
                p3.x = l3;
                p3.y = getY(p3.x);
            }
            ans = maxl;
        }
        cout << fixed << setprecision(10) << ans << '\n';
    } else {
        //B == 0

        p2.x = -C* 1.0L / A;
        p3.x = p2.x;

        det = (up - down) / 3;
        p2.y = down + det;
        p3.y = p2.y + det;
        ld maxdown,maxup;
        int times = 200;
        while (times--) {
             maxdown = maxdist(points, p2);
             maxup = maxdist(points, p3);
            if (maxdown == maxup) {
                up = p3.y;
                down = p2.y;

                det = (up - down) / 3;
                p2.y = down + det;
                p3.y = p2.y + det;
            } else if (maxdown > maxup) {
                down = p2.y;

                det = (up - down) / 3;
                p2.y = down + det;
                p3.y = p2.y + det;
            } else {
                up = p3.y;

                det = (up - down) / 3;
                p2.y = down + det;
                p3.y = p2.y + det;
            }
            ans = maxup;
        }

        cout << fixed << setprecision(10) << ans << '\n';
    }
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
