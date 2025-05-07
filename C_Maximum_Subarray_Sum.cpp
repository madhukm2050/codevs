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
    string s;
    cin >> s;

    vector<ll> vec(n);
    rep(i,n)cin >> vec[i];

    ll sum = 0, max1 = 0, ind = -1;;

    for(ll i = 0; i < n; i++){
        if(s[i] == '1'){
            sum += vec[i];
            max1 = max(max1, sum);
        }
        else{
            if(ind == -1)ind = i;
            sum = 0;
        }
        if(sum < 0){
            sum = 0;
        }
    }
    cerr << max1 << ln;
    if(max1 > k){
        No;
        return;
    }
    else if(max1 == k){
        Yes;
        for(ll i = 0; i < n; i++){
            if(s[i] == '0'){
                vec[i] = -1e18;
            }
            cout << vec[i] << " ";
        }
        cout << ln;
        return;
    }
    else{
        if(ind == -1){
            No;
            return;
        }
        Yes;

        ll pre = 0, suff = 0, psum = 0, ssum = 0;
        for(ll i = ind-1; i >= 0; i--){
            if(s[i] == '0') break;
            psum += vec[i];
            pre = max(pre, psum);
        }

        for(ll i = ind+1; i < n; i++){
            if(s[i] == '0') break;
            ssum += vec[i];
            suff = max(ssum, suff);
        }
        vec[ind] = k-pre-suff;

        for(ll i = 0; i < n ; i++){
            if(s[i] == '0' && i != ind){
                vec[i] = -1e18;
            }
        }

        rep(i,n){
            cout << vec[i] << " ";
        }
        cout << ln;
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