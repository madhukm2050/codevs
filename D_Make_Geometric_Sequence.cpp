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

ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}

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

vector<double> helper(vector<double> a, vector<double> b, ll n){
    vector<double> vec;
    if((ll)a.size()  == n)return a;
    //if(b.size() == n)return b;
    ll i = 0, j = 0, n1 = sz(a), n2 = sz(b);
    ll k = 0;
    while(i < n1 && j < n2){
        if(k%2 == 0){
            vec.pb(a[i]);
            i++;
        }
        else{
            vec.pb(b[j]);
            j++;
        }
        k++;
    }

    if(i < n1){
        vec.pb(a[i]);
        i++;
    }
    
    return vec;
}
void solve() {
    ll n;
    cin >> n;
    vector<double> pos, neg;

    rep(i,n){
        double a;
        cin >> a;
        if(a > 0)pos.pb(a);
        else neg.pb(abs(a));
    }
    sort(all(pos));
    sort(all(neg));
    vector<double>vec1 = helper(pos, neg, n), vec2 = helper(neg, pos, n);


    bool flag1 = true, flag2 = true;

    if(sz(vec1) != n)flag1 = false;
    if(sz(vec2) != n)flag2 = false;
    
    if(flag1){
        for(ll i = 0; i < n-1; i++){
            if(vec1[i] * vec1[1] != vec1[i + 1]*vec1[0]){
                flag1 = false;
            }
        }
    }
    
    if(flag2){
        for(ll i = 0; i < n-1; i++){
            if(vec2[i] * vec2[1] != vec2[i + 1]*vec2[0]){
                flag2 = false;
            }
        }
    }
    
    if(flag1 || flag2){
        Yes;
    }
    else{
        No;
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