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

vector<string> rotate(vector<string> s, ll n){
    vector<string> ans = s;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            ans[j][n-i-1] = s[i][j];
        }
    }
    return ans;
}

ll count(vector<string> s, vector<string> t, ll n){
    ll count = 0;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            if(s[i][j] != t[i][j])count++;
        }
    }
    return count;
}

void solve() {
    ll n;
    cin >> n;
    vector<string> s(n);
    vector<string> t(n);


    rep(i,n)cin >> s[i];
    rep(i,n)cin >> t[i];

    ll c1 = count(s, t, n);

    vector<string> s1 = rotate(s, n);
    vector<string> s2 = rotate(s1, n);
    vector<string> s3 = rotate(s2, n);

    ll c2 = 1 + count(s1, t, n);
    ll c3 = 2 + count(s2, t, n);
    ll c4 = 3 + count(s3, t, n);

    //debug(s1);

    //cerr << c1 << " "<< c2 << " "<< c3 << " "<<c4 << ln;

    cout << min(c1, min(c2, min(c3, c4))) << ln;


    


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