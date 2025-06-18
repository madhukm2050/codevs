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
    
    vector<ll> vec(n+1);
    map<ll,ll> map;
    rep(i,n){
        ll a;
        cin >> a;
        vec[a] = i+1;
        map[i+1] = a;  
    }
    ll count = 1;
    vector<ll> vis(n+1);
    vis[1] = 1;
    for(ll i = 1; i < n; i++){
        if(vec[i] > vec[i+1]){
            count++;
            vis[i+1] = 1;
        }
    }

    auto f = [&](int ind){
        if(ind > 1 && vis[ind] == 1){
            count--;
            vis[ind] = 0;
        }
        if(ind > 1 && vec[ind] < vec[ind-1] && vis[ind] == 0){
            count++;
            vis[ind] = 1;
        }
        if(ind < n && vec[ind] > vec[ind+1] && vis[ind+1] == 0){
            count++;
            vis[ind+1] = 1;
        }
        if(ind < n && vec[ind] < vec[ind+1] && vis[ind+1] == 1){
            vis[ind+1] = 0;
            count--;
        }
    };


    rep(i,m){
        ll a, b;
        cin >> a >> b;

        swap(vec[map[a]], vec[map[b]]);
        swap(map[a], map[b]);

        f(map[a]);
        f(map[b]);
        cout << count << ln;
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