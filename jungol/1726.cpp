#include <cstdio>
#include <algorithm>
using namespace std;
const int _size = 50005;
int el[_size], seg[_size<<1];
 
int build (int idx, int s, int e) {
    if (s == e) seg[idx] = el[s];
    else {
        int m = (s+e)/2;
        int l = build(idx*2+1, s, m);
        int r = build(idx*2+2, m+1, e);
        seg[idx] = max(l, r);
    }
    return seg[idx];
}
 
int query (int idx, int ss, int se, int qs, int qe) {
    if (se < qs || qe < ss) return 0;
    if (qs <= ss && se <= qe) return seg[idx];
    int m = (ss+se)/2;
    return max(
        query(idx*2+1, ss, m, qs, qe),
        query(idx*2+2, m+1, se, qs, qe)
    );
}
 
int main () {
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i=0; i<n; ++i)
        scanf("%d", el+i);
    build(0, 0, n-1);
    int s, e;
    for (int i=0; i<q; ++i) {
        scanf("%d %d", &s, &e);
        printf("%d\n", query(0, 0, n-1, s-1, e-1));
    }
    return 0;
}
