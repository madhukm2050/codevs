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

bool helper(vector<ll> a, ll mid){
    ll count = 0;
    for(ll i = 0; i < sz(a); i++){
        ll d = mid-a[i];
        if(d > 0){
            if(d%2 == 1)d--;
            count += d;
        }
        else count += 2*d;
    }
    //cerr <<mid << " "<< count << ln;
    if(count < 0)return false;
    return true;
}

void solve() {
    ll n;
    cin >> n;

    vector<ll> a(n), b(n);

    rep(i,n)cin >> a[i];
    rep(i,n)cin >> b[i];

    ll min1 = INF, max1 = 0, m1 = 0;

    vector<ll> c(n);
    rep(i,n){
        c[i] = a[i]+b[i];
        m1 = max(m1, a[i]);
        min1 = min(min1, c[i]);
        max1 = max(max1, c[i]);
    }
    //debug(c);

    ll l = max(m1,min1), h = max1, ans = max1;

    while(l <= h){
        ll mid = (l+h)/2;
        if(helper(c, mid)){
            ans = mid;
            h = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    cout << ans << ln;

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