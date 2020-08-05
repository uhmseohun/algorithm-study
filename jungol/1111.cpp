#include <stdio.h>
#include <algorithm>
using namespace std;
const int _size = 105;
int n, x, y, h[_size][_size];
int c[_size][_size], q[_size][_size];
const int xx[] = { -1, 0, 1, 0 };
const int yy[] = { 0, 1, 0, -1 };

void init() {
    for(int i=0; i<_size; ++i) {
        for(int j=0; j<_size; ++j) {
            c[i][j] = 10000000;
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &x, &y);
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) {
            scanf("%d", &h[i][j]);
        }
    }
    init();
    c[x][y] = 0;
    while(true) {
        int _i=0, _j=0;
        for(int i=0; i<=n+1; ++i) {
            for(int j=0; j<=n+1; ++j) {
                if(c[i][j] < c[_i][_j] && !q[i][j]) {
                    _i = i; _j = j;
                }
            }
        }
        q[_i][_j] = true;
        if(_i < 1 || _j < 1 || _i > n || _j > n) {
            printf("%d\n", c[_i][_j]);
            break;
        }
        for(int i=0; i<4; ++i) {
            int next_x=_i+xx[i], next_y=_j+yy[i];
            int d = h[next_x][next_y] - h[_i][_j];
            // d가 0보다 크다면 거꾸로 올라올 때는 내리막길임 (지금 거꾸로 움직이고 있으니까)
            if(d > 0) {
                c[next_x][next_y] = min(c[next_x][next_y], c[_i][_j] + d);
            } else if(d < 0) {
                c[next_x][next_y] = min(c[next_x][next_y], c[_i][_j] + d*d);
            } else {
                c[next_x][next_y] = min(c[next_x][next_y], c[_i][_j]);
            }
        }
    }
    return 0;
}
