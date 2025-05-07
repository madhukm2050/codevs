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

vector<ll> row = {1, -1, 0}, col = {0, 0, 1};

bool dfs(ll i,ll j, vector<vector<string>> s, ll count, ll n, ll c1, vector<vector<ll>> &vis){
    c1++;
    if(c1 == count)return true;

    for(ll x = 0; x < 3; x++){
        ll r = i+row[x], c = j+col[x];

        if(r >= 0 && r < 2 && c >= 0 && c < n && s[r][c] == "B"){
            if(dfs(r, c, s, count,n, c1, vis))return true;
        }
    }
    return false;
}

bool helper(ll i, ll j, vector<vector<string>> s, ll count, ll n){
    if(j == -1)return false;
    vector<vector<ll>> vis(2, vector<ll>(n));
    //return dfs(i, j, s, count, n,  );
}

void solve() {
    ll n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;

    ll count = 0, ind1 = -1, ind2 = -1;
    rep(i,n){
        if(s1[i] == 'B'){
            if(ind1 == -1) ind1 = i;
            count++;
        }
        if(s2[i] == 'B'){
            if(ind2 == -1)ind2 = i;
            count++;
        }
    }
    vector<vector<string>> s;
    s[0].pb(s1);
    s[1].pb(s2);


    
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