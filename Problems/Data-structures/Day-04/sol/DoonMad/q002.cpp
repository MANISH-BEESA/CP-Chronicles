#include<bits/stdc++.h>

using namespace std;
#define int long long

// time complexity: O(n*log(n))
// space complexity: O(n)
// submission link: https://codeforces.com/problemset/submission/1912/355861913

struct Segment {
    int cost;  // min cost (-ve elements before +ve gain)
    int gain; // net gain
    int idx; // list idx
    
    // priority Queue needs to order by cost
    //priority_queue is a max-heap, so we use > for min-heap behavior
    bool operator>(const Segment& other) const {
        return cost > other.cost;
    }
};

int solve(){
    int x, k; cin>>x>>k;
    
    vector<vector<Segment>> segments(k);

    for(int i = 0; i < k; i++){
        int t; cin >> t;
        int sum = 0;
        int cost = 0;
        
        for(int j = 0; j < t; j++){
            int val; cin >> val;
            sum += val;
            cost = min(cost, sum);
            
            // If we found a net positive chunk, save it as a segment
            if(sum > 0){
                // If cost is -5, we need at least 5. If cost is 2, we need 0.
                segments[i].push_back({max(0LL, -cost), sum, i});
                sum = cost = 0;
            }
        }
    }
    
    priority_queue<Segment, vector<Segment>, greater<Segment>> pq;
    vector<int> ptr(k, 0); // ptrs for each list's current idx

    // add the first segment of each list (if it exists)
    for(int i = 0; i < k; i++){
        if(segments[i].size() > 0){
            pq.push(segments[i][0]);
        }
    }

    while(!pq.empty()){
        Segment best = pq.top();
        pq.pop();
        
        if(x >= best.cost){
            x += best.gain;
            int i = best.idx; // mov ptr forward
            ptr[i]++;
            if(ptr[i] < segments[i].size()){
                pq.push(segments[i][ptr[i]]);
            }
        }
        else break;
    }

    return x;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << solve() << endl;

    return 0;
}