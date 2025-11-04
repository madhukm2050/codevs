#include <bits/stdc++.h>
using namespace std;

struct State {
    vector<int> arr;
    int dist;
    State(vector<int> a, int d) : arr(move(a)), dist(d) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    string tmp;
    getline(cin, tmp);
    getline(cin, tmp);

    vector<string> sh(n);
    for (int i = 0; i < n; i++) getline(cin, sh[i]);
    getline(cin, tmp);

    vector<string> orig(n);
    for (int i = 0; i < n; i++) getline(cin, orig[i]);

    map<string, int> idx;
    for (int i = 0; i < n; i++) idx[orig[i]] = i;

    vector<int> start(n), target(n);
    for (int i = 0; i < n; i++) start[i] = idx.count(sh[i]) ? idx[sh[i]] : 0;
    iota(target.begin(), target.end(), 0);

    if (start == target) {
        cout << 0;
        return 0;
    }

    queue<State> q1, q2;
    map<vector<int>, int> dist1, dist2;

    q1.emplace(start, 0);
    q2.emplace(target, 0);
    dist1[start] = 0;
    dist2[target] = 0;

    vector<int> next(n);

    auto expand = [&](queue<State>& q, map<vector<int>, int>& self, map<vector<int>, int>& other) -> int {
        int sz = q.size();
        while (sz--) {
            State state = q.front();
            vector<int> a = state.arr;
            int d = state.dist;
            q.pop();

            for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {
                    int seg = j - i + 1;
                    int rem = n - seg;
                    vector<int> remv; remv.reserve(rem);
                    for (int x = 0; x < i; x++) remv.push_back(a[x]);
                    for (int x = j + 1; x < n; x++) remv.push_back(a[x]);

                    for (int k = 0; k <= rem; k++) {
                        int pos = 0;
                        for (int x = 0; x < k; x++) next[pos++] = remv[x];
                        for (int x = i; x <= j; x++) next[pos++] = a[x];
                        for (int x = k; x < rem; x++) next[pos++] = remv[x];

                        if (next == a) continue;

                        if (other.count(next)) {
                            return d + other[next] + 1;
                        }

                        if (!self.count(next)) {
                            self[next] = d + 1;
                            q.emplace(next, d + 1);
                        }
                    }
                }
            }
        }
        return -1;
    };

    int ans = -1;
    while (!q1.empty() && !q2.empty()) {
        if (q1.size() <= q2.size()) ans = expand(q1, dist1, dist2);
        else ans = expand(q2, dist2, dist1);

        if (ans != -1) {
            cout << ans;
            return 0;
        }
    }

    cout << n - 1;
    return 0;
}
