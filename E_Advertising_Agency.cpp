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

ll N = 1000001;
vector<ll> fac(N+1), ifac(N+1);
void factorial(){
    fac[0] = 1;
    for(ll i = 1; i <= N; i++){
        fac[i] = mod_mul(i, fac[i-1], MOD);
    }
    ifac[N] = expo(fac[N], MOD-2, MOD);
    for(ll i = N-1; i >= 0; i--){
        ifac[i] = mod_mul(ifac[i+1], i+1, MOD);
    }

}
ll combo(ll n, ll k){
    ll res = fac[n];
    ll d = mod_mul(ifac[k], ifac[n-k], MOD);
    res = mod_mul(res, d, MOD);
    return res;
}
void solve() {
    ll n, k;
    cin >> n >> k;

    map<ll,ll> mp;

    for(ll i = 0; i < n; i++){
        ll a;
        cin >> a;
        mp[a]++;
    }

    vector<ll> vec(sz(mp));

    ll x = 0;
    for(auto e : mp){
        vec[x] = e.ss;
        x++;
    }
    //sort(vec.rbegin(), vec.rend());
    reverse(all(vec));
    //debug(vec);
    ll ans = 1;
    for(ll i = 0; i < sz(vec); i++){
        //cerr << vec[i] << " "<< k << ln;
        if(vec[i] <= k){
            //ans = mod_mul(ans, fac[vec[i]], MOD);
            k -= vec[i];
        }
        else{
            ans = mod_mul(ans, combo(vec[i], k), MOD);
            break;
        }
    }
    cout << ans << ln;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    factorial();
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}