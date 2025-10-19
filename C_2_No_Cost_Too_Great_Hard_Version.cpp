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


const ll N = 2*100000; 
vector<ll> spf(N + 1); 

void sieve() {
    for (ll i = 2; i <= N; i++) spf[i] = i;
    for (ll i = 2; i * i <= N; i++) {
        if (spf[i] == i) { 
            for (ll j = i * i; j <= N; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}


vector<ll> getfac(ll x) {
    vector<ll> res;
    while (x > 1) {
        ll p = spf[x];
        res.push_back(p);
        while (x % p == 0)
            x /= p;
    }
    //debug(res);
    return res;
}

void solve() {
    ll n;
    cin >> n;

    

    vector<ll> a(n), b(n);

    ll count = 0, min1 = INF;
    rep(i,n){
        cin >> a[i];
        if((a[i]%2) == 0)count++;
    }
    rep(i,n)cin >> b[i];

    // debug(a);
    // debug(b);

    if(count >= 2){
        cout << 0 << ln;
        return;
    }

    set<ll> st;

    bool flag1 = false, flag2 = false;

    vector<vector<ll>> vec;
    for(ll i = 0; i < n; i++){
        vec.pb(getfac(a[i]));
    }

    vector<vector<ll>> vec1;
    for(ll i = 0; i < n; i++){
        vec1.pb(getfac(a[i]+1));
    }


    for(ll i = 0; i < n; i++){
        vector<ll> v1 = vec1[i];

        for(auto e : v1){
            if(st.count(e)){
                flag2 = true;
                min1 = min(min1, b[i]);
            }
        }

        vector<ll> v2 = vec[i];
        for(auto e : v2){
            if(st.count(e)){
                cout << 0 << ln;
                return;
            }
            st.insert(e);
        }
    }
    
    set<ll> st1;
    for(ll i = n-1; i >= 0; i--){
        vector<ll> v2 = vec1[i];

        for(auto e : v2){
            if(st1.count(e)){
                min1 = min(min1, b[i]);
                flag2 = true;
            }
        }

        vector<ll> v1 = vec[i];
        for(auto e : v1){
            if(st1.count(e)){
                cout << 0 << ln;
                return;
            }
            st1.insert(e);
        }
    }
    if(flag2 || count > 0){
        cout << min1 << ln;
    }
    else{
        sort(all(b));
        cout << b[0]+b[1] << ln;
    }


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}