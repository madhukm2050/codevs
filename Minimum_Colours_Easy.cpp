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

    vector<ll> first(n+1, -1), last(n+1);
    set<ll> s;
    vector<ll>a(n);

    rep(i,n){
        cin >> vec[i];
        if(first[vec[i]] == -1){
            first[vec[i]] = i;
        }
        last[vec[i]] = i;
        s.insert(vec[i]);
        a[i] = s.size();
    }
    priority_queue<pair<ll,pair<ll,ll>>> pq;
    for(auto e : vec){
        ll d = a[last[e]]-a[first[e]]+1;
        //cerr << d << ln;
        pq.push({d, {first[e], last[e]}});
    }

    pair<ll,pair<ll,ll>> p1 = pq.top();
    pq.pop();
    ll m1 = p1.ss.ff, m2 = p1.ss.ss;
    for(ll i = m1; i<= m2; i++){
        vec[i] = vec[m1];
    }
    while(!pq.empty()){
        pair<ll,pair<ll,ll>> p2 = pq.top();
        pq.pop();
        ll f = p2.ss.ff, l = p2.ss.ss;
        if(l < m1){
            for(ll i = f; i <= l; i++){
                vec[i] = vec[f];
            }
        }
        else if(f > m2){
            for(ll i = f; i <= l; i++){
                vec[i] = vec[f];
            }
        }
    }
    debug(vec);
    set<ll> st;
    for(auto e : vec){
        st.insert(e);
    }

    cout << st.size() << ln;


    

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