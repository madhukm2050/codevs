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

vector<ll> pre = {0,16,8,15,42,23,4};
ll ask(ll l, ll r){
    cout <<"? "<< l << " " << r << endl;

    //return pre[l]*pre[r];
    ll n;
    cin >> n;
    return n;
}

void solve() {
    vector<ll> vec = {4, 8, 15, 16, 23, 42};

    map<ll,pair<ll,ll>> map;
    for(ll i = 0; i < 6; i++){
        for(ll j = i+1; j < 6; j++){
            map[vec[i]*vec[j]] = {vec[i], vec[j]};
        }
    }

    vector<ll> ans(6);
    set<ll> s;
    ll a1 = ask(1,2);
    ll a2 = ask(2,3);
    ll aj = 0;

    vector<ll> v = {map[a1].ff, map[a1].ss, map[a2].ff, map[a2].ss};
    for(ll i = 0; i < 4; i++){
        if(s.find(v[i]) != s.end())aj = v[i];
        s.insert(v[i]);
    }
    ans[0] = a1/aj;
    ans[1] = aj;
    ans[2] = a2/aj;

    s.clear();
    v.clear();
    a1 = ask(4,5);
    a2 = ask(5,6);
    aj = 0;
    v = {map[a1].ff, map[a1].ss, map[a2].ff, map[a2].ss};
    for(ll i = 0; i < 4; i++){
        if(s.find(v[i]) != s.end())aj = v[i];
        s.insert(v[i]);
    }

    ans[3] = a1/aj;
    ans[4] = aj;
    ans[5] = a2/aj;

    cout << "! ";
    for(auto e : ans){
        cout << e << " ";
    }
    cout << endl;




    

    //debug(map);
    //cerr << sz(st) << " "<< sz(v) << ln;
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