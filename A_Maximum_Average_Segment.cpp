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
typedef long double ld;


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

ld maximumSubarray(vector<ld> a, ll d, ll n){
    vector<ld> pre(n);
    pre[0] = a[0];
    for(ll i = 1; i < n; i++){
        pre[i] += pre[i-1] + a[i];
    }

    ld ans = -1e18, min1 = 0;

    for(ll i = d-1; i < n; i++){
        ld best = pre[i] - min1;

        min1 = min(min1, pre[i-d+1]);

        ans = max(ans, best);
    }
    return ans;
}

bool helper(ld mid, vector<ld> vec, ll d, ll n){
    vector<ld> a(n);

    rep(i,n)a[i] = vec[i] - mid;

    return maximumSubarray(a, d, n) >= 0;
}

pair<ll,ll> bestsubarray(vector<ld> a, ll d, ll n){
    vector<ld> pre(n);
    pre[0] = a[0];
    for(ll i = 1; i < n; i++){
        pre[i] += pre[i-1] + a[i];
    }

    ld ans = -1e18, min1 = 0;
    ll ind = -1;

    for(ll i = d-1; i < n; i++){
        ld best = pre[i] - min1;
        ans = max(ans, best);
        if(ans >= 0){
            return {ind+1, i};
        }
        if(min1 > pre[i-d+1]){
            min1 = pre[i-d+1];
            ind = i-d+1;
        }
    }
    return {-10, -10};
}

pair<ll,ll> helper1(ld mid, vector<ld> vec, ll d, ll n){
    vector<ld> a(n);

    rep(i,n)a[i] = vec[i] - mid;

    return bestsubarray(a, d, n);
}

void solve() {
    ll n, d;
    cin >> n >> d;

    vector<long double> vec(n);
    rep(i,n)cin >> vec[i];

    //debug(vec);

    long double l = 0, h = 100;

    for(ll i = 0; i < 100; i++){
        //cerr << l << " "<< h <<ln;
        long double mid = (l+h)/2;

        if(helper(mid, vec, d, n)){
            l = mid;
        }
        else{
            h = mid;
        }
    }

    //cerr << l << ln;

    pair<ll,ll> p = helper1(l, vec, d, n);

    cout << p.ff+1 << " "<< p.ss+1 << ln;

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