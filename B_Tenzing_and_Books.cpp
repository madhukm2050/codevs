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
    ll n, x;
    cin >> n >> x;

    vector<ll> a(n),b(n),c(n);

    rep(i,n)cin >> a[i];
    rep(i,n)cin >> b[i];
    rep(i,n)cin >> c[i];


    bool flag1 = true, flag2 = true, flag3 = true;
    ll count = 0;
    for(ll i = 0;i < 32; i++){
        if((x&(1LL<<i)) != 0)count++;
    }
    vector<ll> vis(32,0);

    for(ll i = 0; i < n; i++){
        if(flag1){
            vector<ll> vis1(32,0);
            for(ll j = 0; j < 32; j++){
                if((x&(1ll<<j)) && (a[i] &(1ll <<j))){
                    if((a[i]&(1ll<<j))){
                        vis1[j] = 1;
                    }
                }
                else if((a[i] &(1ll << j))){
                    flag1 = false;
                    break;
                }
            }
            //cerr << a[i]<< " "<<flag1 << ln;

            //debug(vis1);
            if(flag1){
                for(ll j = 0; j < 32; j++){
                    vis[j] = vis[j]|vis1[j];
                }
            }
        }
        if(flag2){
            vector<ll> vis1(32,0);
            for(ll j = 0; j < 32; j++){
                if((x&(1ll<<j)) && (b[i] &(1ll << j))){
                    if((b[i]&(1ll<<j))){
                        vis1[j] = 1;
                    }
                }
                else if((b[i] &(1ll << j))){
                    flag2 = false;
                    break;
                }
            }
            //cerr << b[i]<< " "<<flag2 << ln;
            //debug(vis1);
            if(flag2){
                for(ll j = 0; j < 32; j++){
                    vis[j] = vis[j]|vis1[j];
                }
            }
        }
        if(flag3){
            vector<ll> vis1(32,0);
            for(ll j = 0; j < 32; j++){
                if((x&(1ll<<j)) && (c[i] &(1ll << j))){
                    if((c[i]&(1ll<<j))){
                        vis1[j] = 1;
                    }
                }
                else if((c[i] &(1ll << j))){
                    flag3 = false;
                    break;
                }
            }
            //cerr << c[i] <<" "<< flag3<<ln;
            //debug(vis1);
            if(flag3){
                for(ll j = 0; j < 32; j++){
                    vis[j] = vis[j]|vis1[j];
                }
            }
        }
    }
    //debug(vis)
    for(ll i = 0; i < 32;i++){
        //cerr << (x&(1ll<<i)) <<" "<<vis[i] <<ln;
        if(((x&(1ll<<i)) == vis[i]) || ((x&(1ll<<i)) && vis[i])){
            
        }
        else{
            No;
            return;
        }
    }
    Yes;

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