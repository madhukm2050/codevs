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
    ll count = 0;
    rep(i,n){
        if(vec[i] == 1)count++;
    }
    if(count != 0 && count != n){
        cout << -1 << ln;
        return;
    }
    vector<pair<ll,ll>> vec1(n);

    rep(i,n){
        vec1[i] = {vec[i], i};
    }
    sort(all(vec1));
    vector<pair<ll,ll>> ans;

    while(1){
        vector<pair<ll,ll>> tmp;
        tmp.pb({vec1[0].ff, vec1[0].ss});
        ll c1 = 0;
        
        for(ll i = 1; i < n; i++){
            if(vec1[0].ff  != vec1[i].ff){
                c1++;
                ll a = (vec1[i].ff+vec1[0].ff-1)/vec1[0].ff;
                tmp.pb({a, vec1[i].ss});
                ans.pb({vec1[i].ss, vec1[0].ss});
            }
            else{
                tmp.pb({vec1[i].ff, vec1[i].ss});
            }
        }
        if(c1 == 0)break;
        vec1 = tmp;
        sort(all(vec1));
        //debug(vec1);
    }
    cout << sz(ans) << ln;

    for(auto e : ans){
        cout << e.ff+1 << " "<< e.ss+1 <<ln;
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