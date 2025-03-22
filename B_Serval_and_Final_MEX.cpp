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
    vector<ll> vec(n);
    rep(i,n)cin >> vec[i];

    bool flag1 = false, flag2 = false;
    vector<bool> pre(n), suff(n);

    ll count = 0;

    for(ll i = 0; i < n; i++){
        if(vec[i] == 0){
            count++;
            flag1 = true;
        }
        pre[i] = flag1;
    }
    for(ll i = n-1; i >= 0; i--){
        if(vec[i] == 0)flag2 = true;
        suff[i] = flag2;
    }
    if(!flag1){
        cout << 1 << ln;
        cout << 1 << " "<< n <<ln;
        return;
    }
    if(count == n){
        cout << 3 << ln;
        cout << 1 << " "<< 1 << ln;
        cout << 2 << " "<< n << ln;
        cout << 1 << " "<< 2 << ln;
        return;
    }
    // debug(pre);
    // debug(suff);
    for(ll i = 0; i < n; i++){
        if(i == 0 && vec[i] != 0){
            if(suff[i+1]){
                cout << 2 << ln;
                cout << 2 << " "<< n << ln;
                cout << 1 << " "<< 2 << ln;
                return;
            }
        }
        else if(i == n-1 && vec[i] != 0){
            if(pre[i-1]){
                cout << 2 << ln;
                cout << 1 << " "<< i << ln;
                cout << 1 << " "<< 2 << ln;
                return;
            }
        }
        else{
            if(vec[i] != 0 && pre[i-1] && suff[i+1]){
                cout << 3 << ln;
                cout << 1<<" " << i << " "<< ln;
                cout << 2<<" "<< n << " "<< ln;
                cout << 1 << " "<< 3<<ln;
                return;
            }
        }
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