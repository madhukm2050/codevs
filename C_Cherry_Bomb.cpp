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
    ll n, k;
    cin >> n >> k;

    vector<ll> a(n), b(n);

    rep(i,n)cin >> a[i];
    rep(i,n)cin >> b[i];

    ll m1 = 0;
    set<ll> st;
    bool flag = false;
    rep(i,n){
        if(a[i] == 0)flag = true;
        m1 = max(m1, a[i]);
        if(b[i] != -1){
            st.insert(a[i]+b[i]);
        }
    }
    //debug(st);
    ll n1 = sz(st);
    if(n1 > 1){
        cout << 0 << ln;
    }
    else if(n1 == 1){
        ll first = *st.begin();
        if(m1 > first){
            cout << 0 << ln;
            return;
        }
        rep(i,n){
            if(b[i] == -1){
                if(first-a[i] > k){
                    cout << 0 << ln;
                    return;
                }
            }
        }
        cout << 1 << ln;
    }
    else{ 
        ll min1 = *min_element(all(a));
        ll max1 = *max_element(all(a));

        if(max1-min1 > k){
            cout << 0 << ln;
        }
        else{
            ll mm = max1-min1;
            cout << k-mm+1 << ln;
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