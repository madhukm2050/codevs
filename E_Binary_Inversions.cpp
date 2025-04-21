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
    vector<ll> vec1(n), vec2(n), vec3(n);
    ll one = -1, zero = -1;
    rep(i,n){
        ll a;
        cin >> a;
        if(a == 1){
            one = i;
        }
        if(a == 0 && zero == -1){
            zero = i;
        }
        vec1[i] = a;
        vec2[i] = a;
        vec3[i] = a;
    }
    ll count1 = 0, count2 = 0, count3 = 0, c1 = 0, c2 = 0, c3 = 0;

    for(ll i = 0; i < n; i++){
        if(vec1[i] == 1){
            c1++;
        }
        else{
            count1 += c1;
        }
    }
    if(zero != -1){
        vec2[zero] = 1;
        for(ll i = 0; i < n; i++){
            if(vec2[i] == 1){
                c2++;
            }
            else{
                count2 += c2;
            }
        }
    }
    if(one != -1){
        vec3[one] = 0;
        for(ll i = 0; i < n; i++){
            if(vec3[i] == 1){
                c3++;
            }
            else{
                count3 += c3;
            }
        }
    }

    cout << max(count1, max(count2, count3)) << ln;

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