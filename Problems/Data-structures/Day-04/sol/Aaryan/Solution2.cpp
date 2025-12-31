// link : https://codeforces.com/problemset/submission/1912/355879512

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<pair<ll, ll>>;

int main() {
    ll init_pow, k;
    cin >> init_pow >> k;

    vi seg;

    for (ll grp = 0; grp < k; grp++) {
        ll n;
        cin >> n;

        ll cur = 0, min_pref = 0;

        for (ll i = 0; i < n; i++) {
            ll x;
            cin >> x;

            cur += x;
            min_pref = max(min_pref, -cur);

            if (cur > 0) {
                seg.push_back({min_pref, cur});
                cur = 0;
            }
        }
    }

    sort(seg.begin(), seg.end());

    for (auto p : seg) {
        if (p.first > init_pow) break;
        init_pow += p.second;
    }

    cout << init_pow << '\n';
    return 0;
}


/*
Explanation:

Each group is split into profitable segments. While reading a group, `cur`
stores the running sum and `min_pref` stores the maximum deficit
(-prefix sum), i.e., the minimum power required to start that segment.
Whenever `cur > 0`, the segment is stored as (min_pref, cur) and `cur` is reset.

All segments are sorted by required power and processed greedily.
If the required power of a segment exceeds current power, we stop;
otherwise, we add its gain.

Time Complexity: O(N log N)
Space Complexity: O(N).


*/
