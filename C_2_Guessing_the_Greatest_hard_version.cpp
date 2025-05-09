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

vector<ll> arr = {0,5,3,9,7,10,4,2,1};
int secondMaxInSegment(ll l, ll r) {
    ll max1 = INT_MIN, max2 = INT_MIN, ind1 = -1, ind2 = -1;

    for (int i = l; i <= r; ++i) {
        if (arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
            ind2 = ind1;
            ind1 = i;
        } else if (arr[i] > max2 && arr[i] != max1) {
            max2 = arr[i];
            ind2 = i;
        }
    }

    return (max2 == INT_MIN) ? -1 : ind2; 
}
bool flag = true;

ll interactor(ll l, ll h){
    return secondMaxInSegment(l,h);
}

ll ask(ll l, ll h){
    cout << "? "<< l <<" "<< h << endl;
    //if(flag)return interactor(l,h);
    ll n;
    cin >> n;
    return n;
}

ll right(ll l, ll h){
    ll p = l-1, ans = h;

    while(l <= h){
        ll mid = (l+h)/2;

        if(ask(p, mid) == p){
            ans = mid;
            h = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return ans;
}

ll left(ll l, ll h){
    ll p = h+1, ans = l;

    while(l <= h){
        ll mid = (l+h)/2;

        if(ask(mid, p) == p){
            l = mid+1;
        }
        else{
            ans = mid;
            h = mid-1;
        }
    }
    return ans;
}

void solve() {
    ll n;
    cin >> n;

    ll p = ask(1,n);

    if(p == 1){
        cout << "! "<< right(p+1, n) << endl;
    }
    else if(ask(1,p)==p){
        cout << "! "<< left(1, p-1) << endl;
    }
    else{
        cout << "! "<< right(p+1, n) << endl;
    }
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