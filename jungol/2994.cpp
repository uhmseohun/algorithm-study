#include <cstdio>
#include <climits>
#include <algorithm>
#include <set>
#include <cstdlib>
#include <vector>
using namespace std;
// <position, distance>
typedef pair<int, int> ipair;
const int _size = 100005;
 
struct Data {
    int x, s, e;
    bool operator < (const Data &r) const {
        return x < r.x;
    }
} o[_size];
 
int main () {
    // input
    int n, s, b;
    scanf("%d %d %d", &n, &s, &b);
    for (int i=0; i<n; ++i) {
        scanf("%d %d %d", &o[i].x, &o[i].s, &o[i].e);
    }
 
    // pre-process
    sort(o, o+n);
    set <ipair> q;
    q.insert(make_pair(s, 0));
 
    // process
    for (int i=0; i<n; ++i) {
        int vs=INT_MAX, ve=INT_MAX;
        auto qs = q.lower_bound(make_pair(o[i].s, 0));
        auto qe = q.upper_bound(make_pair(o[i].e, INT_MAX));
        for (auto j=qs; j!=qe; ++j) {
            vs = min(vs, (*j).second + abs((*j).first-o[i].s));
            ve = min(ve, (*j).second + abs((*j).first-o[i].e));
        }
        q.erase(qs, qe);
        if (vs != INT_MAX) q.insert(make_pair(o[i].s, vs));
        if (ve != INT_MAX) q.insert(make_pair(o[i].e, ve));
    }
 
    // output
    set <ipair> rq;
    for (auto i=q.begin(); i!=q.end(); ++i) {
        rq.insert(make_pair((*i).second, (*i).first));
    }
    int min_dist = (*rq.begin()).first;
    printf("%d\n", min_dist+b);
    vector <int> poses;
    for (auto i=rq.begin(); i!=rq.end(); ++i) {
        if ((*i).first == min_dist) poses.push_back((*i).second);
    }
    printf("%d ", poses.size());
    for (auto &pos: poses) {
        printf("%d ", pos);
    }
    return 0;
}
