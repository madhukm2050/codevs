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

    vector<ll> a(n*m+1);
    rep(i,n){
        rep(j,m){
            cin >> vec[i][j];
        }
    }



    for(ll i = 0; i < n; i++){
        ll num = 1, v = vec[i][0];
        for(ll j = 1; j < m; j++){
            if(vec[i][j] == vec[i][j-1]){
                num++;
            }
            else{
                num = 1;
                v = vec[i][j];
            }
            a[v] = max(a[v], num);
        }
    }

    for(ll i = 0; i < m; i++){
        ll num = 1, v = vec[0][i];
        for(ll j = 1; j < n; j++){
            if(vec[j][i] == vec[j-1][i]){
                num++;
            }
            else{
                num = 1;
                v = vec[j][i];
            }
            a[v] = max(a[v], num);
        }
    }
    //debug(a);

    ll m1 = 0, sum = 0, ind = 0;
    rep(i,n*m+1){
        if(a[i] > m1){
            m1 = a[i];
            ind = i;
        }
        sum += a[i];
    }
    a[ind] = 0;
    
    ll count = 0;
    for(ll i = 0; i <= n*m; i++){
        ll c = 0;
        //if(a[i] > 0)a[i]++;
        while (a[i] != 0)
        {
            a[i]/=2;
            count++;
        }
    }
    cout << count << ln;
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