// submission: https://codeforces.com/contest/61/submission/356589066
/* We have army of size n and n elements (power of army) Weakness of an army is equal 
to the number of triplets i, j, k such that i < j < k and 
ai > aj > ak where ax is the power of man standing at position x.  
powers of all the people in army are distinct. Find how weak the army is */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()

const int MOD = 1e9 + 7; // 998244353
const int bada= 1e6+5;
ll a[bada], seg[4*bada];

void update(int ind,int low, int high,int pos){ // for updating/building the segment tree 
    if(low==high){
        seg[ind]++; 
        return;
    }
    int mid=(low+high)/2;
    if(pos<=mid) update(2*ind+1,low,mid,pos);
    else update(2*ind+2,mid+1,high,pos);
    seg[ind]=seg[2*ind+1]+seg[2*ind+2];
}

int query(int ind,int low, int high, int p, int r){ //querying the segment tree
    if(low>=p && high<=r) return seg[ind];     
    if(low>r || high<p) return 0;
    int mid=(low+high)/2;
    int left=query(2*ind+1,low,mid,p,r), right=query(2*ind+2,mid+1,high,p,r);
    return left+right;
}
// T.C.: O(nlogn)
// S.C.: O(n)
int main() {
    int n; cin>>n;
    vector<int> temp(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        temp[i]=a[i];
    }
    sort(all(temp));
    for(int i=0;i<bada;i++){ //a[i] is upto 1e9 so segment tree will be upto 4GB. So we compress the powers
        a[i]=lower_bound(all(temp),a[i])-temp.begin();
    }
    vector<ll> gr(n);
    for(int i=0;i<n;i++){
        gr[i]=query(0,0,n-1,a[i]+1,n-1); //constructing the greater than j vector
        update(0,0,n-1,a[i]);
    }
    ll weakness=0;
    for(int i=0;i<n;i++){
        ll le_i=a[i]-(i-gr[i]); //total nos. smaller than a[i] is a[i] -- as it's the sorted index
        //total elements smaller than a[i] on the left will be j-a[j] obviously
        weakness+=gr[i]*le_i;
    }
    cout<<weakness<<endl;
}
