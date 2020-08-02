#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int _size = 10005;

int n, d[_size];
vector<pair<int, int>> s;

int main() {
    scanf("%d", &n);
    int p, q;
    for(int i=0; i<n; ++i) {
        scanf("%d %d", &p, &q);
        if(q < 0) q = -q;
        s.push_back(make_pair(p, q));
        d[i] = _size * _size;
    }
    sort(s.begin(), s.end());
    for(int i=0; i<n; ++i) {
        int acc_max = 0;
        for(int j=i; j>=0; --j) { // j 전까지 기존에 묶은 기지국 사용
            acc_max = max(acc_max, s[j].second);
            int cost = max(acc_max * 2, s[i].first - s[j].first);
            d[i] = min(d[i], d[j-1] + cost);
        }
    }
    printf("%d\n", d[n-1]);
    return 0;
}
