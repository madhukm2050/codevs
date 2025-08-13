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

void solve() {
    ll n;
    cin >> n;

    vector<ll> a(n), b(n);

    rep(i,n)cin >> a[i];
    rep(i,n)cin >> b[i];

    ll count = 0, l = 0, r = 1, prev = min(a[0], b[0]);

    while(r < n){
        if(prev > max(a[r],b[r])){
            ll n1 = r-l;
            count += (n1*(n1+1))/2;
            debug(count);
            {
                ll min1 = min(a[r], b[r]);
                ll l1 = r-1;
                while(l1 >= 0){
                    if(max(a[l1], b[l1]) < min1){
                        min1 = max(a[l1], b[l1]);
                    }
                    else if(min(a[l1], b[l1]) < min1){
                        min1 = min(a[l1], b[l1]);
                    }
                    else{
                        break;
                    }
                    l1--;
                }
                l1++;
                ll n2 = r-l1;
                debug(n2);
                count -= (n2*(n2+1))/2;
                l = l1;
            }
            
            prev = min(a[r], b[r]);
        }
        else if(min(a[r],b[r]) > prev){
            prev = min(a[r], b[r]);
        }
        else{
            prev = max(a[r], b[r]);
        }
        debug(prev);
        cerr <<" mmm "<< l << " "<< r << ln;
        cerr << count << ln; 
        r++;
    }
    ll n1 = r-l;
    count += (n1*(n1+1))/2;

    cout << count << ln;
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