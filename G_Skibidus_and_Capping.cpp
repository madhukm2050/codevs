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

const ll N = 1e6+7;

vector<ll> seive(N+1);

void primeFactorization(){
    for(ll i = 2; i <= N; i++){
        seive[i] = i;
    }
    for(ll i = 2; i <= N; i++){
        if(seive[i] == i){
            for(ll j = i*i; j <= N; j += i){
                if(seive[j] == j){
                    seive[j] = i;
                }
            }
        }
    }
}
void solve() {
    ll n;
    cin >> n;
    vector<ll> vec(n);
    rep(i,n)cin >> vec[i];

    map<ll,ll> p;
    map<ll,ll> pp;
    map<ll,ll> pq;

    ll prime = 0, one = 0;
    for(auto e : vec){
        if(e == seive[e]){
            p[e]++;
            prime++;
        }
        else if(e == seive[e]*seive[e]){
            pp[e]++;
        }
        else if(e == seive[e]*seive[e/seive[e]]){
            pq[e]++;
        }
        one += (e == 1);
    }
    ll count = 0;
    for(auto e : pq){
        count += e.ss * p[seive[e.ff]]; // p pq
        count += e.ss * p[e.ff/seive[e.ff]]; 
        count += (e.ss * (e.ss+1))/2; // pq pq
        count += one*e.ss;
    }
    ll sum = 0;
    for(auto e : p){
        sum += e.ss*(prime-e.ss);
    }
    count += (sum/2);
    for(auto e : pp){
        count += e.ss * p[e.ff/seive[e.ff]]; // p pp
        count += (e.ss * (e.ss+1))/2;
        count += one*e.ss;
    }

    cout << count << ln;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    primeFactorization();
    //debug(seive);
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}