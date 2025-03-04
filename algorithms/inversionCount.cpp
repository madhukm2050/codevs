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


ll mergesort(ll l, ll mid, ll h, vector<ll>& vec){
    ll i = l, j = mid+1;
    vector<ll> tmp;
    ll count = 0;
    while(i <= mid && j <= h){
        if(vec[i] > vec[j]){
            count += mid-i+1;
            tmp.pb(vec[j++]);
        }
        else{
            tmp.pb(vec[i++]);
        }
    }

    while(i <= mid){
        tmp.pb(vec[i++]);
    }

    while(j <= h){
        tmp.pb(vec[j++]);
    }

    for(ll x = l; x <= h; x++ ){
        vec[x] = tmp[x-l];
    }
    return count;
}

ll merge(ll l, ll h, vector<ll>& vec){
    ll count = 0;
    if(l >= h)return count;

    ll mid = (l+h)/2LL;

    count += merge(l,mid, vec);
    count += merge(mid+1, h, vec);

    count +=  mergesort(l, mid, h, vec);

    return count;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> vec(n);

    rep(i,n)cin >> vec[i];

    cout << merge(0, n-1, vec) << ln;

    debug(vec);
    
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