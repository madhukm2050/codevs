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
    rep(i,n)cin >> vec[i];

    multiset<ll> l, r;

    ll lsum = 0, rsum = 0;

    auto balance = [&](){
        if(r.size() > l.size()){
            lsum += *r.begin();
            rsum -= *r.begin();
            l.insert(*r.begin());
            r.erase(r.begin());
        }

        if(l.size()-1 > r.size()){
            rsum += *l.rbegin();
            lsum -= *l.rbegin();
            r.insert(*l.rbegin());
            l.erase(prev(l.end()));
        }
    };
    //debug(vec);

    vector<ll> ans;
    for(ll i = 0; i < n; i++){
        if(l.empty() || vec[i] <= *l.rbegin()){
            l.insert(vec[i]);
            lsum += vec[i];
        }
        else{
            r.insert(vec[i]);
            rsum += vec[i];
        }
        balance();

        if(i >= k){
            if(vec[i-k] <= *l.rbegin()){
                lsum -= vec[i-k];
                l.erase(l.find(vec[i-k]));
            }
            else{
                rsum -= vec[i-k];
                r.erase(r.find(vec[i-k]));
            } 
            balance();
        }

        if(i >= k-1){
            ll mid =*l.rbegin();
            ll req = 0, n1 = l.size(), n2 = r.size();
            //cerr << lsum << " "<<rsum << " "<<l.size() << " "<< r.size() << ln;
            req += abs((n1*mid)-lsum);
            req += abs(rsum - (n2*mid));
            ans.pb(req);
        }
        //debug(l);
        //debug(r);
    }

    for(auto e : ans){
        cout << e << " ";
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