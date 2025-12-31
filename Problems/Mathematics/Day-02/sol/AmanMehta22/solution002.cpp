//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#define int long long
#define fo(n) for (int i = 0; i < n; i++)
#define fo1(ii, n) for(int i=ii; i<n; i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define fi first
#define se second
#define vec(a) vector<int> a
#define vecn(a,n) vector<int> a(n)
#define py cout<<"YES"<<endl
#define pn cout<<"NO"<<endl
const int MOD = 1e9 + 7;
const int INF = 1e18;
using namespace std;

void solve(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int>a(n);
    fo(n)cin>>a[i];
    sort(a.begin(),a.end());
    int max_diff=abs(a[0]-a.back());
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(abs(a[i]-a[j])==max_diff)count++;
        }
    }
    cout<<count<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}