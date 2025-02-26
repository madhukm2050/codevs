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

class MaxHeap{
    vector<ll> heap;

    void heapify_down(ll ind){
        ll n = heap.size();
        ll left = 2*ind+1;
        ll right = 2*ind+2;

        ll l = heap[ind];
        ll index = ind;

        if(left < n && heap[left] < l){
            l = heap[left];
            index = left;
        }

        if(right < n && heap[right] < l){
            l = heap[right];
            index = right;
        }

        if(index == ind)return;
        swap(heap[index], heap[ind]);
        heapify_down(index);
    }

    void heapify_up(ll ind){
        if(ind == 0)return;

        ll parent = (ind-1)/2;
        if(heap[ind] < heap[parent]){
            swap(heap[ind], heap[parent]);
            heapify_up(parent);
        }
    }

public:
    MaxHeap(vector<ll> arr){
        heap = arr;
    }

    void build(){
        ll n = heap.size();

        for(ll i = n/2-1; i >= 0; i--){
            heapify_down(i);
        }
    }

    ll get_max(){
        if(heap.size() == 0)return -1;
        return heap[0];
    }

    void insert(ll val){
        heap.pb(val);
        heapify_up(heap.size()-1);
    }

    void remove(){
        ll n = heap.size();
        swap(heap[0], heap[n-1]);
        heap.pop_back();
        if(heap.size() == 0) return;
        heapify_down(0);
    }

};

void solve() {
    ll n;
    cin >> n;
    vector<ll> vec(n);

    rep(i,n)cin >> vec[i];

    MaxHeap pq(vec);
    pq.build();
    cout<< pq.get_max() << ln;
    pq.remove();
    cout<< pq.get_max() << ln;
    pq.insert(34);
    cout<< pq.get_max() << ln;



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