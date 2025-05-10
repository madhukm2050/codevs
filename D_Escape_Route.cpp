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

void solve() {
    ll n, m;
    cin >> n >> m;

    vector<string> vec(n);

    rep(i,n)cin >> vec[i];

    vector<vector<ll>> dis(n, vector<ll>(m, INF));

    queue<pair<ll,ll>> q;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            if(vec[i][j] == 'E'){
                q.push({i,j});
                dis[i][j] = 0;
            }
        }
    }

    vector<ll> row = {-1, 0, 1, 0};
    vector<ll> col = {0,-1, 0, 1};
    while(!q.empty()){
        pair<ll,ll> p = q.front();
        q.pop();

        ll i = p.ff, j = p.ss;

        for(ll x = 0; x < 4; x++){
            ll r = i+row[x];
            ll c = j+col[x];

            if(r >= 0 && r < n && c >= 0 && c < m && dis[i][j] + 1 < dis[r][c] && vec[r][c] != '#' && vec[r][c] != 'E'){
                dis[r][c] = 1+dis[i][j];
                if(x == 0){
                    vec[r][c] = 'v';
                }
                else if(x == 1){
                    vec[r][c] = '>';
                }
                else if(x == 2){
                    vec[r][c] = '^';
                }
                else{
                    vec[r][c] = '<';
                }
                q.push({r,c});
            }
        }
    }

    for(auto e : vec){
        cout << e << ln;
    }


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