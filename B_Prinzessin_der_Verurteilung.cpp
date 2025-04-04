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

struct cmp{
    bool operator()(string a, string b){
        if(a.length() != b.length())return a.length() < b.length();
        return a < b;
    }
};

set<string, cmp> st2;

void build(){
    for(ll i = 0; i < 26; i++){
        for(ll j = 0; j < 26; j++){
            for(ll k = 0; k < 26; k++){
                string str = string(1, 'a'+i);
                st2.insert(str);
                str += string(1,'a'+j);
                st2.insert(str);
                str += string(1,'a'+k);
                st2.insert(str); 
            }
        }
    }
    // cout << st2.size() << ln;
    // for(auto e : st2){
    //     cout << e << " ";
    // }
}

void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;

    set<string> st1;

    for(ll i = 0; i < n; i++){
        string s1 = "";
        for(ll j = i; j < n; j++){
            s1 += s[j];
            st1.insert(s1);
        }
    }
    for(auto e : st2){
        if(st1.find(e) == st1.end()){
            cout << e << ln;
            return;
        }
    }
    

    

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    build();
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}