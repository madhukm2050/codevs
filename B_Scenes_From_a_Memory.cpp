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
    vector<ll> freq(8,0);
    for(ll i = 0; i < n; i++){
        if(s[i] == '1' || s[i] == '4' || s[i] == '6' || s[i] == '8' || s[i] == '9'){
            cout << 1 << ln;
            cout << s[i] << ln;;
            return;
        }
        else{
            freq[s[i]-'0']++;
        }
    }
    for(ll i = 2; i < 8; i++){
        if(freq[i] > 1){
            cout << 2 << ln;
            cout << i<<""<<i << ln;
            return;
        }
    }
    
    set<ll> st;
    for(ll i = 0; i < n; i++){
        if(s[i] == '2'){
            if(st.find(5) != st.end()){
                cout << 2 << ln;
                cout << "52" << ln;
                return;
            }
            else if(st.find(7) != st.end()){
                cout << 2 << ln;
                cout << "72" << ln;
                return;
            }
            else if(st.find(3) != st.end()){
                cout << 2 << ln;
                cout << "32" << ln;
                return;
            }
            
        }
        else if(s[i] == '5'){
            if(st.find(2) != st.end()){
                cout << 2 << ln;
                cout << "25" << ln;
                return;
            }
            else if(st.find(7) != st.end()){
                cout << 2 << ln;
                cout << "75" << ln;
                return;
            }
            else if(st.find(3) != st.end()){
                cout << 2 << ln;
                cout << "35" << ln;
                return;
            }
        }
        else if(s[i] == '7'){
            if(st.find(2) != st.end()){
                cout << 2 << ln;
                cout << "27" << ln;
                return;
            }
            else if(st.find(5) != st.end()){
                cout << 2 << ln;
                cout << "57" << ln;
                return;
            }
        }
        st.insert(s[i]-'0');
    }
    //cerr << s << ln;
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