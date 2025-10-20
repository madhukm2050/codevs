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

void solve(ll t) {
    ll n;
    cin >> n;

    vector<ll> vec(n);
    rep(i,n)cin >> vec[i];

    if(sz(vec) == 1){
        cout << "Case #"<<t <<": "<< vec[0] << ln;
        return;
    }

    ll ans = abs(vec[1]-vec[0]), max1 = vec[0];

    for(ll i = 1; i < n; i++){
        if(vec[i] < abs(vec[i] -vec[i-1])){
            
            ans = max(ans, vec[i]);
            ans = max(ans, max1);
            max1 = vec[i];
        }
        else{
            max1 = min(max1, vec[i]);
            ans = max(ans, abs(vec[i]-vec[i-1]));
        }
        //cerr << ans << " "<< max1 << ln;
    }
    ans = max(max1, ans);


    ll ans2 = abs(vec[n-1]-vec[n-2]), max2 = vec[n-1];

    for(ll i = n-2; i >= 0; i--){
        if(vec[i] < abs(vec[i] - vec[i+1])){
            ans2 = max(ans2, vec[i]);
            ans2 = max(ans2, max2);
            max2 = vec[i];
        }
        else{
            max2 = min(max2, vec[i]);
            ans2 = max(ans2, abs(vec[i]-vec[i+1]));
        }
        //cerr << ans2 << " "<< max2 << ln;
    }
    ans2 = max(max2, ans2);

    cout << "Case #"<<t <<": "<< min(ans, ans2) << ln;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // FILE* in = freopen("input12.txt", "r", stdin);

    // FILE* out = freopen("m12.txt", "w", stdout);

    int t=1;
    cin >> t;
    ll c = 1;
    while (t--) {
        solve(c);
        c++;
    }
    return 0;
}