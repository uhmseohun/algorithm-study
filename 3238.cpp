#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;
const int _size = 300005;
int n, q[_size*2];
 
void update (int idx, int s, int e, int p, int v) {
    if (s == e && s == p) {
        q[idx] = v;
        return;
    }
    int m = (s + e) / 2;
    if (p <= m) update(idx*2+1, s, m, p, v);
    else update(idx*2+2, m+1, e, p, v);
    q[idx] = max(q[idx*2+1], q[idx*2+2]);
}
 
int query (int idx, int s, int e, int qs, int qe) {
    if (e < qs || qe < s) return INT_MIN;
    if (qs <= s && e <= qe) return q[idx];
    int m = (s + e) / 2;
    return max(
        query(idx*2+1, s, m, qs, qe),
        query(idx*2+2, m+1, e, qs, qe)
    );
}
 
int main () {
    int t, c, s, e, v;
    scanf("%d %d", &n, &t);
    for (int i=0; i<_size; ++i) {
        q[i] = INT_MIN;
    }
    while (t--) {
        scanf("%d", &c);
        if (c == 1) {
            scanf("%d %d", &s, &v);
            update(0, 0, n-1, s-1, v);
        } else if (c == 2) {
            scanf("%d %d", &s, &e);
            int rv = query(0, 0, n-1, s-1, e-1);
            if (rv != INT_MIN) printf("%d\n", rv);
        } else if (c == 3) {
            scanf("%d", &s);
            update(0, 0, n-1, s-1, INT_MIN);
        }
    }
    return 0;
}
