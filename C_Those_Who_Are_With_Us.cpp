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

bool helper1(vector<ll> row, vector<ll> col, vector<pair<ll,ll>> vec, ll rowmax, ll max1, ll n, ll m){
    // debug(vec);
    // debug(rowmax);
    // debug(colmax);
    for(ll i = 0; i < vec.size(); i++){
        if(vec[i].ff == rowmax){
            col[vec[i].ss]--;
        }
    }
    // debug(row);
    // debug(col);
    bool flag = false;
    for(ll i = 0; i < m; i++){
        if(col[i] > 0 && flag){
            //cout << max1 << ln;
            return false;
        }
        if(col[i] > 0){
            flag = true;
        }
    }
    //cout << max1 -1 << ln;
    return true;

}
bool helper2(vector<ll> row, vector<ll> col, vector<pair<ll,ll>> vec, ll colmax,ll max1, ll n, ll m){
    for(ll i = 0; i < vec.size(); i++){
        if(vec[i].ss == colmax){
            row[vec[i].ff]--;
        }
    }
    bool flag = false;
    for(ll i = 0; i < n; i++){
        if(row[i] > 0 && flag){
            //cout << max1 << ln;
            return false;
        }
        if(row[i] > 0){
            flag = true;
        }
    }
    return true;
}


void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));
    ll max1 = 0;
    rep(i,n){
        rep(j,m){
            cin >> a[i][j];
            max1 = max(max1, a[i][j]);
        }
    }

    vector<pair<ll,ll>> vec;
    vector<ll> row(n,0), col(m,0);
    ll rowmax = 0, indr = 0, colmax = 0, indc = 0;
    rep(i,n){
        rep(j,m){
            if(max1 == a[i][j]){
                vec.pb({i,j});
                row[i]++;
                col[j]++;

                if(row[i] > indr){
                    indr = row[i];
                    rowmax = i;
                }
                if(col[j] > indc){
                    indc = col[j];
                    colmax = j;
                }
            }
        }
    }
    vector<ll> r, c;
    for(ll i = 0; i < n; i++)if(row[i] == indr)r.pb(i);
    for(ll i = 0; i < m; i++)if(col[i] == indc)c.pb(i);



    if(helper1(row, col, vec, rowmax, max1, n, m) || helper2(row, col, vec, colmax, max1, n, m)){
        cout << max1-1 << ln;
    }
    else{
        cout << max1 << ln;
    }
    
    
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