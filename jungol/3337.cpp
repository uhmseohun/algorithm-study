#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
long long n, k;

struct L {
    long long counter, customer, end_time;

    bool operator < (const L &r) const {
        if(end_time == r.end_time) {
            return counter > r.counter;
        } else {
            return end_time > r.end_time;
        }
    }
};

bool sort_comparator(const L a, const L b) {
    if(a.end_time == b.end_time) {
        return a.counter > b.counter;
    } else {
        return a.end_time < b.end_time;
    }
}

int main() {
    scanf("%d %d", &n, &k);
    long long id, quantity;
    priority_queue<L> pq;
    vector<L> sequence;
    for(int i=0; i<n; ++i) {
        scanf("%lld %lld", &id, &quantity);
        if(i < k) {
            pq.push(L({ i+1, id, quantity }));
        } else {
            const auto t = pq.top();
            sequence.push_back(t);
            pq.pop();
            pq.push(L({ t.counter, id, t.end_time + quantity }));
        }
    }
    while(!pq.empty()) {
        const auto t = pq.top();
        pq.pop();
        sequence.push_back(t);
    }
    sort(sequence.begin(), sequence.end(), sort_comparator);
    long long answer = 0;
    for(long long i=0; i<n; ++i) {
        answer += (i + 1) * sequence[int(i)].customer;
    }
    printf("%lld\n", answer);
    return 0;
}
