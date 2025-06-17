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
    ll n1, n2, n3, n4;

    vector<pair<ll,ll>> vec;
    cin >> n1;
    rep(i,n1){
        ll a;
        cin >> a;
        vec.pb({a,1});
    }

    cin >> n2;
    rep(i,n2){
        ll a;
        cin >> a;
        vec.pb({a,2});
    }

    cin >> n3;
    rep(i,n3){
        ll a;
        cin >> a;
        vec.pb({a,3});
    }
    cin >> n4;
    rep(i,n4){
        ll a;
        cin >> a;
        vec.pb({a,4});
    }
    sort(all(vec));
    //debug(vec);

    vector<ll> freq(5,0), a(5,0);
    ll count = 0, start = 0, end = 0, l = 0, max1 = INF;

    for(ll i = 0; i < sz(vec); i++){
        if(freq[vec[i].ss] == 0)count++;
        freq[vec[i].ss]++;
        while(count == 4){
            //cerr <<l << " "<< i << ln;
            //debug(vec[i].ff-vec[l].ff);
            if(vec[i].ff-vec[l].ff < max1){
                max1 = vec[i].ff-vec[l].ff;
                start = l;
                end = i;
            }
            freq[vec[l].ss]--;
            if(freq[vec[l].ss] == 0){
                count--;
            }
            l++;
        }
        //debug(i);
        //debug(freq);
    }
    //cerr<< start << " "<< end << ln;
    //cerr << max1 << ln;
    for(ll i = start ; i <= end; i++){
        a[vec[i].ss] = vec[i].ff;
    }
    for(ll i = 1; i < 5; i++){
        cout << a[i] << " ";
    }
    cout << ln;
    
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