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

ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}

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

    vector<ll> a(n), b(n);

    rep(i,n)cin >> a[i];
    rep(i,n)cin >> b[i];

    vector<ll> pre(n), suff(n);

    pre[0] = a[0];
    ll p = a[0];
    for(ll i = 1; i < n; i++){
        if(p < 0)p = 0;
        p += a[i];
        pre[i] = p;
    }

    suff[n-1] = a[n-1];
    ll s = a[n-1];
    for(ll i = n-2; i >= 0; i--){
        if(s < 0) s = 0;
        s += a[i];
        suff[i] = s;
    }


    vector<ll> pre1(n), suff1(n);

    pre1[0] = b[0];
    p = b[0];
    for(ll i = 1; i < n; i++){
        if(p < 0)p = 0;
        p += b[i];
        pre1[i] = p;
    }

    suff1[n-1] = b[n-1];
    s = b[n-1];
    for(ll i = n-2; i >= 0; i--){
        if(s < 0) s = 0;
        s += b[i];
        suff1[i] = s;
    }

    // debug(pre);
    // debug(suff);

    // debug(pre1);
    // debug(suff1);

    ll min1 = -INF;

    for(ll i = 0; i < n; i++){
        ll val = pre[i]+suff[i]-a[i]+pre1[i]+suff1[i]-b[i];
        min1 = max(min1, val);
    }
    cout << min1 << ln;

    


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