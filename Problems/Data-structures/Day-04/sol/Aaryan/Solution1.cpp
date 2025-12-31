// link  :  https://codeforces.com/problemset/submission/1997/355846660

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;

    s[0] = '(';
    for (ll i = 1; i < n; i++) {
        if (i % 2 == 0) {
            s[i] = (s[i - 1] == '(' ? ')' : '(');
        }
    }

    stack<ll> st;
    ll ans = 0;

    for (ll i = 0; i < n; i++) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            ans += i - st.top();
            st.pop();
        }
    }

    cout << ans << '\n';
}

int main() {
    fastio;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}


/*
Explanation:

We are given a string of length n consisting of '(' and ')'.
First, we fix the string to follow a valid alternating pattern:
- s[0] is always '('
- For every even index i (> 0), we alternate the bracket based on s[i-1]

After this, the string becomes a valid bracket sequence.

To compute the answer:
- Use a stack to store indices of '('
- For every ')', match it with the latest '('
- Add the distance (current index - matched index) to the answer

This distance represents the contribution of that matched pair.

The stack ensures correct pairing and minimal total cost.

Time Complexity:
O(n)

Space Complexity:
O(n)
*/
