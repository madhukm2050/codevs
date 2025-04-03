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
    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll> vec(n);
    rep(i,n)cin >> vec[i];

    ll count = 0;
    ll l = 0, r = 0, sum = 0;
    while(r < n){
        sum += vec[r];
        while(sum >= x){
            sum -= vec[l];
            l++;
        }
        r++;
    }
    // cerr <<x/sum<< " "<< (x%sum) << " "<< sum*(x/sum) << ln;
    // cerr << (k*n)-(x/sum) << ln;
    if(l > 0){
        cout << n*(k-1ll)+l << ln;
        return;
    }
    ll x1 = x%sum , m = n-1, sum1 = 0;
    while(m >= 0 && sum1 < x1){
        sum1 += vec[m];
        m--;
        //cerr << "sum "<< sum1 << ln;
    }
    //cerr << m << " "<<sum1 << ln;
    k -= (x/sum);
    ll val = ((k-1)*n)+m+1;
    if(sum1+(sum*(x/sum)) >= x)val++;
    if(val <= 0){
        cout << 0 << ln;
        return;
    }
    cout << val << ln;
    //cerr << m+1 << ln;
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