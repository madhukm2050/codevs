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

#define LONG_LONG_MAX 9223372036854775807LL
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

ll cal(ll a, ll b, ll c){
    return (a-b)*(a-b) + (b-c)*(b-c) + (a-c)*(a-c);
}

ll ans = LONG_LONG_MAX;
void helper(vector<ll> a, vector<ll> b, vector<ll> c){
    ll i = 0, j = 0, k = 0;

    while(i < a.size()){
        while(j < b.size()-1 && b[j] < a[i])j++;
        while(k < c.size()-1 ){
            if(c[k+1] > a[i])break;
            k++;
        }
        ans = min(ans, cal(a[i], b[j], c[k]));
        i++;
    }
}

void solve() {

    ll r, g, b;
    cin >> r >> g >> b;

    //cerr << r << " "<< g << " "<< b << ln;

    vector<ll> red(r), green(g), blue(b);

    rep(i,r){
        cin >> red[i];
    }
    rep(i,g){
        cin >> green[i];
    }
    rep(i,b){
        cin >> blue[i];
    }

    sort(all(red));
    sort(all(green));
    sort(all(blue));

    ans = cal(red[0], green[0], blue[0]);

    helper(red, green, blue);
    helper(red, blue, green);
    helper(green, red, blue);
    helper(green, blue, red);
    helper(blue, red, green);
    helper(blue, green, red);

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