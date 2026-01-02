//submission link - https://codeforces.com/problemset/submission/1999/356142703

/* Approach: To make the median 1, our chosen group needs to have mostly 1s in it (more than half). 
We just count all the different ways we can pick a group that has enough 1s to "win" and add them all up! 
*/

#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 200005;

long long fact[MAXN];
long long invFact[MAXN];

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, MOD - 2);
}

void precompute() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        invFact[i] = modInverse(fact[i]);
    }
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
}

void solve() {
    int n, k;
    cin >> n >> k;
    
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        if (val == 1) cnt1++;
    }
    
    int cnt0 = n - cnt1;
    int min_ones = (k + 1) / 2;
    long long total_sum = 0;
    
    for (int i = min_ones; i <= k; i++) {
        int ones_to_pick = i;
        int zeros_to_pick = k - i;
        
        if (ones_to_pick > cnt1 || zeros_to_pick > cnt0) continue;
        
        long long ways = (nCr(cnt1, ones_to_pick) * nCr(cnt0, zeros_to_pick)) % MOD;
        total_sum = (total_sum + ways) % MOD;
    }
    
    cout << total_sum << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    precompute();
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
