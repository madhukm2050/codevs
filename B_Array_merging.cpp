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
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    rep(i,n)cin >> a[i];
    rep(i,n)cin >> b[i];
    map<ll,ll> map1, map2;
    
    ll count1 = 1;
    ll i = 1;
    for(i = 1; i < n; i++){
        if(a[i] == a[i-1]){
            count1++;
        }
        else{
            map1[a[i-1]] = max(map1[a[i-1]], count1);
            count1 = 1;
        }
    }
    map1[a[i-1]] = max(map1[a[i-1]], count1);

    ll count2 = 1;
    for(i = 1; i < n; i++){
        if(b[i] == b[i-1]){
            count2++;
        }
        else{
            map2[b[i-1]] = max(map2[b[i-1]], count2);
            count2 = 1;
        }
    }
    map2[b[i-1]] = max(map2[b[i-1]], count2);
    vector<ll> a1(2*n+1), b1(2*n+1);
   
    
    for(auto e : map1){
        a1[e.ff] = e.ss;
    }
    for(auto e : map2){
        b1[e.ff] = e.ss;
    }
    
    
    ll m1 = 1;
    for(int i = 0; i < 2*n+1; i++){
        m1 = max(m1, a1[i]+b1[i]);
    }

    cout << m1 << ln;

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