//link : https://cses.fi/problemset/result/15780990/

#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define loop(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

using pii = pair<int,int>;
using vi = vector<int>;
using vpi = vector<pii>;

void solve() {
    int n;
    cin >> n;

    vpi a(n);
    loop(i, n) cin >> a[i].F >> a[i].S;

    vi ans(n), id(n);
    iota(all(id), 0);

    // keep original indices
    sort(all(id), [&](int i, int j) {
        return a[i] < a[j];
    });

    sort(all(a));

    priority_queue<pii, vpi, greater<>> pq; // {departure, room}

    int mx = 0;
    loop(i, n) {
        int l = a[i].F, r = a[i].S, rm;

        if (pq.empty() || pq.top().F >= l) {
            rm = sz(pq) + 1;
        } else {
            rm = pq.top().S;
            pq.pop();
        }

        pq.push({r, rm});
        mx = max(mx, sz(pq));
        ans[id[i]] = rm;
    }

    cout << mx << '\n';
    for (int x : ans) cout << x << " ";
    cout << '\n';
}

int main() {
    fast_io;
    solve();
    return 0;
}



/*
Explanation:

Each booking is represented as (arrival, departure).
We first sort the bookings by arrival time.

A min-heap (priority queue) is used to keep track of currently occupied
rooms, storing pairs (departure_time, room_number).

For each booking:
- If the room with the earliest departure is free before the current
  arrival, we reuse that room.
- Otherwise, we allocate a new room.

The heap size at any moment represents the number of rooms in use.
We track the maximum heap size, which gives the minimum number of rooms needed.

Room numbers are stored to output the assignment in the original order.

Time Complexity: O(n log n)  
Space Complexity: O(n)


*/