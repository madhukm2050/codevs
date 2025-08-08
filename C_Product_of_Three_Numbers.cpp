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

    vector<ll> vec;
    vector<pair<ll,ll>> v;
    for(ll i = 2; i*i <= n; i++){
        if(n%i == 0){
            ll count = 0;
            while(n%i == 0){
                vec.pb(i);
                n = n/i;
                count++;
            }
            v.pb({i, count});
        }
    }
    //cerr << n << ln;
    if(n > 1){
        v.pb({n, 1});
        vec.pb(n);
    }
    //debug(v);
    if(sz(vec) < 3){
        NO;
        return;
    }
    if(sz(v) == 1){
        ll val = v[0].ff;
        ll count = v[0].ss;
        if(count >= 6){
            YES;
            cout << val << " "<<(val*val) << " "<< pow(val, count-3) << ln;
            return;
        }
        NO;
    }
    else if(sz(v) == 2){
        if(v[0].ss+v[1].ss > 3){
            ll p = 1;
            while(v[0].ss > 1)p*=v[0].ff, v[0].ss = v[0].ss-1;
            while(v[1].ss > 1)p*=v[1].ff , v[1].ss = v[1].ss-1;
            YES;
            cout << v[0].ff << " "<< v[1].ff << " "<< p << ln;
            return;
        }
        NO;
    }
    else{
        //debug(v);
        for(ll i = 0; i < 3; i++){
            //cerr << v[i].ff << " "<< v[i].ss << " "<< pow(v[i].ff, v[i].ss) << ln;
            ll p = expo(v[i].ff, v[i].ss, INF);
            v[i].ff = p;
            //debug(v[i].ff);
        }
        //debug(v);

        for(ll i = 3; i < sz(v); i++){
            v[2].ff *= expo(v[i].ff, v[i].ss, INF);
        }
        YES;
        cout << v[0].ff << " "<<v[1].ff << " "<< v[2].ff << ln;
    }
    //debug(v);
    //debug(vec);
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