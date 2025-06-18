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
    ll n, q;
    cin >> n >> q;

    string s1, s2;
    cin >> s1 >> s2;

    ll one1 = 0, one2 = 0;
    rep(i,n){
        if(s1[i] == '1')one1++;
    }
    rep(i,n){
        if(s2[i] == '1')one2++;
    }
    if(one1+one2 <= n){
        cout << -1 << ln;
        return;
    }
    vector<ll> c1(n), c2(n);
    ll l1 = 0, h1 = 0, l2 = n-1, h2 = n-1;

    ll cost1 = 0;
    while(h1 < n){
        bool flag = false;
        if(s1[h1] == '1'){
            s1[h1] = '0';
            s1[l1] = '1';
            cost1 += (h1-l1);
            flag = true;
        }

        c1[l1] = cost1;
        if(flag)l1++;
        h1++;
    }

    ll cost2 = 0;
    while(h2 >= 0){
        bool flag = false;
        if(s2[h2] == '1'){
            s2[h2] = '0';
            s2[l2] = '1';
            cost2 += (l2-h2);
            flag = true;
        }

        c2[l2] = cost2;
        if(flag)l2--;
        h2--;
    }
    // debug(c1);
    // debug(c2);
    //cerr << n-one2 << " "<< one1 << ln;
    ll ans = INF;
    for(ll i = n-one2; i < one1; i++){
        ans = min(ans, c1[i]+c2[i]);
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