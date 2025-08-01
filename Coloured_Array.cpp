#include<bits/stdc++.h>
using namespace std;

#define YES cout<<"YES"<<endl;
#define NO cout<<"NO"<<endl;
#define Yes cout<<"Yes"<<endl;
#define No cout<<"No"<<endl;
#define rep(i,n) for(int i = 0; i < n; i++)

#ifdef madhukm2050
#define debug(x) cerr << #x << " "; _print(x); cerr << endl;
#else
#define debug(x);
#endif

#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define ln "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(long double t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(unsigned long long t) {cerr << t;}

template <class T, class V> void _print(pair<T, V> p);
template <class T> void _print(vector<T> v);
template <class T> void _print(set<T> v);
template <class T, class V> void _print(map<T, V> v);
template <class T> void _print(multiset<T> v);

template <class T, class V> void _print(pair<T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector<T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set<T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset<T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map<T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

void solve() {
    ll n;
    cin >> n;

    vector<ll> vec(n);
    rep(i,n)cin >> vec[i];

    vector<ll> parent(n), rank(n);

    for(ll i = 0; i < n; i++){
        parent[i] = i;
        rank[i] = 1;
    }

    auto find_parent = [&](auto find_parent,ll u) -> ll {
        if(parent[u] == u)return u;
        return parent[u] = find_parent(find_parent,parent[u]);
    };

    vector<bool> has_cycle(n, false);
    auto join = [&](ll u, ll v)-> ll {
        ll ul_pu = find_parent(find_parent, u);
        ll ul_pv = find_parent(find_parent, v);

        if(ul_pu == ul_pv){
            has_cycle[ul_pu] = true;
            return;
        }

        if(rank[ul_pu] < rank[ul_pv]){
            parent[ul_pu] = ul_pv;
            rank[ul_pv] += rank[ul_pu];
        }
        else{
            parent[ul_pv] = ul_pu;
            rank[ul_pu] += rank[ul_pv];
        }
    };

    vector<bool> self(n, false);

    rep(i,n){
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        if(a == b)self[a] = true;
    }

    ll ans = 0;
    rep(i,n){
        if(parent[i] != i)continue;
        if(has_cycle[i])ans += rank[i];
        else ans += rank[i]+1;
    }

    cout << ans - accumulate(all(self), 0) << ln;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}