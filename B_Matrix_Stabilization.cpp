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

    vector<vector<ll>> vec(n, vector<ll>(m));

    rep(i,n){
        rep(j,m){
            cin >> vec[i][j];
        }
    }

    // while(1){
    //     bool flag = false;

        rep(i,n){
            rep(j,m){
                bool flag1 = true;
                ll max1 = 0;
                
                if(i > 0 ){
                    if(vec[i][j] <= vec[i-1][j]) flag1 = false;
                    max1 = max(max1, vec[i-1][j]);
                }
                if(j > 0){
                    if(vec[i][j] <= vec[i][j-1]) flag1 = false;
                    max1 = max(max1, vec[i][j-1]);
                }
                if(i < n-1){
                    if(vec[i][j] <= vec[i+1][j]) flag1 = false;
                    max1 = max(max1, vec[i+1][j]);
                }
                if(j < m-1){  
                    if(vec[i][j] <= vec[i][j+1]) flag1 = false;
                    max1 = max(max1, vec[i][j+1]);
                }
                if(flag1){
                    vec[i][j] = max1;
                    // flag = true;
                }
            }
        }
    //}

    rep(i,n){
        rep(j,m){
            cout << vec[i][j] << " ";
        }
        cout << ln;
    }
    //cout << ln;
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