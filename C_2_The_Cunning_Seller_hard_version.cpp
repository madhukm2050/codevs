#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

#define ln "\n";
    
vector<ll> pow3(19, 0), cost(19, 0);

void solve(){
    ll n, k;
    cin >> n >> k;

    vector<ll> vec(19, 0);
    

    for(ll i = 18; i >= 0; i--){
        while(n >= pow3[i]){
            n -= pow3[i];
            vec[i]++;
            k--;
        }
    }
    if(k < 0){
        cout << -1 << ln;
        return;
    }
    // for(ll i = 0; i < 19; i++){
    //     cout << vec[i] << " ";
    // }
    // cout << ln;

    ll ans = 0;
    for(ll i = 18; i > 0; i--){
        ll move = min(vec[i], k/2);
        vec[i] -= move;
        vec[i-1] += 3*move;
        k -= 2*move;
        ans += vec[i]*cost[i];
        //cerr <<"h "<< i<< " "<< pow3[i] << " "<< cost[i] <<" "<< vec[i] << ln;
        //cerr << ans << ln;
    }
    ans += vec[0]*cost[0];

    cout << ans << ln;
}

int main(){
    pow3[0] = 1;
    for(ll i = 1; i < 19; i++){
        pow3[i] = pow3[i-1]*3ll;
    }
    cost[0] = 3;
    for(ll i = 1; i < 19; i++){
        cost[i] = cost[i-1]*3ll+pow3[i-1];
    }

    // for(ll i = 0; i < 19; i++)cout << pow3[i] << " ";
    // cout << ln;
    // for(ll i = 0; i < 19; i++)cerr << cost[i] << " ";
    // cerr << ln;

    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}