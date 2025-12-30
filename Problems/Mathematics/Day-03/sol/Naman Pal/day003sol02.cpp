// Submission Link: https://codeforces.com/contest/343/submission/355828800

/*
Problem: Find the mininmum number of 1 ohm resistance needed to make equivalent resistance a/b

The Calkin-Wilf Tree
This problem can be modeled using the Calkin-Wilf Tree, a binary tree that generates every positive rational number exactly once. 
Starting from 1/1, the two possible operations are:
    1. Series: a/b -> (a+b)/b (Moves to the Right Child)
    2. Parallel: a/b -> a/(a+b) (Moves to the Left Child)

Approach: If a resistance a/b can be obained with k resistors then it is clear that we can get resistance (a+b)/b(if 1 ohm in series) or 
a/(a+b)(if 1 ohm in parellel) with k+1 resistance. So we just go in reverse direction if a is greater than b then the last step must have been adding resistors 
in series so we add a/b to our answer and make a equal to a%b.. similarly if b is greater than a then The last step must have been adding resistors in parallel so 
we add b/a in answer and make b=b%a. This process continues untile either a or b becomes zero as either of a and b can become zero only when one is 
completely divisible by other and in this case we will get minimum number of resistor as the quotient.

Time Complexity: O(log(min(a, b))) as it is equivalent to the Euclidean GCD algorithm
*/

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    long long a,b;
    cin>>a>>b;
    long long ans=0;
    while(a>0 && b>0) {
        if(a>b) {
            ans+=a/b;
            a=a%b;
        }
        else {
            ans+=b/a;
            b=b%a;
        }
    }
    cout<<ans<<endl;
}
