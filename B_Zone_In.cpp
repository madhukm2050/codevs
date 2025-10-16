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

ll count1 = 0, max1 = 0;
vector<ll> row = {-1, 0, 1, 0}, col = {0, -1, 0, 1};

void helper(ll i,ll j, vector<vector<bool>> &vis, vector<vector<bool>> &v){
    ll n = sz(v), m = sz(v[0]);
    v[i][j] = true;
    count1++;
    max1 = max(max1, count1);

    for(ll x = 0; x < 4; x++){
        ll r = i+row[x];
        ll c = j+col[x];

        if(r >= 0 && r < n && c >= 0 && c < m && !vis[r][c] && !v[r][c]){
            helper(r, c, vis, v);
        }
    }
}

void solve(ll t) {
    ll n, m, s;
    cin >> n >> m >> s;

    vector<vector<char>> vec(n, vector<char>(m));
    
priority_queue<pair<int, pair<int, int>>, 
               vector<pair<int, pair<int, int>>>, 
               greater<pair<int, pair<int, int>>>> q;
               
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            cin >> vec[i][j];
            if(i == 0 || i == n-1 || j == 0 || j == m-1 || vec[i][j] == '#'){
                //cerr << i << " "<< j << ln;
                if(vec[i][j] == '#')q.push({0, {i, j}});
                else q.push({1, {i,j}});
                vis[i][j] = true;
            }
        }
    }
    //debug(sz(q));



    while(!q.empty()){
        pair<ll,pair<ll,ll>> p = q.top();
        q.pop();
        ll count = p.ff, i = p.ss.ff, j = p.ss.ss;
        if(count == s){
            continue;
        }

        for(ll x = 0; x < 4; x++){
            ll r = i + row[x], c = j + col[x];

            if(r >= 0 && r < n && c >= 0 && c < m && !vis[r][c]){
                vis[r][c] = true;
                q.push({count+1, {r, c}});
            }
        }
    }
    //debug(vis);
    ll ans = 0;

    vector<vector<bool>> v(n, vector<bool>(m, false));

    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            if(!vis[i][j]){
                max1 = 0;
                count1 = 0;
                helper(i, j, vis, v);
                ans = max(ans, max1);
            }
        }
    }
    cout << "Case #"<< t << ": "<<ans << ln;
    
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    
    FILE* in = freopen("b1.txt", "r", stdin);
    if(!in){ cerr << "Failed to open b1.txt\n"; return 1; }
    FILE* out = freopen("m2.txt", "w", stdout);
    if(!out){ cerr << "Failed to open m1.txt\n"; return 1; }


    int t=1;
    cin >> t;
    ll c = 1;
    while (t--) {
        solve(c);
        c++;
    }
    return 0;
}
