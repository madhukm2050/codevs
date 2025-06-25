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

ll N = 1e7+1;
vector<ll> spf(N+1);

void seive(){
    for(ll i = 0; i < N; i++)spf[i] = i;

    for(ll i = 2; i*i <= N; i++){
        if(spf[i] == i){
            for(ll j = i*i; j <= N; j+= i){
                if(spf[j] == j)spf[j] = i;
            }
        }
    }
}
void solve() {
    ll n, m;
    cin >> n >> m;

    vector<ll> a(n), b(m);
    rep(i,n)cin >> a[i];
    rep(i,m)cin >> b[i];

    map<ll,ll> p1, p2, p3;

    for(ll i = 0; i < n; i++){
        ll x = a[i];
        while(x > 1){
            ll p = spf[x], count = 0;
            while(x%p == 0){
                count++;
                x /= p;
            }
            p1[p] += count;
        }
    }

    for(ll i = 0; i < m; i++){
        ll x = b[i];
        while(x > 1){
            ll p = spf[x], count = 0;
            while(x%p == 0){
                count++;
                x /= p;
            }
            p2[p] += count;
        }
    }
    for(auto e : p1){
        p3[e.ff] = min(e.ss, p2[e.ff]);
    }
    p1 = p2 = p3;

    for(ll i = 0; i < n; i++){
        ll x = a[i];
        while(x > 1){
            ll p = spf[x], count = 0;
            while(x%p == 0){
                count++;
                x /= p;
            }
            count = min(count, p1[p]);
            p1[p] -= count;
            while(count--)a[i]/=p;
        }
    }
    for(ll i = 0; i < m; i++){
        ll x = b[i];
        while(x > 1){
            ll p = spf[x], count = 0;
            while(x%p == 0){
                count++;
                x /= p;
            }
            count = min(count, p2[p]);
            p2[p] -= count;
            while(count--)b[i]/=p;
        }
    }
    cout << n << " "<< m << ln;
    for(auto e : a)cout << e << " ";
    cout << ln;
    for(auto e : b)cout << e << " ";
    cout << ln;
    
    //debug(p3);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    seive();
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}