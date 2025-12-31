#include <bits/stdc++.h>
using namespace std;

/*
 We want minimum number of 1-ohm resistors needed
 to build resistance = a / b

 Allowed operations (each consumes exactly 1 resistor):

 1. Series:
      R = Re + 1
      (fraction increases, used when R > 1)

 2.Parallel:
      R = Re / (Re + 1)
      (fraction becomes smaller, used when R < 1)

-----------------------------------------------
 KEY OBSERVATION

 Reverse-thinking makes problem easy:

 Instead of building a/b from 1,
 go BACKWARDS from a/b to 1/1.

 When:
      a >= b   → fraction > 1
 means fraction was formed by SERIES operations
 so we repeatedly do:
      a = a - b
 Each subtraction corresponds to ONE resistor

 Number of such subtractions = a / b
 (integer division)

 Then we reduce:
      a %= b

-----------------------------------------------

 When:
      b > a   → fraction < 1
 means fraction was formed by PARALLEL operations
 so we repeatedly do:
      b = b - a

 Number of such subtractions = b / a

 Then we reduce:
      b %= a

-----------------------------------------------

This is EXACTLY what Euclidean Algorithm does.
But instead of counting steps,
we SUM UP all quotients.

The sum = minimum number of resistors.

And problem guarantees there is always a solution,
so it always eventually reaches (1,1).
*/

long long minResistors(long long a, long long b) {

    long long ans = 0;

    while (a && b) {

        // If numerator >= denominator
        if (a >= b) {
            ans += a / b;   // number of series operations needed
            a %= b;         // continue reducing
        }
        else {
            ans += b / a;   // number of parallel operations needed
            b %= a;         // continue reducing
        }
    }

    return ans;
}

int main() {
    long long a, b;
    cin >> a >> b;

    cout << minResistors(a, b);
}


// Submission Link:- (https://codeforces.com/contest/343/my) 