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
    vector<ll> a(n), b(n);
    rep(i,n)cin >> a[i];
    rep(i,n)cin >> b[i];

    vector<pair<ll,pair<ll,ll>>> v(n);

    rep(i,n){
        v[i].ff = a[i];
        v[i].ss.ff = b[i];
        v[i].ss.ss = i;
    }

    sort(all(v));
    //debug(v);

    map<ll,ll> mp;

    for(ll i = 0; i < n; i++){
        mp[v[i].ff] = i;
    }
    //debug(mp);
    vector<pair<ll,ll>> ans;
    for(ll i = 0; i < n; i++){
        if(v[i].ff > v[i].ss.ff){
            cout << "Case #"<< t << ": "<< -1 << ln;
            return;
        }
        else if(v[i].ff != v[i].ss.ff){
            //cerr << "vv " <<v[i].ff << " "<< v[i].ss << ln;
            auto it = mp.find(v[i].ss.ff);

            if(it != mp.end()){
                //cerr <<it-> first << " "<< it->second+1 << ln;
                ans.pb({v[it->second].ss.ss+1, v[i].ss.ss+1});
            }
            else{
                cout << "Case #"<< t << ": "<< -1 << ln;
                return;
            }
        }
    }

    cout << "Case #"<< t << ": "<< sz(ans) << ln;

    for(ll i = 0; i < sz(ans); i++){
        cout << ans[i].ff << " "<< ans[i].ss << ln;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    FILE* in = freopen("warm_up_input.txt", "r", stdin);
    if (!in) {
        cerr << "Error: Could not open input.txt for reading." << endl << flush;
    } else {
        cerr << "input.txt opened successfully." << endl << flush;
    }

    // Comment out the next line for debugging in terminal
    FILE* out = freopen("m1.txt", "w", stdout);

    int t=1;
    cin >> t;
    ll c = 1;
    while (t--) {
        solve(c);
        c++;
    }
    return 0;
}