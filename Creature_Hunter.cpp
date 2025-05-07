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
    ll n, d;
    cin >> n >> d;

    vector<ll> one, two;
    rep(i,n){
        ll a, b;
        cin >> a >> b;

        if(a == 1){
            one.pb(b);
        }
        else{
            two.pb(b);
        }
    }
    ll v1 = 0, v2 = 0, z1 = 0;

    sort(one.rbegin(), one.rend());
    sort(two.rbegin(), two.rend());

    ll n1 = sz(one), n2 = sz(two);
    if(n1 > 0)v1 = one[0];
    if(n1 > 1)v2 = one[1];
    if(n2 > 0)z1 = two[0];


    v1 = max(v1, v2), v2 = min(v1, v2);
    if(v1 >= d){
        cout << 1 << ln;
        return;
    }
    ll c1 = INF, c2 = INF, c3 = INF, c4 = INF, c5 = INF;

    if(z1 > 0){
        c1 = ((d+z1-1)/z1)*2ll;

        ll dd = d;
        if(v1+v2 > 0){
            c2 = (dd/z1)*2ll;
            dd = dd%z1;
            c2 += (dd+v1-1)/v1;
        }
    }
    
    ll dd1 = d;

    if(v1+v2 > 0) {
        ll z2 = v1+v2;
        c3 = ((d+z2-1)/z2)*2;
        if(v1+v2 > 0){
            c4 = (d/z2)*2;
            d = d%z2;
            c4 += (d+v1-1)/v1;
        }
    }
    if(v1 > 0){
        c5 = (dd1+v1-1)/v1;
    }

    //cerr << c1 << " "<<c2 << " "<<c3 << " "<<c4 << " "<<c5 << ln;

    cout << min({c1,c2,c3,c4, c5}) << ln;


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