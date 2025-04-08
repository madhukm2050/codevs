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
    vector<ll> vec(n);
    map<ll,ll> map;
    ll m1 = 0;

    rep(i,n){
        cin >> vec[i];
        map[vec[i]]++;
        m1 = max(m1, vec[i]);
    }

    ll j = 0;
    for(auto e : map){
        if(e.ff != j){
            cout << j << ln;
            return;
        }
        if(e.ss < k){
            //debug(vec);
            //cerr << e.ff << " "<<e.ss << ln;
            cout << e.ff << ln;
            return;
        }
        j++;
    }

    ll i = 0, ans = m1+1, c1 = 0;
    while(i < n){
        vector<ll> vis(m1+1);
        ll c = 0;
        while(i < n){
            if(vis[vec[i]] == 0){
                vis[vec[i]] = 1;
                c++;
            }
            i++;
            if(c == m1+1)break;
        }
        if(i == n){
            for(ll j = 0; j <= m1; j++){
                if(vis[j] == 0){
                    ans = j;
                    break;
                }
            }
        }
        c1++;
        if(c1 == k)break;
    }
    i = n-1;
    ll c2 = 0, ans1 = m1+1;
    while(i >= 0){
        vector<ll> vis(m1+1);
        ll c = 0;
        while(i >= 0){
            if(vis[vec[i]] == 0){
                vis[vec[i]] = 1;
                c++;
            }
            i--;
            if(c == m1+1)break;
        }
        if(i == -1){
            for(ll j = 0; j <= m1; j++){
                if(vis[j] == 0){
                    ans1 = j;
                    break;
                }
            }
        }
        c2++;
        if(c2 == k)break;
    }
    cout << max(ans, ans1) << ln;



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