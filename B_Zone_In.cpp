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

vector<ll> rows = {-1, 0, 1, 0}, cols = {0, -1, 0, 1};
ll c1 = 0, max1 = 0;
void dfs(ll i , ll j, vector<vector<char>> &vec, vector<vector<bool>> &vis){
    ll n = sz(vec), m = sz(vec[0]);
    vis[i][j] = true;
    c1++;
    max1 = max(max1, c1);

    for(ll x = 0; x < 4; x++){
        ll r = rows[x]+i;
        ll c = cols[x]+j;

        if(r >= 0 && r < n && c >= 0 && c < m && vec[r][c] == '*' && !vis[r][c]){
            dfs(r, c, vec, vis);
        }
    }
}

void helper(ll i , ll j , vector<vector<char>> &vec, vector<vector<bool>> &vis){
    
}

void solve(ll t) {
    ll n, m, s;
    cin >> n >> m >> s;
    max1 = 0;

    vector<vector<char>> vec(n, vector<char>(m));
    

    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            if(vec[i][j] == '.'){
                
            }
        }
    }
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            cout << vec[i][j] <<" ";
        }
        cout << ln;
    }

    vector<vector<bool>> vis(n, vector<bool> (m, false));
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            if(vec[i][j] == '*'){
                c1 = 0;
                dfs(i, j, vec, vis);
            }
        }
    }
    cout << max1 << ln;
    //debug(vec);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    cin >> t;
    ll c = 1;
    while (t--) {
        solve(c);
        c++;
    }
    return 0;
}