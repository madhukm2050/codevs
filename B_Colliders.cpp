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

ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}

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

// ll N = 100000+5;

// vector<ll> primes(N+1, 1);

// void seive(){
//     for(ll i = 2; i*i <= N; i++){
//         if(primes[i] == 1){
//             for(ll j = i*i; j <= N; j += i){
//                 primes[j] = 0;
//             }
//         }
//     }
// }

void solve() {
    ll n, q;
    cin >> n >> q;

    vector<ll> vis(n+1, 0), factors(n+1, 0);

    rep(i,q){
        char c;
        cin >> c;
        ll a;
        cin >> a;

        if(c == '+'){
            if(vis[a]){
                cout << "Already on" << ln;
            }
            else{
                vector<ll> v;
                ll val = a;
                bool flag = true;
                ll conflict = 0;
                for(ll j = 2; j*j <= val; j++){
                    if((val%j) == 0){
                        v.pb(j);
                        if(factors[j] != 0){
                            conflict = factors[j];
                            flag = false;
                            break;
                        }
                        while(val%j == 0){
                            val /= j;
                        }
                    }
                }
                if(val > 1){
                    v.pb(val);
                    if(factors[val] != 0){
                        flag = false;
                        conflict = factors[val];
                    }
                }
                if(flag){
                    vis[a] = 1;
                    cout << "Success" << ln;
                    for(auto e : v){
                        factors[e] = a;
                    }
                }
                else{
                    cout << "Conflict with "<<conflict<< ln;
                }
            }
        }
        else{
            if(vis[a] == 0){
                cout << "Already off" << ln;
            }
            else{
                vis[a] = 0;
                // if(primes[a]){
                //     cout << "Success" << ln;
                // }
                // else{
                    ll val = a;
                    for(ll j = 2; j*j <= val; j++){
                        if((val%j) == 0){
                            factors[j] = 0;
                            while(val%j == 0){
                                val /= j;
                            }
                        }
                    }
                    if(val > 1){
                        factors[val] = 0;
                    }
                    cout << "Success" << ln;
                //}
            }
        }
        //debug(factors);

    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    //cin >> t;
    //seive();
    //debug(primes);
    while (t--) {
        solve();
    }
    return 0;
}