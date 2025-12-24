#include <bits/stdc++.h>
using namespace std;

// Returns -1 if n cannot be reduced to 1, otherwise returns minimum number of steps
int minOperationsTo1(int n, set<int>& visited, map<int,int>& memo) {
    if (n == 1) return 0;              // Already 1, 0 steps
    if (visited.count(n)) return -1;   // Cycle detected
    if (memo.count(n)) return memo[n]; // Memoization

    visited.insert(n);
    int res = INT_MAX;

    if (n % 2 == 1) {
        // Odd number: only one operation
        int next = (n ^ 3) + 1;
        int op = minOperationsTo1(next, visited, memo);
        if (op != -1) res = min(res, op + 1);
    } else {
        // Even number: try both operations
        int op1 = minOperationsTo1(n / 2, visited, memo);
        int op2 = minOperationsTo1((n ^ 3) + 1, visited, memo);

        if (op1 != -1) res = min(res, op1 + 1);
        if (op2 != -1) res = min(res, op2 + 1);
    }

    visited.erase(n); // Backtrack
    memo[n] = (res == INT_MAX ? -1 : res);
    return memo[n];
}

int main() {
    for (int i = 1; i <= 100; i++) {
        set<int> visited;
        map<int,int> memo;
        int steps = minOperationsTo1(i, visited, memo);
        if (steps != -1) {
            cout << i << " YES, min steps = " << steps << "\n";
        } else {
            cout << i << " NO\n";
        }
    }
    return 0;
}
