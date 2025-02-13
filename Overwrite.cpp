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
    vector<ll> a(n);
    vector<ll> b1(m);

    rep(i,n)cin >> a[i];
    ll min1 = INF, ind = n;
    rep(i,m){
        cin >> b1[i];
        if(min1> b1[i]){
            min1 = b1[i];
            ind = i;
        }
    }

    if(m == 1){
        for(ll i = 0; i < n; i++){
            cout << min(a[i],b1[0]) << " ";
        }
        cout << ln;
        return;
    }


    vector<ll> b(m);
    for(ll i = 0; i < m; i++){
        b[i] = b1[ind%m];
        ind++;
    }
    // debug(a);
    // debug(b);

    bool flag = false;
    for(ll i = 0; i <= n-m; i++){
        if(a[i] > b[0]){
            for(ll j = i; j <= n-m; j++){
                a[j] = b[0];
            }
            for(ll j = 1; j < m; j++){
                a[n+j-m] = b[j];
            }
            flag = true;
            break;
        }
    }
    //debug(a);
    
    if(flag){
        for(auto e : a){
            cout << e << " ";
        }
        cout << ln;
    }
    else{
        vector<ll> a1,a2;

        rep(i,n)a1.pb(a[i]);

        rep(i,n-m)a2.pb(a[i]);
        rep(i,m)a2.pb(b[i]);

        vector<ll> ans = min(a1,a2);

        rep(i,n){
            cout << ans[i] << " ";
        }
        cout << ln;
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