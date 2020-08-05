#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int _size = 1000005;
int n, k, w, h;
bool c[_size];

int main() {
    puts("ready");
  scanf("%d %d %d %d", &h, &w, &k, &n);
  int x, y;
  int s=0, e=max(w, h), m;
  for(int i=0; i<n; ++i) {
    scanf("%d %d", &x, &y);
    c[y] = true;
    s = max(s, x);
  }
  int ans = _size;
  while(s <= e) {
    m = (s+e)/2;
    int cnt = 0;
    for(int i=1; i<=w; ++i) {
      if(!c[i]) continue;
      i += m - 1;
      cnt++;
    }
    if(cnt <= k) {
      ans = min(ans, m);
        s = m + 1;
    } else {
      e = m - 1;
    }
  }
  printf("%d\n", ans);
  return 0;
}
