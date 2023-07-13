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
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int bit_cnt(int x){
    return __builtin_popcount(x);
}
ll bex(ll a, ll b, ll mod = 1){ll res = 1LL; while(b){ if (b&1) res = res * a % mod; a = a * a % mod; b >>= 1;} return res;}
template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}

const int MOD = 1e9 + 7; // 998244353
const int N = 1e5 + 5;
const ll INF = 1e18;

void solve(){
    int n,k; cin >> n >> k;
    int x[n+1]; vi y(n+1);
    rep(i,1,n) cin >> x[i];
    rep(i,1,n) cin >> y[i];
    sort(x+1,x+1+n);
    vi ml(n+2), mr(n+2);
    int ans = 1;
    int j = 1;
    rep(i,1,n){
        while (x[j] < x[i] - k) j++;
        ml[i] = i - j + 1;
        if (i >= 2) ml[i] = max(ml[i],ml[i-1]);
    }
    j = n;
    rep_r(i,n,1){
        while (x[j] > x[i] + k) j--;
        mr[i] = j - i + 1;
        if (i <= n - 1) mr[i] = max(mr[i],mr[i+1]);
    }
    rep(i,1,n-1) chmax(ans,ml[i]+mr[i+1]);
    cout << ans << '\n';
}

int main(){
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; cin >> t;
    while (t--){
        solve();
    }
}