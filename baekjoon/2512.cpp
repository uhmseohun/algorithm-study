#include <cstdio>
#include <algorithm>
using namespace std;
const int _size = 10005;
int n, m[_size], k;

bool is_available(int limit) {
    int sum = 0;
    for(int i=0; i<n; ++i) {
        sum += min(m[i], limit);
    }
    return sum <= k;
}

int main() {
    scanf("%d", &n);
    int start = 1, end = 0;
    for(int i=0; i<n; ++i) {
        scanf("%d", &m[i]);
        end = max(end, m[i]);
    }
    scanf("%d", &k);
    int answer = 0;
    while(start <= end) {
        int mid = (start + end) / 2;
        if(is_available(mid)) {
            answer = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    printf("%d\n", answer);
    return 0;
}
