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

void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> vec;

    ll count = 1;
    char c = s[0];

    for(ll i = 1; i < n; i++){
        if(s[i] == c){
            count++;
        }
        else{
            vec.pb(count);
            count = 1;
            c = s[i];
        }
    }
    vec.pb(count);

    //debug(vec);
    ll ind = 0;

    set<char> st;
    vector<ll> v;
    if(s[0] == '1'){
        ind = 1;
        st.insert('1');
        v.pb(-1);
        for(ll i = 1; i < sz(vec)-1; i+=2){
            ll d = vec[i]-vec[i+1];
            if(d > 0){
                st.insert('0');
                v.pb(1);
            }else if(d < 0){
                st.insert('1');
                v.pb(-1);
            }
        }
        if(s[n-1] == '0'){
            st.insert('0');
            v.pb(1);
        }
    }
    else{
        for(ll i = 0; i < sz(vec)-1; i+=2){
            ll d = vec[i]-vec[i+1];
            if(d > 0){
                st.insert('0');
                v.pb(1);
            }else if(d < 0){
                st.insert('1');
                v.pb(-1);
            }
        }
        if(s[n-1] == '0'){
            st.insert('0');
            v.pb(1);
        }
    }
    if(sz(st) == 0){
        cout << 0 << ln;
    }
    else if(sz(st) == 1){
        cout << 1 << ln;
    }
    else{
        bool flag = false, flag1 = true;
        for(auto e : v){
            if(e == -1){
                flag = true;
            }
            else if(e == 1 && flag){
                flag1 = false;
            }
        }
        if(flag1){
            cout<< 1 << ln;
        } 
        else{
            ll zero = 0;
            //debug(vec);
            //debug(v);
            ll j = 0;
            for(ll i = ind; i < sz(vec); i++){
                if((j%2) == 0){
                    zero += vec[i];
                }
                else{
                    if(zero == vec[i]){
                        zero = 0;
                    }
                }
                j++;
            }
            if(zero > 0){
                cout << 2 << ln;
            }
            else{
                cout << 1 << ln;
            }
        }

    }

    //debug(vec);
    //cout << sz(st) << ln;
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