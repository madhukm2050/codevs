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
    vector<ll> a(n), b(m);

    rep(i,n)cin >> a[i];
    rep(i,m)cin >> b[i];

    ll i = 0, j = 0;
    while(i < n && j < m){
        if(a[i] >= b[j]){
            i++;
            j++;
        }
        else{
            i++;
        }
    }
    if(j == m){
        cout << 0 << ln;
        return;
    }

    vector<ll> pre(m,INF), suff(m,-INF);

    i = 0;
    for(ll j = 0; j < m; j++){
        while(i < n && a[i] < b[j]){
            i++;
        }
        if(i < n){
            pre[j] = i;
            i++;
        }
    }
    i = n-1;
    for(ll j = m-1; j >= 0; j--){
        while(i >= 0 && a[i] < b[j]){
            //cerr << a[i] << " "<< b[j] << ln;
            i--;
        }
        if(i >= 0){
            suff[j] = i;
            i--;
        }
        //cerr << i << ln;
    }
    ll ans = INF;

    //debug(pre);
    //debug(suff);


    for(ll i = 1; i < m-1; i++){
        if(suff[i+1] > pre[i-1]){
            ans = min(ans, b[i]);
        }
    }
    if(suff[1] != -INF){
        ans = min(ans, b[0]);
    }
    if(pre[m-2] != INF){
        ans = min(ans, b[m-1]);
    }

    if(ans == INF){
        cout << -1 << ln;
    }
    else{
        cout << ans << ln;
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