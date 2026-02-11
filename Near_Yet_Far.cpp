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
    ll n, k;
    cin >> n >> k;

    vector<ll> vec(n);
    rep(i,n)cin >> vec[i];

    ll max1 = 0, max2 = 0, ind1 = 0, ind2 = 0, min1 = INF, min2 = INF,  d1 = 0, d2 = 0;

    if(k == 2){
        vector<ll> m1, m2;

        for(ll i = 0; i < n; i+=2)m1.pb(vec[i]);
        for(ll i = 1; i < n; i+=2)m2.pb(vec[i]);

        sort(all(m1));
        sort(all(m2));

        cout << max(m1[sz(m1)-1] - m1[0], m2[sz(m2)-1]-m2[0]) << ln;
        return;
    }

    for(ll i = 0; i < n; i++){
        if(vec[i] > max1){
            max2 = max1;
            max1 = vec[i];
            ind2 = ind1;
            ind1 = i;
        }
        else if(vec[i] > max2 ){
            ind2 = i;
            max2 = vec[i];
        }

        if(vec[i] < min1){
            min2 = min1;
            min1 = vec[i];
            d2 = d1;
            d1 = i;
        }
        else if(vec[i] < min2){
            d2 = i;
            min2 = vec[i];
        }
    }

    ll ans = 0;
    for(ll i = 0; i < ind1-1; i++)ans = max(ans,vec[ind1] -vec[i]);
    for(ll i = ind1+ 2; i < n; i++)ans = max(ans,vec[ind1] - vec[i]);

    for(ll i = 0; i < ind2; i++)ans = max(ans,vec[ind2] -vec[i]);
    for(ll i = ind2+ 2; i < n; i++)ans = max(ans,vec[ind2] - vec[i]);

    for(ll i = 0; i < d1-1; i++)ans = max(ans,vec[i] - vec[d1]);
    for(ll i = d1+ 2; i < n; i++)ans = max(ans,vec[i] - vec[d1]);

    for(ll i = 0; i < d2; i++)ans = max(ans,vec[i] - vec[d2]);
    for(ll i = d2+ 2; i < n; i++)ans = max(ans,vec[i] - vec[d2]);

    cout << ans << ln;
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