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
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    ll one1 = 0, zero1 = 0, one2 = 0, zero2 = 0, one3 = 0, zero3 = 0;

    rep(i,n){
        if(s1[i] == '0'){
            zero1++;
        }
        else{
            one1++;
        }
    }
    rep(i,n){
        if(s2[i] == '0'){
            zero2++;
        }
        else{
            one2++;
        }
    }
    rep(i,n){
        if(s3[i] == '0'){
            zero3++;
        }
        else{
            one3++;
        }
    }
    ll one = one1+one2+one3, zero = zero1+zero2+zero3;
    //cerr << one << " "<< zero << ln;
    if((one)%n != 0 || (zero)%n != 0){
        cout << -1 << ln;
        return;
    }
    ll max1 = max(zero1,max(zero2,zero3)), max2 = max(one1,max(one2,one3));
    
    cerr << max1 << " "<< max2 << ln;
    if(one == 3*n || zero == 3*n){
        cout << 0 << ln;
    }
    else if(zero > one){
        cout << n-max2 << ln;
    }
    else if(one > zero){
        cout << n- max1 << ln;
    }
    else{
        cout << 0 << ln;
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