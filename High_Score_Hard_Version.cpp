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
    ll n, m;
    cin >> n >> m;

    vector<ll> a(n), b(m);

    rep(i,n)cin >> a[i];
    rep(i,m)cin >> b[i];
    sort(all(a));
    sort(all(b));

   ll freq1 = 0, max1 = 0, sum = 0, freq2 = 0, max2 = 0;

   map<ll,ll> map1, map2;
   for(ll i = 0; i < n; i++){
    map1[a[i]]++;

    sum += a[i];

    if(map1[a[i]] > freq1){
        freq1 = map1[a[i]];
        max1 = a[i];
    }
   }

   for(ll i = 0; i < m; i++){
    map2[b[i]]++;

    sum += b[i];

    if(map2[b[i]] > freq2){
        freq2 = map2[b[i]];
        max2 = b[i];
    }
   }

   ll count = m - map2[max1];
   ll count2 = n- map1[max2];

   //cerr << map2[max1] << " "<< count << ln;

   if(freq1 > freq2){
        cout << sum -max(0ll,(freq1-count)*max1*2) << ln;
   }
   else if(freq2 > freq1){
        cout << sum -max(0ll,(freq2-count2)*max2*2) << ln;
   }
   else{
        cout << sum -max(0ll,(freq1-count)*max1*2) << ln;
   }
   //cerr << sum << ln;
   
   //cout << sum -max(0ll,(freq1-count)*max1*2) << ln;
   

   //cout << sum << ln;

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