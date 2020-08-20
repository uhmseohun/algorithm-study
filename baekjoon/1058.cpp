#include <cstdio>
#include <algorithm>
using namespace std;
const int _size = 60;
int n;
int r[_size][_size];

int main() {
    scanf("%d", &n);
    char c;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            scanf(" %c", &c);
            r[i][j] = c == 'Y' ? 1 : 100000;
        }
    }
    for(int k=0; k<n; ++k) {
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                if(i == j) continue;
                r[i][j] = min(r[i][j], r[i][k] + r[k][j]);
            }
        }
    }
    int answer = 0;
    for(int i=0; i<n; ++i) {
        int sum = 0;
        for(int j=0; j<n; ++j) {
            if(i == j) continue;
            sum += int(r[i][j] <= 2);
        }
        answer = max(answer, sum);
    }
    printf("%d\n", answer);
    return 0;
}
