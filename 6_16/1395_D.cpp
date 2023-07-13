#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rep_r(i,a,b) for(int i=a;i>=b;i--)
#define each(a,x) for (auto& x : a)
using pi = pair<int,int>;
using pl = pair<ll,ll>;
using vi = vector<int>;
using vl = vector<ll>;
#define fi first    
#define se second
#define sz(x) int(x.size())
#define so(x) sort(all(x))
#define so_r(x) sort(all(x),greater<int>())
#define zero(x) memset(x,0,sizeof(x))
#define pb push_back
#define lb lower_bound
#define ub upper_bound
const char nl = '\n';
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int bit_cnt(int x){
    return __builtin_popcount(x);
}
ll bex(ll a, ll b, ll mod = 1){ll res = 1LL; while(b){ if (b&1) res = res * a % mod; a = a * a % mod; b >>= 1;} return res;}
template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}

// winter is coming 
const int MOD = 1e9 + 7; // 998244353
const int N = 1e5 + 5;
const ll INF = 1e18;
ll n,d; ll m;
vl big, small;
ll pref1[N], pref2[N];
void solve(){
    cin >> n >> d >> m;
    
    rep(i,1,n){
        ll x; cin >> x;
        if (x > m) big.pb(x);
        else small.pb(x);
    }
    so_r(small), so_r(big);
    ll ans = 0;
    ll n1 = sz(big), n2 = sz(small);
    rep(i,1,n1){   
        pref1[i] = pref1[i-1] + big[i-1];
    }
    rep(i,1,n2){
        pref2[i] = pref2[i-1] + small[i-1];
    }
    ll day = min(n1,(n-1)/(d+1)+1);
    rep(i,1,day){
        ll left = n - (i - 1) * (d + 1) - 1;
        left = max(left,0LL);
        ll cur = pref1[i]+pref2[min(left,n2)];
        chmax(ans,cur);
    }
    chmax(ans,pref2[n2]);
    cout << ans;

}

int main(){
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; //cin >> t;
    while (t--){
        solve();
    }
}