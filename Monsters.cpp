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

    vector<string> vec(n);
    ll x = 0, y = 0;
    rep(i,n){
        cin >> vec[i];
        rep(j,m){
            if(vec[i][j] == 'A'){
                x = i;
                y = j;
            }
        }
    }

    vector<vector<bool>> vis(n, vector<bool>(m));
    
    vector<ll> row = {-1, 0, 1, 0};
    vector<ll> col = {0, -1, 0, 1};
    
    //debug(vec);

    queue<pair<string,pair<ll,ll>>> q;
    q.push({"",{x,y}});
    vis[x][y] = true;
    
    vector<char> v = {'U', 'L', 'D', 'R'};
    while(!q.empty()){
        pair<string,pair<ll,ll>> p = q.front();
        q.pop();
        string s = p.ff;
        ll i = p.ss.ff, j = p.ss.ss;
        if(i == 0 || j == 0 || i == n-1 || j == m-1){
            YES;
            cout << sz(s) << ln;
            cout << s << ln;
            return;
        }
        for(ll x = 0; x < 4; x++){
            ll r = i + row[x], c = j+col[x];
            
            if(r >= 0 && r < n && c >= 0 && c <= m && !vis[r][c] && vec[r][c] == '.' ){
                
                vis[r][c] = true;
                q.push({s+v[x],{r,c}});
            }
        }
    }

    //cerr << x << " "<< y << ln;
    //debug(vec);
    NO;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}