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

    set<vector<ll>> pq0,pq1;
    set<pair<ll,ll>> st;

    auto push = [&](ll X, ll Y){
        if(st.find({X,Y}) != st.end())return;

        pq0.insert({3*X+3*Y+2, X, Y});

        pq1.insert({3*X+3*Y+2, 3*X+1, 3*Y+1});
        pq1.insert({3*X+3*Y+3, 3*X+2, 3*Y+1});
        pq1.insert({3*X+3*Y+3, 3*X+1, 3*Y+2});
        pq1.insert({3*X+3*Y+6, 3*X+2, 3*Y+2});
        st.insert({X,Y});
    };

    push(0,0);
    push(0,1);
    push(1,0);

    for(ll i = 0; i < n; i++){
        if(vec[i] == 0){
            auto v = *pq0.begin();
            ll x = v[1], y = v[2];
            pq0.erase(v);
            pq1.erase({3*x+3*y+2, 3*x+1, 3*y+1});
            cout << 3*x+1 << " "<< 3*y+1 << ln;

            push(x+1,y);
            push(x+2,y);
            push(x, y+1);
            push(x, y+2);
            push(x+1,y+1);
        }
        else{
            auto v = *pq1.begin();

            ll x = v[1]/3, y = v[2]/3;
            pq0.erase({3*x+3*y+2, x,y});
            pq1.erase(v);

            cout << v[1] << " "<<v[2] << ln;

            push(x+1,y);
            push(x+2,y);
            push(x, y+1);
            push(x, y+2);
            push(x+1,y+1);
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